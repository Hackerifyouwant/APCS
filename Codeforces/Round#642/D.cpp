#include<iostream>
#include<queue>

#define ll long long
#define endl '\n'

using namespace std;

int arr[1000005];
int cnt;

struct segment{
    int left, right;
}S;

struct cmp{
    bool operator()(segment l, segment r){
        if(l.right - l.left == r.right - r.left)return l.left > r.left;
        else return (l.right - l.left) < (r.right - r.left);
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cnt = 1;

        priority_queue<segment, vector<segment>, cmp> Q;
        S.left = 1;
        S.right = n;
        Q.push(S);
        
        while(!Q.empty()){
            segment s = Q.top();
            Q.pop();
            int right = s.right;
            int left = s.left; 
            if(right < left)continue;      
            if((right - left + 1) % 2 == 1 && arr[(left + right) / 2] == 0){
                arr[(left + right) / 2] = cnt++;    
                s.left = (left + right) / 2 + 1;
                s.right = right;
                Q.push(s);
                s.left = left;
                s.right = (left + right) / 2 - 1;
                Q.push(s);
                
            }else if((right - left + 1) % 2 == 0 && arr[( (left + right) - 1 )/ 2] == 0){
                arr[( (left + right) - 1 )/ 2] = cnt++;
                s.left = (left + right) / 2 + 1;
                s.right = right;
                Q.push(s);
                s.left = left;
                s.right = (left + right) / 2 - 1;
                Q.push(s);
            }
        }
        
        for(int i = 1; i <= n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        for(int i = 1; i <= n; i++){
            arr[i] = 0;
        }
    }


    return 0;
}
