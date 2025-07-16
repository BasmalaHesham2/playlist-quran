#include "surah.h"
surah::surah()
{
       name=" ";
        reciter=" ";
        type=" ";
        path=" ";
}
surah::surah(string n, string rec, string t, string p)
  {
    name=n;
    reciter=rec;
    type=t;
    path=p;

  }
      void surah::setName(string newName)
    {
        name = newName;
    }
    void surah::setReciter(string newReciter)
    {
        reciter = newReciter;
    }
    void surah::setType(string newType)
    {
        type = newType;
    }

    // Set path
    void surah::setPath(string newPath)
    {
            path = newPath;

    }

   string surah::getName() const
    {
        return name;
    }
  string surah::getReciter() const
    {
        return reciter;
    }
    string surah::getType() const
    {
        return type;
    }
    string surah::getPath() const
    {
        return path;
    }

    // Display Function
    void surah::display() const
    {
        cout << name <<setw(20)<<reciter<<setw(20)<<type<<setw(20)<<path<<endl;

    }
    void  surah::input()
    {
        cout << "Enter the name of the surah: " <<"\n";
        cin>>name;
        cout << "Enter the name of the Reciter: " <<"\n";
        cin>>reciter;
        cout << " Enter the Type : " <<"\n";
        cin>>type;
      cout << "Enter the Path: " <<"\n";
      cin>>path;

        }

surah::~surah()
{}
