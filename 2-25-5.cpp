#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:
    string color;

public:
    Shape(string c) : color(c)
    {
    }
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(string s, double w, double h) : Shape(s), width(w), height(h)
    {
    }

    double getArea()
    {
        return width * height;
    }
};


int main()
{
    string c;
    double w, h;

    cout << "请输入图形颜色: " << endl;
    cin >> c;

    cout << "请输入矩形的宽和高: " << endl;
    cin >> w >> h;

    Rectangle r(c, w, h);
    cout << "矩形的面积: " << r.getArea() << endl;;


    system("pause");
    return 0;
}
