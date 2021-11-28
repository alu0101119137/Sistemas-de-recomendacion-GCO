#include "Usuario.hpp"
#include "Matriz.hpp"
#include <cmath>


class Recomendacion {

	private:
		Matriz Matriz_;
		std::vector<Usuario> usuarios_;
		unsigned type_;

	public:
		Recomendacion (void);
		Recomendacion (std::string inputFile);
		~Recomendacion (void);


		unsigned getType (void) const;

		void setType (unsigned newType);

		void runProgram (void);
		void generarUsuarios (void);
		void generarVecinos(void);
		float computeSim (unsigned idA, unsigned idB);
		void reajustarVecinos (unsigned id);
		bool contieneVecino (std::vector<Usuario> v, unsigned id);
		int prediccionSimple (unsigned id, unsigned element);
		float prediccionDiferenciaMedia (unsigned id, unsigned element);

};