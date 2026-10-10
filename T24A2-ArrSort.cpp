#include <iostream>
using namespace std;

void Sort(int* arr)
{
    for (int i = 0; i < 4; i++) //i走到倒数第二个就行
    {
        int Temp_Val = arr[i];
        int Temp_Pos = i;

        for (int j = i + 1; j < 5; j++)
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
    int arr[5];
    //赋值
    cout << "原始数组: " << endl;
    for (int i = 0; i < 5; i++)
    {
        int t;
        cout << "arr[" << i << "] = ";
        cin >> t;
        arr[i] = t;
    }

    //排序
    Sort(arr);

    //输出
    cout << "逆序数组: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    system("pause");
    return 0;
}
