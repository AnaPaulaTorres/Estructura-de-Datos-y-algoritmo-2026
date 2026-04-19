#include <iostream> 
using namespace std;
int main (){
int a,b;
cout << "ingrese su numero " ;
cin>> a >> b;

cout <<"suma " << a+b << endl;
cout << "resta " << a-b << endl ;
cout << "multiplicacion "<< a*b << endl;

if (b==0)
  cout <<"no se divide entre 0 gracias ";
else 
  cout <<"divicion "<< a/b << endl;
return 0;ls
}