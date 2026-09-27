#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> b{1, 2, 3, 4, 5, 2, 0, 8, 9};
    vector<unsigned int> c{1, 2, 3, 4, 5, 2, 0, 8, 9};

    if (a == b)
    {
        cout << "a = b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] != c[i])
        {
            cout << "b[i] != c[i]" << endl;
            break;
        }
        if (i == b.size() - 1)
        {
            cout << "b == c" << endl;
        }
    }


    system("pause");
    return 0;
}
