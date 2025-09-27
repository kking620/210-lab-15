#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Movie
{
    private:
    string mTitle;
    string mScreenWriter;
    int mRelease;

    public:
    string getmTitle()
    {
        return mTitle;
    }
    void setmTitle(string t)
    {
        mTitle = t;
    }
     string getmScreenWriter()
    {
        return mScreenWriter;
    }
    void setmScreenWriter(string sw)
    {
        mScreenWriter = sw;
    }
     int getmRelease()
    {
        return mRelease;
    }
    void setmRelease(int y)
    {
        mRelease = y;
    }

    void print()
    {
        cout << "Movie: " << mTitle << endl;
        cout << setw(15) << "Year Released: " << mRelease << endl;
        cout << setw(15) << "Screenwriter: " << mScreenWriter << endl;
    }
};

int main()
{
    vector<Movie> movies_v;

    ifstream fin ("input.txt");

    string title;
    string screenWriter;
    int year;

    if (fin.good())
    {
        while ( fin.good())
        {
            getline(fin, title);
            fin.ignore();
            fin >> year;
            getline(fin, screenWriter);
            Movie temp;
            temp.setmTitle(title);
            temp.setmRelease(year);
            temp.setmScreenWriter(screenWriter);
            movies_v.push_back(temp);
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";

    for (auto val : movies_v)
    {
        cout << val.print() << endl;
    }

    cout << endl;

    return 0;
}