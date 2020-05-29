#include<iostream>
#include<map>
#include<set>

#define ll long long
#define endl '\n'

using namespace std;


int main(){
    int n;
    map< set<int> , int> arr;
    while(cin >> n && n != 0){
        arr.clear();
        for(int i = 0; i < n; i++){
            set<int> S;
            for(int j = 0; j < 5; j++){
                int a;
                cin >> a;
                S.insert(a);
            }
            // if(arr.find(S) != arr.end())
            arr[S]++;
        }
        int max = -1e9;
        for(auto i : arr){
            if(i.second > max)max = i.second;
        }
        int Max = 0;
        for(auto i : arr){
            //cout << i.second << " ";
            if(max == i.second) Max += max;
        }
        //cout << endl;
        cout << Max << endl;
    }

    

    return 0;
}