#include <iostream>
#include <string>
using namespace std;

// ROT-13 for letters only
//Notes for using c++ in the future, Compared to Python C++ characters are considered integers meaning that a = 0 b =1  
string rot13(const string& text) {
    string result = text;
    for (char& c : result) { // loops the characters in the string 
        if (isalpha(c)) { // Checks if c is a charcter 
            char base = isupper(c) ? 'A' : 'a'; // checks if this is upper case or lowercase
            c = base + (c - base + 13) % 26; // c - base converts letter to number from 0 - 25 , +13 does the actual shift, 26% wraps it around the alphabet so Z becomes M. base + converts back to ASCII
        }
    }
    return result;
}

// ROT-N for printable ASCII (32–126)
string rotN_ascii(const string& text, int N) {
    string result = text;
    const int RANGE = 95; // printable ASCII count

    for (char& c : result) { // loops through all characters
        if (c >= 32 && c <= 126) {
            c = 32 + ( (c - 32 + N) % RANGE + RANGE ) % RANGE; // c - 32 maps printable ASCII to 0 - 94 , + N applies the possitive or negative shift, % wraps around 0-94 and Range % Range ensures negative nyumbers wrap correctly
        }
    }
    return result;
}

int main() {
    string msg = "Security should be important";

    cout << "ROT-13: " << rot13(msg) << endl;
    cout << "ROT +5 ASCII: " << rotN_ascii(msg, 5) << endl;
    cout << "ROT -5 ASCII: " << rotN_ascii(msg, -5) << endl;

    return 0;
}
