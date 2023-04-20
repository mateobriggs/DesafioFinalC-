#pragma once
#include "TiposPrendas.h"

class Pantalon : public Prenda {
public:
	Pantalon(string nombre, Estilo estilo, int precio, Calidad calidad):estilo(estilo){
		this->calidad = calidad;
		this->nombre = nombre;
		this->precio = precio;
	}
	Estilo estilo;
};

class Camisa : public Prenda {
public:
	Camisa(string nombre, Cuello cuello, Manga manga, int precio, Calidad calidad): cuello(cuello), manga(manga){
		this->calidad = calidad;
		this->nombre = nombre;
		this->precio = precio;
	}
	Cuello cuello;
	Manga manga;
};

