#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    void SetName()
    {
        cout << "Please enter name: " << endl;
        cin >> name;
    }
    void SetScore()
    {
        cout << "Please enter score: " << endl;
        cin >> score;
    }
    // void GetName()
    // {
    //     cout << "Name: " << name << endl;
    // }

    friend double calculateAverageScore(vector<Student> stu);
    friend double calculateAverageScore(vector<Student*> stup);
};

double calculateAverageScore(vector<Student> stu)
{
    int len = stu.size();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += stu[i].score;
    }
    return 1.0 * sum / stu.size();
}

vector<Student> Multi_Set_Stu(int Num)
{
    vector<Student> stu;
    for (int i = 0; i < Num; i++)
    {
        Student st ;    //循环内构造的新对象每次进for循环都会被创建，每次for循环结束都会销毁
        cout << "Enter Student #" << i << " : " << endl;
        st.SetName();
        st.SetScore();

        stu.push_back(st);
    }
    return stu;
}

double calculateAverageScore(vector<Student*> stup)
{
    int len = stup.size();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += stup[i]->score;
    }
    return 1.0 * sum / stup.size();

}

vector<Student*> Multi_Set_Stup(int Num)
{
    vector<Student*> stup;
    for (int i = 0; i < Num; i++)
    {
        Student* p = new Student;
        cout << "Enter Student #" << i << " : " << endl;
        p->SetName();   //栈内存上访问对象用.  堆内存上访问对象用->
        p->SetScore();
        stup.push_back(p);
    }
    return stup;
}

int main ()
{
    int Num;
    double Aver;
    // vector<Student> stu;
    // cout << "Please enter number of students: " << endl;
    // cin >> Num;
    // stu = Multi_Set_Stu(Num);
    //
    // Aver = calculateAverageScore(stu);
    // cout << "The average score is: " << Aver << endl;

    vector<Student*> stup;
    cout << "Please enter number of students: " << endl;
    cin >> Num;
    stup = Multi_Set_Stup(Num);

    Aver = calculateAverageScore(stup);
    cout << "The average score is: " << Aver << endl;


    system("pause");
    return 0;
}