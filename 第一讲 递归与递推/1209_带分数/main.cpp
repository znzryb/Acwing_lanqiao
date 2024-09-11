// https://www.luogu.com.cn/problem/P8599
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,ans,up,down,result;
int a[12]={0,1,2,3,4,5,6,7,8,9};
int main()
{
    cin>>n;
    string n_=to_string(n);
    do {
        for(int i=1;i<=n_.size();i++) {
            for(int j=9;j>=i+2;j--) {
                //算分子
                up=0,down=0,result=0;
                for(int k=9;k>=j;k--) {
                    down+=a[k]*pow(10,(9-k));
                }
                //算分母
                for(int k=j-1;k>i;k--) {
                    up+=a[k]*pow(10,(j-1-k));
                }
                if(up%down!=0)
                    continue;
                result=up/down;
                //算整数
                for(int k=1;k<=i;k++) {
                    result+=a[k]*pow(10,(i-k));
                }
                if(result==n) {
                    ans+=1;     // 一旦得到答案说明继续组合一定比答案 大/小 故break剪枝
                    break;
                }
            }
        }
    }while(next_permutation(&a[1],&a[10]));     // 左闭右开
    cout<<ans<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/176141903  https://www.luogu.com.cn/record/176143647