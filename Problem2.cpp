#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

// My own Ciper using  "BXPDSVKMNORCJTQEGHZLFWAYUI”
// Converting all letters in my own ciper to the alphabet

//BXPDSVKMNORCJTQEGHZLFWAYUI
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

string mycrpt(const string& text){
    string key = "BXPDSVKMNORCJTQEGHZLFWAYUI";
    string result = text;
    for (char& c : result){
        if (isalpha(c)) {
            bool upper = isupper(c);
            int index = toupper(c) - 'A';
            c = key[index];
            if (!upper) c = tolower(c);
        }
    }
    return result;
}
void letter_count(const string& text){
    map<char, int> freq;
    for (char c : text ){
        if (isalpha(c)) {
            freq[toupper(c)]++;
        }
    }
    for (auto& pair: freq){
        cout << pair.first << ": " << pair.second << endl;
    }
}

//Question 4 ? why do we use homophonic subsition and why is it a solution to question 3's problem? Homophonic Substitution is the idea of instead of mapping a character to only one symbol it maps to multiple symbols
// TLDR instead of one to one mapping it's one to many mapping
string homos(const string & text){
    unordered_map<char, vector<char>> key;

    key['E'] = {'X','Q','7'};
    key['T'] = {'M','Z'};
    key['A'] = {'3','K'};
    key['O'] = {'P','9'};

    for (char c = 'A'; c <= 'Z'; ++c){
        if(key.find(c) == key.end())
            key[c] = {c};
    }
    string result;
    srand(time(0));
    for(char c : text){
        if (isalpha(c)) {
            char u = toupper(c);
            auto& options = key[u];
            char chosen = options[rand() % options.size()];
            if(islower(c))
                chosen = tolower(chosen);
            result += chosen;
        }
    }
    return result;
}

int main(){
    string msg = "this text";
    letter_count(msg);
    cout << mycrpt(msg) << endl; 
    cout << homos(msg) <<endl;
    letter_count(mycrpt(msg));
    letter_count(homos(msg));

    return 0;
}

// Subsituion frequency cracking works by comparing the frequency and patterns of the letters in the ciphertext with English statistics that likely matches readble plaintext
// Maps the most frequent count in my substituion to the most frequent letter in the common english language and plans according to this.
// Would see what frequency count has the most letters and coorelate it to the most in basic english words.
