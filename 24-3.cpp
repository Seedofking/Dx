#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    string secret, guess;
    int A = 0, B = 0;
    int len;
    vector<int> secret_c;
    vector<int> guess_c;
    vector<int> DO;

    struct Zero_Nine
    {
        int arr[10];
    }Num_Arr;
    typedef Zero_Nine Secret_n;
    typedef Zero_Nine Guess_n;
    Secret_n secret_n;
    Guess_n guess_n;

public:
    void Cin()
    {
        cout << "secret = " << endl;
        cin >> secret;
        cout << "guess = " << endl;
        cin >> guess;
        secret_c = To_One(secret);
        guess_c = To_One(guess);
        len = secret_c.size();
    }

    void Bulls_and_Cows()
    {
        secret_n = To_Num(secret_c);
        guess_n = To_Num(guess_c);

        for (int i = 0; i <= 9; i++)
        {
            int min = 0;
            if (secret_n.arr[i] != 0 && guess_n.arr[i] != 0)
            {
                min = secret_n.arr[i] > guess_n.arr[i] ? guess_n.arr[i] : secret_n.arr[i];
            }
            B += min;
            //min = 0;  开头的min = 0每一次进for都会执行，结尾这句多余
        }
        for (int j = 0; j < len; j++)
        {
            if (secret_c[j] == guess_c[j])
            {
                A++;
                B--;
            }
        }

        cout << A << "A" << B << "B" << endl;
    }
    // vector<int> To_One(int n)        //0111这输入的这个东西压根就不是一个数，不能拿数来处理啊
    // {
    //     DO.clear();
    //     int m = n;
    //     int Ten_Num = 0;
    //
    //     while (m != 0)
    //     {
    //         m = m / 10;
    //         Ten_Num++;
    //     }
    //
    //     for (int i = 0; i < Ten_Num; i++)
    //     {
    //         int Temp_One = n % 10;
    //         n /= 10;
    //         DO.insert(DO.begin(),Temp_One);
    //     }
    //     return DO;
    // }
    vector<int> To_One(string s)
    {
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
        {
            v.push_back(s[i] - '0');    //这样能让字符型的数据变成整型数据，与to_string(int n)相反
        }
        return v;
    }

    struct Zero_Nine To_Num(vector<int>& v) //这一大坨To_Num和To_One完全可以用一句话 ++secret_n[ secret_c[i] - '0']来替代
    {
        for (int i = 0; i < 10; i++)
        {
            Num_Arr.arr[i] = 0;
        }
        for (int i = 0; i < v.size(); i++)
        {
            switch (v[i])
            {
            case 0:
                Num_Arr.arr[0]++;
                break;
            case 1:
                Num_Arr.arr[1]++;
                break;
            case 2:
                Num_Arr.arr[2]++;
                break;
            case 3:
                Num_Arr.arr[3]++;
                break;
            case 4:
                Num_Arr.arr[4]++;
                break;
            case 5:
                Num_Arr.arr[5]++;
                break;
            case 6:
                Num_Arr.arr[6]++;
                break;
            case 7:
                Num_Arr.arr[7]++;
                break;
            case 8:
                Num_Arr.arr[8]++;
                break;
            case 9:
                Num_Arr.arr[9]++;
                break;
            default:
                cout << "Error" << endl;
            }
        }
        return Num_Arr;


    }

};




int main()
{
    Solution s;
    s.Cin();
    s.Bulls_and_Cows();

    system("pause");
    return 0;
}