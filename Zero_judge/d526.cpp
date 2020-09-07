#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node():data(), left(NULL), right(NULL){};
};

void search(Node* rootD, int nodeD){
    if(rootD->data > nodeD){
        if(rootD->left == NULL){
            rootD->left = new Node;
            rootD->left->data = nodeD;
            return ;
        }
        return search(rootD->left, nodeD);
    }else{
        if(rootD->right == NULL){
            rootD->right = new Node;
            rootD->right->data = nodeD;
            return ;
        }
        return search(rootD->right, nodeD);
    }
}

void preorder(Node* Root){
    if(Root == NULL)return ;
    cout << Root->data << " ";
    preorder(Root->left);
    preorder(Root->right);
}


int main(){
    ll N;
    while(cin >> N){
        Node* root = new Node;
        for(int i = 0; i < N; i++){
            int M, idx;
            cin >> M;
            if(i == 0)root->data = M;
            else search(root, M);
        }
        preorder(root);
        cout << endl;
    }
    
    return 0;
}