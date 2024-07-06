#include <iostream>
#include<sstream>
using namespace std;
class Producto{
private:
	string Codigo;
	string Nombre;
	double PrecioBase;
	double PorcentajeDeGanacia;
	int CantidadVendida;
	int Existencia;
	double PesoUnitario;
	int ExistenciaMinima;
	int PrecioDeVenta;
	
public:
	Producto();															  // Por defecto.
	Producto(string, string, double, double, int, int, double, int, int); // Parametrizado.

	// set's ==> Mutadores.
	void setCodigo(string);
	void setNombre(string);
	void setPrecioBase(double);
	void setPorcentajeDeGanacia(double);
	void setCantidadVendida(int);
	void setExistencia(int);
	void setPesoUnitario(double);
	void setExistenciaMinima(int);
	void setPrecioDeVenta(double);
	// get's ==> Accesores.
	string getCodigo();
	string getNombre();
	double getPrecioBase();
	double getPorcentajeDeGanacia();
	int getCantidadVendida();
	int getExistencia();
	double getPesoUnitario();
	int getExistenciaMinima();
	double getPrecioDeVenta();
	// string toString()
	string toString();
};
Producto::Producto(){
	string Codigo = "";
	string Nombre = "";
}

// MUTADORES

void Producto::setCodigo(string Cod)
{
	Codigo = Cod;
}
void Producto::setNombre(string Nom)
{ 
	Nombre = Nom; 
}
void Producto::setPrecioBase(double Pb) 
{ 
	PrecioBase = Pb; 
}
void Producto::setPorcentajeDeGanacia(double Pg)
{ 
	PorcentajeDeGanacia = Pg; 
}
void Producto::setCantidadVendida(int Cv)
{ 
	CantidadVendida = Cv; 
}
void Producto::setExistencia(int Ex) 
{ 
	Existencia = Ex; 
}
void Producto::setPesoUnitario (double Pu)
{
	PesoUnitario = Pu; 
}
void Producto::setExistenciaMinima(int Em) 
{
	ExistenciaMinima = Em; 
}
void Producto::setPrecioDeVenta(double)
{
	PrecioDeVenta=(PrecioBase * PorcentajeDeGanacia)+PrecioBase;
}
// ACCESORES
string Producto::getCodigo()
{
	return Codigo;
}
string Producto::getNombre() { return Nombre; }
double Producto::getPrecioBase() { return PrecioBase; }
double Producto::getPorcentajeDeGanacia() { return PorcentajeDeGanacia; }
int Producto::getCantidadVendida() { return CantidadVendida; }
int Producto::getExistencia() { return Existencia; }
double Producto::getPesoUnitario() { return PesoUnitario; }
int Producto::getExistenciaMinima() { return ExistenciaMinima; }
double Producto::getPrecioDeVenta(){return PrecioDeVenta;}

string Producto::toString(){
	stringstream s;
	s << "------------PRODUCTO--------------" << endl
		<< "Nombre: " << Nombre << endl
		<< "Codigo: " << Codigo << endl
		<< "Porcentaje de ganancia: " << PorcentajeDeGanacia << endl
		<< "Precio de venta: " << PrecioDeVenta << endl
		<< "------------------------------------------" << endl;
	return s.str();
}
class SuperContenedorV{
private:
	Producto vec[200];
	int cantidad;
	int tamano;
public:
	SuperContenedorV(); // Por defecto.
	virtual ~SuperContenedorV();
	int getCantidad();
	int getTamano();
	string toString();
	// mï¿½todo de cï¿½lculo..
	void ingresaProducto();
	void eliminarProductoPorSu();
	Producto obtenerProducDeMayorValor();
	Producto obtenerProducConMayorExistencia();
	void ordenarProductPorCodigo();
	void imprimirTodosLosProductos();
	int cantDeProductosBajosDeExistencia();
	void imprimirProductosBajosDeExistencia();
	double cuantosKgsSeHanVendidoEnGeneral();
	double cuantosKgsSeHanVendidoDelProducto();
	void imprimProductosQueSonMasCostososQue();
	void cuantasUnidadesSeHanVendidoDelProducto();
	double costoDelInventario();
	double costoDeLasVentas();
	double valorDeLasVentas();
	double ganaciaDelSuperMercadoPorVentas();
	void graficoDeVentasDeLos15ProductsMasVendidos();
	void graficoDeVentasDeLos15ProductsMenosVendidos();
	double promedioDeLosPreciosDeVenta();
};
int SuperContenedorV::getCantidad() { return cantidad; }
int SuperContenedorV::getTamano() { return tamano; }
SuperContenedorV::SuperContenedorV()
{
	cantidad = 0;
	tamano = 200;
}
SuperContenedorV::~SuperContenedorV()
{
}
string SuperContenedorV::toString(){
	stringstream s;
	for (int i = 0; i < cantidad; i++)
		s << vec[i].toString() << endl
		<< endl;
	s.str();
	return s.str();
}

