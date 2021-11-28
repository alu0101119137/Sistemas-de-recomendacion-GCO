#include "../include/Usuario.hpp"

Usuario::Usuario (void) {
	setId(0);
    setSimType("");
    setMedia();
}

Usuario::~Usuario (void) {
}

unsigned Usuario::getId (void) const {
	return id_;
}


std::vector<int> Usuario::getValoracion (void) const {
	return valoracion_;
}


std::vector<Usuario> Usuario::getVecinos (void) const {
	return vecinos_;
}

float Usuario::getMedia (void) const {
    return media_;
}

std::vector<float> Usuario::getSim (void) const {
    return sim_;
}

std::string Usuario::getSimType (void) const {
    return simType_;
}

void Usuario::setId (unsigned newId) {
	id_ = newId;
}

void Usuario::setValoracion (std::vector<int> newValoracion) {
	valoracion_ = newValoracion;
}

void Usuario::setVecinos (std::vector<Usuario> newVecinos) {
	vecinos_ = newVecinos;
}

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

void Usuario::setSim (std::vector<float> newSim) {
    sim_ = newSim;
}

void Usuario::setSimType (std::string newSimType) {
    simType_ = newSimType;
}


void Usuario::addValoracion (int newValoracion) {
	valoracion_.push_back(newValoracion);
}


void Usuario::addVecino (Usuario newVecino) {
	vecinos_.push_back(newVecino);
    setMedia();
}

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

void Usuario::addSim (float newSim) {
    sim_.push_back(newSim);
}