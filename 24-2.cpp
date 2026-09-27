#include <iostream>
using namespace std;

class Arr
{
public:
    int arr[5];
    int size = sizeof(arr)/sizeof(arr[0]);
    void Cin_Arr()
    {
        for (int i = 0; i < size; i++)
        {
            cout << " arr[" << i << "] =  ";
            cin >> arr[i];
        }
    }
    void Sort_Arr()
    {
        for (int i = 0; i < size - 1; i++)
        {
            int tempval = arr[i];
            int temppos = i;
            for (int j = i + 1; j < size; j++)
            {
                if ( arr[j] > arr[temppos])
                {
                    tempval = arr[j];
                    temppos = j;
                }

            }
            arr[temppos] = arr[i];
            arr[i] = tempval;
        }
    }
    void Cout_Arr()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
    }

};

int main()
{
    Arr arr1;
    arr1.Cin_Arr();
    arr1.Sort_Arr();
    arr1.Cout_Arr();

    system("pause");
    return 0;
}