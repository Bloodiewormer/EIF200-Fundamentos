#include <iostream>
#include<ctime>
using namespace std;

class CuadraturaDeLaLuna
{	
private:
	int mat[3][3]; 
public:CuadraturaDeLaLuna();
	CuadraturaDeLaLuna(int,bool);
	objeto();
	void llenarMatriz();
	void imprimMatriz();
	bool VerifMatriz();
};

CuadraturaDeLaLuna::CuadraturaDeLaLuna()
{
	srand(time(0));
}
bool repite(int mat[3][3],int num)
{
	for (int f = 0; f < 3; f++)
	{
	for (int c = 0; c < 3; c++)
		{
		if(num == mat[f][c])
			{
		return false;
			}
		}
	}
	return true;
}
void CuadraturaDeLaLuna::llenarMatriz() 
{
int num;
	for(int f =0; f<3;f++)
	{
		for(int c = 0; c<3; c++)
		{
			mat[f][c] = 0;
		}
	}
	for (int f = 0; f < 3; f++)
	{
		for (int c = 0; c < 3; c++)
		{
		num=1+rand()%9;
	while(repite(mat,num)== false)
	{
		num= 1+rand()%9;
	}
mat[f][c] = num;
		}
	}
}
void CuadraturaDeLaLuna::imprimMatriz()
{
cout << "Imprimir la matriz ." << endl;
for (int f = 0; f < 3; f++) 
{
for (int c = 0; c < 3; c++)
{
cout << mat[f][c] << '\t';
}
cout << endl;
}
}
bool CuadraturaDeLaLuna::VerifMatriz() 
{
bool esLuna = true;
int F1,F2,F3,C1,C2,C3,D1,D2;
F1=mat[0][0]+mat[0][1]+mat[0][2];
F2=mat[1][0]+mat[1][1]+mat[1][2];
F3=mat[2][0]+mat[2][1]+mat[2][2];
C1=mat[0][0]+mat[1][0]+mat[2][0];
C2=mat[0][1]+mat[1][1]+mat[2][1];
C3=mat[0][2]+mat[1][2]+mat[2][2];
D1=mat[0][0]+mat[1][1]+mat[2][2];
D2=mat[0][2]+mat[1][1]+mat[2][0];
if(F1==15&&F2==15&&F3==15&&C1==15&&C2==15&&C3==15&&D1==15&&D2==15)
{
esLuna = true;
return esLuna;
}
else{esLuna = false;
return esLuna;
}
}
int main ()
{
CuadraturaDeLaLuna objeto;
bool esLuna = objeto.VerifMatriz();
int count= 0;
cout << "Llenado y verificando matrizes hasta dar con una, por favor espere" << endl;
do
{
count++;
objeto.llenarMatriz();
esLuna = objeto.VerifMatriz();
cout<<"Se han Revisado un total de "<<count<<" Matrizes"<<endl;
}
while(esLuna==false);
objeto.imprimMatriz(); 
system ("pause");
return 0;
}
