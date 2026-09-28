#include <iostream>
using namespace std;


class Solution
{
    private:
    int arr[7];
    public:
    void Multi_Input_Arr()
    {
        for (int i = 0; i < 7; i++)
        {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    void Sort_Arr()
    {

        for (int i = 0; i < 6; i++)
        {
            int TempPos = i;
            int TempVal = arr[i];
            for (int j = i + 1; j < 7; j++)
            {
                if (arr[j] > TempVal)
                {
                    TempPos = j;
                    TempVal = arr[j];
                }
            }
            arr[TempPos] = arr[i];
            arr[i] = TempVal;

        }
    }

    void Cout_Arr()
    {
        for (int i = 0; i < 7; i++)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
    }
};
int main()
{
    Solution s;
    s.Multi_Input_Arr();
    s.Sort_Arr();
    s.Cout_Arr();

    system("pause");
    return 0;
}