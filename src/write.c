#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "note.h"
#include "read.h"
#include "wav.h"
#include "write.h"
#include "../err/error.h"

int32_t writeBar(FILE *wav, double bpm, int beatCount, char melody[][MAX_BUFFER_LENGTH + 1], int melodyCount, int barNumber) {
  int32_t sampleCount = SAMPLERATE * (60.0 / bpm) * beatCount;
  int16_t sample[sampleCount];
  for (int i = 0; i < sampleCount; i++)
    sample[i] = 0;

  for (int i = 0; i < melodyCount; i++) {
    char *ptr = &melody[i][0];
    double duration = 0;
    int sampleIndex = 0;
    while (1) {
      int forward = 0;
      if (isdigit(*ptr)) {
        forward = readDuration(ptr, &duration, barNumber);
      }
      else if (isalpha(*ptr) || *ptr == '(') {
        char notes[10][5];
        int noteCount = 0, noteSampleCount = SAMPLERATE * (60.0 / bpm) * duration;
        forward = readNote(ptr, notes, &noteCount, barNumber);

        if (sampleIndex + noteSampleCount > sampleCount) Error("The melody is too long.", barNumber);
        else {
          writeNote(&sample[0] + sampleIndex, notes, noteCount, noteSampleCount);
          sampleIndex += noteSampleCount;
        }
      }
      else break;
      ptr += forward;
    }
  }

  fwrite(sample, sizeof(int16_t), sampleCount, wav);
  return sizeof(int16_t) * sampleCount;
}

double wave(double freq, double t) {
  double y = sin(1 * 2 * PI * freq / SAMPLERATE * t) * exp(-t / SAMPLERATE);
  y += y*y*y;
  y *= 1 - exp(-6 * t);
  return y;
}

void writeNote(int16_t *sample, char notes[][5], int noteCount, int sampleCount) {
  int16_t queue[sampleCount];
  for (int i = 0; i < sampleCount; i++)
    queue[i] = 0;

  for (int i = 0; i < noteCount; i++) {
    double freq = nameToFreq(notes[i]);
    if (freq != 0) {
      int32_t samplePerCycle = SAMPLERATE / freq;

      for (int j = 0; j + samplePerCycle < sampleCount;)
        for (int k = 0; k < samplePerCycle; j++, k++)
          queue[j] += AMPLITUDE * wave(freq, j);
    }
  }

  for (int i = 0; i < sampleCount; i++)
    sample[i] += queue[i];
}
