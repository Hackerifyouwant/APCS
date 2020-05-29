#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

string Preorder, Inorder; 

void build(int preleft, int preright, int inleft, int inright){
    cout << preleft << " " << preright << " " << inleft << " " << inright << endl;
    if(preleft > preright)return ;
    int root = inleft;
    while(Inorder[root] != Preorder[preleft]) {
        root++;
    }
    build(preleft + 1, preleft + root - inleft, inleft, root - 1);
    build(preleft + root - inleft + 1, preright , root + 1, inright);
    cout << Preorder[preleft];    
}

int main(){
    int C;
    cin >> C;
    while(C--){
        int N;
        cin >> N;
        cin >> Preorder >> Inorder;
        build(0, N - 1, 0, N - 1);
        cout << endl;
    }    

    return 0;
}