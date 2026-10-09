#include <iostream>
#include <string>
using namespace std;

string Get_Password()
{
    int n;
    string rs;
    string as;

    cout << "请输入移动位数n: ";
    cin >> n;
    cout << "请输入原文字符串: ";
    cin >> rs;

    for (int i = 0; i < rs.length(); i++)
    {
        char c;
        if (rs[i] + n <= 'z')
        {
            c = rs[i] + n;
        }
        else
        {
            c = rs[i] - 26 + n;
        }
        as.push_back(c);
    }
    return as;
}


int main()
{
    string answer;
    answer = Get_Password();

    cout << answer << endl;
    system("pause");
    return 0;
}
