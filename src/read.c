#include "read.h"

void readConfig(float *bpm, int32_t *beatCount) {
  scanf("%f%d", bpm, beatCount);
}

void readBars(Bar bar[], int32_t *barCount) {
  char buf[1024];

  int melodyCount = 0;
  while (fgets(buf, 1024, stdin) != NULL) {
    if (strstr(buf, "-----") != NULL) {
      (*barCount)++;
      melodyCount = 0;
    }
    else {
      char noteName[32], *head = &buf[0];
      int noteCount = 0, read = 0, length;
      while (sscanf(head, "%s%f%n", noteName, &bar[*barCount].melody[melodyCount].length[noteCount], &length) == 2) {
        read = 1;
        bar[*barCount].melody[melodyCount].freq[noteCount] = nameToFreq(noteName);
        noteCount++;
        head += length;
      }
      bar[*barCount].melody[melodyCount].noteCount = noteCount;
      melodyCount += read;
    }
  }
}
