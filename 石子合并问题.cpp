#include<iostream>
#define N 105
using namespace std;
int Min[N][N], Max[N][N], s[N][N];//����С�����ֵ
int sum[N];//����ǰi��ʯ�ӵ������ܺͣ�sum[0]=0��w(i,j)=sum[j]-sum[i-1]
int a[N];//��¼����ʯ�ӵ�����

void get_Min(int n) {
	for (int v = 2; v <= n; v++) {//ö�ٺϲ��Ķ�����ģ
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
	for (int v = 2; v <= n; v++) {//ö�ٺϲ��Ķ�����ģ
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
	for (int i = 1; i <= n; i++) {//��ʼ��
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
	cout << "������ʯ�ӵĶ��� n(����-1�˳�):";
	cin >> n;
	if(n==-1)return 0;
	cout << "������������ѵ�ʯ������";
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	straight(a, n);
	cout<<Min[1][n]<<endl;
	cout<<Max[1][n]<<endl;
	}
	return 0;
}
