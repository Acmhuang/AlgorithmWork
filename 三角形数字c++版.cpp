#include<iostream>
using namespace std;
int num[15][15],dp[15][15];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>num[i][j];
		}
	}
	for(int j=1;j<=n;j++){
		dp[n][j]=num[n][j];
	}
	for(int i=n-1;i>0;i--){
		for(int j=1;j<=i;j++){
			dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+num[i][j];
		}
	}
	cout<<dp[1][1];
}