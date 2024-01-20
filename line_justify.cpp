//Justifies a line user inputs
//Ryan Anderson
//1/19/2024

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// Constant for the desired line length
const int lineLength = 90;
const int endLineLength = 40;

// Prototype Functions here before main function
void addSpaceAfterPuncs(string&,string, bool);
void addSpaceRandom(string&, bool);
void needsSpace(string&, bool&);




int main() {
    string user_string;
    string punct = ".,!?;:";
    bool manipok = false;
    srand(time(nullptr));

    cout << "Input line: ";
    getline(cin, user_string);

    cout << "You entered: " << user_string << endl;

    // Call function to see if string needs manipulated at all
    // pass in my names not the data type
    needsSpace(user_string, manipok);

    addSpaceAfterPuncs(user_string, punct, manipok);

    //check to see if previous function met requirements
    needsSpace(user_string, manipok);

    //If condition is not met previously add spaces until condition is met
    addSpaceRandom(user_string, manipok);

    cout << "Your justified line is : " << user_string << endl;

    return 0;
}




// Function Definitions
// input is my variable name for user input named user_string
void addSpaceAfterPuncs(string& user_string, string punct, bool manipok) { 
    if (manipok == true) {
        int start = 0;

        while (user_string.find_first_of(punct, start) < user_string.size()) {
            //insert a space after the first punctuation is found based off my punct string located  in main
            //+1 to get the place after the punctuation then add space there
            user_string.insert(user_string.find_first_of(punct, start) + 1, " ");
            //set new start to after the last space was inserted to find next punct
            start = user_string.find_first_of(punct, start) + 2;
        }
    }
}

void addSpaceRandom(string& user_string, bool manipok) {
    if (manipok == true) {
        //Set random place (int) within the string being less than the total string size will keep it in bound (dont get 2312123131)
        int randstart(rand() % user_string.size());
        //while less than 90 it will do the while loop until the string is 90 or greater
        while (user_string.size() < 90) {
            user_string.insert(user_string.find_first_of(" ", randstart) + 1, " ");
            randstart = rand() % user_string.size();
        }
    }
}

void needsSpace(string& user_string, bool& manipok) {
    // if string meets 1st argument jump into if statement if not it is false and string is fine how it is
    if (user_string.size() > 40) {
        if (user_string.size() < 90) {
            manipok = true;
        }
        else {
            manipok = false;
        }
    }
    else {
        manipok = false;
    }
}
