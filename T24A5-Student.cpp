#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    void setName()
    {
        cout << "Please enter Name: ";
        cin >> name;
    }

    void setScore()
    {
        cout << "Please enter Score: ";
        cin >> score;
    }

    int getScore()
    {
        return score;
    }
};

double calculateAverageScore(vector<Student*> vs)
{
    int sum = 0;
    int count = 0;
    double aver;

    for (vector<Student*>::iterator it = vs.begin(); it != vs.end(); it++)
    {
        sum += (*it)->getScore();
        count++;
    }
    aver = 1.0 * sum / count;
    return aver;
}

int main()
{
    int num;
    int Average;
    vector<Student*> Stupv;

    cout << "请输入学生数量: ";
    cin >> num;



    for (int i = 1; i <= num; i++)
    {
        Student* Stup = new Student;

        Stup->setName();
        Stup->setScore();

        Stupv.push_back(Stup);
    }

    Average = calculateAverageScore(Stupv);

    cout << "学生平均分数为: " << Average << endl;

    system("pause");
    return 0;
}
