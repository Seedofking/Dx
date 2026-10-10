#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    int n;
    int Dh, Dw, Xh, Xm, Xs;

public:
    Solution(int n) : n(n)
    {
        Dh = n;
        Dw = n;
        Xh = n;
        Xm = Dw + (n + 1) / 2;
        Xs = Dw + 1;
    }

    void Create_DX()
    {
        for (int i = 1; i <= (1 + n) / 2; i++)
        {
            Create_Row(i);
        }
        for (int i = (1 + n) / 2 - 1; i >= 1; i--)
        {
            Create_Row(i);
        }
    }

    void Create_Row(int r)
    {
        int s = 2 * r - 1;
        int Fspace = s - 2;
        int t = (r + 1) / 2 - r;
        int Mspace = t - s - 1;

        cout << "*";


        if (r == 1)
        {
            cout << "*";
            int space = n - 1;
            Create_Space(space);
            cout << "*";
            Create_Space(n - 2);
            cout << "*" << endl;
        }
        else
        {
            cout << "*";
            Create_Space(Fspace);
            cout << "*";
            Create_Space(Mspace);
            cout << "*";
            Create_Space(2 * n - 1);
            cout << "*";

            Create_Space(2 * n - 1);
            cout << "*";
            Create_Space(Mspace);
            cout << "*";
            Create_Space(Fspace);
            cout << "*";
            cout << endl;
        }
    }

    void Create_Space(int sp)
    {
        for (int i = 1; i <= sp; i++)
        {
            cout << " ";
        }
    }
};


int main()
{
    int n;
    cin >> n;

    Solution s(n);
    s.Create_DX();
    system("pause");
    return 0;
}
