#include<iostream>
using namespace std;
bool judge(int num);
int main(){
	int M,N,cnt=0;
	cin>>M>>N;
	if(M==N){
		for(int i=2;cnt<=N;i++){
			if(judge(i)){
				cnt++;
				if(cnt==N)cout<<i;
			}
		}
	}
	else
		for(int i=2;cnt<N;i++){
			if(judge(i)){
				cnt++;
				if(cnt>=M){
					cout<<i;
					if(cnt!=N||(cnt-M+1)%10==0)cout<<" ";
					if((cnt-M+1)%10==0)cout<<endl;
				}
			}
		}
}
bool judge(int num){
	for(int i=2;i<=num/2;i++){
		if(num%i==0)return false;
	}
	return true;
}