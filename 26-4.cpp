#include <iostream>
using namespace std;

struct sArr
{
    int arr[10] = {0};
};

class Solution
{
public:
    static sArr Count(int M, int N)
    {
        struct sArr sarr;
        for (int i = M; i <= N; i++)
        {
            //i
            int temp = i;
            while (temp > 0)
            {
                int one = temp % 10;
                temp /= 10;
                sarr.arr[one]++;
            }
        }
        return sarr;
    }

    static void Print_Arr(int* arr)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    int M, N;
    cout << "Please enter M and N: " << endl;
    cin >> M >> N;

    Solution s;
    sArr sarr = Solution::Count(M, N);
    Solution::Print_Arr(sarr.arr);


    system("pause");
    return 0;
}
