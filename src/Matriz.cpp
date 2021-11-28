#include "../include/Matriz.hpp"

Matriz::Matriz (void) {
	setFil(0);
	setCol(0);
	setFichero("");
}

Matriz::Matriz (std::string fichero) {
	setFil(0);
	setCol(0);
	setFichero(fichero);
	lecturaFichero();
}

Matriz::~Matriz (void) {
}

unsigned Matriz::getFil (void) const {
	return fil_;
}

unsigned Matriz::getCol (void) const {
	return col_;
}

std::vector<std::vector<int>> Matriz::getMatriz (void) const {
	return Matriz_;
}

std::string Matriz::getFichero (void) const {
	return fichero_;
}

void Matriz::setFil (unsigned nuevaFil) {
	fil_ = nuevaFil;
}

void Matriz::setCol (unsigned nuevaCol) {
	col_ = nuevaCol;
}

void Matriz::setMatriz (std::vector<std::vector<int>> nuevaMatriz) {
	Matriz_ = nuevaMatriz;
}

void Matriz::setFichero (std::string nuevoFich) {
	fichero_ = nuevoFich;
}

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

void Matriz::printMatriz (void) {
	for (unsigned i = 0; i < fil_; i++) {
		std::cout << "\n|\t";
		for (unsigned j = 0; j < col_; j++) {
			std::cout << Matriz_[i][j] << "\t";
		}
		std::cout << "|";
	} 
}

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
