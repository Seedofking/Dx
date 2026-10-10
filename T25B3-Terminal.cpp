#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
private:
    int n;
    vector<string> file;

public:
    Solution()
    {
        cout << "ÇëÊäÈë²Ù×÷Êý: " << endl;
        cin >> n;
        cin.ignore();
    }

    void Terminal()
    {
        for (int i = 1; i <= n; i++)
        {
            string rs, stemp;

            getline(cin, rs);
            stringstream ss(rs);

            vector<string> vcut;
            while (ss >> stemp)
            {
                vcut.push_back(stemp);
                stemp.clear();
            }
            ss.clear();
            ss.str("");

            Practice_Handler(vcut);
        }
    }

    void Practice_Handler(vector<string>& vs)
    {
        if (vs.size() == 1)
        {
            if (vs[0] == "ls")
            {
                Ls();
            }
            else
            {
                // cout << "Command Not Found" << endl;
            }
        }
        else if (vs.size() == 2)
        {
            if (vs[0] == "touch" && Exist(vs[1]) == false)
            {
                file.push_back(vs[1]);
            }
            else if (vs[0] == "rm" && Exist(vs[1]) == true)
            {
                Erase(vs[1]);
            }
            else
            {
                // cout << "Command Not Found" << endl;
            }
        }
        else if (vs.size() == 3)
        {
            if (vs[0] == "rename")
            {
                if (Exist(vs[1]) && !Exist(vs[2]))
                {
                    Rename(vs[1], vs[2]);
                }
            }
            else
            {
                cout << "Command Not Found" << endl;
            }
        }
        // else
        // {
        //     cout << "Command Not Found" << endl;
        // }
    }

    bool Exist(string s)
    {
        for (vector<string>::iterator it = file.begin(); it != file.end(); it++)
        {
            if (*it == s)
            {
                return true;
            }
        }
        return false;
    }


    void Erase(string s)
    {
        for (vector<string>::iterator it = file.begin(); it != file.end(); it++)
        {
            if (*it == s)
            {
                file.erase(it);
                break;
            }
        }
    }

    void Rename(string xxx, string yyy)
    {
        for (vector<string>::iterator it = file.begin(); it != file.end(); it++)
        {
            if (*it == xxx)
            {
                *it = yyy;
            }
        }
    }

    void Ls()
    {
        for (vector<string>::iterator it = file.begin(); it != file.end(); it++)
        {
            cout << *it << endl;
        }
    }
};

int main()
{
    Solution s;
    s.Terminal();

    system("pause");
    return 0;
}
