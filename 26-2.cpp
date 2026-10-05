#include <iostream>
using namespace std;

int Find_SecMax(int len, int* arr)
{
    for (int i = 0; i <= 1; i++)
    {
        int Temp_Val = arr[i];
        int Temp_Pos = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] > Temp_Val)
            {
                Temp_Val = arr[j];
                Temp_Pos = j;
            }
        }
        arr[Temp_Pos] = arr[i]; //别放if后面啊，循环都没跑完就重置
        arr[i] = Temp_Val;
    }
    return arr[1];
}


int main()
{
    int arr[6] = {8, 9, 3, 4, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    int SecMax = Find_SecMax(len, arr);
    cout << SecMax << endl;

    system("pause");
    return 0;
}
