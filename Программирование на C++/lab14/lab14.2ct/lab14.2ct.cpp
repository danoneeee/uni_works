#include <iostream>
#include <string_view>
#include <vector>
using namespace std;

template<typename Container>
void Print_elements(const Container& container, const string& delimiter) {
    auto elem = container.begin();
    while (elem != container.end()) {
        cout << *elem;
        ++elem;
        if (elem != container.end())
        {
            cout << delimiter;
        }
    }
    cout << '\n';
}

int main() {
    vector<int> number = { 1, 2, 3, 4, 5 };
    vector<string> words = { "a", "b", "c", "d", "e" };
    Print_elements(number, ", ");
    Print_elements(words, "-");
    return 0;
}
