#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <string>
#include<iomanip>
#include"surah.h"
#include"DLL.h"
using namespace std;
class Playlist
{
    public:
        Playlist(string);
         ~Playlist();
         void setname(string);
         string getname() const;
         DLL<surah>& getSurahs();
         void addSurah(const surah& newSurah);
         void removeSurah(int pos);
         void displaySurahs()const;
         void playSoundSurah();
    private:
        string playlist_name;
        DLL <surah> surahs;

};

#endif // PLAYLIST_H
