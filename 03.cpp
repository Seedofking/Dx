#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution
{
private:
    string rs;

public:
    Solution(string s) : rs(s)
    {
    }

    string Remove()
    {
        string t;
        t = Erase_Char(rs);
        string ans;
        ans = Turn_String(t);

        return ans;
    }

    string Erase_Char(string& S)
    {
        vector<int> pos;

        for (int i = 0; i < S.length(); i++)
        {
            int ASC2 = S[i];
            bool isChar = (ASC2 >= 'A' && ASC2 <= 'Z') || (ASC2 >= 'a' && ASC2 <= 'z' || (ASC2 >= '0' && ASC2 <=
                '9'));
            if (!isChar)
            {
                pos.push_back(i);
            }
        }
        for (int i = pos.size() - 1; i >= 0; i--)
        {
            S.erase(S.begin() + pos[i]);
        }

        return S;
    }

    string Turn_String(string s)
    {
        string as;
        int dis = 'a' - 'A';

        for (int i = 0; i < s.length(); i++)
        {
            //前一个, 需要改成大写
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                char c = s[i] + dis;
                as.push_back(c);
            }
            else
            {
                as.push_back(s[i]);
            }
        }
        return as;
    }
};


int main()
{
    cout << "请输入一行字符串：" << endl;
    string s;

    getline(cin, s);
    Solution sl(s);

    cout << sl.Remove() << endl;

    system("pause");
    return 0;
}
