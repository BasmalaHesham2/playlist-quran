#ifndef SURAH_H
#define SURAH_H
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
class surah
{
private:
    string name;
    string reciter;
    string type;
    string path;

public:
    surah();
    surah(string n, string rec, string t, string p);
    void setName(string newName);
    void setReciter(string newReciter);
    void setType(string newType);
    void setPath(string newPath);
    void input();
   string getName() const;
   string getReciter() const;
    string getType() const;
    string getPath() const;
    void display() const;
    ~surah();
};

#endif // SURAH_H
