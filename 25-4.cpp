#include<iostream>
#include<vector>
using namespace std;

#include <string>
#include <sstream>

class Solution
{
private:
    vector<int> v;

public:
    void Multi_Input()
    {
        string line; //line一会用于存储从cin得到的一整行数据
        cout << "请输入若干数字，须使用空格分隔，按回车提交: " << endl;

        getline(cin, line); //getline可以实现从cin中拿到一整行的输入数据，放在line里
        stringstream ss(line); //stringstream ss(line) 可以从line中构造输入流数据给ss， 并且可以从中分割数据

        int tmp;
        while (ss >> tmp)
        {
            v.push_back(tmp);
        }
    }

    int Sum()
    {
        int Sum = 0;
        for (int i : v)
        {
            Sum += i;
        }
        return Sum;
    }

    int Max()
    {
        int Max = 0;
        for (int i : v)
        {
            i > Max ? Max = i : NULL;
        }
        return Max;
    }
};


int main()
{
    Solution s;
    s.Multi_Input();
    int Sum = s.Sum();
    int Max = s.Max();

    cout << "Sum = " << Sum << endl;
    cout << "Max = " << Max << endl;


    system("pause");
    return 0;
}
