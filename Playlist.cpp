#include "Playlist.h"

Playlist::Playlist() {
    this->playlistName = "none";
}
Playlist::Playlist(string playlistName) {
    this->playlistName = playlistName;
}
void Playlist::AddSongToPlaylist(Song *songPointer) {
    songsInPlaylist.push_back(songPointer);
}
string Playlist::GetPlaylistName() const {
    return this->playlistName;
}
void Playlist::GetSongsFromPlaylist() {
    for(int i = 0; i < songsInPlaylist.size(); i++){
        cout << i << ": " << songsInPlaylist.at(i)->GetSongName() << endl;
    }
}
void Playlist::PlayingSongsFromPlaylist(){
    for(int i = 0; i < songsInPlaylist.size(); i++){
        songsInPlaylist.at(i)->PlayingSongs();
    }
}
void Playlist::RemoveSongFromPlaylist(int songIndex){
    songsInPlaylist.erase(songsInPlaylist.begin() + songIndex);
}
void Playlist::RemoveSongFromPlaylist(string songName){
    vector<int> indexesToDelete;
    for(int i = 0; i < songsInPlaylist.size(); i++){
        songsInPlaylist.at(i)->GetSongName();
        if(songsInPlaylist.at(i)->GetSongName() == songName){
            indexesToDelete.push_back(i);
        }

    }
    for(int i = indexesToDelete.size() - 1; i >= 0; --i){
        songsInPlaylist.erase(songsInPlaylist.begin() + indexesToDelete.at(i));
    }
}
