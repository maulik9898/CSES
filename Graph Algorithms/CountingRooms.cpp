#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int mxN=1e3;
string room[mxN];
int h,w;
bool valid(int i,int j){
    return i>=0 &&j>=0 &&i<h &&j<w &&room[i][j]=='.';
}

void dfs(int i,int j){
    room[i][j]='#';
    if(valid(i,j-1))
        dfs(i,j-1);
    if(valid(i-1,j))
        dfs(i-1,j);
    if(valid(i,j+1))
        dfs(i,j+1);
    if(valid(i+1,j))
        dfs(i+1,j);

}

int main(){

   cin >>h>>w;
   for(int i =0;i<h;i++){
       cin>>room[i];
   }
   int ans = 0;
   for(int i=0;i<h;i++)
    for(int j = 0;j<w;j++){
        if(valid(i,j)){
            dfs(i,j);
            ans++;
        }
    }
    cout<<ans;

    return 0;
}