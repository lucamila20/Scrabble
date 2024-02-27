#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void cambiar(int *x);

int main(){
    int x=5;
    char s;
    int a[3];
    a[0]=13;
    int *apx;
    int *apa;

    cout << &x <<" "<< apx;
    apx = &x;
    cout << endl << &x << endl;
    cout << *apx << endl;
    *apx= *apx+4;
    cout << x << endl;
    cambiar(&x);
    cout << x << endl;
    cout << a << endl;
    cout << &a[0] << endl;
    cout << &a[1] << endl;
    apa=&a[0];
    cout << apa << endl;
    apa++;
    cout << apa << endl;
    cout <<(apa+1) << endl;

    cambiar(&x);
    cout << x;

}

void cambiar(int *x){
    *x =*x+10;
}

