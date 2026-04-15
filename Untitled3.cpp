#include <iostream>
using namespace std; 
class PersegiPanjang{
	private:
	int a ,b,c;
	float rata ;
	public :
		void input(){
			cout<<"masukan a"; 
			cin >> a;
			cout <<"masukan b";
			cin>> b;
			cout <<"masukan c";
			cin>> c;
		
		}
		void hitung (){
			rata = (a+b+c)/3.0;
			
		}
		void output (){
			cout << "rata = "<< rata <<endl ;
		
		}
};
int main (){
	PersegiPanjang pp;
	pp.input();
	pp.hitung();
	pp.output();
	return 0;
}
