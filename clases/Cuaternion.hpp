#include <cmath>
#include <iostream>


Cuaternion::Cuaternion(double real, double ima_i, double ima_j, double ima_k) : r(real), i(ima_i), k(ima_k), j(ima_j)
{
}

double Cuaternion::real()
{
    return r;
}

double Cuaternion::imag_i()
{
    return i;
}

double Cuaternion::imag_j()
{
    return j;
}

double Cuaternion::imag_k()
{
    return k;
}

double Cuaternion::abs()
{
    return sqrt(r * r + i * i + j * j + k * k);
}

double Cuaternion::norma()
{
    return r * r + i * i + j * j + k * k;
}

Cuaternion Cuaternion::conju()
{
    return Cuaternion(r, -i, -j, -k);
}

void Cuaternion::show()
{
    std::cout << r << " + " << i << "i + " << j << "j + " << k << "k" << std::endl;
}

double Cuaternion::dot(Cuaternion Q)
{
    return r * Q.r + i * Q.i + j * Q.j + k * Q.k;
}

Cuaternion Cuaternion::operator+(Cuaternion Q)
{
    return  Cuaternion(r + Q.r, i + Q.i, j + Q.j, k + Q.k);
}

Cuaternion Cuaternion::operator-(Cuaternion Q)
{
    return Cuaternion(r - Q.r, i - Q.i, j - Q.j, k - Q.k);
}

Cuaternion Cuaternion::operator*(Cuaternion Q)
{
    return Cuaternion(
    r * Q.r - i * Q.i - j * Q.j - k * Q.k,
    i * Q.r + r * Q.i + j * Q.k - k * Q.j, 
    j * Q.r + r * Q.j + k * Q.i - i * Q.k, 
    k * Q.r + r * Q.k + i * Q.j - j * Q.i);
}

Cuaternion Cuaternion::normalizado()
{
    return 0;
}