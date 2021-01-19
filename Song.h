#ifndef MAINLAB8_SONG_H
#define MAINLAB8_SONG_H
#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    Song();
    Song(string songName, string songFirstLine, int songCounter);
    int GetSongCounter() const;
    string GetSongName() const;
    string GetSongFirstLine() const;
    void SetSongCounter();
    void PlayingSongs();

private:
    string songName;
    string songFirstLine;
    int songCounter;
};


#endif //MAINLAB8_SONG_H
