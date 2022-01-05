#include "note.h"
#include "wav.h"

float nameToFreq(char noteName[]) {
  if (noteName[0] == '0') return 0.0;

  char chart[13] = "C D EF G A B";
  char *ptr = strchr(chart, noteName[0]);

  float freq = C4;
  freq *= pow(TWO_TWELVE, ptr - chart);
  freq *= pow(2, noteName[1] - '4');
  if (noteName[2] == '#') freq *= TWO_TWELVE;
  if (noteName[2] == 'b') freq /= TWO_TWELVE;

  return freq;
}

int32_t writeBar(FILE *wav, float bpm, Bar bar) {
  int32_t sampleCount = SAMPLERATE * (60.0 / bpm) * bar.beatCount;
  int16_t value[sampleCount];
  for (int i = 0; i < sampleCount; i++)
    value[i] = 0;

  for (int i = 0; i < MAXMELODY; i++) {
    int sampleIndex = 0;
    for (int j = 0; j < bar.melody[i].noteCount; j++) {
      int32_t noteSampleCount = SAMPLERATE * (60.0 / bpm) * bar.melody[i].length[j];
      int16_t queue[noteSampleCount];
      for (int k = 0; k < noteSampleCount; k++)
        queue[k] = 0;

      if (bar.melody[i].freq[j] != 0) {
        int32_t samplePerCycle = SAMPLERATE / bar.melody[i].freq[j];
        float delta = 2 * PI / samplePerCycle;

        for (int k = 0; k + samplePerCycle < noteSampleCount;)
          for (int l = 0; l < samplePerCycle; k++, l++)
            queue[k] += (AMPLITUDE * sin(delta * l)) * pow(1 - i / MAXMELODY, 4);

        for (int k = 0; k < 5 * samplePerCycle; k++)
          queue[k] *= (k / (5.0 * samplePerCycle));

        for (int k = 0; k < 15 * samplePerCycle; k++)
          queue[noteSampleCount - 1 - k] *= (k / (15.0 * samplePerCycle));
      }

      for (int k = 0; k < noteSampleCount; k++)
        value[sampleIndex + k] += queue[k];

      sampleIndex += noteSampleCount;
    }
  }

  fwrite(value, sizeof(int16_t), sampleCount, wav);
  return sizeof(int16_t) * sampleCount;
}
