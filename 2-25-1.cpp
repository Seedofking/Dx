#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Solution
{
private:
    int n;
    int width;

public:
    Solution(int n) : n(n)
    {
        width = 2 * n;
    }

    void Create_Row(int r)
    {
        static int count = 0;
        string s;

        for (int i = 1; i <= r; i++)
        {
            count++;
            if (count < 10)
            {
                s += "0";
            }
            s += to_string(count);
        }
        cout << right << setw(width) << s << endl;
    }

    void Create_Matrix()
    {
        for (int row = 1; row <= n; row++)
        {
            Create_Row(row);
        }
    }
};

int main()
{
    int n;
    cout << "ÇëÊäÈë¾ØÕó¹æÄ£: " << endl;
    cin >> n;

    Solution s(n);
    s.Create_Matrix();

    system("pause");
    return 0;
}
