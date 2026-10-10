#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    string s, g;
    int x = 0, y = 0;
    int arrs[10] = {0};
    int arrg[10] = {0};

public:
    Solution()
    {
        cout << "secret = ";
        cin >> s;
        cout << "guess = ";
        cin >> g;
    }

    void Bulls_and_Cows()
    {
        for (int i = 0; i < s.length(); i++)
        {
            //Detect Bulls
            if (s[i] == g[i])
            {
                x++;
            }
            //Add 0 to 9 for detect Cows
            else
            {
                arrs[s[i] - '0']++;
                arrg[g[i] - '0']++;
            }
        }
 //Detect Cows
        for (int i = 0; i < 10; i++)
        {
            y += arrs[i] < arrg[i] ? arrs[i] : arrg[i];
        }

        cout << x << "A" << y << "B" << endl;
    }
};


int main()
{
    Solution s;
    s.Bulls_and_Cows();

    system("pause");
    return 0;
}
