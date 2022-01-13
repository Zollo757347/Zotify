#include <stdint.h>
#include "src/read.h"
#include "src/wav.h"

int main() {
  double bpm;
  int32_t beatCount = 0;
  char wavName[1024];
  getBasicInfo(wavName, &bpm, &beatCount);

  FILE *wav = openWAV(wavName);
  int32_t dataSize = makeWAV(wav, bpm, beatCount);
  closeWAV(wav, dataSize);

  return 0;
}
