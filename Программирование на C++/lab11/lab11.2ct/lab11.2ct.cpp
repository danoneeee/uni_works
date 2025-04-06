#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;
class Point {
public:
    Point(double x, double y) : x(x), y(y) {}
    double distance_to_origin() const {
        return sqrt(x * x + y * y);
    }
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Point& point) {
        os << "Point(" << point.x << ", " << point.y << ")";
        return os;
    }
    //Перегрузка оператора сравнения
    bool operator<(const Point& other) const {
          return this->distance_to_origin() < other.distance_to_origin();
      }
private:
    double x;
    double y;
};

int main() {
    vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    sort(v.begin(), v.end());

    for (const auto& point : v) {
        cout << point << '\n';
    }

    return 0;
}