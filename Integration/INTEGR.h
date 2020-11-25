#pragma once
#include<iostream>
#include<functional>
#include<vector>
#include<cmath>

using FuncX_t = std::function<double(double)>;
using FuncXY_t = std::function<double(double, double)>;
double Trapezes_method(FuncX_t& Fx,const double& l_border,const double& r_border,int& n);
double  Simpson_method(FuncX_t& Fx,const double& l_border, const double& r_border,int& n);
double c_Simpson_method(FuncXY_t& Fxy, const double& lX_border, const double& rX_border, 
	                    const double& lY_border, const double& rY_border,int& n,int& m);
bool Runge_criteria(double(*func)(FuncX_t&, const double&, const double&, int&),FuncX_t& Fx,
	                const double& l_border, const double& r_border, int& n,const double& eps);
/*c_Simpson_method for curved region */
double c_Simpson_method(FuncXY_t& Fxy, FuncXY_t& rg_func, const double& lX_border, const double& rX_border,
	                    const double& lY_border, const double& rY_border, int& n, int& m);
std::vector<double> range_vector(double l_border, double step, double n);
//creates the vector of values
double step_count(const double& l_border, const double& r_border, const int& n);
//calculate stride length
double Fx(double x);
//x-depend function
double Fxy(double x, double y);
//xy-depend function
double Gxy(double x, double y, FuncXY_t funkArea, FuncXY_t Fxy);
//xy-depend function for curved region

double rg_func(double x, double y);
