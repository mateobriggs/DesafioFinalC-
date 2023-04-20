#include "Tienda.h"

void Tienda::iniciarCantidades() {
	cantidades[0] = 100;
	cantidades[1] = 100;
	cantidades[2] = 150;
	cantidades[3] = 150;
	cantidades[4] = 75;
	cantidades[5] = 75;
	cantidades[6] = 175;
	cantidades[7] = 175;
	cantidades[8] = 750;
	cantidades[9] = 750;
	cantidades[10] = 250;
	cantidades[11] = 250;
}

int Tienda::controladorDeStockCamisas(string input2a, string input2b, string input3) {
	if (input2a == "1") {
		if (input2b == "1") {
			if (input3 == "1") return cantidades[0];
			
			else return cantidades[1];
		}
		else {
			if (input3 == "1") return cantidades[2];
			else return cantidades[3];
		}
	}
	else {
		if (input2b == "1") {
			if (input3 == "1") return cantidades[4];

			else return cantidades[5];
		}
		else {
			if (input3 == "1") return cantidades[6];
			else return cantidades[7];
		}
	}
}

int Tienda::controladorDeStockPantalones(string input2, string input3) {
	if (input2 == "1") {
		if (input3 == "1") return cantidades[8];
		else return cantidades[9];
	}
	else {
		if (input3 == "1") return cantidades[10];
		else return cantidades[11];
	}
}