#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s;
    int a, b;
    getline(cin, s);
    stringstream ss;

    ss >> a >> b;

    cout << ss.good() << endl;
    cout << ss.fail() << endl;
    cout << ss.bad() << endl;

    system("pause");
    return 0;
}
