#ifndef NOTE
#define NOTE

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define AMPLITUDE 3000
#define C4 261.62556530060
#define PI 3.14159265359
#define TWO_TWELVE 1.05946309436

#define MAXMELODY 5
#define MAXNOTE 32

/**
  * Stores a single melody
  *
  * @property {float[]} freq The freqency of each note
  * @property {float[]} length The length of each note
  * @property {int} noteCount The note count of this melody
**/
typedef struct _melody {
  float freq[MAXNOTE];
  float length[MAXNOTE];
  int noteCount;
} Melody;

/**
  * Stores different melodies in a single bar
  *
  * @property {Melody} melody
  * @property {int} beatCount The beats count of the bar
**/
typedef struct _bar {
  Melody melody[MAXMELODY];
  int beatCount;
} Bar;

/**
  * Transfers noteName into it's freqency (Hz)
  *
  * @param {char[]} noteName
  * @return {float}
**/
float nameToFreq(char noteName[]);


/**
  * Writes all notes of a Bar into a file
  *
  * @param {FILE*} wav The .WAV file pointer
  * @param {float} bpm beats per second for the song
  * @param {Bar}
  * @return {int32_t} The size of the written data
**/
int32_t writeBar(FILE *wav, float bpm, Bar bar);

#endif
