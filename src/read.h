#ifndef READ
#define READ

#include <stdint.h>
#include <stdio.h>
#include "note.h"

/**
  * Reads the config of a song, and stores it into corresponding parameters
  *
  * @param {float*} bpm The bpm of the song
  * @param {int32_t*} beatCount The beat count of a single bar of the song
  * @return {void}
**/
void readConfig(float *bpm, int32_t *beatCount);

/**
  * Reads the bar information of a song, and stores it into corresponding parameters
  *
  * @param {Bar[]} bar The Bar structure to store the bar information
  * @param {int32_t*} barCount The bar count of the song
  * @return {void}
**/
void readBars(Bar bar[], int32_t *barCount);

#endif
