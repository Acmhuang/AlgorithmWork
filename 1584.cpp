#include<cstdio>
int main(){
	int n,cnt;
	scanf("%d",&n);
	cnt=n;
	int st[n+5],en[n+5];
	for(int i=0;i<n;i++){
		scanf("%d%d",&st[i],&en[i]);
	}
	for(int i=0;i<n-1;i++){
		if(en[i]>st[i+1]){
			cnt--;
			en[i+1]= en[i+1]>en[i]?en[i]:en[i+1];
			st[i+1]= st[i+1]>st[i]?st[i+1]:st[i];
		}
	}
	printf("%d",cnt);
}