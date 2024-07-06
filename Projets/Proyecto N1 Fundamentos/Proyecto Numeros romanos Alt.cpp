#include <iostream>
#include <windows.h>
using namespace std;

int ConvRomano(int Num){
	int Uni, Dec, Cen, Mil; 
	
	Uni= Num%10;	
	Num=Num/10;	
	Dec=Num%10;	
	Num=Num/10;	
	Cen=Num%10;	
	Mil=Num/10;
	
	switch (Mil){
	case 1: cout<<"M";break;
	case 2: cout<<"MM";break;
	case 3: cout<<"MMM";break;
	}
	switch (Cen){
	case 1: cout<<"C";break;
	case 2: cout<<"CC";break;
	case 3: cout<<"CCC";break;
	case 4: cout<<"CD";break;
	case 5: cout<<"D";break;
	case 6: cout<<"DC";break;
	case 7: cout<<"DCC";break;
	case 8: cout<<"DCCC";break;
	case 9: cout<<"CM";break;
	}
	switch (Dec){
	case 1: cout<<"X";break;
	case 2: cout<<"XX";break;
	case 3: cout<<"XXX";break;
	case 4: cout<<"XL";break;
	case 5: cout<<"L";break;
	case 6: cout<<"LX";break;
	case 7: cout<<"LXX";break;
	case 8: cout<<"LXXX";break;
	case 9: cout<<"XC";break;
	}
	switch (Uni){
	case 1: cout<<"I";break;
	case 2: cout<<"II";break;
	case 3: cout<<"III";break;
	case 4: cout<<"IV";break;
	case 5: cout<<"V";break;
	case 6: cout<<"VI";break;
	case 7: cout<<"VII";break;
	case 8: cout<<"VIII";break;
	case 9: cout<<"IX";break;
	}
	cout<<"\n";
	return Num;
}

int morse(int Num){
	int Uni2, Dec2, Cen2, Mil2; 
		
		Uni2= Num%10;
		Num=Num/10;
		Dec2=Num%10;		
		Num=Num/10;
		Cen2=Num%10;		
		Mil2=Num/10;
		
		switch (Mil2){
		case 1: cout<<".----";Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 2: cout<<"..---";Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 3: cout<<"...--";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450); break; 
		}
		switch (Cen2){
		case 1: cout<<" .----";Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 2: cout<<" ..---";Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 3: cout<<" ...--";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450); break; 
		case 4: cout<<" ....-";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150);Beep(1000,450); break; 
		case 5: cout<<" .....";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150); break; 
		case 6: cout<<" -....";Beep(1000,450); Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150);  break; 
		case 7: cout<<" --...";Beep(1000,450);Beep(1000,450); Beep (1000,150); Beep (1000,150); Beep (1000,150); break; 
		case 8: cout<<" ---..";Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep (1000,150); Beep (1000,150); break; 
		case 9: cout<<" ----.";Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep(1000,450); Beep (1000,150);  break; 
		}
		switch (Dec2){
		case 1: cout<<" .----";Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 2: cout<<" ..---";Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 3: cout<<" ...--";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450); break; 
		case 4: cout<<" ....-";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150);Beep(1000,450); break; 
		case 5: cout<<" .....";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150); break; 
		case 6: cout<<" -....";Beep(1000,450); Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150);  break; 
		case 7: cout<<" --...";Beep(1000,450);Beep(1000,450); Beep (1000,150); Beep (1000,150); Beep (1000,150); break; 
		case 8: cout<<" ---..";Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep (1000,150); Beep (1000,150); break; 
		case 9: cout<<" ----.";Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep(1000,450); Beep (1000,150);  break; 
		}
		switch (Uni2){
		case 1: cout<<" .----";Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 2: cout<<" ..---";Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450);Beep(1000,450); break; 
		case 3: cout<<" ...--";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep(1000,450);Beep(1000,450); break; 
		case 4: cout<<" ....-";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150);Beep(1000,450); break; 
		case 5: cout<<" .....";Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150); break; 
		case 6: cout<<" -....";Beep(1000,450); Beep (1000,150); Beep (1000,150); Beep (1000,150); Beep (1000,150);  break; 
		case 7: cout<<" --...";Beep(1000,450);Beep(1000,450); Beep (1000,150); Beep (1000,150); Beep (1000,150); break; 
		case 8: cout<<" ---..";Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep (1000,150); Beep (1000,150); break; 
		case 9: cout<<" ----.";Beep(1000,450);Beep(1000,450);Beep(1000,450);Beep(1000,450); Beep (1000,150);  break; 
		}
		cout<<"\n";
		return Num;
	}
	int main(){
		
		int Num;
		cout<<"\n";
		cout<<"Digite un numero del 1 al 3000 :"<<endl; cin>>Num;
			if (Num > 0 && Num <3001){
				cout<<"el numero anterior en numeros romanos es: "<<endl; 
				ConvRomano (Num);
				cout<<"este numero a morse seria:"<<endl;
				morse(Num);
			}
		
			else 
			cout<<"este numero esta fuera de rango"<<endl;
		
		
		system("pause");
		return 0;
		
	}
