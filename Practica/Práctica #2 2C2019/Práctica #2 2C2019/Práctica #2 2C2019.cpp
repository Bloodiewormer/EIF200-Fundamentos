// Práctica #1 1C2020.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;  
string mes(int mes) {
	switch (mes) {
	case 1:
		return "Enero";
		break;
	case 2:
		return "Febrero";
		break;
	case 3:
		return "Marzo";
		break;
	case 4:
		return "Abril";
		break;
	case 5:
		return "Mayo";
		break;
	case 6:
		return "Junio";
		break;
	case 7:
		return "Julio";
		break;
	case 8:
		return "Agosto";
		break;
	case 9:
		return "Septiembre";
		break;
	case 10:
		return "Octubre";
		break;
	case 11:
		return "Noviembre";
		break;
	case 12:
		return "Diciembre";
		break;
	default:
		return "Mes no valido";
	break;

	}
}
	bool Vocal(char letra) {
		if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
			return true;
		}
		else {
			return false;
		}
	}
	void HastaN(int N) {
		//for
		cout << "For" << endl;
		for (int i = 1; i <= N; i++) {
			cout << i << endl;
		}
		//while
		cout << "While" << endl;
		while (N > 0) {
			cout << N << endl;
			N--;
			
		}
	}

	int Sumatoria(int N) {
		int suma = 0;
		for (int i = 0; i <= N; i++) {
			suma += i;
		}
		return suma;
	}

class Person {
public:
	string name;
	int age;
	string ID;
	Person(string name, int age, string ID) {
		this->name = name;
		this->age = age;
		this->ID = ID;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setID(string ID) {
		this->ID = ID;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	string getID() {
		return ID;
	}
};

int main() {
	string name;
	int age;
	string ID;
	cout << "Ingrese el nombre de la persona: ";
	cin>> name;
	cout << "Ingrese la edad de la persona: ";
	cin >> age;
	cout << "Ingrese el ID de la persona: ";
	cin >> ID;
	Person person1(name, age, ID);
	cout << "Nombre: " << person1.getName() << endl;
	cout << "Edad: " << person1.getAge() << endl;
	cout << "ID: " << person1.getID() << endl;
	cout << "Ingrese un mes: ";
	int mes1;
	cin >> mes1;
	cout << mes(mes1) << endl;

	cout << "Ingrese una letra: ";
	char letra;
	cin >> letra;
	if (Vocal(letra)) {
		cout << "Es una vocal" << endl;
	}
	else {
		cout << "No es una vocal" << endl;
	}
	cout << "Ingrese un numero: ";
	int N;
	cin >> N;
	cout << "Contando hasta " << N << endl;
	HastaN(N);
	cout << "Ingrese un numero: ";
	int N1;
	cin >> N1;
	cout << "La sumatoria de los numeros hasta " << N1 << " es: " << Sumatoria(N1) << endl;


	
	return 0;




}
	







