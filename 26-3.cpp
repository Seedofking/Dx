#include <iostream>
#include <string>
#include <vector>
using namespace std;


//a 65 - 90 // A 97 - 122


class Solution
{
public:
    string Erase_Char(string& S)
    {
        vector<int> pos;

        for (int i = 0; i < S.length(); i++)
        {
            int ASC2 = S[i];
            bool isChar = (ASC2 >= 'A' && ASC2 <= 'Z') || (ASC2 >= 'a' && ASC2 <= 'z');
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
};


int main()
{
    string s;
    cout << "Please enter line: " << endl;
    cin >> s;
    Solution S;

    cout << S.Erase_Char(s) << endl;

    system("pause");
    return 0;
}
