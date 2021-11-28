#include "../include/Matriz.hpp"

// Constructor por defecto de la clase matriz
Matriz::Matriz (void) {
	setFil(0);
	setCol(0);
	setFichero("");
}

// Constructor al que se le pasa el fichero de entrada de la matriz
Matriz::Matriz (std::string fichero) {
	setFil(0);
	setCol(0);
	setFichero(fichero);
	lecturaFichero();
}

// Destructor de la clase
Matriz::~Matriz (void) {
}

// Getter de las filas
unsigned Matriz::getFil (void) const {
	return fil_;
}

// Getter de las columnas
unsigned Matriz::getCol (void) const {
	return col_;
}

// Getter de la matriz
std::vector<std::vector<int>> Matriz::getMatriz (void) const {
	return Matriz_;
}

// Getter del fichero de entrada
std::string Matriz::getFichero (void) const {
	return fichero_;
}

// Setter de las filas
void Matriz::setFil (unsigned nuevaFil) {
	fil_ = nuevaFil;
}

// Setter de las columnas
void Matriz::setCol (unsigned nuevaCol) {
	col_ = nuevaCol;
}

// Setter de la matriz
void Matriz::setMatriz (std::vector<std::vector<int>> nuevaMatriz) {
	Matriz_ = nuevaMatriz;
}

// Setter del fichero de entrada
void Matriz::setFichero (std::string nuevoFich) {
	fichero_ = nuevoFich;
}

// Función que lee el fichero introducido y guarda los datos que queremos
void Matriz::lecturaFichero (void) {
	std::ifstream file(fichero_, std::ios::in);
	if (file.fail()) {
		std::cout << std::endl << "Error, no se pudo abrir el fichero." << std::endl;
		exit(1);
	}
	while (!file.eof()) {
		std::string line = "";
		std::getline(file, line);
		if (line.length() > 1) {
			Matriz_.push_back(generarFilas(line));
		}
	}
	setFil(Matriz_.size());
	setCol(Matriz_[0].size());
	file.close();
}

// Imprime por pantalla la matriz
void Matriz::printMatriz (void) {
	for (unsigned i = 0; i < fil_; i++) {
		std::cout << "\n|\t";
		for (unsigned j = 0; j < col_; j++) {
			std::cout << Matriz_[i][j] << "\t";
		}
		std::cout << "|";
	} 
}

// Función que genera un vector con las filas de las columnas,
// la cual sirve para obtener el número de usuarios del programa
std::vector<int> Matriz::generarFilas (std::string line) {
	std::vector<int> result;
	std::string tmp = "";
	for (unsigned i = 0; i < line.length(); i++) {
		if ((line[i] == ' ' or line[i] == '\r' or line[i] == '\n') and (tmp.length() > 0)) {
			result.push_back(std::stoi(tmp));
			tmp = "";
		}
		else if (line[i] == '-') {
			tmp += "-1";
		}
		else {
			tmp += line[i];
		}
	}
	if (tmp.length() > 0)
		result.push_back(std::stoi(tmp));
	return result;
}
