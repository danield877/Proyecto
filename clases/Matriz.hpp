#ifndef MATRIZ_HPP
#define MATRIZ_HPP
#include <cmath>
#include "Filtro.hpp"
#include "Complex.hpp"
#include <iostream>


class Matriz
{

    public:

        Matriz(int, int);
        
        int dim_matriz_v, dim_matriz_h;

        int dim_matriz_re_v, dim_matriz_re_h;

        float m[10][10];
        

        void random();

        void show();

        Matriz convolucion(Filtro);

        Matriz DFT();

        Complex DFTc();

        Matriz DS(Complex*);

};

Matriz::Matriz(int n, int m):dim_matriz_v(n), dim_matriz_h(m)
{

    for (int i = 0; i < dim_matriz_v; i++)
    {
        for (int j = 0; j < dim_matriz_h; j++)
        {
            this->m[i][j] = 0;
        }
    }    
}

void Matriz::random()
{
    for (int i = 0; i < dim_matriz_v; i++)
    {
        for (int j = 0; j < dim_matriz_h; j++)
        {
            //m[i][j] = rand() % 256;

            m[i][j] = 0;
            
        }
    }
    m[4][4]   = 256;
    m[4][5]  = 256;
    m[5][4]  = 256;
    m[5][5] = 256;
}

Matriz Matriz::convolucion(Filtro filtro)
{

    dim_matriz_re_v = dim_matriz_v - filtro.dim_filtro_v + 1;

    dim_matriz_re_h = dim_matriz_h - filtro.dim_filtro_h + 1;


    Matriz *matriz_re = new Matriz (dim_matriz_re_v, dim_matriz_re_h);


    for (int conv_v = 0; conv_v < dim_matriz_re_v; conv_v++)
    {
        for (int conv_h = 0; conv_h < dim_matriz_re_h; conv_h++)
        {

            float conv_suma = 0;

            for (int filtro_v = 0; filtro_v < filtro.dim_filtro_v; filtro_v++)
            {
                for (int filtro_h = 0; filtro_h < filtro.dim_filtro_h; filtro_h++)
                {

                    conv_suma += m[conv_v + filtro_v][conv_h + filtro_h] * filtro.m[filtro_v][filtro_h];

                }
            }

            matriz_re->m[conv_h][conv_v] = conv_suma;

        }
    }
    
    return *matriz_re;

}

void Matriz::show()
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

Matriz Matriz::DFT()
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

Complex Matriz::DFTc()
{
    Complex **matriz_re = new Complex[dim_matriz_v][dim_matriz_h];

    for (int u = 0; u < dim_matriz_v; u++)
    {
        for (int v = 0; v < dim_matriz_h; v++)
        {

            float DosPiu_M = 2 * M_PI * u / dim_matriz_v;
            float DosPiv_N = 2 * M_PI * v / dim_matriz_h;

            Complex *sum = new Complex;
            
            for (int x = 0; x < dim_matriz_v; x++)
            {
                for (int y = 0; y < dim_matriz_h; y++)
                {
                    sum->Re += m[x][y] * cos(DosPiu_M * x + DosPiv_N * y);
                    sum->Im -= m[x][y] * sin(DosPiu_M * x + DosPiv_N * y);
                }
                
            }

            (matriz_re + u + v)->Re = sum->Re;
            (matriz_re + u + v)->Im = sum->Im;
            delete sum;
        }
    }
    return *matriz_re;
}

Matriz Matriz::DS(Complex *m)
{
    Matriz *matriz_re = new Matriz (dim_matriz_v, dim_matriz_h);

    for (int u = 0; u < dim_matriz_v; u++)
    {
        for (int v = 0; v < dim_matriz_h; v++)
        {
            float p_real = (m + u + v)->Re;
            float p_imag = (m + u + v)->Im;

            matriz_re->m[u][v] = p_real * p_real + p_imag * p_imag;
        }
    }
    
    return *matriz_re;
}









#endif // MATRIZ_HPP