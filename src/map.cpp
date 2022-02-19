#include "vector"
#include "map.h"
#define rep(i,n) for (int i = 0;i < (int)n;i++)

using namespace std;

const int length = 400,width = 200;
vector<vector<int>> field_map(length,vector<int>(width,0));

void set_map(float r,float theta){
    int x = r*cos(theta), y = r*sin(theta);
    rep(i,length){
        rep(j,width){
            if(i == x && j == y) field_map[i][j]--;
            else field_map[i][j]++;
        }
    }
}