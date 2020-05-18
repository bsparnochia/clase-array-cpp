/*
 * main.cpp
 *
 *  Created on: 12 may. 2020
 *      Author: brian
 */

#include "Array.h"
#include <iostream>

int main(){

	/* defino un arreglo con tamaño 2 */
	Array a(2);

	/* arreglo inicializado por vector temporal */
	Array b = { 6,3,7};

	/* copia de b en c */
	Array c (b);

	/* asigno un vector "b" a "a" */
	a=b;

	/* asigno un vector temporal */
	a = { 1, 2, 33, 44, 5 };

	c.mostrarArray();
	a.mostrarArray();

	/* contenido de c en la posición 2 */
	std::cout<<c[2]<<std::endl;

	/* comparaciones */
	std::cout<< (c == b) <<std::endl;
	std::cout<< (a == b) <<std::endl;

	return 0;
}


