#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Song
{
private:

    char* name;
    char* artist;
    double seconds;

public:

    Song()
    {   name = new char[8];
        strcpy(name, "unknown");
        artist = new char[8];
        strcpy(artist, "unknown");
        seconds = 0;
    }
    Song(const char* name1,const char *artist1, double seconds1)
    {
        name = new char[strlen(name1)+1];
        strcpy(name, name1);
        artist = new char[strlen(artist1)+1];
        strcpy(artist, artist1);
        seconds = seconds1;
    }
    const char* getName () const
    {
        return name;
    }
    const char* getArtist () const
    {
        return artist;
    }
    int getSeconds () const
    {
        return seconds;
    }
    void Print () const
    {
        cout << "name: " << name << endl;
        cout << "artist: " << artist << endl;
        cout << "time in seconds: " << seconds << endl;
    }
    ~Song()
    {
        delete[] name;
        delete[] artist;
    }
    bool operator== (const Song& two)
    {
        if(strcmp(name, two.name) != 0)
        {
            return false;
        }
        if(strcmp(artist, two.artist) != 0)
        {
            return false;
        }
        if(seconds != two.seconds)
        {
            return false;
        }
        return true;
    }
    bool operator> (const Song& two)
    {
        if(seconds > two.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Song& operator=(const Song& two)
    {   
        name = new char[strlen(two.name)+1];
        strcpy(name, two.name); 
        artist = new char[strlen(two.artist)+1];
        strcpy(artist, two.artist);
        seconds = two.seconds;
        return *this;
    }
};

class Playlist
{
private:

    int max;
    Song* playlist;

public:
    Playlist()
    {
        max = 10;
        playlist = new Song [max];
    }
    Playlist(int max1)
    {
        max = max1;
        playlist = new Song [max];
    }
    Playlist(const Playlist& one)
    {
        max = one.max;
        playlist = new Song [max];
        for (int i{0}; i < max; i++)
        {
            playlist[i] = Song();
            playlist[i] = one.playlist[i];
        }
    }
    Playlist& operator=(const Playlist& two)
    {   
        for (int i{0}; i < max; i++)
        {
            playlist[i] = Song();
            playlist[i] = two.playlist[i];
        }
        return *this;
    }
    ~Playlist()
    {
        delete [] playlist;
    }
    void Print () const
    {
        for(int i{0}; i < max; i++)
        {
            playlist[i].Song::Print();
        }
    }
    void AddSong (Playlist& one, const Song& two)
    {
        for(int i{0}; i < one.max; i++)
        {
            if (one.playlist[i] == two)
            {
                return;
            }
        }
        Playlist temp ((one.max)+1);
        temp.playlist = new Song [temp.max];
        for (int i{0}; i < one.max; i++)
        {
            temp.playlist[i] = one.playlist[i];
        }
        temp.playlist[one.max] = two;
        one = temp;
    }
    double TotalLenght (const Playlist& one)
    {
        double total{0};
        for (int i{0}; i < one.max; i++)
        {
            total += one.playlist[i].Song::getSeconds();
        }
    }
    Song Longest (const Playlist& one)
    {
        Song temp;
        for (int i{0}; i < one.max; i++)
        {
            for (int j{0}; j < one.max; j++)
            {
                if(one.playlist[i].Song::getSeconds() > one.playlist[j].Song::getSeconds())
                {
                    temp = one.playlist[i];
                }
            }
        }
        return temp;
    }
};

// Abstract Base Class
class AbstractBase {
public:
    virtual void function1() = 0;
    virtual void function2() = 0;
    virtual ~AbstractBase() {} // Virtual destructor for a base class with virtual functions
};

// Interface 1
class Interface1 {
public:
    virtual void interfaceFunction1() = 0;
    virtual ~Interface1() {}
};

// Interface 2
class Interface2 {
public:
    virtual void interfaceFunction2() = 0;
    virtual ~Interface2() {}
};

// Derived Class 1 implementing AbstractBase and Interface1
class DerivedClass1 : public AbstractBase, public Interface1 {
public:
    // Implementing pure virtual functions from AbstractBase
    void function1() override {
        std::cout << "DerivedClass1 - Function 1\n";
    }

    void function2() override {
        std::cout << "DerivedClass1 - Function 2\n";
    }

    // Implementing pure virtual function from Interface1
    void interfaceFunction1() override {
        std::cout << "DerivedClass1 - Interface Function 1\n";
    }
};

// Derived Class 2 implementing AbstractBase and Interface2
class DerivedClass2 : public AbstractBase, public Interface2 {
public:
    // Implementing pure virtual functions from AbstractBase
    void function1() override {
        std::cout << "DerivedClass2 - Function 1\n";
    }

    void function2() override {
        std::cout << "DerivedClass2 - Function 2\n";
    }

    // Implementing pure virtual function from Interface2
    void interfaceFunction2() override {
        std::cout << "DerivedClass2 - Interface Function 2\n";
    }
};

int main(const int argc,const char *argv[])
{
    cout << "28 July 2024\n";
    return 0;
}
