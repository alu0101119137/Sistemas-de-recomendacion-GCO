#include "Usuario.hpp"
#include "Matriz.hpp"
#include <cmath>


class Recomendacion {

	private:
		Matriz Matriz_;
		std::vector<Usuario> usuarios_;
		unsigned tipo_;

	public:
		Recomendacion (void);
		Recomendacion (std::string inputFile);
		~Recomendacion (void);


		unsigned getTipo (void) const;

		void setTipo (unsigned newTipo);

		void runProgram (void);
		void generarUsuarios (void);
		void generarVecinos(void);
		float computeSim (unsigned idA, unsigned idB);
		void reajustarVecinos (unsigned id);
		bool contieneVecino (std::vector<Usuario> v, unsigned id);
		int prediccionSimple (unsigned id, unsigned element);
		float prediccionDiferenciaMedia (unsigned id, unsigned element);

};