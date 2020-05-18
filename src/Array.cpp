/*
 * Array.cpp
 *
 *  Created on: 12 may. 2020
 *      Author: brian
 */
#include "Array.h"
#include <iostream>

const int PRIMERA_POSICION = 0;

/* Constructores y Destructores */

Array::Array(int tamanio){

	this->ptr = new int[tamanio];
	this->size = tamanio;
}

/* Constructor con arreglo temporal asignado
 * asignado mediante {}
 */

Array::Array ( std::initializer_list<int> right){

	this->size = right.size();
	this->ptr = new int[ this->size];
	std::copy( right.begin(), right.end(), this->ptr );
}

/*
 * Constructor de copia
 */
Array::Array( const Array& right){

	this->ptr = new int[right.size];
	this->size = right.size;

	this->copiarArray(right);

}

Array::~Array(){

	delete[] this->ptr;
}

/* Visualización de posiciones del arreglo */

void Array::mostrarArray(){

	std::cout<<"{ ";

	for ( int i=PRIMERA_POSICION; i < this->size; i++){

		 std::cout<< this->ptr[i] <<" ";
	}

	std::cout<<"}"<<std::endl;
}

/* Sobrecarga de operadores del Array */

int& Array::operator[]( int indice ){

	return this->ptr[indice];
}

Array& Array::operator= ( const Array& right ){

	if ( &right != this ){

		if( right.size != this->size){
			this->redimensionar( right );
		}
	}else{

		this->copiarArray(right);
	}

	return *this;
}

bool Array::operator== ( const Array& right){

	return ( mismaCantidadDePosiciones(right) && mismoContenido(right) );
}

/*Implementación de metodos privados */

bool Array::mismoContenido( const Array& copia){

	bool sonIguales = true;

	int posicionActual = PRIMERA_POSICION;

	while (  sonIguales &&  ( posicionActual < copia.size ) ){

		if ( this->ptr[posicionActual] != copia.ptr[posicionActual] ){

			sonIguales = false;
		}

		posicionActual++;
	}

	return sonIguales;
}

bool Array::mismaCantidadDePosiciones( const Array& right){

	return ( this->size == right.size );
}

/*
 * Cambia el tamaño del arreglo original y copia el
 * contenido del arreglo enviado por parámetro
 */
void Array::redimensionar( const Array& right) {

	delete[] this->ptr;

	this->size = right.size;
	this->ptr = new int[right.size];

	this->copiarArray(right);
}

/*
 * Copia el contenido del arreglo enviado por parámetro
 */
void Array::copiarArray( const Array& right){

	for ( int i=PRIMERA_POSICION; i<right.size; i++){

		this->ptr[i] = right.ptr[i];
	}
}
