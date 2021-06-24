#include <iostream>
//#include "Matriz.hpp"
#include "Filtro.hpp"
#include "Complex.hpp"
#include "Matriz.hpp"
using namespace std;



int main()
{
    Matriz matriz(10, 10);
    Filtro filtro(3,3);

    matriz.random();
    filtro.random();

    matriz.show();
    filtro.show();


    Matriz m = matriz.DFT();

    m.show();

    /*Matriz matriz(10, 10);

    matriz.random();

    matriz.show();

    Matriz m = matriz.DFT();
    Complex m1 = matriz.DFTc();


    cout << m.m[0][0] << endl;
    cout << (*m1 + 0)->Re << endl; */

    //Matriz m2 = matriz.DS(&m1);

    //m2.show();

    

    return 0;
}