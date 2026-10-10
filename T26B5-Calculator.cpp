#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Calculator
{
private:
    vector<string> history;
    int count = 0;

public:
    void menu()
    {
        while (1)
        {
            int num;
            cout << "========== 计算器菜单 ==========\n";
            cout << "1. 整数加法\n";
            cout << "2. 浮点数加法\n";
            cout << "3. 显示历史记录\n";
            cout << "4.清空历史记录\n";
            cout << "请选择操作: \n";
            cin >> num;

            switch (num)
            {
            case 1:
                {
                    int a, b;
                    cout << "请输入两个整数: ";
                    cin >> a >> b;
                    int ans = add(a, b);
                    cout << "结果: " << ans << '\n' << '\n';
                    count++;
                    Add_History(a, b, ans);
                    break;
                }
            case 2:
                {
                    double a, b;
                    cout << "请输入两个小数: ";
                    cin >> a >> b;
                    double ans = add(a, b);
                    cout << "结果: " << ans << '\n' << '\n';
                    count++;
                    Add_History(a, b, ans);
                    break;
                }
            case 3:
                {
                    showHistory();
                    break;
                }
            case 4:
                {
                    clearHistory();
                    break;
                }
            default:
                {
                    cout << "操作无效, 请重新输入: " << endl;
                }
            }
        }
    }

    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    template <typename T>
    void Add_History(T a, T b, T ans)
    {
        stringstream ss;
        ss << count << ". " << a << " + " << b << " = " << ans;
        string s = ss.str();

        history.push_back(s);
    }

    void showHistory()
    {
        if (history.size() == 0)
        {
            cout << "No history" << endl;
        }
        else
        {
            for (string s : history)
            {
                cout << s << endl;
            }
            cout << endl;
        }
    }

    void clearHistory()
    {
        history.clear();
    }
};

int main()
{
    Calculator c;
    c.menu();

    system("pause");
    return 0;
}
