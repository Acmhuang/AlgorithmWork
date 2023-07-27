#include<iostream>
#include<vector>
using namespace std;
int k,x;
int MaxMerge(int a[],int k) {
	int max=0;
	for(int i=0; i<k-1; i++) {
		sort(a+i,a+k,greater<int>());//Ωµ–Ú≈≈¡–
		a[i+1]=a[i]+a[i+1];
		max=max+a[i+1]-1;
	}
	return max;
}
 
int MinMerge(int b[],int k) {
	int min=0;
	for(int i=0; i<k-1; i++) {
		sort(b+i,b+k);//…˝–Ú≈≈¡–
		b[i+1]=b[i]+b[i+1];
		min=min+b[i+1]-1;
	}
	return min;
}
 
int main() {
	while(true){
	cout<<" ‰»Î-1ÕÀ≥ˆ"<<endl; 
	cin>>k;
	if(k==-1)return 0;
	int a[k+5],b[k+5];
	for(int i=0; i<k; i++) {
		cin>>x;
		a[i]=x;
		b[i]=x;
	}
	cout<<MaxMerge(a,k)<<" "<<MinMerge(b,k)<<endl;		
	}
	return 0;
}