void SuperContenedorV::ingresaProducto(){
	string Cod, Nom = "";
	double Pb, Pg, Pu =0;
	int Cv,Ex,Em=0;
	if(cantidad<tamano){
		cout<<"------------------INGRESAR PRODUCTO------------------"<<endl;
		cout<<"Ingrese el nombre del producto"<<endl;
		cin>>Nom;
		cout<<"Ingrese el codigo del producto"<<endl;
		cin>>Cod;
		cout<<"Ingrese el Precio base del producto"<<endl;
		cin>>Pb;
		cout<<"Ingrese el Porcentaje de ganancia del producto"<<endl;
		cin>>Pg;
		cout<<"Ingrese la Cantidad de "<<Nom<<" que se han vendido "<<endl;
		cin>>Cv;
		cout<<"Ingrese cuantos productos quedan"<<endl;
		cin>>Ex;
		cout<<"Ingrese el peso unitario del producto"<<endl;
		cin>>Pu;
		cout<<"Ingrese la existencia minima del producto"<<endl;
		cin>>Em;
		vec[cantidad].setCodigo(Cod);
		vec[cantidad].setNombre(Nom);
		vec[cantidad].setPrecioBase(Pb);
		vec[cantidad].setPorcentajeDeGanacia(Pg);
		vec[cantidad].setCantidadVendida(Cv);
		vec[cantidad].setExistencia(Ex);
		vec[cantidad].setPesoUnitario(Pu);
		vec[cantidad].setExistenciaMinima(Em);
		vec[cantidad].setPrecioDeVenta((Pb *Pg)+Pb);
		cantidad++;
	}
	else{
		cout << "No hay espacio para mas productos en el SuperContenedor" << endl;
	}
}						
void SuperContenedorV::eliminarProductoPorSu(){
	string Cod;
	cout << "--------------------ELIMINAR PRODUCTO POR SU CODIGO------------------" << endl;
	cout << "Ingrese el codigo del producto que quiere eliminar" << endl;
	cin >> Cod;
	for (int i = 0; i < cantidad; i++){
		if (Cod == vec[i].getCodigo()){
			vec[i].setCodigo("");
			vec[i].setNombre("");
			vec[i].setPrecioBase(0);
			vec[i].setPorcentajeDeGanacia(0);
			vec[i].setCantidadVendida(0);
			vec[i].setExistencia(0);
			vec[i].setPesoUnitario(0);
			vec[i].setExistenciaMinima(0);
		}
	}
	cantidad--;
}
Producto SuperContenedorV::obtenerProducDeMayorValor(){
	cout << "---------OBTENIENDO PRODUCTO DE MAYOR VALOR------------" << endl;
	Producto Mvalor = vec[0];
	for (int i = 1; i < cantidad; i++)
		if (vec[i].getPrecioDeVenta() > Mvalor.getPrecioDeVenta())
			Mvalor.getNombre() = vec[i].getNombre();
	cout<<"El de mayor valor es: "<<Mvalor.getNombre()<<" con un Valor de venta de: "<<Mvalor.getPrecioDeVenta()<<endl;
	return Mvalor;
}

