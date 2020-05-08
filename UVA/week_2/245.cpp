#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> word_list;
int main(){
	string buf;
	while (getline(cin, buf) && buf[0] != '0') {
		int value = 0, state = 0; // 2:number, 1:letter, 0:others
		string s;
		for (int i = 0; buf[i]; ++ i) { 
			if (isalpha(buf[i])) {
				s = "";
				while (isalpha(buf[i]))
					s.insert(s.end(), buf[i ++]);
				word_list.push_back(s);
				i --;
				cout << s;
			} else if (isdigit(buf[i])) {
				value = 0;
				while (isdigit(buf[i]))
					value = value * 10 + buf[i ++] - '0';
				s = word_list[word_list.size() - value];
				word_list.erase(word_list.end() - value);
	        	word_list.push_back(s);
	        	i --;
				cout << s;
			} else 
                cout << buf[i];
		}
		cout << "" << endl;
	}
    return 0;
}