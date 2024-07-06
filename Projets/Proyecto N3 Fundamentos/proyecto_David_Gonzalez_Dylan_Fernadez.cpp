//Trabajo hecho Por David Gonzalez Cordoba y Dylan Fernadez

#include<iostream>
#include<sstream>

using namespace std;
const int maxMat=25;

class Bateria {
private:
	int tipo;
	int modelo;
	int annio;
	int CostoDeProduccion;
	int filas;
	int columna;
	
public:
	int voltios[maxMat][maxMat];
	int amperios[maxMat][maxMat];
	int Condicion[maxMat][maxMat];
	
	Bateria();
	Bateria(int,int,int,int,int,int,int,int,int);
	Bateria bat1();
	Bateria bat2();
	
	void setfilas(int);
	void setcolumnas(int);
	void setTipo(int);
	void setModelo(int);
	void setAnnio(int);
	void setCostoDeProduccion(int);
	void setVoltios(int);
	void setAmperios(int);
	void setCondicion(int);
	
	int getfilas();
	int getcolumnas();
	int getTipo();
	int getModelo();
	int getAnnio();
	int getCostoDeProduccion();
	int getVoltios();
	int getAmperios();
	int getCondicion();
	
	string toStringBateria();
	string toStringDetalleCelda();
	void llenarAleatorio();
	void estadoDeLaBateria();
	void inicioDeSistema();
	void modificarCelda();
	void modificarTamanoBateria();
	void cambiarBateria(Bateria); 
	string compararBaterias(Bateria);	

};
Bateria::Bateria(){//bateria default
	tipo=0;
	modelo=0;
	annio=0;
	CostoDeProduccion=0;
	filas=0;
	columna=0;
	
}
Bateria::Bateria(int tp,int md,int an,int cp,int fil,int col,int vol,int amp,int con){//bateria parametrisada
	filas=fil;
	columna=col;
	tipo= tp;
	modelo= md;
	annio= an;
	CostoDeProduccion= cp;
}
//zona de gets y sets
void Bateria::setfilas(int fil){filas=fil;}
void Bateria::setcolumnas(int col){columna=col;}
void Bateria::setTipo(int tp){tipo= tp;}
void Bateria::setModelo(int md){modelo= md;}
void Bateria::setAnnio(int an){annio= an;}
void Bateria::setCostoDeProduccion(int cp){CostoDeProduccion= cp;}

int Bateria::getfilas(){return filas;}
int Bateria::getcolumnas(){return columna;}
int Bateria::getTipo(){return tipo;}
int Bateria::getModelo(){return modelo;}
int Bateria::getAnnio(){return annio;}
int Bateria::getCostoDeProduccion(){return CostoDeProduccion;}

void Bateria::inicioDeSistema(){
	int fil,col,tp,md,an,cp;
	do{
		cout<<"Ingrese las filas habilitadas: "<<endl;
		cin>>fil;
		setfilas(fil);
		if(fil<0||fil>25){
			cout<<"has ingresado un dato no valido";
			system("pause");
		}
	}while(fil<0||fil>25);
	do{
		cout<<"Ingrese las columna habilitadas: "<<endl;
		cin>>col;
		setcolumnas(col);
		if(col<0||col>25){
			cout<<"has ingresado un dato no valido";
			system("pause");
		}
	}while(col<0||col>25);
	cout<<"Ingrese el costo de cada celda: "<<endl;
	cin>>cp;
	setCostoDeProduccion(cp);
	cout<<"Ingrese el modelo de cada celda: "<<endl;
	cin>>md;
	setModelo(md);
	cout<<"Ingrese el annio de cada celda: "<<endl;
	cin>>an;
	setAnnio(an);
	cout<<"Ingrese el Tipo de cada celda: "<<endl;
	cin>>tp;
	setTipo(tp);
	
	for (int f = 0; f <25; f++){
		for (int c = 0; c < 25; c++){
			Condicion[f][c]=-1;
			amperios[f][c] = -1;
			voltios[f][c]=-1;
			for (int f = 0; f <fil; f++){
				for (int c = 0; c <col ; c++){
					Condicion[f][c] = 1;
					amperios[f][c] = 12;
					voltios[f][c]=12;
				}
			}
		}
	}
}

