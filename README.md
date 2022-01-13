# Zotify
A .WAV file generator written in C language.

## GCC Compile
```
gcc -Wall main.c err/error.c src/note.c src/read.c src/wav.c src/write.c -std=c99 -O2 -o main
```

## Input format
The first line is the output `fileName`.
The second line contains two floating numbers, `bpm` and `beatPerBar`.

The following lines contains the melodies of the song. A song can hold several `bar` (more bars, of course, result in a larger file), and every `bar` ends with a single line containing at least five continuous dashes (`-----`). A `bar` can holds several `melody` (up to 10 for each `bar`). `melody` is a single line with several `note`/`chord` or `duration`, each can be separated by several spaces. Please refer to the following example:
```
[Melody 1]
[Melody 2]
[Melody 3]
----- Bar 1 ends
[Melody 1]
[Melody 2]
[Melody 3]
[Melody 4]
----- Bar 2 ends
```
There's two components in a melody, `note`/`chord` and `duration`.
* `note`: A legal note is a string with 2 ~ 3 characters. The first 1~2 character is the name of the note, such as `C`, `Bb` or `F#`. The following character is the octo of the note, from `0` to `8`. For example, `C4`, `Eb0`, `D#8` are considered legal notes, while `X0`, `A$2`, `G9` are not. Besides that, you can use a single character `R` to represent a rest.
* `chord`: A legal chord consists of several notes, separated by a single comma (`,`), and wrapped by round bracket. For example, `(G1)`, `(C4,Eb4,G4)` are considered legal chords, while `[A4]`, `(C#4, C#5, C#6)` are not.
* `duration`: A positive floating number indicating how long the following notes should be played.
You should specify a duration before a note, if no duration is specified, the current note will inherit the duration of the previous note.

Please refer to the following example:
```
canon.wav
60 4

1 E5  0.5 C5 E5  1 D5  0.5 B4 D5
2 (C4,E4,G4)       (B3,D4,F4)
----- (1) This is the end of the first bar
1 C5  0.5 A4 C5  1 B4  0.5 G4 B4
2 (A3,C4,E4)       (G3,C4,E4)
----- (2) You can put any text here
1 A4  0.5 F4 A4  1 G4  0.5 E4 G4
2 (F3,A3,C4)       (E3,G3,C4)
----- (3) Such as lyrics or comments
1 F4  0.5 D4 F4  1 B4  0.5 G4 B4
2 (D3,F3,A3)       (G3,B3,D4)
----- (4) Putting bar No. here is highly recommended
2 (C4,E4,G4,C5) R
----- (5) To make it easier to debug
```

## Output
The program generates sine waves according to the input, and make a .WAV file in the same directory of your .exe file.

## Upcoming Features
* Articulations such as accent, marcato, ornament, etc.
* Bpm, beat count adjustment.
* Different sound waves.
* Volume control.

## Credits
* ~~[愛情你比我想的閣較偉大](https://www.youtube.com/watch?v=zTntSG7KcBk): composed by [茄子蛋(EggPlantEgg)](https://www.youtube.com/channel/UCXBcSkBS763VgEmoKYUxfMg).~~ (Archived)
* 名探偵コナン メイン・テーマ: composed by Katsuo Ōno.
* [Nice piano sheets](https://www.youtube.com/channel/UCI2FRQyYm-Vo9rvs6q6wcHg) for the piano sheet.
