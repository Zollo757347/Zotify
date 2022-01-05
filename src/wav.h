#ifndef WAV
#define WAV

#include <stdint.h>
#include <stdio.h>

#define SAMPLERATE 44100

/**
  * The .WAV file header
**/
typedef struct _wavheader {
  char RIFF[4];
  int32_t fileSize;
  char WAVE[4];
  char fmt[4];
  int32_t firstChunkSize;
  int16_t audioFormat;
  int16_t channels;
  int32_t sampleRate;
  int32_t byteRate;
  int16_t blockAlign;
  int16_t bitsPerSample;
  char data[4];
  int32_t dataSize;
} WAVHeader;

/**
  * Opens a .WAV file (creates if not exists), sets up the header, and returns the file pointer
  *
  * @param {char[]} fileName
  * @return {FILE*}
**/
FILE *openWAV(char fileName[]);

/**
  * Adds one second of blank data at the end of the file, fills in the total data size to the header, and closes the file
  *
  * @param {FILE*} wav
  * @param {int32_t} dataSize
  * @return {void}
**/
void closeWAV(FILE *wav, int32_t dataSize);

#endif
