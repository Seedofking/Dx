#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
private:
    string rs;

public:
    string Turn_String(string s)
    {
        string as;
        int dis = 'a' - 'A';

        for (int i = 0; i < s.length(); i++)
        {
            //前一个, 需要改成大写
            if (i % 2 == 0) //双数，但是作为单数使用01234
            {
                char c = s[i] - dis;
                as.push_back(c);
            }
            else
            {
                as.push_back(s[i]);
            }
        }
        return as;
    }

    string Turn_S()
    {
        string ts;
        string as;
        vector<string> v;

        cout << "请输入由小写英文字符和空格组成的标题S: ";
        getline(cin, rs);
        stringstream ss(rs);

        while (ss >> ts)
        {
            v.push_back(ts);
        }

        for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
        {
            ts = Turn_String(*it);
            as += ts;
            as += ' ';
        }
        as.erase(as.length() - 1);
        return as;
    }
};

int main()
{
    Solution s;
    cout << s.Turn_S() << endl;

    system("pause");
    return 0;
}
