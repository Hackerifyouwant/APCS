#include<iostream>
#include<algorithm>
#include<set>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    string s = "abc";
    set <string> S;
    S.insert(s);
    cout << s << endl;
    next_permutation(s.begin(), s.end());
	while (S.find(s) == S.end()){
        cout << s << '\n';
        S.insert(s);
        next_permutation(s.begin(), s.end());
	}
    cout << "no next permutation exists.\n";
		
}