Producto SuperContenedorV::obtenerProducConMayorExistencia(){
	cout << "---------OBTENIENDO PRODUCTO DE MAYOR VALOR------------" << endl;
	Producto Mexistencia = vec[0];
	for (int i = 1; i < cantidad; i++)
		if (vec[i].getExistencia() > Mexistencia.getExistencia())
			Mexistencia.getNombre() = vec[i].getNombre();
	cout<<"El de mayor valor es: "<<Mexistencia.getNombre()<<" con una existencia de: "<<Mexistencia.getExistencia()<<endl;
	return Mexistencia;
}
void SuperContenedorV::ordenarProductPorCodigo(){
	cout << "---------ORDENANDO PRODUCTO POR CODIGO------------" << endl;
	Producto aux;
	for (int i = 0; i < cantidad; i++){
		for (int j = i + 1; j < cantidad; j++){
			if (vec[i].getCodigo() > vec[j].getCodigo()){
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
void SuperContenedorV::imprimirTodosLosProductos(){
	cout << "---------IMPRIMIENDO TODOS LOS PRODUCTOS------------" <<endl<<endl;
	for (int i = 0; i < cantidad; i++)
		cout << vec[i].toString() << endl
		<< endl;
}
int SuperContenedorV::cantDeProductosBajosDeExistencia(){
	cout << "---------OBTENIENDO CUANTOS PRODUCTOS BAJOS DE EXISTENCIA HAY------------" <<endl<<endl;
	int acum = 0;
	for (int i = 0; i < cantidad; i++){
		if (vec[i].getExistencia() < vec[i].getExistenciaMinima()){
			acum++;
		}
	}
	cout << "Hay " << acum << " productos que estan bajos de existencia" << endl;
	return acum;
}
void SuperContenedorV::imprimirProductosBajosDeExistencia(){
	cout << "---------IMPRIMIENDO TODOS LOS PRODUCTOS BAJOS DE EXISTENCIA------------" <<endl<<endl;
	for (int i = 0; i < cantidad; i++){
		if (vec[i].getExistencia() < vec[i].getExistenciaMinima()){
			cout <<" -- -- -- -- -- -PRODUCTO-- -- -- -- -- -- -- - "<< endl;
			cout << "Nombre: " << vec[i].getNombre() << endl; 
			cout << "Codigo: " << vec[i].getCodigo() << endl ;
			cout << "Existencia: " << vec[i].getExistencia() << endl ;
			cout << "ExistenciaMinima: " << vec[i].getExistenciaMinima() << endl;
		}
	}
}
double SuperContenedorV::cuantosKgsSeHanVendidoEnGeneral(){
	cout << "---------IMPRIMIENDO CUANTOS KILOGRAMOS SE HAN VENDIDO EN GENERAL------------" <<endl<<endl;
	double acumkg = 0;
	for (int i = 0; i < cantidad; i++){
		acumkg = vec[i].getCantidadVendida() * vec[i].getPesoUnitario();
	}
	cout << "Se han vendido " << acumkg << " kilogramos de productos en general" << endl;
	return acumkg;
}
double SuperContenedorV::cuantosKgsSeHanVendidoDelProducto(){
	string Nom;
	double kgVendidos;
	cout << "Ingrese el nombre del producto que quiere saber cuantos kgs se han vendido" << endl;
	cin >> Nom;
	cout << "---------IMPRIMIENDO CUANTOS KILOGRAMOS SE HAN VENDIDO DE "<<Nom<<"------------" <<endl<<endl;
	for (int i = 0; i < cantidad; i++){
		if (Nom == vec[i].getNombre()){
			kgVendidos = vec[i].getCantidadVendida() * vec[i].getPesoUnitario();
			cout << "Se han vendido " << kgVendidos << " kilogramos de " << vec[i].getNombre() << endl;
		}
	}
	return kgVendidos;
}
void SuperContenedorV::imprimProductosQueSonMasCostososQue(){ 
	string Nom ="";
	double PrecioMin = 0;
	cout << "Ingrese el Nombre del producto para imprimir productos de mayor precio " << endl;
	cin >>Nom;
	for (int i = 0; i < cantidad; i++){
		if (vec[i].getNombre() == Nom){
			PrecioMin = vec[i].getPrecioDeVenta();
		}
	}
	for(int i =0; i < cantidad; i++){
		if(vec[i].getPrecioDeVenta() > PrecioMin){
			cout << "-- -- -- -- --PRODUCTO-- -- -- -- -- -- -- -" << endl;
			cout << "Nombre: " << vec[i].getNombre() << endl ;
			cout << "Codigo: " << vec[i].getCodigo() << endl ;
			cout << "precio: " << vec[i].getPrecioDeVenta();
			cout<<endl;
		}
	}
}
void SuperContenedorV::cuantasUnidadesSeHanVendidoDelProducto(){
	string Cod ="";
	cout << "Ingrese el codigo producto del que desea saber sus unidades vendidas" << endl ;
	cin >> Cod ;
	for (int i = 0; i < cantidad; i++){
		if (vec[i].getCodigo() == Cod){
			cout << "-- -- -- -- --PRODUCTO-- -- -- -- -- -- -- - "<< endl;
			cout << "Nombre: " << vec[i].getNombre() << endl ;
			cout << "Codigo: " << vec[i].getCodigo() << endl; 
			cout << "unidades vendidas: " << vec[i].getCantidadVendida();
			cout<<endl;
		}
	}
	
}
double SuperContenedorV::costoDelInventario(){
	double costo = 0; 
	cout << "-- -- -- -- --costoDelInventario-- -- -- -- -- -- -- -" << endl;
	for (int i = 0; i < cantidad; i++){
		costo = costo + vec[i].getExistencia() * vec[i].getPrecioBase();
	}
	cout << "El costo total del inventario del supermercado es de :" << costo << endl;
	return costo;
}
double SuperContenedorV::costoDeLasVentas(){
	double costo = 0;
	cout << "-- -- -- -- --CostoDeLasVentas-- -- -- -- -- -- -- - "<< endl;
	for (int i = 0; i < cantidad; i++){
		costo = costo + vec[i].getPrecioBase() * vec[i].getCantidadVendida();
	}
	cout << "El costo total del las ventas del supermercado es de :" << costo << endl;
	return costo;
}
double SuperContenedorV::valorDeLasVentas(){
	double valor = 0;
	cout << "-- -- -- -- --ValorDeLasVentas-- -- -- -- -- -- -- -" << endl;
	for (int i = 0; i < cantidad; i++){
		valor = valor + vec[i].getPrecioDeVenta() * vec[i].getCantidadVendida();
	}
	cout << "El costo total del las ventas del supermercado es de :" << valor << endl;
	return valor;
}//Percio de venta es 0
double SuperContenedorV::ganaciaDelSuperMercadoPorVentas(){
	double Ganancias = 0;
	cout <<" -- -- -- -- --GananciasDelSuperMercadoPorVentas-- -- -- -- -- -- -- - "<< endl;
	for (int i = 0; i < cantidad; i++){
		Ganancias = Ganancias + ((vec[i].getPrecioDeVenta() * vec[i].getCantidadVendida()) - (vec[i].getPrecioBase() * vec[i].getCantidadVendida()));
	}
	cout << "El costo total del las ganancias del supermercado es de :" << Ganancias << endl;
	return Ganancias;
}
void SuperContenedorV::graficoDeVentasDeLos15ProductsMasVendidos(){
	Producto aux;
	int Op=0,Result=0;
	for (int i = 0; i < cantidad; i++){
		for (int j = i + 1; j < cantidad; j++){
			if (vec[i].getCantidadVendida() > vec[j].getCantidadVendida()){
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
	cout<<"Desea que su graficas sea expresada en:"<<endl;
	cout<<"1.- Unidades"<<endl;
	cout<<"2.- Decenas"<<endl;
	cout<<"3.- centenas"<<endl;
	cout<<"4.- millares"<<endl;
	cin>>Op;
	
	cout << "---------GRAFICA------------" << endl;
	for(int i=cantidad-1;i>cantidad-6&&i>-1;--i){
		cout<<vec[i].getNombre()<<": ";
		switch (Op) {
		case 1:{
			Result=vec[i].getCantidadVendida();
			for(int j =0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		case 2:{
			Result=vec[i].getCantidadVendida()/10;
			for(int j = 0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		case 3:{
			Result=vec[i].getCantidadVendida()/100;
			for(int j = 0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		case 4:{
			Result=vec[i].getCantidadVendida()/1000;
			for(int j = 0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		}
		
		
	}
	
}
void SuperContenedorV::graficoDeVentasDeLos15ProductsMenosVendidos(){
	Producto aux;
	int Op=0,Result=0;
	for (int i = 0; i < cantidad; i++){
		for (int j = i + 1; j < cantidad; j++){
			if (vec[i].getCantidadVendida() > vec[j].getCantidadVendida()){
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
	cout<<"Desea que su graficas sea expresada en:"<<endl;
	cout<<"1.- Unidades"<<endl;
	cout<<"2.- Decenas"<<endl;
	cout<<"3.- centenas"<<endl;
	cout<<"4.- millares"<<endl;
	cin>>Op;
	
	cout << "---------GRAFICA------------" << endl;
	for(int i=0;i<5;++i){
		cout<<vec[i].getNombre()<<": ";
		switch (Op) {
		case 1:{
			Result=vec[i].getCantidadVendida();
			for(int j =0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		case 2:{
			Result=vec[i].getCantidadVendida()/10;
			for(int j = 0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		case 3:{
			Result=vec[i].getCantidadVendida()/100;
			for(int j = 0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		case 4:{
			Result=vec[i].getCantidadVendida()/1000;
			for(int j = 0;j<Result;j++){
				cout<<"*";
			}
			cout<<endl;
		}break;
		}
		
		
	}
	
}
double SuperContenedorV::promedioDeLosPreciosDeVenta(){
	double promedio = 0;
	for(int i=0;i<cantidad;i++){
		promedio = promedio + vec[i].getPrecioDeVenta();
	}
	promedio = promedio/cantidad;
	cout<<"El Promedio de los precio de venta es: "<< promedio << endl;
	return promedio;
}//Percio de venta es 0
int menu();
void logicaDeControl(int, SuperContenedorV&);

int main(){
	int op;
	SuperContenedorV SuperMercado;
	do {
		op = menu();
		logicaDeControl(op, SuperMercado);
		system("pause");
	} while (op != 20);
	return 0;
}
int menu() {
	int op;
	system("cls");
	cout << endl << endl;
	cout<<"---------------------------------------SUPERMERCADO------------------------------------------" << endl;
	cout<<"- 1- Ingresar un producto." << endl;
	cout<<"- 2- Eliminar un producto." << endl;
	cout<<"- 3- Desplegar el producto de mayor precio." << endl;
	cout<<"- 4- Desplegar el producto con mayor existencia." << endl;
	cout<<"- 5- Ordenar los productos por código." << endl;
	cout<<"- 6- Desplegar todos los productos." << endl;
	cout<<"- 7- Desplegar la cantidad de productos bajos de existencia." << endl;
	cout<<"- 8- Desplegar los productos bajos de existencia." << endl;
	cout<<"- 9- Desplegar el total de kilogramos de todos los productos vendidos." << endl;
	cout<<"- 10- Desplegar el total de Kilogramos vendidos de un producto." << endl;
	cout<<"- 11- Desplegar la lista de productos que son más costosos que un producto dado." << endl;
	cout<<"- 12- Desplegar la cantidad de unidades vendidas de un producto en particular." << endl;
	cout<<"- 13- Desplegar el Costo del Inventario." << endl;
	cout<<"- 14- Desplegar el Costo de las Ventas." << endl;
	cout<<"- 15- Desplegar el Valor de las Ventas." << endl;
	cout<<"- 16- Desplegar la ganancia total del supermercado por concepto de ventas." << endl;
	cout<<"- 17- Desplegar el gráfico de las ventas de los 5 productos más vendidos." << endl;
	cout<<"- 18- Desplegar el gráfico de las ventas de los 5 productos menos vendidos." << endl;
	cout<<"- 19- Desplegar el promedio de precios de venta de los productos vendidos con ganancia." << endl;
	cout<<"- 20- SALIR." << endl;
	cin>>op;
	return op;
}
void logicaDeControl(int op, SuperContenedorV& SM) {
	switch (op) {
	case 1: {
		SM.ingresaProducto();
	}break;
	
	case 2: {
		SM.eliminarProductoPorSu();
	}break;
	
	case 3: {
		SM.obtenerProducDeMayorValor();
	}break;
	
	case 4: {
		SM.obtenerProducConMayorExistencia();
	}break;
	
	case 5: {
		SM.ordenarProductPorCodigo();
	}break;
	
	case 6: {
		SM.imprimirTodosLosProductos();	
	}break;
	
	case 7: {
		SM.cantDeProductosBajosDeExistencia();	
	}break;
	
	case 8: {
		SM.imprimirProductosBajosDeExistencia();	
	}break;
	
	case 9: {
		SM.cuantosKgsSeHanVendidoEnGeneral();
	}break;
	
	case 10: {
		SM.cuantosKgsSeHanVendidoDelProducto();
	}break;
	
	case 11: {
		SM.imprimProductosQueSonMasCostososQue();
	}break;
	
	case 12: {
		SM.cuantasUnidadesSeHanVendidoDelProducto();
	}break;
	
	case 13: {
		SM.costoDelInventario();
	}break;
	
	case 14: {
		SM.costoDeLasVentas();
	}break;
	
	case 15: {
		SM.valorDeLasVentas();
	}break;
	
	case 16: {
		SM.ganaciaDelSuperMercadoPorVentas();
	}break;
	
	case 17: {
		SM.graficoDeVentasDeLos15ProductsMasVendidos();
	}break;
	
	case 18: {
		SM.graficoDeVentasDeLos15ProductsMenosVendidos();
	}break;
	
	case 19: {
		SM.promedioDeLosPreciosDeVenta();
	}break;
	
	case 20: {
		cout << " Salir." << endl;
	}
	};
}

