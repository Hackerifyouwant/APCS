#include<iostream>
#include<algorithm>
#include<queue>

#define ll long long
#define endl '\n'

using namespace std;
priority_queue <int, vector<int> , greater<int> > pq;

int main(){
    int N;
    while(cin >> N && N != 0){
        int cost = 0;
        while(!pq.empty())pq.pop();
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            pq.push(a);
        }
        while(1){
            int a, b, c;
            a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			c = a + b;
			cost = cost + c;
            if(pq.empty())break;
            pq.push(c);
        }
        cout << cost << endl;
    }

    return 0;
}