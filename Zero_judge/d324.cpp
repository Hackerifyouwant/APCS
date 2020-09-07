#include <iostream>
#include <string>
using namespace std;
int s[8],m[8][8],x,y,num;

void qn(int step){
    if (step<8){
        for(int i=0;i<8;i++){   //(s[j],j) (i,step)
            for(int j=0;j<step;j++){
                if ((s[j]==i)||((s[j]-i)==(j-step))||((s[j]-i)==(step-j))) break;//有一個衝突就不用再檢查 
                if (j==(step-1)) {  //全部都檢查，沒有衝突才加入 
                    s[step]=i;
                    qn(step+1);
                }
            }        
        }                     
    }else {//八列都填滿，計算加總和 
        if (s[y-1]==(x-1)){
            cout << " " << num++ << "      ";
            for(int i=0;i<8;i++){
                cout << s[i]+1 <<" ";        
            }
            cout << endl;    
        }    
    }     
}

int main(void){
    int n;
    cin >> n;
    for(int k=0;k<n;k++){
        num=1;
        cin >> x>>y;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl; 
        for(int i = 0; i < 8; i++){
            s[0]=i; //第一行有8個位置可以填     
            qn(1);
        }   
        cout << endl;
    }
}

