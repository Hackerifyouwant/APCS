#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <set>
using namespace std;

int main(){
    set<string> dictionary;
    char word;
    string alphaWord;
    while( scanf("%c", &word) != EOF ){
        if( isalpha(word) ){
            alphaWord += tolower(word);
        }else if( alphaWord != "" ){
            dictionary.insert(alphaWord);
            alphaWord = "";
        }
    }

    if( alphaWord != "" ){
        dictionary.insert(alphaWord);
    }

    for(set<string>::iterator itr = dictionary.begin() ; itr != dictionary.end() ; itr++ ){
    cout << itr->c_str() << endl;
    }

  return 0;
}