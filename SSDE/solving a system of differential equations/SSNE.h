#pragma once
#include"SSLE.h"

using SFunction_t = std::vector<std::function<double(std::vector<double>)>>;
using function_t = std::function<double(std::vector<double>)>;
using func_t = std::vector <std::function<double(double, std::vector<double>)>>;
using functions_t = std::vector<func_t>;
bool newton_metod(func_t dFy, std::vector<double>& Y ,int& iter);
double derivative(lb_t f, std::vector<double> Y, int numb_cord, int func_cord);
bool max_check(std::vector<double> x, std::vector<double> delX);
//check norm of vector
bool b_check(std::vector<double> b);