string Bateria::toStringBateria(){
	system("cls");
	Bateria bat;
	stringstream s;
	cout<<"--------------Bateria--------------"<<endl;
	cout<<"Tipo: "<<getTipo()<<endl;
	cout<<"Modelo: "<<getModelo()<<endl;
	cout<<"Annio: "<<getAnnio()<<endl;
	cout<<"Costo de Produccion: "<<getCostoDeProduccion()<<endl;
	
	cout<<"Filas Habilitadas: "<<getfilas()<<endl;
	cout<<"Columnas Habilitadas: "<<getcolumnas()<<endl;
	
	cout << "Imprimir la matriz ." << endl;
	for (int f = 0; f < 25; f++) {
		for (int c = 0; c < 25; c++){
			cout <<  Condicion[f][c];
			if (Condicion[f][c]==-1)
				cout << " ";
			else
				cout <<"  ";
		}
		cout << endl; 
	}
	
	return s.str();
} 	
string Bateria::toStringDetalleCelda(){
	int fil,col;
	cout<<"Ingrese la posicion que desea ver"<<endl;
	cout<<"Ingrese la fila: "<<endl;
	cin>>fil;
	cout<<"Ingrese la columna: "<<endl;
	cin>>col;
	system("cls");
	stringstream s;
	for (int f = 0; f < 25; f++) {
		for (int c = 0; c < 25; c++){
			if(fil-1==f && col-1==c){
				cout <<"La condicion de la posicion "<<fil<<","<<col<<" es: "<< Condicion[f][c] <<endl;
				cout<<"Voltios: "<< voltios[f][c]<<endl;
				cout<<"Amperios: "<< amperios[f][c]<<endl;
			}
		}
		cout << endl; 
	}
	return s.str();
}
void Bateria::llenarAleatorio(){
	int fila=0;
	int colun=0;
	for (int f = 0; f <25; f++){
		for (int c = 0; c < 25; c++){
			Condicion[f][c] = -1;
		}
	}
	cin>>colun;
	cin>>fila;
	int num=0;
	for (int f = 0; f <colun; f++){
		for (int c = 0; c <fila ; c++){
			num=0+rand()%2;
			Condicion[f][c] = num;
		}
	}
	cout << "Imprimir la matriz ." << endl;
	for (int f = 0; f < 25; f++) {
		for (int c = 0; c < 25; c++){
			cout << Condicion[f][c];
			if (Condicion[f][c]==-1)
				cout << " ";
			else
				cout <<"  ";
		}
		cout << endl; 
	}
	for (int f = 0; f < 25; f++) {
		for (int c = 0; c < 25; c++){
			if (Condicion[f][c] == 1){
				voltios[f][c]=12;
				amperios[f][c]=12;
			}
		}
	}
	for (int f = 0; f < 25; f++) {
		for (int c = 0; c < 25; c++){
			if (Condicion[f][c] == 0){
				voltios[f][c]=0;
				amperios[f][c]=0;
			}
		}
	}
}
void Bateria::modificarCelda(){
	int fil = 0,col = 0,amp=0,vol=0,con=0;
	cout<<"ingrese la celda que descea modificar"<<endl;
	cout<<"Fila"<<endl;
	cin>>fil;
	cout<<"Columnas"<<endl;
	cin>>col;
	system("cls");
	
	cout<<"usted a ingresado la siguiente celda"<<endl;
	cout << "[" << fil << "][" << col << "]"<<endl;
	cout <<"ingrese los amperios de la celda: "<<"[" << fil << "][" << col << "]"<<endl;
	cin>>amp;
	for (int f=0;f<25;f++) {
		for (int c=0;c<25;c++) {
			if(f==fil-1&&c==col-1){
				amperios[f][c]=amp;
			}
		}
	}
	cout <<"ingrese los voltios de la celda: "<<"[" << fil << "][" << col << "]"<<endl;
	cin>>vol;
	for (int f=0;f<25;f++) {
		for (int c=0;c<25;c++) {
			if(f==fil-1&&c==col-1){
				voltios[f][c]=vol;//no lo hace
			}
		}
	}
	cout <<"ingrese la Condicion de la celda: "<<"[" << fil << "][" << col << "]"<<endl;
	cin>>con;
	if(con==1||con==0){
		for (int f=0;f<25;f++) {
			for (int c=0;c<25;c++) {
				if(f==fil-1&&c==col-1){
					Condicion[f][c]=con;//no lo hace
				}
			}
		}	
	}else if(con==-1){
		cout<<"apagar una celda no es posible en este caso"<<endl;
	}else{
		cout<<"usted igreso un numero no valido"<<endl;
	}
}
void Bateria::estadoDeLaBateria(){
	int off=0,on=0,mal=0;
	for (int f = 0; f < 25; f++) {
		for (int c = 0; c < 25; c++){
			if (Condicion[f][c]==-1){
				off=off+1;
			}
			if (Condicion[f][c]==0){
				mal=mal+1;}
			if (Condicion[f][c]==1){
				on = on+1;
			}
		}
	}
	cout<<"hay un total de " << on  <<" encendidas"<<endl;
	cout<<"hay un total de " << off <<" apagadas"<<endl;
	cout<<"hay un total de " << mal <<" en mal estado"<<endl;
	cout<<"Un "<< on*100/625<<"% de la bateria esta encendida"<<endl;
	for(int j = 0;j<((on*100/625)/10);j++){
		cout<<"*";
	}cout<<endl;
	cout<<"Un "<< off*100/625<<"% de la bateria esta apagada"<<endl;
	for(int j = 0;j<((off*100/625)/10);j++){
		cout<<"*";
	}cout<<endl;
	cout<<"Un "<< mal*100/625<<"% de la bateria esta en mal estado"<<endl;
	for(int j = 0;j<((mal*100/625)/10);j++){
		cout<<"*";
	}cout<<endl;
}

