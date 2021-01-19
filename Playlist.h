#ifndef MAINLAB8_PLAYLIST_H
#define MAINLAB8_PLAYLIST_H
#include <iostream>
#include <string>
#include "Song.h"
#include <vector>
using namespace std;

class Playlist {
public:
    Playlist();
    Playlist(string playlistName);
    void AddSongToPlaylist(Song* songPointer);
    string GetPlaylistName() const;
    void GetSongsFromPlaylist();
    void PlayingSongsFromPlaylist();
    void RemoveSongFromPlaylist(int songIndex);
    void RemoveSongFromPlaylist(string songName);

private:
    vector<Song*> songsInPlaylist;
    string playlistName;
};


#endif //MAINLAB8_PLAYLIST_H
