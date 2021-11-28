#include <vector>
#include <iostream>

class Usuario {

	private:
		unsigned id_;
		std::vector<int> valoracion_;
		std::vector<Usuario> vecinos_;
		std::vector<float> sim_;
		std::string simType_;
		float media_;

	public:

		Usuario (void);
		~Usuario (void);

		unsigned getId (void) const;
		std::vector<int> getValoracion (void) const;
		std::vector<Usuario> getVecinos (void) const;
		float getMedia (void) const;
		std::vector<float> getSim (void) const;
 		std::string getSimType (void) const;

		void setId (unsigned newId);
		void setValoracion (std::vector<int> newValoracion);
		void setVecinos (std::vector<Usuario> newVecinos);
		void setMedia (void);
		void setSim (std::vector<float> newSim);
		void setSimType (std::string newSimType);

		void addValoracion (int newValoracion);
		void addVecino (Usuario newVecino);
		void printUsuario (void);
		void addSim (float newSim);
};