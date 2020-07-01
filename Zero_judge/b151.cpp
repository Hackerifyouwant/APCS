#include<iostream>
#include<algorithm>
#include<queue>

#define ll long long
#define endl '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pq.push(x);    
    }
    int sum = 0;
    while(!pq.empty()){
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        int result = a + b;
        sum += result;
        if(!pq.empty())pq.push(result);
        //cout << a << " " << b << " " << sum << endl;
    }
    cout << sum << endl;


    return 0;
}