#include<cstdio>
#include<algorithm>
#define MAX 105
using namespace std;
int n;//输入 
int maxsum[MAX][MAX];//计算当前位置最大的数字之和 
int D[MAX][MAX];//存放三角形的数字 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&D[i][j]);
		}
	}//输入完毕 
	for(int i=1;i<=n;i++){//将倒一行的数直接输入 
		maxsum[n][i]=D[n][i];
	} 
	for(int i=n-1;i>0;i--){//从倒二行开始循环逆向累加 
		for(int j=1;j<=i;j++){
			maxsum[i][j]=max(maxsum[i+1][j],
			maxsum[i+1][j+1])+D[i][j];//计算当前位置的和并记录在数组里 
		}
	}
	printf("%d",maxsum[1][1]);
}
/*测试输入 
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/