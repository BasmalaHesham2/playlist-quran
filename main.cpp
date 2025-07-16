#include <iostream>
#include <string>
#include"surah.h"
#include"DLL.h"
#include"Playlist.h"
#include"All_Playlists.h"
#include <windows.h>
#include <mmsystem.h>
#include<conio.h>
#include<fstream>
using namespace std;
int main()
{
    All_Playlists all;
    bool exit = false;
   do{
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1.Add a new playlist "<<endl;
    cout<<"2.Add surah to an existing playlist "<<endl;
    cout<<"3.Remove surah to an existing playlist "<<endl;
    cout<<"4.Update the order of existing playlist "<<endl;
    cout<<"5.Display all current playlists "<<endl;
    cout<<"6.Display all playlist's surahs "<<endl;
    cout<<"7.Display surah from specific playlist "<<endl;
    cout<<"8.Play surahs from specific playlist "<<endl;
    cout<<"Use left arrow(<-) to play the previous surah"<<endl;
    cout<<"Use right arrow(->) to play the next surah"<<endl;
    cout<<"Use the up arrow(^) to pause the current surah"<<endl;
    cout<<"Use the down arrow(v) to resume the current surah"<<endl;
    cout<<"Press esc to stop the surah "<<endl;
    cout<<"9.Save the playlist to an existing file "<<endl;
    cout<<"10.Load an existing playlist to a file "<<endl;
    cout<<"11.Remove an existing playlist "<<endl;
    cout<<"12.Exit"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;

    int choice;
    cout << "Enter your choice: ";
    cin>>choice;
        if (choice < 1 || choice > 12)
        {
           cout << "Please select a number between 1 and 12.\n";
            continue;
        }

        switch(choice)
        {

        case 1:
        {
            string name;
            cout<<"Enter tha name of the playlist to add: ";
            cin>>name;
            Playlist p1(name);
            all.addPlaylist(p1);
            break;

        }
        case 2:
        {
        string name,reciter,type,path,playlistname;
        cout<<"Enter the name of the playlist to add the Surah ";
        cin>>playlistname;
        Playlist *p=all.getPlaylistByName(playlistname);
        if(p==nullptr)
            cout<<"There is no playlist with that name. "<<endl;
        else
        {
        cout << "Enter the name of the surah: " <<"\n";
        cin>>name;
        cout << "Enter the name of the Reciter: " <<"\n";
        cin>>reciter;
        cout << " Enter the Type : " <<"\n";
        cin>>type;
        cout << "Enter the Path: " <<"\n";
        cin>>path;
        surah s(name,reciter,type,path);
         p->addSurah(s);
        }
         break;
        }
        case 3:
        {
            int position;
        string playlistname;
        cout<<"Enter the name of the playlist to remove the Surah ";
        cin>>playlistname;
        cout<<"Enter the position of the Surah in the playlist ";
        cin>>position;
        Playlist *p=all.getPlaylistByName(playlistname);
        p->removeSurah(position);
        break;

        }
        case 4:
            {



            }
        case 5:
            {
                all.displayAllPlaylists();
                break;
            }
        case 6:
            {
                all.displayAllSurahsInPlaylists();
                break;

            }
        case 7:
            {
               string name;
               cout<<"Enter the name of the playlist to display it's Surahs :";
               cin>>name;
               Playlist *p=all.getPlaylistByName(name);
               p->displaySurahs();
                break;


            }
        case 8:
            {
               string name;
               cout<<"Enter the name of the playlist to play Surahs :";
               cin>>name;
               Playlist *p=all.getPlaylistByName(name);
               p->playSoundSurah();
               break;


     }
        case 9:
            {
                string filename;
                cout<<"Enter the file name : ";
                cin>>filename;
                all.savePlaylistToFile(filename);
                break;
            }
        case 10 :
            {
                string filename;
                cout<<"Enter the file name : ";
                cin>>filename;
                all.LoadPlaylist(filename);
                break;
            }
        case 11:
            {
                int pos;
                cout<<"Enter the position of the playlist to remove : ";
                cin>>pos;
                all.removePlaylist(pos);
                break;

            }
        case 12:
            {
                exit=true;
                break;
            }

        }
        }while(!exit);
    return 0;
}
