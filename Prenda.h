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
	string nombre;
	int precio, cantidad;
	Calidad calidad;
};