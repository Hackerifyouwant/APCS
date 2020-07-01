#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

#define N 1001
#define ll long long
#define endl '\n'

using namespace std;

int s, t;
int tbl[N + 2];
vector<int> prime;

int bfs(int s, int t){
    int count[1001] = {};//深度
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int p_idx = 0; prime[p_idx] < now; p_idx++)//不包含 now 自己
        {
            if (!(now%prime[p_idx]))
            {
                int temp = now + prime[p_idx];
                if (count[temp])//已經排進去過了
                    continue;

                if (temp == t)
                    return count[now] + 1;
                else if (temp < t)
                {
                    count[temp] = count[now]+1;
                    q.push(temp);
                }
                else
                    break;
            }
        }
    }

    return -1;

}

int main(){
    
    for(int i = 2; i <= N + 1; i++){
        if(!tbl[i]){
            prime.push_back(i);
        }
        for(int j = i + i; j <= N + 1; j += i){
            tbl[j] = 1;
        }
    }
    int Case = 0;
    while (scanf("%d%d", &s, &t) && s&&t){
        printf("Case %d: ",++Case);
        if (s == t)
            puts("0");
        else
            printf("%d\n", bfs(s,t));
    }


    return 0;
}