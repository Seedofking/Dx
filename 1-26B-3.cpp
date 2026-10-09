#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    static void Sort(int* arr)
    {
        for (int i = 0; i < 2; i++) //i走到倒数第二个就行
        {
            int Temp_Val = arr[i];
            int Temp_Pos = i;

            for (int j = i + 1; j < 3; j++)
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

    static void Judge_Triangle()
    {
        int ra, rb, rc;
        int arr[3];

        cout << "请输入三角形三边的值，用空格隔开" << endl;
        cin >> ra >> rb >> rc;

        arr[0] = ra;
        arr[1] = rb;
        arr[2] = rc;

        Sort(arr);

        int a = arr[0];
        int b = arr[1];
        int c = arr[2];

        if (a >= b + c)
        {
            cout << "Not trianngle" << endl;
        }
        else
        {
            if (b * b + c * c == a * a)
            {
                cout << "Right triangle" << endl;
            }
            if (b * b + c * c > a * a)
            {
                cout << "Acute triangle" << endl;
            }
            if (b * b + c * c < a * a)
            {
                cout << "Obtuse triangle" << endl;
            }
            if (a == b || b == c)
            {
                cout << "Isosceles triangle" << endl;
            }
            if (a == b && a == c && b == c)
            {
                cout << "Equilateral triangle" << endl;
            }
        }
    }
};

int main()
{
    Solution::Judge_Triangle();

    system("pause");
    return 0;
}
