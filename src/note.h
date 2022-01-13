#ifndef NOTE
#define NOTE

#define AMPLITUDE 3000
#define C4 261.6255653006
#define PI 3.1415926535
#define TWO_TWELVE 1.0594630943

/**
  * Transfers noteName into it's freqency (Hz)
  *
  * @param {char[]} noteName
  * @return {double}
**/
double nameToFreq(char noteName[]);

/**
  * Converts any legal note name to readable note name
  *
  * @param {char[]} noteName
  * @return {int} if receives a legal note name, returns 1, else returns 0
**/
int convertNote(char noteName[]);

#endif
