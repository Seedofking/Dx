#include <iostream>
using namespace std;

void Sort_Arr(int* arr)
{
    for (int i = 0; i < 6; i++) //i走到倒数第二个就行
    {
        int Temp_Val = arr[i];
        int Temp_Pos = i;

        for (int j = i + 1; j < 7; j++)
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
    int arr[7];
    //赋值
    cout << "请为数组赋值, 用空格隔开数字: " << endl;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6];
    //排序
    Sort_Arr(arr);

    //输出
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}
