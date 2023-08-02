#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double num[10],a4_cnt=0;
	int N,temp;
	bool num_sure[10],a2_flag=true;
	for(int i=1;i<=5;i++){
		num_sure[i]=false;
		num[i]=0;
	}
	cin>>N;
	while(N--){
		cin>>temp;
		switch(temp%5){
			case 0:{
				if(temp%2==0){
					num[1]+=temp;
					num_sure[1]=true;
				}
				break;
			}
			case 1:{
				num_sure[2]=true;
				if(a2_flag)num[2]+=temp;
				else num[2]-=temp;
				a2_flag=!a2_flag;
				break;
			}
			case 2:{
				num_sure[3]=true;
				num[3]++;
				break;
			}
			case 3:{
				num_sure[4]=true;
				num[4]+=temp;
				a4_cnt++;
				break;
			}
			case 4:{
				num_sure[5]=true;
				if(num[5]<temp)num[5]=temp;
				break;
			}
		}
	}
	for(int i=1;i<=5;i++){
		if(num_sure[i]){
			if(i==4){
				num[i]/=a4_cnt;
				cout<<setprecision(1)<<fixed<<num[i];
			}
			else cout<<setprecision(0)<<fixed<<num[i];
		}
		else cout<<"N";
		if(i!=5)cout<<" ";
	}
}