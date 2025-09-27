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
};

int main()
{
    vector<Movie> movies_v;

    ifstream fin ("input.txt");

    string title;
    string screenWriter;
    int year;
    int i = 0;

    if (fin.good())
    {
        while ( fin >> title)
        {
            fin.ignore();
            fin >> year;
            Movie temp;
            temp.setmTitle(title);
            temp.setmScreenWriter(screenWriter);
            temp.setmRelease(year);
            movies_v.push_back(temp);

            i++;
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";

}