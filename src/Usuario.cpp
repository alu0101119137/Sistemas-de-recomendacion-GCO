#include "../include/Usuario.hpp"

// Constructor de la clase
Usuario::Usuario (void) {
	setId(0);
    setSimType("");
    setMedia();
}

// Destructor de la clase
Usuario::~Usuario (void) {
}

// Getter del ID del usuario
unsigned Usuario::getId (void) const {
	return id_;
}

// Getter del la valoracion del usuario
std::vector<int> Usuario::getValoracion (void) const {
	return valoracion_;
}

// Getter de los vecinos del usuario
std::vector<Usuario> Usuario::getVecinos (void) const {
	return vecinos_;
}

// Getter de la media de las valoracion del usuario
float Usuario::getMedia (void) const {
    return media_;
}

// Getter de la similitud del usuario
std::vector<float> Usuario::getSim (void) const {
    return sim_;
}

// Getter del tipo de similitud
std::string Usuario::getSimType (void) const {
    return simType_;
}

// Setter del ID del usuario
void Usuario::setId (unsigned newId) {
	id_ = newId;
}

// Setter de la valoracion del usuario
void Usuario::setValoracion (std::vector<int> newValoracion) {
	valoracion_ = newValoracion;
}

// Setter de los vecinos del usuario
void Usuario::setVecinos (std::vector<Usuario> newVecinos) {
	vecinos_ = newVecinos;
}

// Setter de la media de las valoraciones del usuario
void Usuario::setMedia (void) {
    float sum = 0;
    unsigned counter = 0;
    for (unsigned i = 0; i < valoracion_.size(); i++) {
        if (valoracion_[i] != -1) {
            counter++;
            sum += valoracion_[i]; 
        }
    }
    media_ = sum / counter;
}

// Setter de la similitud
void Usuario::setSim (std::vector<float> newSim) {
    sim_ = newSim;
}

// Setter del tipo de similitud
void Usuario::setSimType (std::string newSimType) {
    simType_ = newSimType;
}

// Se añade una nueva valoración al vector donde están almacenadas
void Usuario::addValoracion (int newValoracion) {
	valoracion_.push_back(newValoracion);
}

// Se añade un nuevo vecino al vector donde se encuentran todos los vecinos de ese usuario
void Usuario::addVecino (Usuario newVecino) {
	vecinos_.push_back(newVecino);
    setMedia();
}

// Se añade una nueva similitud
void Usuario::addSim (float newSim) {
    sim_.push_back(newSim);
}

// Se imprime por pantalla los datos del usuario
void Usuario::printUsuario (void) {
    std::cout << std::endl << std::endl << "ID usuario: " << getId() << std::endl << "Media: " << media_ <<  std::endl << "Valoraciones: ";
    for (unsigned i = 0; i < getValoracion().size(); i++) {
        std::cout << "\t" << valoracion_[i];
    }
    std::cout << std::endl << "Vecinos: ";
    for (unsigned i = 0; i < getVecinos().size(); i++) {
        std::cout << "\t" << vecinos_[i].getId();
    }
    std::cout << std::endl << "Similitud por " << simType_ << ":";
    for (unsigned i = 0; i < getSim().size(); i++) {
        if (id_ != i) {
            std::cout << std::endl << "\tsim(Persona" << id_ << ", Persona" << i << ") = " << sim_[i];
        }
    }
}