#include "prestamo.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Coleccion{
private:
		int cantMaxima;
		int cantPrestamos;
		Prestamo prestamos[200];
	public:
		Coleccion(int cantMaxima){
			this->cantMaxima = cantMaxima;
			this->cantPrestamos = 0;
		}
		
		~Coleccion(){}
		
		void imprimir(){
			for(int i = 0; i < cantPrestamos; i++){
				cout << prestamos[i].toString();
			}
		}
		
		void setCantidad(int cant){
			this->cantPrestamos = cant;
		}
		
		int getCantidad(){
			return cantPrestamos;
		}
		
		Prestamo getPrestamo(int pos){
			return prestamos[pos];
		}
		
		void insertarObjeto(Prestamo prestamo){
			//cout << prestamo.toString() << endl;
			prestamos[cantPrestamos].igualar(prestamo);
			cantPrestamos++;
		}
			
		double porcentajeEnMora(){
			int cantMora = 0;
			for(int i = 0; i < cantPrestamos; i++){
				if(prestamos[i].getDiasAtraso() > 0){
					cantMora++;
				}
			}
			return ((double)cantMora)/((double)cantPrestamos);
		}
		
		bool esConveniente(Coleccion nueva){
			bool pare = false;
			if(porcentajeEnMora() >= nueva.porcentajeEnMora()){
				for(int i = 0; i < nueva.getCantidad() && !pare; i++){
					if(nueva.getPrestamo(i).getDiasAtraso() > 0){
						pare =!(nueva.getPrestamo(i).getArregloDePago());
					}
				}
			}
			return !pare;
		}
		
		void fusionarCartera(Coleccion nueva){
			
			for(int i = 0; i < nueva.getCantidad(); i++){
				prestamos[cantPrestamos] = nueva.getPrestamo(i);
				cantPrestamos++;
			}
			nueva.setCantidad(0);
		}
		
		int beneficionCovid(){
			int cantBeneficio = 0;
			for(int i = 0; i < cantPrestamos; i++){
				if(prestamos[i].getDiasAtraso() > 0){
					if(prestamos[i].getDiasAtraso() < 60){
						prestamos[i].setTasa( prestamos[i].getTasa() - 2);
						cantBeneficio++;
					}else if( prestamos[i].getDiasAtraso() < 90){
						prestamos[i].setTasa( prestamos[i].getTasa() - 1);
						cantBeneficio++;
					}
				}
			}
			return cantBeneficio;
		}
};

