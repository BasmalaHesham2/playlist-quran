#ifndef ALL_PLAYLISTS_H
#define ALL_PLAYLISTS_H
#include <iostream>
#include <string>
#include"surah.h"
#include"DLL.h"
#include"Playlist.h"
#include<iomanip>
#include<fstream>
using namespace std;
class All_Playlists
{
    public:
        All_Playlists();
         ~All_Playlists();
         void addPlaylist(const Playlist & p);
         void removePlaylist(int p);
         void displayAllPlaylists();
         void displayAllSurahsInPlaylists()const;
         void savePlaylistToFile(string filename);
         void LoadPlaylist(string filename);
         Playlist*getPlaylistByName(string name);

    private:
        DLL <Playlist> playlists;
};

#endif // ALL_PLAYLISTS_H
