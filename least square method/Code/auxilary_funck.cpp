#include "MNQ.h"


double sumXstep(std::vector<double>& X, const std::vector<double>& X0)
{
	double sum(0);
	for (int i(0); i < X.size(); i++)
	{
		sum += X[i];
	}
	for (int i(0); i < X.size(); i++)
	{
		X[i] *= X0[i];
	}
	return sum;
}

double bCount(const std::vector<double> &X, const std::vector<double> &Y, bool t)
{
	double sum(0);
	if (t == 0)
	{
		for (int i(0); i < X.size(); i++)
		{
			sum += X[i] * Y[i];
		}
	}
	else
	{
		for (int i(0); i < X.size(); i++)
		{
			sum += Y[i];
		}
	}
	return sum;
}

void outFile(std::ifstream& read, std::vector<double>& X0,
	std::vector<double>& Y0, std::vector<std::string>& names)
{
	double x(0);
	double y(0);
	for(int i (0);!read.eof();i++)
	{
		if (names.size() != 0)
		{
			getline(read, names[i], ',');
			//std::cout << names[i] << "\n";
		}

		read >> y;	
		read.ignore(100,',');
		read >> x;
		if (!read) return ;
		Y0.push_back(y);
		X0.push_back(x);
		 
	//	std::cout << X0[X0.size() - 1] << " " << Y0[Y0.size() - 1] << " - " << X0.size() << " " << names.size() << "\n";
	}
}

void inFile(std::ofstream& read, const std::vector<double>& X0, 
	const std::vector<double>& Y0, const  std::vector<std::string> names)
{

	for (int i(0); i<Y0.size(); i++)
	{
		if (names.size() != 0)
		{
			read << names[i];
			read << ',';
		}
		read << X0[i] << ',';
		read << Y0[i]<< '/n';
		if(names.size() == 0)
			read <<std::endl;
	}
}

void countY(const std::vector<double>& X, const std::vector<double>& A, std::vector<double>& Y)
{
	for (int i (0); i < Y.size(); i++)
	{
		for (int g (A.size() - 1); g >0; g--)
		{
			Y[i] += pow(X[i], g) * A[g];
		}
		Y[i]+= A[0];
	}
}

double standart_deviation(const std::vector<double>& y, const std::vector<double>& Y)
{
	double sum(0);
	for (int i (0); i <Y.size(); i++)
	{
		sum += pow((y[i] - Y[i]), 2);
	}
	double q = sqrt(1./(Y.size()-m) * sum);
	return q;
}

void LSM_for_exponent(const std::vector<double>& Y0, const std::vector<double>& X0, std::vector<double>& A, std::vector<double>& Y)
{
	std::vector<double> lnY0(Y0.size());
	for (int i (0); i < Y0.size(); i++)
	{
		lnY0[i] = log(Y0[i]);
	}
	MNQ(X0,lnY0,A);
	std::vector<double> lnY(X0.size());
	countY(X0, A, lnY);
	for (int i(0); i < Y0.size(); i++)
	{
		Y[i] =exp(lnY[i]);
	}
		A[0] = exp(A[0]);
	
}