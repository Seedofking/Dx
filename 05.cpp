#include <iostream>
#include <string>
using namespace std;

class Motor
{
private:
    string name;
    double P_MAX, V_MAX, T_MAX;

public:
    Motor(string n, double p, double v, double t) : name(n), P_MAX(p), V_MAX(v), T_MAX(t)
    {
    }

    string getName()
    {
        return name;
    }

    double getPMax()
    {
        return P_MAX;
    }

    double getVMax()
    {
        return V_MAX;
    }

    double getTMax()
    {
        return T_MAX;
    }

    void showInfo()
    {
        cout << name << " P_Max= " << getPMax() << " V_Max=" << getVMax() << " T_Max=" << getTMax() << endl;
    }

    virtual void setCommand(double p, double v, double t) = 0;
};

class DM_Motor : public Motor
{
private:
    double position = 0, velocity = 0, torque = 0;

public:
    DM_Motor(string n, double p, double v, double t) : Motor(n, p, v, t)
    {
    }

    void setCommand(double p, double v, double t)
    {
        if (p > getPMax())
        {
            p = getPMax();
        }
        if (p < -getPMax())
        {
            p = -getPMax();
        }
        if (v > getVMax())
        {
            v = getVMax();
        }
        if (v < -getVMax())
        {
            v = -getVMax();
        }

        if (t > getTMax())
        {
            t = getTMax();
        }
        if (t < -getTMax())
        {
            t = -getTMax();
        }

        position = p;
        velocity = v;
        torque = t;
    }

    void showCommand()
    {
        cout << getName() << " position=" << position << " velocity=" << velocity << " torque=" << torque << endl;
    }
};


int main()
{
    DM_Motor DM8009("DM8009", 12.5, 45, 54);
    DM8009.showInfo();
    DM_Motor DM4310("DM4310", 12.5, 30, 10);

    DM4310.showInfo();

    DM8009.setCommand(20, 50, 60);
    DM4310.setCommand(20, 50, 60);
    DM8009.showCommand();
    DM4310.showCommand();

    DM4310.setCommand(-20, -40, -20);
    DM8009.showCommand();
    DM4310.showCommand();


    system("pause");
    return 0;
}
