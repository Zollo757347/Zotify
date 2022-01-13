#ifndef WRITE
#define WRITE

#include <stdio.h>

#define MAX_BUFFER_LENGTH 1024

/**
  * Writes a bar into the .WAV file
  *
  * @param {FILE*} wav
  * @param {double} bpm The bpm of the song
  * @param {int} beatCount Beat count per bar
  * @param {char[][]} melody The melody information of this bar
  * @param {int} melodyCount The melody count of this bar
  * @param {int} beatCount The bar number of this bar
  * @return {int32_t} The data size of this bar
**/
int32_t writeBar(FILE *wav, double bpm, int beatCount, char melody[][MAX_BUFFER_LENGTH + 1], int melodyCount, int barNumber);

/**
  * Writes a note/chord into sample array
  *
  * @param {int16_t*} sample The int16_t pointer to a certain location of sample array
  * @param {char[][]} notes The notes of this note/chord
  * @param {int} noteCount The note count of this note/chord
  * @param {int} sampleCount The sample count of this note/chord
  * @return {void}
**/
void writeNote(int16_t *sample, char notes[][5], int noteCount, int sampleCount);

#endif
