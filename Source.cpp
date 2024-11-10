#include"Header.h"


int main() {
	std::cout << "size of vector x:";
	std::size_t size;
	std::cin >> size;
	assert(size > 0);
	std::vector<double>x;
	x.resize(size);
	std::vector<double>f;
	f.resize(size);
	//xi's elements
	std::cout << "elements for vector x:\n";
	for (size_t i = 0; i < size; i++) {
		std::cin >> x[i];
	}
	//fi's elements
	std::cout << "elements for vector f:\n";
	for (size_t i = 0; i < size; i++) {
		std::cin >> f[i];
	}
	std::vector<std::vector<double>>a(size);
	
	for (size_t j = 0; j < x.size(); j++) {
		for (size_t i = 0; i < x.size(); i++) {


			a[j].push_back(std::pow(x[j], i));

		}


	}

	printmatrix(a, f);

	gauss(a, f);
	
	

	

	
}