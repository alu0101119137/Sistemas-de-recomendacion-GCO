#include "../include/Recomendacion.hpp"

// Constructor por defecto de la clase
Recomendacion::Recomendacion (void) {
}

// Constructor al que se le pasa el fichero de entrada
Recomendacion::Recomendacion (std::string inputFile) {
	Matriz_.setFichero(inputFile);
	Matriz_.lecturaFichero();
}

// Destructor de la clase
Recomendacion::~Recomendacion (void) {
}

// Getter del tipo de predicción
unsigned Recomendacion::getTipo (void) const {
	return tipo_;
}

// Setter del tipo de predicción
void Recomendacion::setTipo (unsigned newtipo) {
	tipo_ = newtipo;
}

// Pone el programa en funcionamiento
void Recomendacion::runProgram (void) {
	Matriz_.printMatriz();
	generarUsuarios();
	// Crea la similitud
	for (unsigned i = 0; i < usuarios_.size(); i++) {
		for (unsigned j = 0; j < usuarios_.size(); j++) {
			usuarios_[i].addSim(computeSim(i, j));
		}
	}
	// Genera los vecinos y muestra los usuarios con sus datos correspondientes
	generarVecinos();
	for (unsigned i = 0; i < usuarios_.size(); i++) {
		usuarios_[i].printUsuario();
	}

	// Menú de selección del tipo de calculo
	unsigned tipo;
	while (tipo > 3) {
		std::cout << "\n\nSeleccione el tipo de calculo:\n";
		std::cout << "- 1. Prediccion Simple\n";
		std::cout << "- 2. Predicción diferencia de la media\n";
		std::cout << "- 0. Salir\n";
		std::cin >> tipo;
	}
	for (unsigned i = 0; i < usuarios_.size(); i++) {
		for (unsigned j = 0; j < usuarios_[i].getValoracion().size(); j++) {
			if (usuarios_[i].getValoracion()[j] == -1) {
				switch (tipo) {
					case 0:
						std::exit(0);
						break;
					case 1:
						std::cout << std::endl << "Resultado de la predicción simple del usuario " << i << " en el elemento " << j << ": " << prediccionSimple(i, j);
						std::cout << std::endl;
						break;
					case 2:
						std::cout << std::endl << "Resultado de la predicción diferencia de la media del usuario " << i << " en el elemento " << j << ": " << prediccionDiferenciaMedia(i, j);
						std::cout << std::endl;
						break;
				}

			}
		}
	}
}

// Genera los usuarios a partir de la matriz y del tipo de calculo seleccionado
void Recomendacion::generarUsuarios (void) {
	unsigned tipo = 4;
	std::string tipoName = "";
	while (tipo > 3) {
		std::cout << "\n\nSeleccione el tipo de calculo:\n";
		std::cout << "- 1. Correlación de Pearson\n";
		std::cout << "- 2. Distancia Coseno\n";
		std::cout << "- 3. Distancia Euclídea\n";
		std::cout << "- 0. Salir\n";
		std::cin >> tipo;
	}
	setTipo(tipo);
	std::system("clear");
	switch (tipo) {
		case 0:
			std::exit(0);
			break;
		case 1:
			tipoName = "Correlación de Pearson";
			break;
		case 2:
			tipoName = "Distancia Coseno";
			break;
		case 3:
			tipoName = "Distancia Euclídea";
			break;
	}
	for (unsigned i = 0; i < Matriz_.getFil(); i++) {
		Usuario tmp;
		tmp.setId(i);
		for (unsigned j = 0; j < Matriz_.getCol(); j++) {
			tmp.addValoracion(Matriz_.getMatriz()[i][j]);
		}
		tmp.setMedia();
		tmp.setSimType(tipoName);
		usuarios_.push_back(tmp);
	}
}

// Calcula la similitud mediante las formulas correspondientes
float Recomendacion::computeSim (unsigned idA, unsigned idB) {
	float sim = 0;
	if (getTipo() == 1) { // Correlacion Pearson
		float sumUxI = 0.0;
		float sumU = 0.0;
		float sumI = 0.0;
		for (unsigned k = 0; k < usuarios_[idA].getValoracion().size(); k++) {
			if (usuarios_[idA].getValoracion()[k] != -1 and usuarios_[idB].getValoracion()[k] != -1) {
				sumUxI += ((usuarios_[idA].getValoracion()[k] - usuarios_[idA].getMedia()) * (usuarios_[idB].getValoracion()[k] - usuarios_[idB].getMedia()));
				sumU += ((usuarios_[idA].getValoracion()[k] - usuarios_[idA].getMedia()) * (usuarios_[idA].getValoracion()[k] - usuarios_[idA].getMedia()));
				sumI += ((usuarios_[idB].getValoracion()[k] - usuarios_[idB].getMedia()) * (usuarios_[idB].getValoracion()[k] - usuarios_[idB].getMedia()));
			}
		}
		sim = (sumUxI / (std::sqrt(sumI) * std::sqrt(sumU)));
	}
	else if (getTipo() == 2) {	// Distancia Coseno
		float sumUxI = 0.0;
		float sumU = 0.0;
		float sumI = 0.0;
		for (unsigned k = 0; k < usuarios_[idA].getValoracion().size(); k++) {
			if (usuarios_[idA].getValoracion()[k] != -1 and usuarios_[idB].getValoracion()[k] != -1) {
				sumUxI += (usuarios_[idA].getValoracion()[k]  * usuarios_[idB].getValoracion()[k]);
				sumU += (usuarios_[idA].getValoracion()[k]  * usuarios_[idA].getValoracion()[k]);
				sumI += (usuarios_[idB].getValoracion()[k]  * usuarios_[idB].getValoracion()[k]);
			}
		}
		sim = (sumUxI / (std::sqrt(sumI) * std::sqrt(sumU)));
	}
	else if (getTipo() == 3) {	// Distancia Euclidea
		float sum = 0;
		for (unsigned k = 0; k < usuarios_[idA].getValoracion().size(); k++) {
			if (usuarios_[idA].getValoracion()[k] != -1 and usuarios_[idB].getValoracion()[k] != -1) {
				float dist = (usuarios_[idA].getValoracion()[k]  - usuarios_[idB].getValoracion()[k]);
				sum += (dist * dist);
			}
		}
		sim = std::sqrt(sum);
	}
	return sim;
}

