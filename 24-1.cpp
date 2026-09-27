#include <iostream>
using namespace std;

class Tree
{
public:
    int layer, row, dot, space, trunk;

    Tree(int layer)
    {
        this->layer = layer;
    }


    void Create_Leaves()
    {
        //layer
        int mid = 4 * layer + 1;
        //row
        for (int i = 1; i <= layer; i++)
        {
            row = i + 1;
            //space & dot
            for (int j = 1; j <= row; j++)
            {
                dot = j * 4 - 3;
                space = mid - dot;
                for (int k = 1; k <= space; k++)
                {
                    cout << " ";
                }
                for (int k = 1; k <= dot; k++)
                {
                    cout << "*" << " ";
                }
                cout << endl;
            }
        }
    }
    void Create_Trunk()
    {
        int mid = 4 * layer + 1;
        trunk = layer + 1;
        for (int i = 1; i <= trunk; i++)
        {
            space = mid - 3;
            dot = 3;
            for (int j = 1; j <= space; j++)
            {
                cout << " ";
            }
            for (int k = 1; k <= dot; k++)
            {
                cout << "*" << " ";
            }
            cout << endl;

        }
    }
    void Create_Tree()
    {
        Create_Leaves();
        Create_Trunk();
        cout << "Merry Christmas !" << endl;
    }
};



int main()
{
    int la;
    cout << "请输入你想要圣诞树的层数: " << endl;
    cin >> la;

    Tree tree(la);
    tree.Create_Tree();

    system("pause");
    return 0;
}