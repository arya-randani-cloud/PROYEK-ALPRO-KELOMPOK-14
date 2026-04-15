#include <iostream>
using namespace std; 
class PersegiPanjang{
	private:
	 
	float tengah,a,b,x1,x2,y1,y2 ;
	public :
		void input(){
			cout<<"masukan x1"; 
			cin >> x1;
			cout <<"masukan x2";
			cin>> x2;
			cout << endl << endl;
			
			cout <<"masukan y1";
			cin>> y1;
			cout <<"masukan y2";
			cin>> y2;
		
		}
		void hitung (){
			a =(x1+x2)/2;
			b =(y1+y2)/2;
		
			
		}
		void output (){
			cout << "tengah = "<< "(" << a << ","<< b << ")"<<endl ;
	
		}
};
int main (){
	PersegiPanjang pp;
	pp.input();
	pp.hitung();
	pp.output();
	return 0;
}
