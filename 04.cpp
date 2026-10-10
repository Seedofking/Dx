#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
private:
    int seq[5];
    int process = 0;
    vector<int> t;
    vector<int> id;
    int count = -1;
    bool Activated = false;

public:
    void Handler()
    {
        cout << "请先输入5个数赋值激活顺序, 然后一行输入两个数，输入非数字会终止输入" << endl;
        string s;
        getline(cin, s);

        stringstream ss(s);

        ss >> seq[0] >> seq[1] >> seq[2] >> seq[3] >> seq[4];


        string s2;
        stringstream ss2;
        stringstream ss3;
        while (ss2.good())
        {
            count++;
            int t1, id1;
            getline(cin, s2);
            ss2.str(s2);
            ss2 >> t1 >> id1;

            t.push_back(t1);
            id.push_back(id1);

            Judge();
            ss2.clear();
            ss2.str("");
            s2 = "";
        }
        if (Activated)
        {
            cout << "Activated at " << t[t.size() - 1] << endl;;
        }
        else
        {
            cout << "Miss" << endl;
        }
    }

    void Judge()
    {
        int size = t.size();


        if (id[count] == seq[count])
        {
            process++;
        }
        else
        {
            process = 0;
            id.clear();
            count = -1;
        }
        if (t.size() > 1)
        {
            if ((t[size - 1] - t[size - 2]) > 3)
            {
                process = 0;
            }
        }


        if (process == 5)
        {
            Activated = true;
        }
    }
};


int main()
{
    Solution s;
    s.Handler();


    system("pause");
    return 0;
}
