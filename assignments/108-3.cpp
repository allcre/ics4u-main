#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

string reverse(string sentence, string rev, int a) {
    if (a == 0)
        return (rev + sentence[a]);
    else {
        rev += sentence[a];
        return reverse(sentence, rev, a - 1);
    }
}

bool isPalindrome(string sentence, int a) {
    if (a <= 0) {
        if (sentence[0] == sentence[sentence.length() - 1])
            return true;
        else 
            return false;
    }
    else {
        if (sentence[a] == sentence[sentence.length() - 1 - a])
            return isPalindrome(sentence, a - 1);
        else 
            return false;
    }
}

int main() {
    string sentence;
    getline(cin, sentence);

    string rev = reverse(sentence, "", sentence.length() - 1);
    cout << rev << endl;

    // remove whitespace
    sentence.erase(remove_if(sentence.begin(), sentence.end(), ::isspace), sentence.end()); 
    // convert to lowercase
    for (int i = 0; i < sentence.length(); i++)
        sentence[i] = tolower(sentence[i]);

    if (isPalindrome(sentence, ceil(sentence.length()/2) - 1) == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}