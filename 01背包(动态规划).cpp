#include<cstdio>
#include<algorithm>
using namespace std;
int n,ww;
int dp[1005][1005];/*dp[i][j]的数值表示到第i件物品时的背包总价值，
					不一定放入到i（包括i）的每个物品;j表示剩余背包容量*/ 
int v[1005],w[1005];//vi表示价值，wi表示重量 
int main(){
	scanf("%d%d",&n,&ww);
	memset(dp,0,n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&v[i]);
	}//输入完毕 
	for(int i=1;i<=n;i++){
		for(int j=ww;j>=1;j--){
				dp[i][j]=dp[i-1][j];
				if(j>=w[i])dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);//放入当前的第i个物品
		}
	}
	printf("%d",dp[n][ww]);
}
/*
4 5
1 2
2 4
3 4
4 5
*/