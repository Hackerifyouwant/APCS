#include<iostream>
#include<queue>
#include<vector>

#define ll long long
#define endl '\n'

using namespace std;

struct node {
    int A, B;
    vector<int> moves;
};

bool state[1005][1005];

void out(int in) {
    switch (in) {
        case 0:
            cout << "fill A" << endl;
        case 1:
            cout << "fill B" << endl; break;
        case 2:
            cout << "pour A B" << endl; break;
        case 3:
            cout << "pour B A" << endl; break;
        case 4:
            cout << "empty A" << endl; break;
        case 5:
            cout << "empty B" << endl; break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a, b, n;
    while (cin >> a >> b >> n) {
        node now, tmp;
        queue<node> que;
        now.A = now.B = 0;
        que.push(now);
        for (int i = 0; i < 1005; i++){
            for (int j = 0; j < 1005; j++){
                state[i][j] = 1;
            }
        } 
        while (!que.empty()){
            now = que.front();
            que.pop();
            if (now.B == n)break;
            
            for (int i = 0; i < 6; i++){
                tmp = now;
                tmp.moves.push_back(i);
                switch (i) {
                    case 0:
                        if (now.A < a) {
                            tmp.A = a;
                            que.push(tmp);
                            if (state[tmp.A][tmp.B]) {
                                que.push(tmp);
                                state[tmp.A][tmp.B] = 0;
                            }
                        }
                        break;
                    case 1:
                        if (now.B < b) {
                            tmp.B = b;
                            if (state[tmp.A][tmp.B]) {
                                que.push(tmp);
                                state[tmp.A][tmp.B] = 0;
                            }
                        }
                        break;
                    case 2:
                        if (now.B < b && now.A > 0) {
                            tmp.B += tmp.A;
                            tmp.A = 0;
                            if (tmp.B > b)
                                tmp.A = tmp.B - b, tmp.B = b;
                            if (state[tmp.A][tmp.B]) {
                                que.push(tmp);
                                state[tmp.A][tmp.B] = 0;
                            }
                        }
                        break;
                    case 3:
                        if (now.A < a && now.B > 0) {
                            tmp.A += tmp.B;
                            tmp.B = 0;
                            if (tmp.A > a)
                                tmp.B = tmp.A - a, tmp.A = a;
                            if (state[tmp.A][tmp.B]) {
                                que.push(tmp);
                                state[tmp.A][tmp.B] = 0;
                            }
                        }
                        break;
                    case 4:
                        if (now.A > 0) {
                            tmp.A = 0;
                            if (state[tmp.A][tmp.B]) {
                                que.push(tmp);
                                state[tmp.A][tmp.B] = 0;
                            }
                        }
                        break;
                    case 5:
                        if (now.B > 0) {
                            tmp.B = 0;
                            if (state[tmp.A][tmp.B]) {
                                que.push(tmp);
                                state[tmp.A][tmp.B] = 0;
                            }
                        }
                        break;
                }
            }
        }
        int size = now.moves.size();
        for (int i = 0; i < size; i++){
            out(now.moves[i]);
        }
        cout << "success" << endl;
    }

    return 0;
}