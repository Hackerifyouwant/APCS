#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

vector <int> arr;
int r;

int sum_(int mid){
    int sum = 0;
    for(int i = 0; i < r; i++){
        sum += abs(mid - arr[i]);        
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        arr.clear();
        cin >> r;
        for(int y = 0; y < r; y++){
            int a;
            cin >> a;
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        int best = arr[arr.size() / 2];
        int result = sum_(best);
        cout << result << endl;
    }
    return 0;
}