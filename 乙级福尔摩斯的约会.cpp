#include<iostream>
#include<string>
using namespace std;

int get_inf1(string str1, string str2);
int get_inf2(string str3, string str4);

int main() {
    string str[10];
    for (int i = 1; i < 5; i++) {
        cin >> str[i];
    }
    int hour = get_inf1(str[1], str[2]);
    cout << " ";
    int minu = get_inf2(str[3], str[4]);
    if (hour < 10)cout << 0 << hour;
    else cout << hour;
    cout << ":";
    if (minu < 10)cout << 0 << minu;
    else cout << minu;
}
int get_inf1(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length(), times = 1;
    for (int i = 0; i <= len1 && i <= len2; i++) {
        if (str1[i] == str2[i]) {
            switch (times) {
                case 1: {
                        if (isupper(str1[i]) && isupper(str2[i]) && str1[i] <= 'G' && str1[i] >= 'A') {
                            int key = str1[i] - 'A' + 1;
                            switch (key) {
                                case 1:
                                    cout << "MON";
                                    break;
                                case 2:
                                    cout << "TUE";
                                    break;
                                case 3:
                                    cout << "WED";
                                    break;
                                case 4:
                                    cout << "THU";
                                    break;
                                case 5:
                                    cout << "FRI";
                                    break;
                                case 6:
                                    cout << "SAT";
                                    break;
                                case 7:
                                    cout << "SUN";
                                    break;
                            }
                            times++;
                        }
                        break;
                    }
                case 2: {
                        char target = str1[i];
                        if (target <= 'N' && target >= 'A') {
                            return target - 'A' + 10;
                        } else if (target <= '9' && target >= '0') {
                            return target - '0';
                        }
                        break;
                    }
            }
        }
    }
    return 0;
}
int get_inf2(string str3, string str4) {
    int len3 = str3.length(), len4 = str4.length();
    for (int i = 0; i < len3 && i < len4; i++) {
        if (isalpha(str3[i]) && isalpha(str4[i]) && str3[i] == str4[i]) {
            return i;
        }
    }
    return 0;
}