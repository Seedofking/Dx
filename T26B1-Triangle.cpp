#include<iostream>
using namespace std;

class Solution
{
private:
    int layer;
    int mid;

public:
    Solution(int n) : layer(n)
    {
        mid = layer;
    }

    void Create_Space(int sp)
    {
        for (int i = 1; i <= sp; i++)
        {
            cout << " ";
        }
    }

    void Create_Num(int r)
    {
        for (int i = 1; i <= r; i++)
        {
            cout << i;
        }
        for (int j = r - 1; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }

    void Create_Row(int ro)
    {
        int space = mid - ro;
        Create_Space(space);
        Create_Num(ro);
    }

    void Create_Triangle()
    {
        for (int i = 1; i <= layer; i++)
        {
            Create_Row(i);
        }
    }
};


int main()
{
    int l;
    cout << "请输入三角形的行数: ";
    cin >> l;

    Solution s(l);
    s.Create_Triangle();


    system("pause");
    return 0;
}
