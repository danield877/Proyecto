#include <cmath>

/* PUBLIC METHODS */

class DFT_1d
{
    public:
        DFT
}

void DFT_1d::DFT(Complex *array, int N)
{
    Complex *TEMP = new Complex[N];
    float TWOPI_N = 2 * M_PI / N;
    for (int i = 0; i < N; i++)
    {
        float TWOPI_N_i = TWOPI_N * i;
        real_sum = 0;
        img_sum = 0;
        for (int k = 0; k < N; k++)
        {
            if (i == 0)
            {
                (TEMP + k)->Re = (array + k)->Re;
            }
            real_sum += (TEMP + k)->Re * cos(TWOPI_N_i * k);
            img_sum -= (TEMP + k)->Re * sin(TWOPI_N_i * k);
        }
        (array + i)->Re = real_sum;
        (array + i)->Im = img_sum;
    }
    delete[] TEMP;
}