// Genera los vecinos de cada usuario
void Recomendacion::generarVecinos (void) {
	// K = 3, para que el mínimo de vecinos generados siempre sea ese
	const unsigned K = 3;
	for (unsigned i = 0; i < usuarios_.size(); i++) {
		for (unsigned j = 0; j < usuarios_[i].getSim().size(); j++) {
			// Caso de Pearson o Coseno
			if (getTipo() == 1 or getTipo() == 2) {
				if (usuarios_[i].getSim()[j] > 0 and i != j) {
					usuarios_[i].addVecino(usuarios_[j]);
				}
			}
		}
		while (usuarios_[i].getVecinos().size() < K) {
			reajustarVecinos(i);
		}
	}
}

// Añade los vecinos al usuario
void Recomendacion::reajustarVecinos (unsigned id) {
	float tmpSim;
	unsigned tmpId = id;
	// Caso de Pearson o Coseno
	if (getTipo() == 1 or getTipo() == 2) {
		tmpSim = -1;
		for (unsigned j = 0; j < usuarios_[id].getSim().size(); j++) {
			if ((id != j) and (usuarios_[id].getSim()[j] > tmpSim) and (contieneVecino(usuarios_[id].getVecinos(), j) == false)) {
				tmpSim = usuarios_[id].getSim()[j];
				tmpId = j;
			}
		}
	}
	// Caso de Euclidea
	else if (getTipo() == 3) {
		tmpSim = 999999;
		for (unsigned j = 0; j < usuarios_[id].getSim().size(); j++) {
			if ((id != j) and (usuarios_[id].getSim()[j] < tmpSim) and (contieneVecino(usuarios_[id].getVecinos(), j) == false)) {
				tmpSim = usuarios_[id].getSim()[j];
				tmpId = j;
			}
		}
	}
	usuarios_[id].addVecino(usuarios_[tmpId]);
}

// Comprobamos si un vecino ya está en el vector vecinos del usuario
bool Recomendacion::contieneVecino (std::vector<Usuario> v, unsigned id) {
	for (unsigned i = 0; i < v.size(); i++) {
		if (v[i].getId() == id) {
			return true;
		}
	}
	return false;
}

// Realiza el cálculo de la predicción simple
int Recomendacion::prediccionSimple (unsigned id, unsigned element) {
	float sumA = 0;
	float sumB = 0;
	for (unsigned i = 0; i < usuarios_[id].getVecinos().size(); i++) {
		unsigned idVecino = usuarios_[i].getVecinos()[i].getId();
		sumA += (usuarios_[id].getSim()[idVecino] * usuarios_[idVecino].getValoracion()[element]);
		if (usuarios_[id].getSim()[idVecino] < 0) {
			sumB += (usuarios_[id].getSim()[idVecino] * -1);
		}
		else {
			sumB += usuarios_[id].getSim()[idVecino];
		}
	}
	int result = (sumA / sumB);
	return result;
}

// Realiza el cálculo de la prediccion con la Diferencia de Media
float Recomendacion::prediccionDiferenciaMedia (unsigned id, unsigned element) {
	float sumA = 0;
	float sumB = 0;
	for (unsigned i = 0; i < usuarios_[id].getVecinos().size(); i++) {
		unsigned idVecino = usuarios_[i].getVecinos()[i].getId();
		sumA += (usuarios_[id].getSim()[idVecino] * (usuarios_[idVecino].getValoracion()[element] - usuarios_[idVecino].getMedia()));
		if (usuarios_[id].getSim()[idVecino] < 0) {
			sumB += (usuarios_[id].getSim()[idVecino] * -1);
		}
		else {
			sumB += usuarios_[id].getSim()[idVecino];
		}
	}
	float result = usuarios_[id].getMedia() + (sumA / sumB);
	return result;
}