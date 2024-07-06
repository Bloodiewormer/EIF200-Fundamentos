#ifndef prestamo123
#define prestamo123
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Prestamo  {
private:
	int numPrestamo; 		// Debe ser consecutivo 
	string  tipoPrestamo; 		// vivienda, carro, personal, salud etc
	int numCuotas; 			// número total de cuotas 
	int diasAtraso;			// Si los días de atraso es 0 el préstamo se encuentra al día, 
	int montoPrestamo;
	float tasa; 			//tasa de interés
	bool arregloDePago;		 // true si tiene arreglo de pago, false no tiene arreglo de pago
public:
	Prestamo( ){       // prestamos con -1 en sus atributos representa prestamos sin definir o no existente
		numPrestamo=-1;
		tipoPrestamo="-1"; 
		numCuotas=-1; 
		diasAtraso=-1;
		montoPrestamo=-1;
		tasa=-1;
		arregloDePago= 0;
	}
Prestamo(int PnumPrestamo,
		 string PtipoPrestamo, 
		 int PnumCuotas, 
		 int PdiasAtraso,
		 int PmontoPrestamo,
		 float Ptasa,
		 bool ParregloDePago)
	{
		numPrestamo= PnumPrestamo;
		tipoPrestamo= PtipoPrestamo; 
		numCuotas= PnumCuotas; 
		diasAtraso= PdiasAtraso;
		montoPrestamo= PmontoPrestamo;
		tasa= Ptasa;
		arregloDePago= ParregloDePago;
	}
	//----------------------------------------------------
	void igualar(Prestamo prestamoNuevo){
		numPrestamo= prestamoNuevo.numPrestamo;
		tipoPrestamo= prestamoNuevo.tipoPrestamo; 
		numCuotas= prestamoNuevo.numCuotas; 
		diasAtraso= prestamoNuevo.diasAtraso;
		montoPrestamo= prestamoNuevo.montoPrestamo;
		tasa= prestamoNuevo.tasa;
		arregloDePago= prestamoNuevo.arregloDePago;
	}
	void setNumPrestamo(int n){   numPrestamo =n;}
	void setTipoPrestamo(string t){    tipoPrestamo=t;}
	void setNumCuotas(int n ){ numCuotas =n;}
	void setDiasAtraso(int d ){diasAtraso =d ;}
	void setMontoPrestamo(int  m){   montoPrestamo=m;}
	void setTasa(float t){ tasa  =t;}
	void setArregloDePago(bool a){ arregloDePago =a  ;}
	int getNumPrestamo(  ) { return numPrestamo;}   
	string getTipoPretamo(  ) { return tipoPrestamo;}   
	int getNumCuotas(  ) { return numCuotas;} 
	int getDiasAtraso(  ) { return diasAtraso;}
	int geMontoPrestamo(  ) { return montoPrestamo;}
	int getTasa(  ) { return tasa;}
	bool getArregloDePago (  ) { return arregloDePago ;}
	//-------------------------------------------------
	string toString() {
		stringstream s;
		s <<"  Num  Prestamo : " << numPrestamo<<endl;
		s<< "     Tipo Prestado: "<<tipoPrestamo <<endl;
		s<< "     Monto: " << montoPrestamo<<endl;
		s<< "     Num cuotas: " << numCuotas<<endl;
		s<< "     Tasa: " << tasa<<endl;
		s<< "     Dias de Atraso: " << diasAtraso<<endl;
		if (diasAtraso > 0 ) // si el préstamo se encuentra al día no es necesario contar con arreglo de pago
		{
			if (arregloDePago==true){
		       s<< "     Prestamo en mora, pero CUENTA con arreglo de pago con el Banco"<<endl;
			}
			else{
				s<< "     Prestamo en mora y NO CUENTA con arreglo de pago con el Banco"<<endl;
			}
		}
		return s.str();
	  }
};
#endif
