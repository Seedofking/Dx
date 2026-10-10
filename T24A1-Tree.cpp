#include <iostream>
using namespace std;

class Solution
{
private:
    int layer;
    int mid, trunk;

public:
    Solution(int l) : layer(l)
    {
        mid = 4 * layer + 1;
        trunk = layer + 1;
    }


    void Create_Tree()
    {
        for (int i = 1; i <= layer; i++)
        {
            for (int row = 1; row <= i + 1; row++)
            {
                Create_Row(row);
            }
        }
        Create_Trunk();
        cout << "Merry Christmas !" << endl;
    }

    void Create_Space(int sp)
    {
        for (int i = 1; i <= sp; i++)
        {
            cout << " ";
        }
    }

    void Create_Dot(int d)
    {
        for (int i = 1; i <= d; i++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    void Create_Row(int r)
    {
        int dot = 4 * r - 3;
        int space = mid - (4 * r - 4) - 1;

        Create_Space(space);
        Create_Dot(dot);
    }

    void Create_Trunk()
    {
        int dot = 3;
        int space = mid - 2 - 1;

        for (int i = 1; i <= trunk; i++)
        {
            Create_Space(space);
            Create_Dot(dot);
        }
    }
};


int main()
{
    int lay;
    cout << "请输入你想要圣诞树的层数: " << endl;
    cin >> lay;

    Solution s(lay);

    s.Create_Tree();


    system("pause");
    return 0;
}
