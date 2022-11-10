#include <iostream>
#include <string>
using namespace std;

void decimalToBinary(string word1, string word2, int i) {
    if (i == 0)
        word2.append(getchar(word1[0])); 
}

int main() {
    string word;
    getline(cin, word);

    decimalToBinary(word, word, word.length());
    
    return 0;
}