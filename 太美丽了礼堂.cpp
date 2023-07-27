#include<cstdio>
int main(){
	int n,t=0,cnt=0;
	scanf("%d",&n);
	int B[n+5],E[n+5];
	for(int i=0;i<n;i++){
		scanf("%d%d",&B[i],&E[i]);
	}
	while(t<n-1){
		int tmp=1;
		int st=t;
		for(int i=t+1;i<n;i++){
			if(B[i]>E[st]){
				tmp++;
				st=i;
			}
		}
		if(tmp>cnt)cnt=tmp;
		t++;
	}
	printf("%d",cnt);
}