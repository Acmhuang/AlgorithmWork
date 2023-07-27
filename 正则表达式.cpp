#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > f; // ����һ����ά�������ڼ��仯���������е��м���
int n, m; // �ַ��� s �� p �ĳ���
bool isMatch(string s, string p);
bool dp(int x, int y, string &s, string &p);
int main(){
	string s,p;
	cin>>s>>p;
    isMatch(s,p); 
}
bool isMatch(string s, string p) { // �ж��ַ��� s �Ƿ�ƥ��������ʽ p
        n = s.size();
        m = p.size();
        f = vector<vector<int> >(n + 1, vector<int>(m + 1, -1)); // ��ʼ����ά��������Ԫ�ظ�ֵΪ -1
        if(dp(0, 0, s, p))cout<<"true"; // ��ʼ���仯����
        else cout<<"false";
}
bool dp(int x, int y, string &s, string &p){ // ���仯�����������жϴ� s[x:] ��ʼ���Ӵ��Ƿ��ܹ�ƥ��� p[y:] ��ʼ���Ӵ�
        if (f[x][y] != -1) return f[x][y]; // ���֮ǰ�Ѿ�����������ֱ�ӷ��ؽ��
        if (y == m) return f[x][y] = (x == n); // ���������ʽ�Ѿ�ƥ�����ˣ����ж� s �Ƿ�Ҳƥ������
        bool match = (x < n) && (s[x] == p[y] || p[y] == '.'); // �ж� s[x] �Ƿ��ܹ��� p[y] ƥ��
        bool ans;
        if (p[y + 1] == '*' && y + 1 < m) { // ��� p[y+1] �� '*'����������ѡ��1��'*' ƥ���� 0 �Σ�ֱ������ p[y:y+2]��2��'*' ƥ�������� 1 �Σ�s[x] �� p[y] ƥ��ɹ��������� s[x+1:] �� p[y:] ����ƥ��
            ans = ((match && dp(x + 1, y, s, p)) || dp(x, y + 2, s, p)); // �ݹ���� dp ����
        }
        else { // ��� p[y+1] ���� '*'����ֱ��ƥ�� s[x] �� p[y]��Ȼ���� s[x+1:] �� p[y+1:] ����ƥ��
            ans = match && dp(x + 1, y + 1, s, p); // �ݹ���� dp ����
        }
        return f[x][y] = ans; // ��¼�������
}
/*ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ�䡣

״̬��ʾ��f[i][j]��ʾp��j��ʼ����β���Ƿ���ƥ��s��i��ʼ����β
״̬ת�ƣ�
���p[j+1]����ͨ���'*'����f[i][j]���棬���ҽ���s[i]���Ժ�p[j]ƥ�䣬��f[i+1][j+1]���棻
���p[j+1]��ͨ���'*'������������ֻҪ��һ�����㣬f[i][j]�����棻
f[i][j+2]���棻
s[i]���Ժ�p[j]ƥ�䣬��f[i+1][j]���棻
*/