#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

enum Calidad;

class Prenda {
public:
	Prenda() { nombre = ""; cantidad = 0; precio = 0; }
	string nombre;
	int precio, cantidad;
	Calidad calidad;
};