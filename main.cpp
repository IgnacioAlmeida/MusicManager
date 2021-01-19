#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

using namespace std;

string GetUserString(const string& prompt);

void AddSongsMenuOption(vector<Song*> &allSongs);
void ListSongsMenuOption(vector<Song*> &allSongs);
void AddPlaylistMenuOption(vector<Playlist*> &playlists);
void AddSongToPlaylistMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs);
void ListPlaylistsMenuOption(vector<Playlist*> &playlists);
void PlayPlaylistMenuOption(vector<Playlist*> &playlists);
void RemovePlaylistMenuOption(vector<Playlist*> &playlists);
void RemoveSongFromPlaylistMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs);
void RemoveSongFromLibraryMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs);
void OptionsMenuOption();
void QuitMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs);

int main() {
   vector <Song*> allSongs;
   vector <Playlist*> playlists;

    cout << endl << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

   string userMenuChoice = "none";
   bool continueMenuLoop = true;

   while (continueMenuLoop) {
      userMenuChoice = GetUserString("Enter your selection now: (Enter 10 to see the whole menu");

      if (userMenuChoice == "add") {
         AddSongsMenuOption(allSongs);
      }
      else if (userMenuChoice == "list") {
         ListSongsMenuOption(allSongs);
      }
      else if (userMenuChoice == "addp") {
         AddPlaylistMenuOption(playlists);
      }
      else if (userMenuChoice == "addsp") {
         AddSongToPlaylistMenuOption(playlists, allSongs);
      }
      else if (userMenuChoice == "listp") {
         ListPlaylistsMenuOption(playlists);
      }
      else if (userMenuChoice == "play") {
         PlayPlaylistMenuOption(playlists);
      }
      else if (userMenuChoice == "remp") {
         RemovePlaylistMenuOption(playlists);
      }
      else if (userMenuChoice == "remsp") {
         RemoveSongFromPlaylistMenuOption(playlists, allSongs);
      }
      else if (userMenuChoice == "remsl") {
         RemoveSongFromLibraryMenuOption(playlists, allSongs);
      }
      else if (userMenuChoice == "options") {
         OptionsMenuOption();
      }
      else if (userMenuChoice == "quit") {
         QuitMenuOption(playlists, allSongs);
         continueMenuLoop = false;
      }
      else {
         OptionsMenuOption();
      }
   }

   return 0;
}


string GetUserString(const string& prompt) {
   string userAnswer = "none";

   cout << prompt;
   getline(cin, userAnswer);
   cout << endl;
   return userAnswer;
}

void AddSongsMenuOption(vector<Song*> &allSongs) {
   const string DONE_KEYWORD = "DONE";
   cout << "Enter songs' names and first lines"
             << " (type \"" << DONE_KEYWORD << "\" when done):" << endl;

   string songName = "none";
   string firstLine = "none";

   songName = GetUserString("Song Name: ");
   int songCounter = 0;

   while (songName != DONE_KEYWORD) {
      firstLine = GetUserString("Song's first line: ");
      allSongs.push_back(new Song(songName, firstLine, songCounter));

      songName = GetUserString("Song Name: ");
   }
}

void ListSongsMenuOption(vector<Song*> &allSongs) {
   for (int i = 0; i < allSongs.size(); i++){
      cout << allSongs.at(i)->GetSongName() << ": \"" << allSongs.at(i)->GetSongFirstLine() << "\", "  << allSongs.at(i)->GetSongCounter() << " play(s)." << endl;
   }
   cout << endl;
}

void AddPlaylistMenuOption(vector<Playlist*> &playlists) {
   string playlistName = "none";
   cout << "Playlist name: " << endl;
   getline(cin,playlistName);
   playlists.push_back(new Playlist(playlistName));

}

void AddSongToPlaylistMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs) { //TODO FAIL
   int playlistIndex = 0;
   int songIndex = 0;
   ListPlaylistsMenuOption(playlists);
   cout << "Pick a playlist index number: " << endl;
   cin >> playlistIndex;
   for (int i = 0; i < allSongs.size(); i++){
      cout << i << ": " << allSongs.at(i)->GetSongName() << endl;
   }
   cout << "Pick a song index number: " << endl;
   cin >> songIndex;
   cout << endl;
   Song* songSelected = allSongs.at(songIndex);
   Playlist* playlistSelected = playlists.at(playlistIndex);
   playlistSelected->AddSongToPlaylist(songSelected);
   cin.ignore();
}

void ListPlaylistsMenuOption(vector<Playlist*> &playlists) {
   for (int i = 0; i < playlists.size(); i++){
      cout << i << ": " << playlists.at(i)->GetPlaylistName() << endl;
   }
}

void PlayPlaylistMenuOption(vector<Playlist*> &playlists) {
   ListPlaylistsMenuOption(playlists);
   cout << "Pick a playlist index number: " << endl;
   int playlistIndex = 0;
   cin >> playlistIndex;
   cout << "Playing songs from playlist: " << playlists.at(playlistIndex)->GetPlaylistName() << endl;
   playlists.at(playlistIndex)->PlayingSongsFromPlaylist();
   cin.ignore();
}

void RemovePlaylistMenuOption(vector<Playlist*> &playlists) {
   int indexNumber = 0;
   ListPlaylistsMenuOption(playlists);
   cout << "Pick a playlist index number to remove: " << endl;
   cin >> indexNumber;
   delete playlists.at(indexNumber); //FREEING MEMORY
   playlists.erase(playlists.begin() + indexNumber);
   cin.ignore();
}

void RemoveSongFromPlaylistMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs) {
   ListPlaylistsMenuOption(playlists);
   int playlistIndex = 0;
   cout << "Pick a playlist index number: " << endl;
   cin >> playlistIndex;
   playlists.at(playlistIndex)->GetSongsFromPlaylist();
   cout << "Pick a Song index number to remove: " << endl;
   int songIndex = 0;
   cin >> songIndex;
   playlists.at(playlistIndex)->RemoveSongFromPlaylist(songIndex);
   cin.ignore();
}

void RemoveSongFromLibraryMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs) {
   int songIndex = 0;
   for (int i = 0; i < allSongs.size(); i++){
      cout << i << ": " << allSongs.at(i)->GetSongName() << endl;
   }
   cout << "Pick a song index number to remove: " << endl;
   cin >>songIndex;
   string songToBeReplaced = allSongs.at(songIndex)->GetSongName();
   for(int i = 0; i < playlists.size(); i++){
      playlists.at(i)->RemoveSongFromPlaylist(songToBeReplaced);
   }
   delete allSongs.at(songIndex); //FREEING MEMORY
   allSongs.erase(allSongs.begin() + songIndex);
   cin.ignore();
}

void OptionsMenuOption() {
   cout << "add      Adds a list of songs to the library" << endl
             << "list     Lists all the songs in the library" << endl
             << "addp     Adds a new playlist" << endl
             << "addsp    Adds a song to a playlist" << endl
             << "listp    Lists all the playlists" << endl
             << "play     Plays a playlist" << endl
             << "remp     Removes a playlist" << endl
             << "remsp    Removes a song from a playlist" << endl
             << "remsl    Removes a song from the library (and all playlists)" << endl
             << "options  Prints this options menu" << endl
             << "quit     Quits the program" << endl << endl;
}

void QuitMenuOption(vector<Playlist*> &playlists, vector<Song*> &allSongs) { //FREEING MEMORY
   for (int i = 0; i < allSongs.size(); i++){
      delete allSongs.at(i);
   }
   for (int i = 0; i < playlists.size(); i++){
      delete playlists.at(i);
   }
   cout << "Goodbye!" << endl;
}

