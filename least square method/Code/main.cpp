#include"MNQ.h"


int main()
{
	std::vector<double> Y0;
	std::vector<double> X0;

	std::vector<std::string> names(9);
	std::ifstream read("A_galaxies.txt");
	if (!read.is_open()) {
		std::cout << "File not found!\n";
		return 1;
	}
	outFile(read,X0,Y0,names);
	read.close();
	m = 1;
	std::vector<double> A(m+1);
	MNQ(Y0,X0,A);
	std::vector<double> Y(X0.size());
	countY(Y0,A,Y);
	std::cout <<std::endl<< "H0= " <<1/ A[1]*3e5 <<" km/s/MPa"<< std::endl << "b= "<<-A[0]/A[1] * 3e5 <<std::endl
		<<"standart deviation: "<<standart_deviation(X0,Y)<<std::endl;
	std::ofstream read1("MNQ.csv");
	inFile(read1, Y0, Y, names);
	std::cout << "distance to the galaxy UGC 02716: " << 0.00127* A[1] + A[0]<<" MPa" << std::endl
		<< "distance to the galaxy UGC 9357: " << 0.01325 * A[1] + A[0] <<" MPa"<< std::endl << std::endl;
	////////////////////////// for exponentional//////////////////////////////////////////////
	std::cout << "////////////////////////// for exponentional//////////////////////////////////////////////" << std::endl;
	std::vector<double> Y01;
	std::vector<double> X01;
	std::vector<std::string> names1(0);
	std::ifstream read2("E_exponent.txt");
	if (!read2.is_open()) {
		std::cout << "File not found!\n";
		return 1;
	}
	outFile(read2, X01, Y01, names1);
	read2.close();
	m = 1;
	std::vector<double> A1(m + 1);
	std::vector<double> Y1(X01.size());
	LSM_for_exponent(X01,Y01,A1,Y1);
	
	std::cout << std::endl << "l= " << A1[0] << std::endl << "b= " <<A1[1] << std::endl
		<< "standart deviation: " << standart_deviation(X01, Y1) << std::endl;
	std::ofstream read4("LSM_for_exponent.csv");
	inFile(read4, Y01, Y1, names1);

	/////////////////////////////////////D_algo///////////////////////////////////////////////////////////////
	std::vector<double> Y02;
	std::vector<double> X02;
	std::vector<std::string> names2(0);
	std::ifstream read5("D_algo.txt");
	if (!read5.is_open()) {
		std::cout << "File not found!\n";
		return 1;
	}
	outFile(read5, Y02, X02, names2);
	read5.close();
	std::ofstream read6("LSM_for_D_algo.csv");
	for (int i (1); i <X02.size(); i++)
	{
		m = i;
		std::vector<double> A2(m + 1);
		std::vector<double> Y2(X02.size());
		MNQ(X02, Y02, A2);
		countY(X02, A2, Y2);
		read6 << "m: " << i << std::endl;
		inFile(read6, X02, Y2, names1);
		read6 << "standart_deviation: " << standart_deviation(Y02, Y2) << std::endl << std::endl;
	}
}