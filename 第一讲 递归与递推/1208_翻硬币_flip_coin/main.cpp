#include <iostream>
#include <bitset>
using namespace std;
string s1,s2;
int n,cnt,ans;
bitset<105> diff;
int main()
{
    cin>>s1>>s2;
    n=s1.size();
    for(int i=0;i<n;i++) {
        if(s1[i]!=s2[i])
            diff[i]=true;
    }
    bool isfirst=true;
    for(int i=0;i<n;i++) {
        cnt+=1;
        if(diff[i]) {
            if(!isfirst)
                ans+=cnt,isfirst=true;
            else
                isfirst=false;
            cnt=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
// AC https://www.luogu.com.cn/record/176116199
