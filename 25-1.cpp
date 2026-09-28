#include <iostream>
using namespace std;

class Solution
{
private:
    int n;


public:
    Solution(int in) : n(in){}

    void Create_Space(int Space_Num)
    {
        for (int i = 1; i <= Space_Num; i++)
        {
            cout << "  ";
        }
    }

    void Create_Num(int Nums_Num)
    {
        static int Nums_Val = 0;
        for (int i = 1; i <= Nums_Num; i++)
        {
            Nums_Val++;
            string sout = to_string(Nums_Val);
            if (sout.size() == 1)
            {
                sout.insert(0, "0");
            }
            cout << sout;
        }
    }

    void Create_Matrix()
    {
        int Space_Num;
        int Nums_Num;
        for (int i = 1; i <= n; i++)    //一次循环一个Row
        {
            Space_Num = n - i;
            Create_Space(Space_Num);

            Nums_Num = i;
            Create_Num(Nums_Num);
            cout << endl;
        }
    }

};



int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    Solution s(n);
    s.Create_Matrix();

    system("pause");
    return 0;
}