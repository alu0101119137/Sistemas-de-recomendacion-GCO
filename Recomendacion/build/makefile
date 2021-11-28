# Variables
TIME =$(LOGPATH)$(shell date)
# Object Vars
OBJECTS = main.o Matriz.o Usuario.o Recomendacion.o
# Compilation flags
CFLAGS = -c -std=c++17 -Wall

recomendacion: $(OBJECTS)
	g++ $(OBJECTS) -o recomendacion
	mv recomendacion ../bin

main.o: ../src/main.cpp
	g++ $(CFLAGS) ../src/main.cpp

Matriz.o: ../src/Matriz.cpp ../include/Matriz.hpp
	g++ $(CFLAGS) ../src/Matriz.cpp

Usuario.o: ../src/Usuario.cpp ../include/Usuario.hpp
	g++ $(CFLAGS) ../src/Usuario.cpp

Recomendacion.o: ../src/Recomendacion.cpp ../include/Recomendacion.hpp
	g++ $(CFLAGS) ../src/Recomendacion.cpp


.PHONY: clean
clean:
	rm -rf ../build/*.o
	rm -rf ../bin/*

run:
	../bin/recomendacion ../inputs/input_file.txt

runLog:
	echo "\n\n\nExecuted ${TIME}" >> ../outputs/runDetails.txt
	make run >> ../outputs/runDetails.txt
	echo "You can find full output at outputs/runDetails.txt"
