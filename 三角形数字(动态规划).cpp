#include<cstdio>
#include<algorithm>
#define MAX 105
using namespace std;
int n;//���� 
int maxsum[MAX][MAX];//���㵱ǰλ����������֮�� 
int D[MAX][MAX];//��������ε����� 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&D[i][j]);
		}
	}//������� 
	for(int i=1;i<=n;i++){//����һ�е���ֱ������ 
		maxsum[n][i]=D[n][i];
	} 
	for(int i=n-1;i>0;i--){//�ӵ����п�ʼѭ�������ۼ� 
		for(int j=1;j<=i;j++){
			maxsum[i][j]=max(maxsum[i+1][j],
			maxsum[i+1][j+1])+D[i][j];//���㵱ǰλ�õĺͲ���¼�������� 
		}
	}
	printf("%d",maxsum[1][1]);
}
/*�������� 
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/