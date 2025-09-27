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

    string t;
    string sw;
    int y;

    if (fin.good())
    {
        while (getline(fin, t))
        {
            fin >> y;
            fin.ignore();
            getline(fin, sw);

            Movie temp;
            temp.setmTitle(t);
            temp.setmRelease(y);
            temp.setmScreenWriter(sw);
            movies_v.push_back(temp);
        }
        fin.close();
    }
    else
        cout << "Input file not found.\n";

    for (auto val : movies_v)
        val.print();

    cout << endl;

    return 0;
}