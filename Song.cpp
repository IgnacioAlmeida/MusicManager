#include "Song.h"

Song::Song() {
    this->songName = "none";
    this->songCounter = 0;
    this->songFirstLine = "none";
}
Song::Song(string songName, string songFirstLine, int songCounter){
    this->songName = songName;
    this->songFirstLine = songFirstLine;
    this->songCounter = songCounter;
}
int Song::GetSongCounter() const {
    return this->songCounter;
}
string Song::GetSongName() const {
    return this->songName;
}
string Song::GetSongFirstLine() const {
    return this->songFirstLine;
}
void Song::SetSongCounter() {
    this->songCounter++;
}
void Song::PlayingSongs(){
    cout << this->GetSongFirstLine() << endl;
    SetSongCounter();
}


