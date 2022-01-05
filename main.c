#include <stdint.h>
#include "src/note.h"
#include "src/read.h"
#include "src/wav.h"

int main() {
  FILE *wav = openWAV("sample.wav");
  Bar bar[100];
  float bpm;
  int32_t beatCount = 0, barCount = 0;

  readConfig(&bpm, &beatCount);
  printf("Read Config: Success!\n");
  readBars(bar, &barCount);
  printf("Read Bars: Success!\n");

  int32_t dataSize = 0;
  for (int i = 0; i < barCount; i++) {
    bar[i].beatCount = beatCount;
    dataSize += writeBar(wav, bpm, bar[i]);
  }

  closeWAV(wav, dataSize);
  printf("Make File: Success!\n");
  return 0;
}
