//COMSC-210 | Lab 15 | Kristofer King
//IDE Used: VSC
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//declaring and initializing a class withi its members
class Movie
{
    //declaring the private class members
    private:
    string mTitle;
    string mScreenWriter;
    int mRelease;

    //declaring the public class functions with the appropriate setter and getter functions to obtain the movie title, screenwriter, and release date
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

    //an in class print function that can be used by class objects to output the values found by the setter and getter functions in the appropriate format
    void print()
    {
        cout << "Movie: " << mTitle << endl;
        cout << setw(15) << "Year Released: " << mRelease << endl;
        cout << setw(15) << "Screenwriter: " << mScreenWriter << endl;
    }
};

int main()
{
    //declares a vector in which we will be storing the movie information
    vector<Movie> movies_v;

    //function that attempts to open the designated file
    ifstream fin ("input.txt");

    //declares variables that will hold the values for our temporary vector
    string t;
    string sw;
    int y;

    //if the file is found and can be opened, this if will initiate a while loop to gather information
    if (fin.good())
    {
        //a while loop that obtains the appropriate information from the input file and will store the class object into a temporary vector
        while (getline(fin, t))
        {
            fin >> y;
            fin.ignore();
            getline(fin, sw);

            //declaring a temporary class object and inputs the information from the file to the appropriate location
            //then adds this object to the vector before gathering data for the next class object
            Movie temp;
            temp.setmTitle(t);
            temp.setmRelease(y);
            temp.setmScreenWriter(sw);
            movies_v.push_back(temp);
        }
        //closes the input file as we have gathered all necessary information
        fin.close();
    }
    //if the file cannot be found or opened it displays this message
    else
        cout << "Input file not found.\n";

    //for loop that traverses the vector and calls on the in class print function to display the information
    for (auto val : movies_v)
        val.print();

    cout << endl;

    return 0;
}