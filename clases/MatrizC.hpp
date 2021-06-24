#ifndef MATRIZC_HPP
#define MATRIZC_HPP
#include <cmath>
#include "Filtro.hpp"
#include "Complex.hpp"
#include <iostream>


class MatrizC
{

    public:

        MatrizC(int, int);
        
        int dim_matriz_v, dim_matriz_h;

        int dim_matriz_re_v, dim_matriz_re_h;

        float m[10][10];
        

        void random();

        void show();

        Matriz convolucion(Filtro);

        Matriz DFT();

};

MatrizC::MatrizC(int n, int m):dim_matriz_v(n), dim_matriz_h(m)
{

    for (int i = 0; i < dim_matriz_v; i++)
    {
        for (int j = 0; j < dim_matriz_h; j++)
        {
            this->m[i][j] = 0;
        }
    }    
}


void MatrizC::show()
{
    for (int i = 0; i < dim_matriz_v; i++)
    {
        std::cout << "|";
        for (int j = 0; j < dim_matriz_h; j++)
            {
                std::cout << " " << m[i][j] << " " ;
            }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

MatrizC MatrizC::DFT()
{
    Matriz *matriz_re = new Matriz (dim_matriz_v, dim_matriz_h);

    for (int u = 0; u < dim_matriz_v; u++)
    {
        for (int v = 0; v < dim_matriz_h; v++)
        {

            float DosPiu_M = 2 * M_PI * u / dim_matriz_v;
            float DosPiv_N = 2 * M_PI * v / dim_matriz_h;

            float sum_real = 0;
            float sum_imag = 0;
            
            for (int x = 0; x < dim_matriz_v; x++)
            {
                for (int y = 0; y < dim_matriz_h; y++)
                {
                    sum_real += m[x][y] * cos(DosPiu_M * x + DosPiv_N * y);
                    sum_imag += m[x][y] * sin(DosPiu_M * x + DosPiv_N * y);
                }
                
            }

            matriz_re->m[u][v] = (sum_real * sum_real + sum_imag * sum_imag) / (dim_matriz_h * dim_matriz_h * dim_matriz_v * dim_matriz_v);
        }
    }

    return *matriz_re;
}













#endif // MATRIZC_HPP