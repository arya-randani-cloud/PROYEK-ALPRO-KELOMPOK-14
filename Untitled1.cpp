#include <iostream>
using namespace std; 
class PersegiPanjang{
	private:
	int panjang ,lebar,luas;
	
	public :
		void input(){
			cout<<"masukan panjang"; 
			cin >> panjang;
			cout <<"masukan lebar";
			cin>> lebar;
		
		}
		void hitung (){
			luas = panjang * lebar;
			
		}
		void output (){
			cout << "luas = "<< luas <<endl ;
		
		}
};
int main (){
	PersegiPanjang pp;
	pp.input();
	pp.hitung();
	pp.output();
	return 0;
}
