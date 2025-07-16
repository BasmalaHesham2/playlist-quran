#include "All_Playlist.h"
#include"surah.h"
#include"DLL.h"
#include"Playlist.h"
All_Playlists::All_Playlists()
{}
 void All_Playlists::addPlaylist(const Playlist&p)
 {
     cout<<"Adding the playlist"<<endl;
     playlists.insertAtEnd(p);
     cout<<"Playlist is added "<<endl;
 }
void All_Playlists::removePlaylist(int p)
{
    playlists.deleteAtSpecificPos(p);

}
void All_Playlists::displayAllPlaylists()
{
    Node<Playlist>*temp=playlists.gethead();
    if(temp==nullptr){
        cout<<"No playlists available "<<endl;
        return;
    }

            cout<<"The current playlists are: "<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    while(temp)
        {
           cout<<temp->data.getname()<<endl;
            temp=temp->next;


    }
     cout<<"-------------------------------------------------------------------"<<endl;

}
 void All_Playlists::displayAllSurahsInPlaylists()const
 {
    Node<Playlist>*temp=playlists.gethead();
    if(temp==nullptr){
        cout<<"There is no  playlists "<<endl;
        return;
    }
    while(temp)
            {
                cout<<"Playlist:"<<temp->data.getname()<<endl;
                cout<<"-------------------------------------------------------------------------------------------------"<<endl;
                temp->data.displaySurahs();
                temp=temp->next;

            }

 }

All_Playlists::~All_Playlists()
{}
