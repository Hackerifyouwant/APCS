#include<iostream>

using namespace std;
 
int count(int a, int b){
    int ans = b - a;
    if(ans < 0)
        ans += 40;
    return ans * 9;
}

int main(){
    int p[4];
    
    while(cin >> p[0] >> p[1] >> p[2] >> p[3]){
        if(p[0] + p[1] + p[2] + p[3] == 0)
            break;
        int ans = 0;
        ans += 360 - count(p[0], p[1]);//第二步 
        ans += count(p[1],p[2]);//第四步 
        ans += 360 - count(p[2] ,p[3]);//第五步 
        ans += 1080;//順兩圈+逆一圈 
        cout << ans <<endl;
    }
    
}