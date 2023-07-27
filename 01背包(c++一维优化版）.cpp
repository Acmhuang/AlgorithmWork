#include<algorithm>
#include<iostream>
using namespace std;
int v[1005],w[1005];//v为体积 w为价值
int dp[1005];
int n,ww;
int main(){
    cin>>n>>ww;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=ww;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
        /*for(int j=0;j<=ww;j++){
            cout<<dp[j];
        }
        cout<<"\n";
        */
    }
    cout<<dp[ww];
}