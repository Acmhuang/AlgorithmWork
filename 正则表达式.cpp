#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > f; // 创建一个二维矩阵，用于记忆化搜索过程中的中间结果
int n, m; // 字符串 s 和 p 的长度
bool isMatch(string s, string p);
bool dp(int x, int y, string &s, string &p);
int main(){
	string s,p;
	cin>>s>>p;
    isMatch(s,p); 
}
bool isMatch(string s, string p) { // 判断字符串 s 是否匹配正则表达式 p
        n = s.size();
        m = p.size();
        f = vector<vector<int> >(n + 1, vector<int>(m + 1, -1)); // 初始化二维矩阵，所有元素赋值为 -1
        if(dp(0, 0, s, p))cout<<"true"; // 开始记忆化搜索
        else cout<<"false";
}
bool dp(int x, int y, string &s, string &p){ // 记忆化搜索函数，判断从 s[x:] 开始的子串是否能够匹配从 p[y:] 开始的子串
        if (f[x][y] != -1) return f[x][y]; // 如果之前已经搜索过，则直接返回结果
        if (y == m) return f[x][y] = (x == n); // 如果正则表达式已经匹配完了，则判断 s 是否也匹配完了
        bool match = (x < n) && (s[x] == p[y] || p[y] == '.'); // 判断 s[x] 是否能够和 p[y] 匹配
        bool ans;
        if (p[y + 1] == '*' && y + 1 < m) { // 如果 p[y+1] 是 '*'，则有两种选择：1）'*' 匹配了 0 次，直接跳过 p[y:y+2]；2）'*' 匹配了至少 1 次，s[x] 和 p[y] 匹配成功，继续在 s[x+1:] 和 p[y:] 进行匹配
            ans = ((match && dp(x + 1, y, s, p)) || dp(x, y + 2, s, p)); // 递归调用 dp 函数
        }
        else { // 如果 p[y+1] 不是 '*'，则直接匹配 s[x] 和 p[y]，然后在 s[x+1:] 和 p[y+1:] 进行匹配
            ans = match && dp(x + 1, y + 1, s, p); // 递归调用 dp 函数
        }
        return f[x][y] = ans; // 记录搜索结果
}
/*模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。

状态表示：f[i][j]表示p从j开始到结尾，是否能匹配s从i开始到结尾
状态转移：
如果p[j+1]不是通配符'*'，则f[i][j]是真，当且仅当s[i]可以和p[j]匹配，且f[i+1][j+1]是真；
如果p[j+1]是通配符'*'，则下面的情况只要有一种满足，f[i][j]就是真；
f[i][j+2]是真；
s[i]可以和p[j]匹配，且f[i+1][j]是真；
*/