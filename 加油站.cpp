#include<iostream>
#include<vector>
using namespace std;
int n=0,k,oil,res;
bool flag=true;
vector<int> sta;
void solve(){
	for(int i=0;i<k;i++){
		oil-=sta[i];
		if(oil<sta[i+1]){
			oil=n;
			res++;
		}
		if(sta[i]>n||sta[i+1]>n){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<res<<endl;
	}else{
		cout<<"No Solution!"<<endl;
	}
}
int main(){
	while(true){
		cout<<"输入-1退出"<<endl; 
		cin>>n;
		if(n==-1)return 0;
		cin>>k;//n代表满油后最大行驶距离，k代表k个加油站
		//第 0 个加油站表示出发地，汽车已加满油。
		//第 k 个加油站表示目的地。
		oil=n;
		res=0;
		sta=vector<int>(k+5);
		for(int i=0;i<k+1;i++){
			cin>>sta[i];
		}
		solve();
	}
}