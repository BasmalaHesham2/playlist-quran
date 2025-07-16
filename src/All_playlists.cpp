#include "All_Playlists.h"
#include"surah.h"
#include"DLL.h"
#include"Playlist.h"
All_Playlists::All_Playlists()
{}
 void All_Playlists::addPlaylist(const Playlist&p)
 {
     playlists.insertAtEnd(p);
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
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    while(temp)
        {
           cout<<temp->data.getname()<<endl;
            temp=temp->next;


    }

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
void All_Playlists::savePlaylistToFile(string filename)
{
      ofstream file(filename);
          if (!file.is_open()) {
        cout << "File is not opened." << endl;
        return;
    }
    cout<<"The file is opened. "<<endl;
    Node<Playlist>* current = playlists.gethead();
    if(!current){
        cout<<"There is no playlists "<<endl;
    }
    else{
        while(current!=nullptr){
            file<<"The name of the playlist is "<<current->data.getname()<<endl;
            Node<surah>* temp = current->data.getSurahs().gethead();
        while (temp) {
            file << "Surah name :"<<temp->data.getName() <<endl;
            file<<"Reciter: "<<temp->data.getReciter()<<endl;
            file<<"Type: "<<temp->data.getType()<<endl;
            file<<"Path: "<<temp->data.getPath()<<endl;
            temp = temp->next;
        }
            current=current->next;

        }

    }
    file.close();
    cout << "Playlists saved successfully." << endl;
}
void All_Playlists::LoadPlaylist(string filename)
{
    ifstream file(filename);
        if (!file.is_open()) {
        cout << "File is not opened " << filename << endl;
        return;
    }
    string playlistName, surahName, reciter, type, path;
    cout<<"The file is opened. "<<endl;
    while(file>>playlistName)
        {
            Playlist P(playlistName);
            while (file >> surahName >> reciter >> type >> path) {
            surah newSurah(surahName, reciter, type, path);
            P.addSurah(newSurah);
        }

        playlists.insertAtEnd(P);

    }
     file.close();
}
Playlist* All_Playlists::getPlaylistByName(string name) {
    Node<Playlist>* current = playlists.gethead();
    while (current != nullptr) {
        if (current->data.getname() == name) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

All_Playlists::~All_Playlists()
{}
