#include<iostream>
#include<stack>
#include<vector>
#include<map>

#define ll long long
#define endl '\n'
#define ERROR_COUNT -1

using namespace std;

struct Martix{
    Martix(){};
    Martix(int r, int c):rows(r),columns(c){};
    int rows;
    int columns;
};

map <char, Martix> arr;

int main(){
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char c;
        int a;
        int b;
        Martix A;
        cin >> c >> a >> b;
        A.rows = a;
        A.columns = b;
        arr[c] = A;    
    }
    string s;
    while(cin >> s){
        int multiplication = 0;
        stack <Martix> martixStack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')continue;
            if(s[i] != ')'){
                martixStack.push(arr[s[i]]);
                continue;
            }
            Martix b = martixStack.top();
            martixStack.pop();
            Martix a = martixStack.top();
            martixStack.pop();

            if(a.columns != b.rows){
                multiplication = ERROR_COUNT;
                break;
            }

            multiplication += (a.rows * b.rows * b.columns);
            Martix martix(a.rows, b.columns);
            martixStack.push(martix);
        }
        if(multiplication == ERROR_COUNT)cout << "error" << endl;
        else cout << multiplication << endl;
    }

    return 0;
}

// #include <iostream>
// #include <cstdio>
// #include <stack>
// #include <map>
// using namespace std;

// struct Matrix{
//   Matrix(){};
//   Matrix(int r, int c):row(c),column(c){};
//   int row;
//   int column;
// };

// int main(){
//   const int ERROR_COUNT = -1;

//   int n;
//   scanf("%d", &n);

//   map<char, Matrix> matrices;
//   for(int i = 0 ; i < n ; ++i){
//     char name;
//     Matrix matrix;
//     scanf(" %c %d%d", &name, &(matrix.row), &(matrix.column));
//     matrices[name] = matrix;
//   }

//   string expression;
//   while(cin >> expression){
//     int multiplicationCount = 0;
//     stack<Matrix> matrixStack;
//     for(int i = 0 ; i < expression.length() ; ++i){
//       if(expression[i] == '(') continue;
//       if(expression[i] != ')'){
//         matrixStack.push(matrices[expression[i]]);
//         continue;
//       }

//       Matrix b = matrixStack.top();
//       matrixStack.pop();
//       Matrix a = matrixStack.top();
//       matrixStack.pop();

//       if(a.column != b.row){
//         multiplicationCount = ERROR_COUNT;
//         break;
//       }

//       multiplicationCount += a.row * b.row * b.column;
//       Matrix matrix (a.row, b.column);
//       matrixStack.push(matrix);
//     }

//     if(multiplicationCount == ERROR_COUNT) printf("error\n");
//     else printf("%d\n", multiplicationCount);
//   }

//   return 0;
// }