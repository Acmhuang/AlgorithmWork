#include<cstdio> 
int main(){
	int m,n,k=0,cost=0;
	scanf("%d%d",&m,&n);
	int pc[n+5],lt=0,rt=n;
	for(int i=0;i<n;i++){
		scanf("%d",&pc[i]);
	}
	if(m==n){
	for(int i=0;i<n;i++){
		cost+=pc[i];
	}	
	}
	else if(m==1){
			while(rt>0){
				rt--;
				cost+=(k+1)*pc[rt];
				k++;
				}
	}
	else{
	while(rt>0){
		int j=m;
		while(j--&&rt>0){
			rt--;
			cost+=(k+1)*pc[rt];
		}
		k++;
	}		
	}
	printf("%d",cost);
}