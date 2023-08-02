#include <iostream>
using namespace std;

int main() {
    int T, temp;
    long int a,b,c;
    temp=1;
    string flag;
    cin>>T;
    while (temp<=T) {
        cin>>a>>b>>c;
        if(a+b>c)flag="true";
        else flag="false";
        cout<<"Case #"<<temp<<": "<<flag<<endl;
        temp++;
    }
}