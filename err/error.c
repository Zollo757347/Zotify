#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void RangeError(char name[], int leftBound, int rightBound, int value, int barNumber) {
  if (barNumber > 0) fprintf(stderr, "At Bar %d:\n", barNumber);
  fprintf(stderr, "Range Error: Expecting %s in the range of [%d, %d], receiving %d.\n", name, leftBound, rightBound, value);
  fprintf(stderr, "Exiting...\n");
  exit(-1);
}

void Error(char statement[], int barNumber) {
  if (barNumber > 0) fprintf(stderr, "At Bar %d:\n", barNumber);
  fprintf(stderr, "%s\n", statement);
  fprintf(stderr, "Exiting...\n");
  exit(-1);
}
