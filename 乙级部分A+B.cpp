#include<iostream>
#include<string>
using namespace std;

long power(long n1, long n2) {
    long res = 1;
    for (int i = 0; i < n2; i++)res *= n1;
    return res;
}

int main() {
    string a, b;
    char Da, Db;
    long Pa, Pb, cnt_a, cnt_b;
    Pa = Pb = 0;
    cnt_a = cnt_b = 0;
    cin >> a >> Da >> b >> Db;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == Da) {
            Pa += (Da - '0') * power(10, cnt_a);
            cnt_a++;
        }
    }
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == Db) {
            Pb += (Db - '0') * power(10, cnt_b);
            cnt_b++;
        }
    }
    cout << Pb + Pa;
}