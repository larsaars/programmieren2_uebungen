#include<iostream>

using namespace std;

class coord_2d {
	int x, y;
public:
	coord_2d(int x, int y) : x(x), y(y) {}

	friend ostream& operator<<(ostream &out, const coord_2d &other) {
		return out << other.x << "," << other.y;
	}
};

void foo(coord_2d a, coord_2d b) {
	cout << "Point a is at " << a
		 << " and point b is at " << b << endl;
}

int main() {
	coord_2d a(1,2);
	coord_2d b(3,4);
	foo(a, b);
	
	return 0;
}
