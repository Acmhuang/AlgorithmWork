#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student {
    long number;
    int moral, score, sum, level;
} stu;
vector<student> level_1, level_2, level_3, level_4;
bool cmp(student s1, student s2) {
    if (s1.sum != s2.sum)return s1.sum > s2.sum;
    else if (s1.moral != s2.moral)return s1.moral > s2.moral;
    else return s1.number < s2.number;
}
void stu_printf(vector<student> s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i].number << " " << s[i].moral << " " << s[i].score << endl;
    }
}
int main() {
    int N, L, H, cnt = 0;
    cin >> N >> L >> H;
    while (N--) {
        cin >> stu.number >> stu.moral >> stu.score;
        stu.sum = stu.moral + stu.score;
        if (stu.moral < L || stu.score < L)
            continue;
        else if (stu.moral >= H && stu.score >= H) { //德才兼备
            stu.level = 1;
            level_1.push_back(stu);
        } else if (stu.moral >= H && stu.score < H) { //德胜才
            stu.level = 2;
            level_2.push_back(stu);
        } else if (stu.moral < H && stu.score < H &&
                   stu.moral >= stu.score) { //德才兼亡，尚有德
            stu.level = 3;
            level_3.push_back(stu);
        } else { //剩余合格考生
            stu.level = 4;
            level_4.push_back(stu);
        }
        cnt++;
    }
    cout << cnt << endl;
    if (level_1.size() != 0) {
        sort(level_1.begin(), level_1.end(), cmp);
        stu_printf(level_1);
    }
    if (level_2.size() != 0) {
        sort(level_2.begin(), level_2.end(), cmp);
        stu_printf(level_2);
    }
    if (level_3.size() != 0) {
        sort(level_3.begin(), level_3.end(), cmp);
        stu_printf(level_3);
    }
    if (level_4.size() != 0) {
        sort(level_4.begin(), level_4.end(), cmp);
        stu_printf(level_4);
    }
    return 0;
}

