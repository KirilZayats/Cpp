#include"SSDE.h"


double const stepMax(1);
double const stepMin(0.1);
bool Euler_implicit_method(difFunc_t& dFy, std::vector<double>& X, matrix_t& Y, const double x0,
	const std::vector<double>& Y0, double& h, const double length) {
	X.push_back(x0);
	Y.push_back(Y0);
	double h_1 = stepMin;
	for (int i(1); X[i - 1] <= (x0 + length); i++) {
		X.push_back(X[i - 1] + h);
		Y.push_back(Y[i - 1]);
		std::vector<double> Y_1(Y[i - 1]);
		if (!newton_metod(dFy, Y[i], X[i], Y[i - 1], h)) {
			if (!newton_metod(dFy, Y[i], X[i], Y[i - 1], h)) {
				std::cout << "Newton" << std::endl;
				return false;
			}
		}
		if (i > 1) {			
			if (!h_step(Y[i - 2], Y[i - 1], Y[i], h, h_1)) {
				i--;
				X.pop_back();
				Y.pop_back();
				continue;
			}
			h_1 = h;
		}
	}
		return true;
	
}


