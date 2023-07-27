#include<iostream>
using namespace std;
int n,k;
int num[105];
int main(){
	cin>>n>>k;
	int oil=n,res=0;
	bool flag=true;
	for(int i=0;i<k+1;i++){
		cin>>num[i];
	}
	for(int i=0;i<k+1;i++){
		if(oil>=num[i]){
			oil-=num[i];
			continue;
		}
		else{
			i-=1;
			res++;
			flag=false;
			oil=n;
		}
	}
	if(!flag){
		cout<<res;
	}else{
		cout<<"No Solution";
	}
} 