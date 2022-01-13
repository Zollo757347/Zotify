#include "read.h"
#include "wav.h"
#include "write.h"

FILE *openWAV(char fileName[]) {
  WAVHeader header = {
    {'R', 'I', 'F', 'F'}, 0, {'W', 'A', 'V', 'E'}, {'f', 'm', 't', ' '},
    16, 1, 1, SAMPLERATE, SAMPLERATE * 4, 4, 16, {'d', 'a', 't', 'a'}, 0
  };
  FILE *wav = fopen(fileName, "wb");
  fwrite(&header, sizeof(WAVHeader), 1, wav);
  return wav;
}

int32_t makeWAV(FILE *wav, double bpm, int beatCount) {
  char buf[10][MAX_BUFFER_LENGTH + 1];
  int melodyCount = 0, barNumber = 1;
  int32_t dataSize = 0;

  while (readBar(buf, &melodyCount, barNumber) == 0) {
    dataSize += writeBar(wav, bpm, beatCount, buf, melodyCount, barNumber);
    melodyCount = 0;
    barNumber++;
  }

  printf("WAV file successfully made!\n");
  return dataSize;
}

void closeWAV(FILE *wav, int32_t dataSize) {
  int16_t value[SAMPLERATE] = {};
  fwrite(value, sizeof(int16_t), SAMPLERATE, wav);
  dataSize += sizeof(int16_t) * SAMPLERATE;

  int32_t fileSize = dataSize + 36;
  fseek(wav, 4, SEEK_SET);
  fwrite(&fileSize, sizeof(int), 1, wav);
  fseek(wav, 40, SEEK_SET);
  fwrite(&dataSize, sizeof(int), 1, wav);

  fclose(wav);
}
