// Práctica #1 1C2020.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;  
float prom(float num1, float num2) {
	return (num1 + num2) / 2;
}
class Pet {
public:
	string tipo;
	string raza;
	int edad;
	string razon;
};
int main()
{
	Pet pet1;
	pet1.tipo = "Perro";
	pet1.raza = "Labrador";
	pet1.edad = 5;
	pet1.razon = "Vacunación";
	cout << "Tipo de mascota: " << pet1.tipo << endl;
	cout << "Raza de la mascota: " << pet1.raza << endl;
	cout << "Edad de la mascota: " << pet1.edad << endl;
	cout << "Razón por la que ingresó: " << pet1.razon << endl;
	cout << "Promedio de 5 y 6: " << prom(5, 6) << endl;
	return 0;
}






