/*
 * Array.h
 *
 *  Created on: 12 may. 2020
 *      Author: brian
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <initializer_list>


class Array{

public:

	/* Inicializa el arreglo con el tama�o asignado por par�metro */
	Array(int tamanio);

	/* Inicializa el arreglo mediante la asignaci�n
	 * de un arreglo temporal definido con {}
	 */
	Array( std::initializer_list<int> lista);

	/*
	 * Constructor de copia
	 */
	Array( const Array& right);

	~Array();

	/*
	 * Copia el tama�o y el contenido de cada posici�n del vector
	 */
	Array& operator = ( const Array& right);

	/* Permite obtener el contenido de la posici�n "�ndice"
	 * del arreglo
	 */
	int& operator[] (int indice);

	/*
	 * Compara los vectores para saber si son iguales
	 */
	bool operator== ( const Array& right);

	/*
	 * Emite por pantalla el contenido del arreglo
	 */
	void mostrarArray();

private:

	int size;
	int* ptr;

	void redimensionar( const Array& right);

	void copiarArray( const Array& right);

	bool mismoContenido( const Array& right);

	bool mismaCantidadDePosiciones( const Array& right);
};

#endif /* ARRAY_H_ */
