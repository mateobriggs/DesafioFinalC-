#pragma once
#include "TiposPrendas.h"

class Pantalon : public Prenda {
public:
	Estilo estilo;
};

class Camisa : public Prenda {
public:
	Cuello cuello;
	Manga manga;
};

