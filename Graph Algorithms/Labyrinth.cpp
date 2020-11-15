#include <bits/stdc++.h>

using namespace std;
const int mxN = 1e3, di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0}, d[4] = {'L', 'U', 'R', 'D'};
string room[mxN], dir[mxN][mxN];
int path[mxN][mxN];
int h, w, sh, sw, eh, ew;
queue<int> iq, jq;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < h && j < w && room[i][j] != '#';
}
void en(int i, int j)
{
    iq.push(i);
    jq.push(j);
}

bool bfs()
{
    en(sh, sw);
    room[sh][sw] = '#';
    while (!iq.empty())
    {
        int i = iq.front();
        int j = jq.front();
        if(i==eh && j==ew)
            return true;
        iq.pop();
        jq.pop();
        for (int k = 0; k < 4; k++)
        {
            int newi = i + di[k];
            int newj = j + dj[k];
            if (valid(newi, newj))
            {

                dir[newi][newj] = d[k];
                room[newi][newj] = '#';
                en(newi, newj);
                path[newi][newj] = k;
            }
        }
    }
    return false;
}

int main()
{

    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> room[i];
        
    }
     for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (room[i][j] == 'A')
            {
                sh = i;
                sw = j;
            }
            if (room[i][j] == 'B')
            {
                eh = i;
                ew = j;
            }
        }
    }
    
    if(bfs()){
        cout<<"YES"<<endl;
        string p="";
        int i=eh;
        int j=ew;
        while (i!=sh || j !=sw){
            p+=dir[i][j];
            int n = path[i][j]^2;
            i=i+di[n];
            j=j+dj[n];
            
        }
        reverse(p.begin(),p.end());
        cout<<p.size()<<endl;
        cout<<p;

        
    }
    else{
        cout<<"NO";
    }

    return 0;
}