#include "Header.h"

void controlTiempos(Monta_t *this)
{
    this->flags.inteTimer0 = 0; //Limpio flag interrupcion

    this->tiempos.t500useg++; //Incremento contador

    if (this->tiempos.t500useg == 20) //Parasron 10mseg?
    {
        this->tiempos.t500useg = 0;

        this->flags.leerEntradas = 1; //Levanto flag para leer entradas
       
        this->tiempos.t100mseg++; //para 100mseg de tiempo

        //A partir de aca la base de tiempos se establece en 100mseg
        if (this->tiempos.t100mseg == 10)
        {
            this->tiempos.t100mseg = 0; //Pasaron 100mseg

        }
    }
}

#define MASCARAPUERTOB  0X1F
void leerEntradasB(Monta_t *this)
{
    uint8_t auxiliarLectura;
    uint8_t diferencia;
    
    if (!this->flags.primeraLecturaB)
    {
        this->flags.primeraLecturaB = 1;          //Hago la primer lectura
        this->entradaB.entradas = PORTB & MASCARAPUERTOB; //Enmascaro estado entradas y guardo en.entradas
    }

    auxiliarLectura = PORTB & MASCARAPUERTOB;                             //Enmascaro
    diferencia = this->entradaB.entradas - auxiliarLectura; // comparo con la primer muestra

    if (diferencia == 0) //Si dio cero, son iguales
    {
        this->contador.antirebote++;         //Incremento antirebote
        if (this->contador.antirebote == 30) //Pasaron como 300 mseg
        {
            this->contador.antirebote = 0;
            this->entradaB.entradas = auxiliarLectura; //Transfiero lectura a los flags en entrada
        }
    }
    else
    {
        auxiliarLectura = 0;
        diferencia = 0;
        this->flags.primeraLecturaB = 0;
    }
}

#define MASCARAPUERTOC  0X07
void leerEntradasC(Monta_t *this)
{
    uint8_t auxiliarLectura;
    uint8_t diferencia;

    if (!this->flags.primeraLecturaC)
    {
        this->flags.primeraLecturaC = 1;          //Hago la primer lectura
        this->entradaC.entradas = PORTC & MASCARAPUERTOC; //Enmascaro estado entradas y guardo en.entradas
    }

    auxiliarLectura = PORTC & MASCARAPUERTOC;                             //Enmascaro
    diferencia = this->entradaC.entradas - auxiliarLectura; // comparo con la primer muestra

    if (diferencia == 0) //Si dio cero, son iguales
    {
        this->contador.antirebote++;         //Incremento antirebote
        if (this->contador.antirebote == 30) //Pasaron como 300 mseg
        {
            this->contador.antirebote = 0;
            this->entradaC.entradas = auxiliarLectura; //Transfiero lectura a los flags en entrada
        }
    }
    else
    {
        auxiliarLectura = 0;
        diferencia = 0;
        this->flags.primeraLecturaC = 0;
    }
}

