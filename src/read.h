#ifndef READ
#define READ

#include <stdint.h>
#include "note.h"

#define MAX_BUFFER_LENGTH 1024

/**
  * Reads the basic information of a song, and stores it into corresponding parameters
  *
  * @param {char[]} wavName The output file name
  * @param {double*} bpm The bpm of the song
  * @param {int32_t*} beatCount Beat count per bar
  * @return {void}
**/
void getBasicInfo(char wavName[], double *bpm, int32_t *beatCount);

/**
  * Reads the bar information and store them into buffer
  *
  * @param {char[]} buf
  * @param {int*} melodyCount The melody count of this bar
  * @param {int} barNumber The bar number of this bar
  * @return {int} if no information can be read, returns 1, else returns 0
**/
int readBar(char buf[][MAX_BUFFER_LENGTH + 1], int *melodyCount, int barNumber);

/**
  * Reads the duration of a note/chord
  *
  * @param {char*} ptr The pointer to the location of the duration
  * @param {double*} duration The place to store duration
  * @param {int} beatCount The bar number of this bar
  * @return {int} the char count that have been read
**/
int readDuration(char *ptr, double *duration, int barNumber);

/**
  * Reads a note/chord
  *
  * @param {char[]} ptr The pointer to the location of the note/chord
  * @param {char[][]} notes The place to store note/chord
  * @param {int*} noteCount The note count of this note/chord
  * @param {int} beatCount The bar number of this bar
  * @return {int} the char count that have been read
**/
int readNote(char *ptr, char notes[][5], int *noteCount, int barNumber);

#endif
