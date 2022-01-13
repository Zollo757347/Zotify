#include <ctype.h>
#include <math.h>
#include <string.h>
#include "note.h"
#include "wav.h"

double nameToFreq(char noteName[]) {
  if (strcmp(noteName, "R") == 0) return 0.0;

  char chart[13] = "C D EF G A B";
  char *ptr = strchr(chart, noteName[0]);

  double freq = C4;
  freq *= pow(2, noteName[1] - '4');
  freq *= pow(TWO_TWELVE, ptr - chart);
  if (noteName[2] == '#') freq *= TWO_TWELVE;
  if (noteName[2] == 'b') freq /= TWO_TWELVE;

  return freq;
}

int convertNote(char noteName[]) {
  if (strcmp(noteName, "R") == 0) return 1;

  if (strchr("abcdefg", noteName[0]) != NULL) noteName[0] += 'A' - 'a';
  if (strchr("ABCDEFG", noteName[0]) == NULL) return 0;

  if (noteName[1] == '#' || noteName[1] == 'b') {
    char temp = noteName[1];
    noteName[1] = noteName[2];
    noteName[2] = temp;
  }
  return '0' <= noteName[1] && noteName[1] <= '8';
}
