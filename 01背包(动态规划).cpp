#include<cstdio>
#include<algorithm>
using namespace std;
int n,ww;
int dp[1005][1005];/*dp[i][j]����ֵ��ʾ����i����Ʒʱ�ı����ܼ�ֵ��
					��һ�����뵽i������i����ÿ����Ʒ;j��ʾʣ�౳������*/ 
int v[1005],w[1005];//vi��ʾ��ֵ��wi��ʾ���� 
int main(){
	scanf("%d%d",&n,&ww);
	memset(dp,0,n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&v[i]);
	}//������� 
	for(int i=1;i<=n;i++){
		for(int j=ww;j>=1;j--){
				dp[i][j]=dp[i-1][j];
				if(j>=w[i])dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);//���뵱ǰ�ĵ�i����Ʒ
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