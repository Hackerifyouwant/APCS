#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

int preorder[100005];

void postorder(int preleft, int preright){
    //cout << preleft << " " << preright << endl;
    if(preleft > preright)return;
    int root = preorder[preleft];
    int left_size = 0;
    int right_size = 0;
    for(int i = preleft + 1; i <= preright; i++){
        if(preorder[i] < root){
            left_size++;
        }else{
            right_size++;
        }
    }
    postorder(preleft + 1, preleft + left_size);
    postorder(preleft + left_size + 1, preright);
    cout << root << endl;    
}

int main(){
    int n;
    int cnt = 0;
    while(cin >> n && n != EOF){
        preorder[cnt++] = n;
    }
    postorder(0, cnt - 1);

    return 0;
}