#include <iostream>
#include <set>
#include <fstream>
#include <vector>

class Matriz {

	private:
		unsigned fil_;
		unsigned col_;
		std::vector<std::vector<int>> Matriz_;
		std::string fichero_;

	public:
		Matriz (void);
		Matriz (std::string fichero);
		~Matriz (void);

		unsigned getFil (void) const;
		unsigned getCol (void) const;
		std::vector<std::vector<int>> getMatriz (void) const;
		std::string getFichero (void) const;

		void setFil (unsigned newRows);
		void setCol (unsigned newColumns);
		void setMatriz (std::vector<std::vector<int>> newMatriz);
		void setFichero (std::string newInputFile);

		void lecturaFichero (void);
		void printMatriz (void);
		std::vector<int> generarFilas (std::string line);

};