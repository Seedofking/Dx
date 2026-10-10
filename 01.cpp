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
            cout << "*" << endl;
            int space =
        }void Create_Space(int sp)
    {
        for (int i = 1; i <= sp; i++)
        {
            cout << " ";
        }
    }
};


int main()
{
    system("pause");
    return 0;
}
