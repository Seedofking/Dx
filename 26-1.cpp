#include <iostream>
using namespace std;

class Solution
{
private:
    int n = 0;
    int Front_Space = 0, Mid_Space = 0;
    int center;

public:
    void CreateX()
    {
        int center = (n + 1) / 2;
        if (n != 0)
        {
            for (int i = 1; i < center; i++)
            {
                Front_Space = i - 1;
                Create_Space(Front_Space);

                cout << "*";

                Mid_Space = center - (Front_Space + 1);
                Create_Space(Mid_Space);

                Create_Space(Mid_Space - 1);

                cout << "*" << endl;
            }
            Create_Space(center - 1);
            cout << "*" << endl;
            for (int i = center - 1; i > 0; i--)
            {
                Front_Space = i - 1;
                Create_Space(Front_Space);

                cout << "*";

                Mid_Space = center - (Front_Space + 1);
                Create_Space(Mid_Space);

                Create_Space(Mid_Space - 1);

                cout << "*" << endl;
            }
        }
    }

    void Create_Space(int sp)
    {
        for (int i = 1; i <= sp; i++)
        {
            cout << " ";
        }
    }

    void Set_n()
    {
        int temp;
        cout << "Please enter n: " << endl;
        cin >> temp;
        if (temp >= 5 && temp <= 100 && temp % 2 != 0)
        {
            n = temp;
        }
        else
        {
            cout << "n must be odd, and 5 <= n <= 100" << endl;
        }
    }
};


int main()
{
    Solution s;
    s.Set_n();
    s.CreateX();

    system("pause");
    return 0;
}
