#include<cstdio>
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int arr,res=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr);
			res^=arr;
			printf("%d\n",res);
		}
		printf("%d\n",res);
	}
}