#pragma once
#include "SLE.h"

extern int m;//степень полинома
void outFile(std::ifstream& read, std::vector<double>& X0, std::vector<double>& Y0,
	std::vector<std::string>& names);
void inFile(std::ofstream& read, const std::vector<double>& X0,const std::vector<double>& Y0,
	const  std::vector<std::string> names);
bool MNQ(const std::vector<double>& X0, const std::vector<double>& Y0, std::vector<double>& A);
double sumXstep(std::vector<double>& X, const std::vector<double>& X0);
double bCount(const std::vector<double>& X, const std::vector<double>& Y,bool t=0);
void countY(const std::vector<double>& X,const std::vector<double>& A,std::vector<double>& Y);//для линейной
double standart_deviation(const std::vector<double>& y, const std::vector<double>& Y);
void LSM_for_exponent(const std::vector<double>& Y0, const std::vector<double>& X0, std::vector<double>& A,std::vector<double>& Y);