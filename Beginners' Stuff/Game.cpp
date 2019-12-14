#include<iostream>

using namespace std;

class GameEntry{
    public:
        GameEntry(const string& n="", int s = 0);
        string getName() const;
        int getScore() const;
    private:
        int score;
        string name;
};


class Scores
{
    public:
        Scores(int maxEnt = 15);
        ~Scores();
        void add(const GameEntry& ge);
        GameEntry remove(int i) throw(out_of_range);
        void ShowScores();
    private:
        int maxEntries;
        int numEntries;
        GameEntry *Entries;
};

int main()
{
    Scores list(10);
    GameEntry ge("Animesh",230);
    GameEntry ge1("Avishai",1000);
    GameEntry ge2("Sanjeev",219);
    GameEntry ge3("Anjusha",450);

    list.add(ge);
    list.add(ge1);
    list.add(ge2);
    list.add(ge3);
    list.ShowScores();

    return 0;
}



GameEntry::GameEntry(const string& n, int s)
{
    name = n;
    score = s;
}

string GameEntry::getName() const {return name;}
int GameEntry::getScore() const {return score;}

Scores::Scores(int maxEnt)
{
    maxEntries = maxEnt;
    numEntries = 0;
    Entries = new GameEntry[maxEntries];
}

Scores::~Scores()
{
    delete[] Entries;
}

void Scores::add(const GameEntry& e)
{
    int newScore;
    newScore = e.getScore();

    //When array is full i.e.
    if (numEntries == maxEntries)
    {
        if (newScore <= Entries[maxEntries - 1].getScore())
            return ;     //Nothing to add here
    }

    else
        numEntries++;   //when array is not full
    int i = numEntries - 2;
    while (i>=0 && newScore <= Entries[i].getScore())
    {
        Entries[i+1] = Entries[i];
        i--;
    }
    Entries[i+1] = e;
}


/*
void Scores::add(const GameEntry& e) { // add a game entry
    int newScore = e.getScore();
// score to add
    if (numEntries == maxEntries) {
// the array is full
        if (newScore <= Entries[maxEntries−1].getScore())
            return;
// not high enough - ignore
        }
    else numEntries++;
// if not full, one more entry
    int i = numEntries−2;
// start with the next to last
    while ( i >= 0 && newScore > entries[i].getScore() ) {
        Entries[i+1] = Entries[i];
// shift right if smaller
    i−−;
    }
Entries[i+1] = e;
// put e in the empty spot
}
*/


GameEntry Scores::remove(int i) throw(out_of_range)
{
    GameEntry entry;

    if (i<0 || i>=maxEntries)
        throw out_of_range("Index is out of range...");
    else
    {
        entry = Entries[i];
        for (int j = i; j<=numEntries-1; j++)
        {
            Entries[j] = Entries[j+1];
            j++;
        }

    }

    return entry;
}

void Scores::ShowScores()
{
    if (numEntries == 0)
        cout<<"List is empty"<<endl;
    for (int i = 0; i<maxEntries;i++)
        cout<<Entries[i].getName()<<" : "<<Entries[i].getScore()<<endl;
}




