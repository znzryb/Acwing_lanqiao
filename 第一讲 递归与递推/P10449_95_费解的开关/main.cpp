#include <iostream>
#include <bitset>
#include <unordered_set>
#include <queue>
// https://www.luogu.com.cn/problem/P10449
// bfs
using namespace std;
int t,ox,dir[4]={-1,1,5,-5};
char a;
bitset <27> maze,maze2;
unordered_set<int> ans;
queue<int> q;
int main()
{
    cin>>t;
    for(int s=1;s<=25;s++) {    // start
        for(int i=1;i<=25;i++) {
            maze2[i]=true;
        }
        q.push(s),maze2[s]=false;
        while (!q.empty()) {
            ox=q.front();
            q.pop();
            for(auto d:dir) {
                if(s+d<=25 && s+d>=1)
                    maze2[s+d]=false,q.push(s+d);
            }

        }


    }

    while(t--) {
        for(int i=1;i<=25;i++) {
            cin>>a;
            if(a=='1')
                maze[i]=true;
            else
                maze[i]=false;
        }

    }
    return 0;
}
