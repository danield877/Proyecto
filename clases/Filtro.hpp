#ifndef FILTRO_HPP
#define FILTRO_HPP
#include <cmath>
#include <iostream>


class Filtro
{

    public:

        int dim_filtro_v;
        int dim_filtro_h;

        float m[3][3];
        

        Filtro(int, int);

        void random();
        void show();

};

Filtro::Filtro(int n, int m): dim_filtro_v(n), dim_filtro_h(m){}

void Filtro::random()
{
    for (int i = 0; i < dim_filtro_v; i++)
    {
        for (int j = 0; j < dim_filtro_h; j++)
        {
            m[i][j] = ((float) rand() / (RAND_MAX)) * 2 - 1;
        }
    }
}

void Filtro::show()
{
    for (int i = 0; i < dim_filtro_v; i++)
    {
        std::cout << "|";
        for (int j = 0; j < dim_filtro_h; j++)
            {
                std::cout << " " << m[i][j] << " " ;
            }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

#endif // FILTRO_HPP