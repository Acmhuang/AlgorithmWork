#include<cstdio>
int main(){
	int pe=0,cnt=0;
	int N,R;
	scanf("%d%d",&N,&R);
	int Xi[N+5];
	for(int i =0;i<N;i++){
		scanf("%d",&Xi[i]);
	}
	while(pe<=N-1){
		int j=pe+1;
		if(Xi[j]<=Xi[pe]+R){
		while(Xi[j+1]<Xi[pe]+R){
			j++;
		}
		}else{
			j--;
		}
		if(pe!=N-1){
		int tmp=Xi[j];
		while(Xi[j+1]<=tmp+R){
			j++;
		}
		}
		pe=j+1;
		cnt++;
	}
	printf("%d",cnt);
}