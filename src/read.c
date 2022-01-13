#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "note.h"
#include "read.h"
#include "../err/error.h"

void getBasicInfo(char wavName[], double *bpm, int32_t *beatCount) {
  int argc = scanf("%s%lf%d", wavName, bpm, beatCount);
  if (argc != 3) RangeError("argument count", 3, 3, argc, 0);

  int len = strlen(wavName);
  if (len >= 32) RangeError("file name length", 0, 31, len, 0);
  if (*bpm < 1 || 3987 < *bpm) RangeError("bpm", 1, 3987, *bpm, 0);
  if (*beatCount < 1 || 87 < *beatCount) RangeError("beat count", 1, 87, *beatCount, 0);

  printf("Basic information successfully read!\n");
}

int allSpace(char *str) {
  while (*str != '\0')
    if (!isspace(*str)) return 0;
    else str++;
  return 1;
}

int readBar(char buf[][MAX_BUFFER_LENGTH + 1], int *melodyCount, int barNumber) {
  while (fgets(buf[*melodyCount], MAX_BUFFER_LENGTH, stdin) != NULL) {
    if (strstr(buf[*melodyCount], "-----") != NULL) return 0;
    else if (allSpace(buf[*melodyCount])) continue;
    else {
      int len = strlen(buf[*melodyCount]);
      if (len < 1 || 511 < len) RangeError("melody length", 0, 511, len, barNumber);
      if (10 < *melodyCount) RangeError("melody count", 0, 10, *melodyCount, barNumber);
      (*melodyCount)++;
    }
  }

  return 1;
}

int readDuration(char *ptr, double *duration, int barNumber) {
  int forward;
  sscanf(ptr, "%lf%n", duration, &forward);
  ptr += forward;
  while (isspace(*ptr)) {
    ptr++;
    forward++;
  }
  return forward;
}

int readNote(char *ptr, char notes[][5], int *noteCount, int barNumber) {
  char group[MAX_BUFFER_LENGTH + 1];
  int forward;
  sscanf(ptr, "%s%n", group, &forward);

  int len = strlen(group);
  if (group[0] == '(' && group[len - 1] != ')') Error("Note not closed correctly.", barNumber);

  char *notePtr = strtok(group, "(,)");
  while (notePtr != NULL) {
    int noteLen = strlen(notePtr);
    if (4 < noteLen) RangeError("note name length", 1, 4, noteLen, barNumber);
    if (10 < *noteCount) RangeError("note count", 1, 10, *noteCount, barNumber);

    if (convertNote(notePtr)) strcpy(notes[(*noteCount)++], notePtr);
    else Error("Illegal note name caught.", barNumber);
    notePtr = strtok(NULL, "(,)");
  }

  ptr += forward;
  while (isspace(*ptr)) {
    ptr++;
    forward++;
  }
  return forward;
}
