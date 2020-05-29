#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

istream& operator>>(istream& in, vector<int> &vec){
    vec.clear();
    string str;
    getline(in, str);
    stringstream sin(str);
    int num;
    while(sin >> num)vec.push_back(num);
    return in;
} 

void Findleaf(vector<int> &in, vector<int> &post, int &mini, int &ansleaf, int parweight){
    if(in.size() > 1){
        int root = post.back();
        vector<int> ::iterator itr = find(in.begin(), in.end(), root);

        vector<int>inLeft(in.begin(), itr);
        vector<int>inRight(itr + 1, in.end());
        vector<int>postLeft(post.begin(), post.begin() + inLeft.size());
        vector<int>postRight(post.begin() + inLeft.size(), post.end() - 1);


        Findleaf(inLeft, postLeft, mini, ansleaf, root + parweight);
        Findleaf(inRight, postRight, mini, ansleaf, root + parweight);
    }else if(in.size() == 1){
        if(mini > in.back() + parweight){
            mini = in.back() + parweight;
            ansleaf = in.back();
        }else if(mini == in.back() + parweight && in.back() < ansleaf){
            ansleaf = in.back();
        }
    }
}

int main(){
    vector<int> inord, postord;
    while(cin >> inord >> postord){
        int mini = 1e9;
        int ansleaf = 0;
        Findleaf(inord, postord, mini, ansleaf, 0);
        cout << ansleaf << endl;
    }
    return 0;
}