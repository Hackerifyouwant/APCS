#include<iostream>
#include<cmath>

#define ll long long
#define endl '\n'

using namespace std;

struct Rectangle{
    int status;
    double left_up_x;
    double left_up_y;
    double right_down_x;
    double right_down_y;
};
struct Circle{
    int status;
    double center_x;
    double center_y;
    double r;
};
struct Triangle{
    int status;
    double top_x;
    double top_y;
    double left_x;
    double left_y;
    double right_x;
    double right_y; 
};
struct fig{
    int status;
    Rectangle R;
    Circle C;
    Triangle T;
};


int main(){
    char pic;
    int index;
    fig figure[10005];
    while(cin >> pic){
        if(pic == 'r'){
            figure[index].status = 1;
            cin >> figure[index].R.left_up_x >> figure[index].R.left_up_y
            >> figure[index].R.right_down_x >> figure[index].R.right_down_y;
        }else if(pic == 'c'){
            figure[index].status = 2;
            cin >> figure[index].C.center_x >> figure[index].C.center_y >> figure[index].C.r;
        }else if(pic == 't'){
            figure[index].status = 3;
            cin >> figure[index].T.top_x >> figure[index].T.top_y
                >> figure[index].T.left_x >> figure[index].T.left_y 
                >> figure[index].T.right_x >> figure[index].T.right_y;
        }else if(pic == '*')break;
        index++;
    }
    double x, y;
    bool check = 0;
    int index2;
    while(cin >> x >> y){
        if(x == 9999.9 && y == 9999.9)break;
        check = 0;
        for(int i = 0; i < index; i++){ 
            if(figure[i].status == 1){
                if(x > figure[i].R.left_up_x && x < figure[i].R.right_down_x && 
                   y < figure[i].R.left_up_y && y > figure[i].R.right_down_y){
                        cout << "Point " << index2 + 1 << " is contained in figure " << i + 1 << endl;
                        check = 1;
                    }
            }else if(figure[i].status == 2){
                double X = pow((x - figure[i].C.center_x), 2);
                double Y = pow((y - figure[i].C.center_y), 2);
                double R = pow(figure[i].C.r, 2);
                if( X + Y < R){
                    cout << "Point " << index2 + 1<< " is contained in figure " << i + 1 << endl;
                    check = 1;
                }
            }else if(figure[i].status == 3){
                double vec1_x = figure[i].T.top_x - x;
                double vec1_y = figure[i].T.top_y - y;
                double vec2_x = figure[i].T.left_x - x;
                double vec2_y = figure[i].T.left_y - y;
                double vec3_x = figure[i].T.right_x - x;
                double vec3_y = figure[i].T.right_y - y;

                double Vec1_x = figure[i].T.right_x - figure[i].T.top_x;
                double Vec1_y = figure[i].T.right_y - figure[i].T.top_y ;
                double Vec2_x = figure[i].T.left_x - figure[i].T.top_x;
                double Vec2_y = figure[i].T.left_y - figure[i].T.top_y;
                double Area = fabs(Vec1_x * Vec2_y - Vec1_y * Vec2_x) / 2;

                double area1 = fabs(vec1_x * vec2_y - vec1_y * vec2_x) / 2;
                double area2 = fabs(vec2_x * vec3_y - vec2_y * vec3_x) / 2;
                double area3 = fabs(vec1_x * vec3_y - vec1_y * vec3_x) / 2;
                //cout  << "##" << Area << " " << area1 << " " << area2 << " " << area3 << endl;
                if(area1 + area2 + area3 - Area < 1e-8){
                    cout << "Point " << index2 + 1 << " is contained in figure " << i + 1 << endl;
                    check = 1;
                } 
            }
        }
        if (check == 0){
            cout << "Point " << index2 + 1 << " is not contained in any figure" << endl;
        }
        index2++;
    }

    return 0;
}