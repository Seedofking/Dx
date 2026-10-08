#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> b = {1, 2, 3, 4, 5, 2, 0, 8, 9};
    vector<unsigned int> c = {1, 2, 3, 4, 5, 2, 0, 8, 9};


    if (a == b)
    {
        cout << "a和b相等" << endl;
    }
    else
    {
        cout << "a和b不相等" << endl;
    }
    
    bool Is_Equal = true;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != c[i])
        {
            Is_Equal = false;
            break;
        }
    }

    if (Is_Equal)
    {
        cout << "b和c相等" << endl;
    }
    else
    {
        cout << "b和c不相等" << endl;
    }


    system("pause");
    return 0;
}

