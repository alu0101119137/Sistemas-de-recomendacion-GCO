#include "../include/Recomendacion.hpp"

int main (int argc, char* argv[]) {
	if (argc == 2) {
		Recomendacion myRecomendacion(argv[1]);
		myRecomendacion.runProgram();
	}
	else {
		std::cout << "Modo de empleo: " << std::endl;
		std::cout << "./recomendacion 'inputFile.txt'" << std::endl;
	}
	
	return 0;
}	
