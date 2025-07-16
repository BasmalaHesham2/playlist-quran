#include "Playlist.h"
#include"surah.h"
#include"windows.h"
#include<conio.h>
Playlist::Playlist(string name)
{
    playlist_name=name;
}
 void Playlist::addSurah(const surah& newSurah)
 {
     surahs.insertAtEnd(newSurah);
 }
 void Playlist::removeSurah(int pos)
 {
     surahs.deleteAtSpecificPos(pos);
 }
string Playlist::getname()const
{
    return playlist_name;
}
DLL<surah>& Playlist::getSurahs()
 {
    return surahs;
}
 void Playlist::displaySurahs()const
 {
     Node<surah>*temp=surahs.gethead();
     if(temp==nullptr){
        cout<<"There is no surahs "<<endl;
         cout<<"----------------------------------------------------------------------------------------"<<endl;
     }
     else{
                    cout<<"Name "<<setw(20)<<"Reciter"<<setw(20)<<"Type"<<setw(20)<<"Path"<<endl;
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        while(temp){
        temp->data.display();
        temp=temp->next;
        }

     }
 }

 void Playlist::playSoundSurah()
  {

      Node<surah>*current=surahs.gethead();
      if(current==nullptr){
        cout<<"No surahs to play "<<endl;
      }
      else
    {
      char key=0;
      bool isPlaying=true;
      bool AudioOfSurah=false;
      while(true)
        {

            if(isPlaying==true &&  AudioOfSurah==false)
            {

                cout<<current->data.getName()<<" Surah is playing right now "<<endl;
                string path=current->data.getPath();
                cout << "Playing sound from: " << path << endl;
                PlaySound(path.c_str(),NULL,SND_FILENAME|SND_ASYNC);
                AudioOfSurah=true;
            }
            if(!isPlaying )
                {
                    PlaySound(NULL,NULL,SND_ASYNC);

            }
                if (kbhit()) {
                key = getch(); // Read the pressed key
                cout << "Key pressed: " << int(key) << endl;
            }

            if(key==77) //ascii of the right arrow
                {
                    if(current->next!=nullptr){
                        current=current->next;
                        AudioOfSurah=false;
                        isPlaying=true;

                    }
                    else
                        {
                        cout<<"That is the last Surah "<<endl;
                    }

            }
            else if(key==75)//ascii of the left arrow
            {
                if(current->prev!=nullptr)
                    {
                        current=current->prev;
                        AudioOfSurah=false;
                        isPlaying=true;
            }
            else{
                cout<<"This is the first Surah "<<endl;
            }

      }
      else if(key==94)//ascii of up arrow to pause
      {
          isPlaying=false;
           cout << "Paused." << endl;

      }
           else if(key==118)//ascii of down arrow to resume
      {
          isPlaying=true;
          AudioOfSurah = false;
          cout << "Resumed." << endl;

      }
                        if (key == 27)
            {  // Escape key to quit
                PlaySound(NULL,NULL,SND_ASYNC);
                cout << "The Surah stopped playing." << endl;
                break;
            }
      key=0;

  }
    }
  }

Playlist::~Playlist()
{}
