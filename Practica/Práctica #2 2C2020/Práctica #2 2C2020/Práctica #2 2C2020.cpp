
#include <iostream>
#include <sstream>
using namespace std;


class Persona
{
public:
	int edad;
	string nombre;
	string ID;

	int getEdad()
	{
		return edad;
	}

	string getNombre()
	{
		return nombre;
	}

	string getID()
	{
		return ID;
	}	

	void setEdad(int edad)
	{
		this->edad = edad;
	}	

	void setNombre(string nombre)
	{
		this->nombre = nombre;
	}

	void setID(string ID)
	{
		this->ID = ID;
	}
	string toString()
	{
		stringstream s;
		s << "Nombre: " << nombre << " Edad: " << edad << " ID: " << ID;
		return s.str();
	}
	

};
string mes(int mes)
{
	string meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio",
	"Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
	return meses[mes-1];
}


int main()
{

	int edad;
	string nombre;
	string ID;
	cout<< "Ingrese la edad de la persona: ";
	cin >> edad;
	cout << "Ingrese el nombre de la persona: ";
	cin >> nombre;
	cout << "Ingrese el ID de la persona: ";
	cin >> ID;

	Persona persona;
	persona.setEdad(edad);
	persona.setNombre(nombre);
	persona.setID(ID);


	cout << persona.toString() << endl;
	

	for(int i = 1; i <= 12; i++)
	{
		cout << mes(i) << endl;
	}
	return 0;
}

