//==========================================================================================================================================================
//
// FFT_1d class
//
//==========================================================================================================================================================

/*!
*   \file       FFT_1d.hpp
*   \brief      Clase para calcular la FFT.
*   \details    Una clase que contiene un metodo para calcular la FFT de un array.
*   \author     Daniel Reyes Barrera
*   \version    1.0
*   \date       2021
*   \copyright  GNU Public License.
*/

#ifndef FFT_1D_HPP
#define FFT_1D_HPP

#include <cmath>
#include <Complex.hpp>

//! Clase FFT_1d
/*!
Esta clase contiene un metodo para calcular la FFT de un array.
*/

class FFT_1d
{
    public:
        //! Metodo para calcular la FFT de un array.
        /*!
        \param[in] N Tamaño del array.
        \param[in] *array Array de los datos de entrada para la DFT y donde se guardaran los calculos.
        \param[in] E Cantidad total de etapas.
        */
        void FFT(int N, Complex *array, int E);

    private:
        //! Wn es la funcion de ponderacion exponencial en la forma a + ib.
        Complex Wn;
        //! Variable auxiliar temporal.
        Complex TEMP; 
        //! Puntero que apunta al valor bajo en la mariposa.
        Complex *pLo;
        //! Puntero que apunta al valor alto en la mariposa.
        Complex *pHi;
        
        //! Ancho de la mariposa.
        int Mari_Ancho; 
        //! Distancia al valor bajo.   
        int Mari_Opuesto;
        //! Cantidad de Wn similares   
        int P;
        //! Valor axuliar para el calculo de la mariposa.      
        int j; 
        //! Etapa en el calculo de la mariposa.    
        int Etapa;
        //! Indice al valor alto de la mariposa.
        int HiIndex;   

        //! Variables auxiliares para ahorrar calculo.
        double TwoPi_NP;
        double TwoPi_N;
};

/* PUBLIC METHODS */

void FFT_1d::FFT(int N, Complex *array, int E)
{
    Complex *parray = array; 
    TwoPi_N = 2 * M_PI / N;
    for (Etapa = 1; Etapa <= E; Etapa++) 
    {
        Mari_Ancho = (int)(pow(2, Etapa)); 
        P = N / Mari_Ancho;                
        Mari_Opuesto = Mari_Ancho / 2;    
        TwoPi_NP = TwoPi_N * P;
        for (j = 0; j < Mari_Opuesto; j++)
        {
            if (j != 0) 
            {          
                Wn.Re = cos(TwoPi_NP * j);
                Wn.Im = -sin(TwoPi_NP * j);
            }
            for (HiIndex = j; HiIndex < N; HiIndex += Mari_Ancho) 
            {
                pHi = parray + HiIndex; 
                pLo = pHi + Mari_Opuesto; 
                if (j != 0)
                {
                   
                    TEMP.Re = (pLo->Re * Wn.Re) - (pLo->Im * Wn.Im);
                    TEMP.Im = (pLo->Re * Wn.Im) + (pLo->Im * Wn.Re);

                    pLo->Re = pHi->Re - TEMP.Re; 
                    pLo->Im = pHi->Im - TEMP.Im;

                    pHi->Re = (pHi->Re + TEMP.Re);
                    pHi->Im = (pHi->Im + TEMP.Im);
                }
                else
                {
                    TEMP.Re = pLo->Re;
                    TEMP.Im = pLo->Im;

                    pLo->Re = pHi->Re - TEMP.Re; 
                    pLo->Im = pHi->Im - TEMP.Im;

                    pHi->Re = (pHi->Re + TEMP.Re);
                    pHi->Im = (pHi->Im + TEMP.Im);
                }
            }
        }
    }

    pLo = 0; 
    pHi = 0;
    parray = 0;
    array = 0;
}

#endif // FFT_1D_HPP