# Sistemas de recomendacion
- Andrea Hernández Martín
- Alu0101119137

## Introducción
En esta práctica se ha implementado un sistema de recomendación siguiendo el método de filtrado colaborativo, en mi caso ha sido realizado mediante el lenguaje de programación C++.

## Descripción del código
Para la realización de la práctica, se han creado tres clases: matriz, usuario y recomendación. Las cuales se explica el código implementado a continuación.
- Clase matriz:  
La clase matriz se encarga de leer el fichero de entrada y obtener los datos de él, de forma que se crea una matriz con todos los usuarios y las valoraciones correspondientes, además de imprimir por pantalla la matriz original. La función a destacar en esta clase es la función generarFilas, la cual al obtener los datos de la matriz se encarga de guardar las filas con las valoraciones en blanco con '-' poniendo un -1, en vez del caracter '-', para a la hora de trabajar con el vector no de error.
- Clase usuario:  
La clase usuario es la encargada de almacenar todos los datos de cada usuario, es decir, el identificador de usuario (ID),la valoración realizada por dicho usuario, la media de las valoraciones, los vecinos que tiene ese usuario, la similitud, el tipo de cálculo de similitud que escogemos para realizar el programa y la media de las valoraciones de cada usuario. Además, imprime por pantalla dichos valores una vez calculados. A la hora de calcular la media que es la función que más destaca de esta clase lo que se ha hecho es recorrer el vector de valoración mientras se sumaban sus datos y a continuación dividirlo por el total de datos.
- Clase recomendacion:
La clase recomendación es la más compleja ya que se encarga de poner en funcionamiento el programa y hace las operaciones más complicadas. Por lo que se explican las funciones una a una. En primer lugar, explicar la función *generarUsuarios* la cual se encarga de mostrar por pantalla el menú de selección del tipo de cálculo que queremos realizar (correlación de Pearson, distancia coseno o distancia euclídea) y una vez escogida la opción, se crean los usuarios a partir de la matriz obtenida anteriormente. La siguiente función es *computeSim*, que se encarga de calcular la similitud mediante las fórmulas aprendidas en clase, según la opción escogida en la función de *generarUsuarios*. Otra función es *generarVecinos* la cual por cada usuario genera sus vecinos llamando a la función *addVecinos* de la clase usuario y contempla el caso de que si un usuario tiene menos de 3 vecinos,le añade los mejores vecinos obtenidos hasta llegar a tener 3. Esta función por último llama a la función *reajustarVecinos*

