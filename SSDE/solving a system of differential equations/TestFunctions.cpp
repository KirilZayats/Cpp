#include "SSDE.h"

using std::vector;
#define y1 y[0]
#define y2 y[1]

double f1(double x, vector<double>y) {
	assert(y.size() == 2);
	return -2 * y1 + 4 * y2;
}

double f2(double x, vector<double>y) {
	assert(y.size() == 2);
	return -y1 + 3 * y2;
}

#undef y1
#undef y2

typedef std::function<double(double, vector<double>)> equation;

vector<equation> get_differential_system() {
	return { f1, f2 };
}

double get_initial_x() {
	return 0;
}

vector<double> get_initial_values() {
	return { 3, 2 };
}