// #include "vector"
// #include "map.h"
// #define rep(i,n) for (int i = 0;i < (int)n;i++)

// using namespace std;

// const int length = 80,width = 40, det_dis = 100;
// int cur_x = length/2, cur_y = width/2;
// vector<vector<int>> field_map(length,vector<int>(width,0));
// const int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
// bool seen[length][width];

// void set_map(float r,float theta){
//     int x = cur_x + r*cos(theta)/10, y = cur_x + r*sin(theta)/10;
//     if(r > det_dis)return 0;
//     rep(i,length){
//         rep(j,width){
//             if(i == x && j == y) field_map[i][j]--;
//             else field_map[i][j]++;
//         }
//     }
// }

// void dfs(int x,int y){
//     seen[x][y] = true;
//     rep(dir,4){
//         int xd = x + dx[dir], yd = y + dy[dir];
//         if(xd < 0 || xd >= length || yd < 0 || yd >= width)continue;
//         if(field_map[xd][yd] < 0)continue;
//         if(seen[xd][yd])continue;
//         if(field_map[xd][yd] == 0)return 0;
//         dfs(xd,yd);
//     }
// }

// void scan(){
    
// }