void Bateria::modificarTamanoBateria(){
	int fil=0,col=0;
	cout<<"ingrese a la cantidad de filas y columnas que desea modificar"<<endl;
	cout<<"Filas"<<endl;
	cin>>fil;
	cout<<"Columnas"<<endl;
	cin>>col;
	cout<<"usted a ingresado la siguiente celda"<<endl;
	cout << "[" << fil << "][" << col << "]";
	
	
	for (int f = 0; f <fil; f++){
		for (int c = 0; c < col; c++){
			if (Condicion[f][c] == -1){
				Condicion[f][c] = 1;
				voltios[f][c] = 12;
				amperios[f][c] = 12;
			}
		}
	}
	
	
}
void Bateria::cambiarBateria(Bateria bateria){//falta la creacion de la bateria b1 y b2
	for(int f= 0;f<25;++f){
		for(int c=0;c<25;++c){
			this->amperios[f][c]= bateria.amperios[f][c];
			this->voltios[f][c]= bateria.voltios[f][c];
			this->Condicion[f][c]= bateria.Condicion[f][c];
		}
	}
	cout<<"Se ha modificado la bateria"<<endl;
}
string Bateria::compararBaterias(Bateria bateria){//falta la creacion de la bateria b1 y b2
	stringstream retornar;
	int sumAmpB1=0,sumAmpB2=0,MatB1=0,MatB2=0;
	MatB1 = this->getcolumnas()*this->getfilas();
	MatB2 =bateria.getcolumnas()*bateria.getfilas();
	
	for(int f= 0;f<this->getfilas();++f){
		for(int c=0;c<this->getcolumnas();++c){
			sumAmpB1+= this->amperios[f][c];
		}
	}
	for(int f= 0;f<bateria.getfilas();++f){
		for(int c=0;c<bateria.getcolumnas();++c){
			sumAmpB1+= amperios[f][c];
		}
	}
	retornar<<"promedio de bateria actual:"<<sumAmpB1/MatB1<<"%"<<endl;
	retornar<<"promedio de bateria a comparar:"<<sumAmpB2/MatB2<<"%"<<endl;
	if((sumAmpB1/MatB1)>(sumAmpB2/MatB2)){
		retornar<<"La bateria actual es mejor"<<endl;
	}
	if((sumAmpB1/MatB1)<(sumAmpB2/MatB2)){
		retornar<<"La bateria a comparar es mejor"<<endl;
	}
	return retornar.str();
}
int main() {
	Bateria bat1;
	Bateria bat2;	
	int batset;
	cout<<"------Iniciando construncion de Bateria 1------"<<endl;
	bat1.inicioDeSistema();
	cout<<"------Iniciando construncion de Bateria 2-------"<<endl;
	bat2.inicioDeSistema();
	int op;
	do{
		cout<<"ingrese una opcionde la bateria\n"
			"( 1 ) Información de la batería\n"
			"( 2 ) Detalle de una celda\n"
			"( 3 ) Llenar aleatoriamente las celdas de una batería\n"
			"( 4 ) Modificar una celda\n"
			"( 5 ) Determinar el estado de la batería\n"
			"( 6 ) Modificar la capacidad de la batería\n"
			"( 7 ) Intercambiar las baterías\n"
			"( 8 ) Comparar baterías\n"
			"( 0 ) Salir\n";
		
		cin>>op;
		switch (op) {
		case 1:
			cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
			cin>>batset;
			if(batset == 1){
				system("cls");
				bat1.toStringBateria();	
				system("pause");
			}
			else if(batset == 2){
				system("cls");
				bat2.toStringBateria();	
				system("pause");
			}
			else{
				system("cls");
				cout<<"caracter Invalido, vuelva a intentar..."<<endl;
				system("pause");
			}
			system("cls");
			break;
		case 2:
			cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
			cin>>batset;
			if(batset == 1){
				system("cls");
				bat1.toStringDetalleCelda();
				system("pause");
			}
			else if(batset == 2){
				system("cls");
				bat2.toStringDetalleCelda();	
				system("pause");
			}
			else{
				system("cls");
				cout<<"caracter Invalido, vuelva a intentar..."<<endl;
				system("pause");
			}
			system("cls");
			break;
		case 3:
			cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
			cin>>batset;
			if(batset == 1){
				system("cls");
				bat1.llenarAleatorio();
				system("pause");
			}
			else if(batset == 2){
				system("cls");
				bat2.llenarAleatorio();	
				system("pause");
			}
			else{
				system("cls");
				cout<<"caracter Invalido, vuelva a intentar..."<<endl;
				system("pause");
			}
			break;
		case 4:
			cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
			cin>>batset;
			if(batset == 1){
				system("cls");
				bat1.modificarCelda();
				system("pause");
			}
			else if(batset == 2){
				system("cls");
				bat2.modificarCelda();	
				system("pause");
			}
			else{
				system("cls");
				cout<<"caracter Invalido, vuelva a intentar..."<<endl;
				system("pause");
			}
			break;
		case 5:cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
		cin>>batset;
		if(batset == 1){
			system("cls");
			bat1.estadoDeLaBateria();
			system("pause");
		}
		else if(batset == 2){
			system("cls");
			bat2.estadoDeLaBateria();
			system("pause");
		}
		else{
			system("cls");
			cout<<"caracter Invalido, vuelva a intentar..."<<endl;
			system("pause");
		}
		break;
		case 6:
			cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
			cin>>batset;
			if(batset == 1){
				system("cls");
				bat1.modificarTamanoBateria();
				system("pause");
			}
			else if(batset == 2){
				system("cls");
				bat2.modificarTamanoBateria();
				system("pause");
			}
			else{
				system("cls");
				cout<<"caracter Invalido, vuelva a intentar..."<<endl;
				system("pause");
			}
			break;
		case 7:
			cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
			cin>>batset;
			if(batset == 1){
				system("cls");
				bat1.cambiarBateria(bat2);
				system("pause");
			}
			else if(batset == 2){
				system("cls");
				bat2.cambiarBateria(bat1);
				system("pause");
			}
			else{
				system("cls");
				cout<<"caracter Invalido, vuelva a intentar..."<<endl;
				system("pause");
			}
			
			break;
		case 8:
			cout<<"con que bateria vas a trabajar (1 o 2)"<<endl;
			cin>>batset;
			if(batset == 1){
				system("cls");
				cout<<bat1.compararBaterias(bat2);
				system("pause");
			}
			else if(batset == 2){
				system("cls");
				cout<<bat2.compararBaterias(bat1);
				system("pause");
			}
			else{
				system("cls");
				cout<<"caracter Invalido, vuelva a intentar..."<<endl;
				system("pause");
			}
			break;
		};
		
	} while(op>0&&op<9);
	if (op==0){
		system("cls");
		cout<<"saliendo del progama"<<endl;
	}else {
		system("cls");
		cout<<"caracter Invalido, saliendo..."<<endl;
	}
	return 0;
}

