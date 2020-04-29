#include<iostream>

#define ll long long
#define endl '\n'

using namespace std;

enum{ B = 0, C = 1, G = 2};
int main(){
    int bincolor[][3] =  { {B, C, G}, {B, G, C}, {C, B, G},
        {C, G, B}, {G, B, C}, {G, C, B}
    };
    
    char s[][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    
    int bin[3][3];
    while(cin >> bin[0][B] >> bin[0][G] >> bin[0][C] >>
                 bin[1][B] >> bin[1][G] >> bin[1][C] >>
                 bin[2][B] >> bin[2][G] >> bin[2][C]){
        int currentMove = 0;
        int totalGlasses = 0;

        for(int i = 0; i < 3; i++){
            totalGlasses +=(bin[i][B] + bin[i][G] + bin[i][C]);
        }

        int minMove = totalGlasses;
        int minNo = 0;

        for(int i = 0; i < 6; i++){
            currentMove = totalGlasses
                          - bin[0][bincolor[i][0]]
                          - bin[1][bincolor[i][1]]
                          - bin[2][bincolor[i][2]];

            if(currentMove < minMove){
                minMove = currentMove;
                minNo = i;
            }
        }
        cout << s[minNo] << " " << minMove << endl;

    }
    return 0;
}