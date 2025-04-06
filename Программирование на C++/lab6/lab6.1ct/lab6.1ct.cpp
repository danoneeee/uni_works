#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");


    ofstream out("poem.txt");

    if (!out) {
        cout << "File imposible to open\n";
        return 1;
    }

    cout << "Введите стихотворение (закончить ввод пустой строкой):\n";

    string line;
    while (getline(cin, line)) {
        if (line.empty()) { 
            break;
        }
        out << line << '\n'; 
    }

    out.close();

    cout << "Стихотворение сохранено в файле poem.txt" << endl;

    return 0;
}