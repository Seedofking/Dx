#include <iostream>
#include <string>
using namespace std;

class Shape
{
private:
    string color;

public:
    Shape(string Color_In) : color(Color_In)
    {
    }
};

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(string C, int w, int h) : Shape(C), width(w), height(h)
    {
    }

    int getArea()
    {
        int area = width * height;


        return area; //别忘了return啊
    }
};


int main()
{
    string cl;
    int w, h;
    cout << "Please enter the color: " << endl;
    cin >> cl;
    cout << "Please enter the width and height: " << endl;
    cin >> w >> h;
    Rectangle rect(cl, w, h);

    int S = rect.getArea();
    cout << "Area = " << S << endl;


    system("pause");
    return 0;
}
