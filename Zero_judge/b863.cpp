#include<iostream>
#include<math.h>
#include<algorithm>

#define ll long long
#define endl '\n'

using namespace std;

struct S{
    int index, num;
}arr[100005];

bool cmp(S l, S r){
    return l.num < r.num;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i].num;
            arr[i].index = i + 1;
        }
        int sum = 0;
        sort(arr, arr + N, cmp);
        sum += max(arr[0].index - 1, arr[0].num);
        for(int i = 1; i < N; i++){
            sum += max(arr[i].index - arr[i - 1].index, arr[i].num - sum);
            
        }
        sum += (arr[N - 1].index - 1);
        cout << sum << endl;
    }

    return 0;
}