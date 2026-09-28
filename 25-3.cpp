#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

/*因为vector初始化时没有放任何东西，所以用下标访问导致报错
 *而如果使用vector<int> v{10}来初始化的话，就会在前面放10个0，这样确实是可以使用下标访问
 *但是这样push_back的话就会把数据扔在10个0后面
 *
 *所以默认构造就要用迭代器访问
 *带初始值的初始化构造就要用下表赋值
 *
 *循环套的条件到底变量是谁得弄清楚，老是套了不正确的变量
 *
 */


class Solution
{
private:
    vector<string> Files;
    vector<string> Practice;
    int PracticeNum;

public:
    void Input()
    {
        cout << "Pleas enter the times of Practice: " << endl;
        cin >> PracticeNum;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < PracticeNum; i++)
        {
            string P;
            getline(cin, P);
            Practice.push_back(P);
        }
    }

    void Handler()
    {
        Input();
        static int i = 0;
        i = 0;
        for (vector<string>::iterator it = Practice.begin(); it != Practice.end(); ++it)
        {
            i++;
            Judgement(*it, i);
        }
    }

    void Judgement(string& s, int Pos)
    {
        // cout << s << endl;
        // cout << s.substr(0, 5) << endl;
        // cout << (s.substr(0, 5)).compare("touch") << endl;
        // cout << ((s.substr(0, 2) == "ls") == 0) << endl;
        if ((s.substr(0, 5)).compare("touch") == 0)
        {
            cout << "1" << endl;
            string pt = s.substr(6);
            static int i = 0;
            i = 0;
            if (Files.size() == 0)
            {
                cout << "2" << endl;
                Files.push_back(pt);
            }
            else
            {
                for (vector<string>::iterator it = Files.begin(); it != Files.end(); it++)
                {
                    i++;
                    if (*it == pt)
                    {
                        break;
                    }
                    if (i == Pos)
                    {
                        cout << "2" << endl;
                        Files.push_back(pt);
                    }
                }
            }
        }
        else if (s.substr(0, 2) == "rm")
        {
            string pt = s.substr(3);
            static int i = 0;
            i = 0;
            for (vector<string>::iterator it = Files.begin(); it != Files.end(); it++)
            {
                i++;
                if (*it == pt)
                {
                    Files.erase(Files.begin() + i);
                }
            }
        }
        else if (s.substr(0, 2) == "ls")
        {
            for (vector<string>::iterator it = Files.begin(); it != Files.end(); it++)
            {
                cout << *it << endl;
            }
        }
        else if (s.substr(0, 6) == "rename")
        {
            string pt = s.substr(7);
            int Space_Pos = pt.find(" ");
            string PreName = pt.substr(0, Space_Pos + 1);
            string ToName = pt.substr(Space_Pos + 1);

            for (vector<string>::iterator it = Files.begin(); it != Files.end(); it++)
            {
                if (*it == PreName)
                {
                    static int i = 0;
                    i = 0;
                    for (vector<string>::iterator vit = Files.begin(); vit != Files.end(); vit++)
                    {
                        i++;
                        if (*vit == ToName)
                        {
                            break;
                        }
                        if (i == Pos)
                        {
                            Files[i] = ToName;
                        }
                    }
                }
            }
        }
        else
        {
            cout << "Error" << endl;
        }
    }
};


int main()
{
    Solution s;
    s.Handler();

    system("pause");
    return 0;
}
