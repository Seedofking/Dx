#include <iostream>
#include <vector>
using namespace std;

void Sort_Arr(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 2; i++) //i走到倒数第二个就行
    {
        int Temp_Val = arr[i];
        int Temp_Pos = i;

        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            if (arr[j] > Temp_Val)
            {
                Temp_Val = arr[j];
                Temp_Pos = j;
            }
        }
        arr[Temp_Pos] = arr[i];
        arr[i] = Temp_Val;
    }
}


int main()
{
    int m1;
    vector<int> mv;

    cout << "请输入一系列整数，直到输入一个非数字字符为止: " << endl;
    while (cin >> m1)
    {
        mv.push_back(m1);
    }
    cin.clear(); //读到最后cin会读不到数置fail = 1
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); //后面输入的int读不了的字符会残留在缓冲区, 要整行丢弃

    int sum = 0;
    for (int x : mv)
    {
        sum += x;
    }
    cout << "Sum: " << sum << endl;

    Sort_Arr(mv);

    cout << "Max: " << mv[0] << endl;


    system("pause");
    return 0;
}
