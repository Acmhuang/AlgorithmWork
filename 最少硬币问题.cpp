#include<iostream>
#define max_m 20001
using namespace std;
int n,m;
int coin[15],t[15],dp[max_m];
void change(){
	cin>>n;
	if(n==-1)return;
	for(int i=1;i<=n;i++)cin>>t[i]>>coin[i];
	cin>>m;
	for(int i=1;i<=max_m;i++)dp[i]=99999;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=coin[i];j++)
			for(int k=m;k>=t[i];k--)
				dp[k]=min(dp[k-t[i]]+1,dp[k]);
}
int main(){
	cout<<"请输入一组硬币数值(输入-1退出)："<<endl;
	change();
	while(n!=-1){
		cout<<endl;
		cout<<(dp[m]<99999?dp[m]:-1)<<endl;
		cout<<"请输入一组硬币数值(输入-1退出)："<<endl;
		change();
	}
	return 0;
}
