# Zotify
A .WAV file generator written in C language.

## GCC Compile
```
gcc -Wall main.c src/note.c src/read.c src/wav.c -std=c99 -O2 -o main
```

## Input format
The first line contains two float numbers, `bpm` and `beatPerBar`.

The following lines contains the melodies of the song.
* `note`: Every note is represented with a string `noteName` and float number `length`, separated with white spaces.
** `noteName` format examples: `C4`, `G5#`, `D6b`.
* `melody`: A single line represents a melody, containing up to 32 notes, all separated with white spaces.
* `bar`: Every bar holds up to 5 melodies (5 lines of notes), and ends with a single line containing at least five continuous dashes (`-----`).
* `song`: All the things above form a song, which can only hold up to 100 bars.

Example:
```
120 4

C4 1    C4 1    G4 1    G4 1
C5 1    C5 1    G5 1    G5 1
----- First Bar
A4 1    A4 1    G4 2
A5 1    A5 1    G5 2
----- Second Bar
F4 1    F4 1    E4 1    E4 1
F5 1    F5 1    E5 1    E5 1
----- You can put any text here
D4 1    D4 1    C4 2
D5 1    D5 1    C5 2
----- Such as lyrics or comments
```

## Output
The program generates sine waves acording to the input, and make a sound file called `sample.wav` in the same directory of your `.exe` file.

## Note
This project is still under heavy development, any incorrect input formats can cause runtime error.

## Upcoming Features
* Different sound waves.
* Volume control.

## Credits
* [茄子蛋(EggPlantEgg)](https://www.youtube.com/channel/UCXBcSkBS763VgEmoKYUxfMg): for composing the original song [愛情你比我想的閣較偉大](https://www.youtube.com/watch?v=zTntSG7KcBk) of `sample.wav` in this project folder.
* [Nice piano sheets](https://www.youtube.com/channel/UCI2FRQyYm-Vo9rvs6q6wcHg): for the piano sheet.
