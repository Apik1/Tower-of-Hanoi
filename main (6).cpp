/*
Max Zurniewicz
10 / 22 / 2021
CSC 121
Week 9 Lab TOH
*/

#include <iostream>
#include <vector>                       //needed for vectors

using namespace std;                    //declare namespace

vector <char> T1{ 'A', 'B', 'C', 'D'};      //create vectors
vector <char> T2{};
vector <char> T3{};

void display();                         //function prototypes
void source();
void determineWin();
int protectData(string);
int checkSource(int);
void dest();
int checkDest(int);

char temp, temp2;                       //global ints

void printVector(vector <char> const& v)    //func that prints the entirity of a vector
{
    for (auto const& i : v)
    {
        cout << i << ' ';
    }
}

int main()
{
    int win = 0;            //while win = 0, no win has occured and game will continue

    while (win != 1)        //while no win
    {
        display();          //display board
        source();           //ask and verify source
        dest();             //ask and verify destination

    }
    return 0;
}

void source()
{
    int s;                                      //where players choice will be stored
    enum tower { one = 1, two, three };         //creates an enum 

    s = protectData("Choose source(1/2/3): ");      //will ask for source, make sure its correct data, and store in s
    s = checkSource(s);                              //will make sure s is a valid source that has a letter on it
    if (s == tower::one)                            //if s == 1
    {
        temp = T1.back();                           //store last element of vector in temp
        T1.pop_back();                              //remove last element of vector 
    }
    if (s == tower::two)                            //if s == 2
    {
        temp = T2.back();                            //store last element of vector in temp
        T2.pop_back();                              //remove last element of vector 
    }
    if (s == tower::three)                          //if s == 3
    {
        temp = T3.back();                           //store last element of vector in temp
        T3.pop_back();                              //remove last element of vector 
    }
}

int checkSource(int s)                              //checks if the vector has an element and makes user chose another source 
{
    while (s == 1 && T1.size() == 0)                //while source is first tower and first tower is empty
    {
        cout << "Choose another source.\n";
        s = protectData("Choose source(1/2/3): "); //promts user to choose another tower
    }
    while (s == 2 && T2.size() == 0)                //while source is second tower and second tower is empty
    {
        cout << "Choose another source.\n";
        s = protectData("Choose source(1/2/3): "); //promts user to choose another tower
    }
    while (s == 3 && T3.size() == 0)                //while source is third tower and third tower is empty
    {
        cout << "Choose another source.\n";
        s = protectData("Choose source(1/2/3): "); //promts user to choose another tower
    }
    return s;                                       //returns new s
}

void dest()                                         //function for getting destination
{
    int d;              //int
label:
    d = protectData("Choose destination(1/2/3): "); //gets int makes sure it is 1-3 
    if (d == 1)                                     //if destination is tower one
    {
        if (T1.size() != 0)                         //if tower one is has elements
        {
            temp2 = T1[T1.size() - 1];              //stores value of last element in temp2
            if (temp2 > temp)                    //while not alphabetical order
            {
                cout << "Cannot place heavier object on ligher object, please reenter destination\n";
                goto label;                         //go to start of func for new destination
            }

        }

    }
    if (d == 2)                                     //if destination is tower two
    {
        if (T2.size() != 0)                         //if tower two has elements 
        {
            temp2 = T2[T2.size() - 1];              //stores value of last element in temp2
            if (temp2 > temp)                    //while not alphabetical order
            {
                cout << "Cannot place heavier object on ligher object, please reenter destination\n";
                goto label;                      //go to start of function for new destination
            }
        }
    }
    if (d == 3)                                    //if destination is tower three
    {
        if (T3.size() != 0)                         //if tower three has elements
        {
            temp2 = T3[T3.size() - 1];              //stores value of last element in temp2
            if (temp2 > temp)                    //while not alphabetical order
            {
                cout << "Cannot place heavier object on ligher object, please reenter destination\n";
                goto label;                         //go to start of funtion for new destination
            }
        }
    }

    if (d == 1)                                     //if destination is the first tower
    {
        T1.push_back(temp);                         //push source into end of first vector
    }
    if (d == 2)                                     //if destination is the second tower
    {
        T2.push_back(temp);                         //push source into end of second vector       
    }
    if (d == 3)                                     //if destination is the third tower
    {
        T3.push_back(temp);                         //push source into end of third vector
        determineWin();
    }

}

void display()                              //displays board
{
    cout << "T1 ";
    printVector(T1);                        //prints contents of vector
    cout << endl << "T2 ";
    printVector(T2);
    cout << endl << "T3 ";
    printVector(T3);
    cout << endl;
}

void determineWin()
{
    if (T3.size() == 4 && T3[0] == 'A' && T3[1] == 'B' && T3[2] == 'C' && T3[3] == 'D')      //if win
    {
        cout << "\nYOU WON!!!!\n";
        display();                          //display board
        exit(EXIT_FAILURE);                 //end game
    }

}
int protectData(string prompt)
{
    int tower;
    cout << prompt;                             //outputs prompt
    cin >> tower;                               //stors input
    while (tower < 1 || tower > 3 || cin.fail())//if input is 1-3 and int
    {
        while (cin.fail())      //if not int
        {
            cin.clear();         //get rid of wrong data type
            cin.ignore();       //reset buffer, get ready for next input
        }
        cout << "Reenter a valid int 1-3 ";
        cin >> tower;       //stores new input
    }
    return tower;           //returns input
}
