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

        for (vector<string>::iterator it = Practice.begin(); it != Practice.end(); ++it)
        {
            Judgement(*it);
        }
    }

    void Judgement(string& s)
    {
        // cout << s << endl;
        // cout << s.substr(0, 5) << endl;
        // cout << (s.substr(0, 5)).compare("touch") << endl;
        // cout << ((s.substr(0, 2) == "ls") == 0) << endl;
        if ((s.substr(0, 5)).compare("touch") == 0)
        {
            string pt = s.substr(6);

            bool exist = false;
            for (vector<string>::iterator it = Files.begin(); it != Files.end(); ++it)
            {
                if (*it == pt)
                {
                    exist = true;
                    break;
                }
            }
            if (!exist)
            {
                Files.push_back(pt);
            }
        }
        else if (s.substr(0, 2) == "rm")
        {
            string pt = s.substr(3);
            //为了不每次都++, 遍历时使用while, 而非for循环
            /*            for (vector<string>::iterator it = Files.begin(); it != Files.end(); it++)
                        {
                            i++; //i++在使用迭代器时没有意义，而且删除元素之后，it的值可能不再准确
                            if (*it == pt)
                            {
                                // Files.erase(Files.begin() + i);  erase之后原迭代器会失效，需要用erase返回值接受新的迭代器
                                //而且erase之后再使用++it会跳过元素，erase之后迭代器就会接下一个元素，不需要再++
                                it = Files.erase(it);
                            }
                        }
            */
            vector<string>::iterator it = Files.begin();
            while (it != Files.end())
            {
                if (*it == pt)
                {
                    it = Files.erase(it);
                }
                // Files.erase(Files.begin() + i);  erase之后原迭代器会失效，需要用erase返回值接受新的迭代器
                //而且erase之后再使用++it会跳过元素，erase之后迭代器就会接下一个元素，不需要再++
                else
                {
                    ++it;
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
            string PreName = pt.substr(0, Space_Pos);
            string ToName = pt.substr(Space_Pos + 1);

            for (vector<string>::iterator it = Files.begin(); it != Files.end(); it++)
            {
                if (*it == PreName)
                {
                    bool exist = false; //用标志位来判断是否存在，而不是用break能不能走到最后来判断有没有存在
                    for (vector<string>::iterator vit = Files.begin(); vit != Files.end(); vit++)
                    {
                        if (*vit == ToName)
                        {
                            exist = true;
                            break;
                        }
                    }
                    if (!exist)
                    {
                        *it = ToName;
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
