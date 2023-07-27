#include<iostream>
#define N 105
using namespace std;
int Min[N][N], Max[N][N], s[N][N];//求最小、最大值
int sum[N];//计算前i堆石子的数量总和，sum[0]=0，w(i,j)=sum[j]-sum[i-1]
int a[N];//记录各堆石子的数量

void get_Min(int n) {
	for (int v = 2; v <= n; v++) {//枚举合并的堆数规模
		for (int i = 1; i <= n - v + 1; i++) {
			int j = i + v - 1;
			int tmp = sum[j] - sum[i - 1];
			int i1 = s[i][j - 1] > i ? s[i][j - 1] : i;
			int j1 = s[i + 1][j] < j ? s[i + 1][j] : j;
			Min[i][j] = Min[i][i1] + Min[i1 + 1][j];
			s[i][j] = i1;

			for (int k = i1 + 1; k <= j1; k++) {
				if (Min[i][k] + Min[k + 1][j] < Min[i][j]) {
					Min[i][j] = Min[i][k] + Min[k + 1][j];
					s[i][j] = k;
				}
				
			}
			Min[i][j] += tmp;
		}

	}
}
void get_Max(int n) {
	for (int v = 2; v <= n; v++) {//枚举合并的堆数规模
		for (int i = 1; i <= n - v + 1; i++) {
			int j = i + v - 1;
			int tmp = sum[j] - sum[i - 1];
			Max[i][j] = -1;
			if (Max[i + 1][j] > Max[i][j - 1])
				Max[i][j] = Max[i + 1][j] + tmp;
			else
				Max[i][j] = Max[i][j - 1] + tmp;

		}

	}
}
void straight(int a[], int n) {
	for (int i = 1; i <= n; i++) {//初始化
		Min[i][i] = 0, Max[i][i] = 0, s[i][i] = 0;
	}
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	get_Min(n);
	get_Max(n);
}

int main()
{
	while(true){
	int n;      		
	cout << "请输入石子的堆数 n(输入-1退出):";
	cin >> n;
	if(n==-1)return 0;
	cout << "请依次输入各堆的石子数：";
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	straight(a, n);
	cout<<Min[1][n]<<endl;
	cout<<Max[1][n]<<endl;
	}
	return 0;
}
