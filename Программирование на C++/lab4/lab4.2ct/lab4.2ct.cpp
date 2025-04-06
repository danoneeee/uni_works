#include <iostream>

using namespace std;



bool Input(int& a, int& b) {
    if (!(cin >> a >> b) || (a == 0)) {
        cin.clear();
        return false;
    }
    return true;
}


int main()
{
    int a, b;
    if (Input(a, b) == false)
    {
        cerr << "error";
        return 1;
    }

    int s = a + b;
    cout << "s = " << s << endl;
    return 0;
}

