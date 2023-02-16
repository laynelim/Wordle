#include "wordle.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Wordle::Wordle(char * code) : code{code} {}
      
Wordle::~Wordle() {}

int countChar(string s, char c) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == c) {
            ++count;
        }
    }
    return count;
}

void Wordle::playGame() {
    int guesses = 0;
    string answer = string(code);
    string curGuess;
    int lengthAns = answer.length();
    char c;
    char g;
    bool badLen = false;
    bool won= false;
    cout << "Enter a " << lengthAns << " letter word as guess: " ;
    while (true) {
        if (cin >> curGuess) {
            ++guesses;
            if (guesses > 6 ){
                cout << "Out of guesses! The word was: " << answer << endl;
                break;
            }
            if (curGuess.length() != lengthAns) {
                badLen = true;
                cout << "Incorrect guess size, please enter guess of length " << lengthAns << ": " ;
            } else {
                badLen = false;
                if (curGuess == answer){
                    for(string::iterator it = curGuess.begin(); it != curGuess.end(); ++it) {
                        cout << GREEN << *it << RESET ;
                    }
                    cout << endl << "Congrats you found the word!" << endl;
                    won = true;
                    break;
                } else {
                    istringstream guess{curGuess};
                    istringstream ans{answer};
                    string soFar;
                    while (guess >> c) {
                        ans >> g;
                        
                        if (c == g) {
                            cout << GREEN << c << RESET;
                        } else if (answer.find(c) != string::npos ){
                            int cInAns = countChar(answer, c);
                            int cInSoFar = countChar(soFar, c);
                            if (cInAns == 1 && (soFar.find(c) == string::npos)) {
                                cout << YELLOW << c << RESET;
                            } else if (cInAns > 1 && cInSoFar < cInAns) {
                                cout << YELLOW << c << RESET;
                            } else {
                                cout  << c;
                            }
                        } else {
                            cout  << c;
                        }
                        soFar += c;
                    }
                    cout << endl;
                }
            }
            if (!badLen) {
                cout << "Enter a " << lengthAns << " letter word as guess: ";
            }
        } else {
            if (guesses < 6 && !won){
                cout << "Enter " << lengthAns << " length word as guess: ";
                cout << "Out of guesses! The word was: " << answer << endl;
            } else {
                cout << "Enter " << lengthAns << " length word as guess: ";
                cout << "Out of guesses! The word was: " << answer << endl;
            }
            break;
        }
        
    }
}

