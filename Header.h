#ifndef  _HEADER_H
#define _HEADER_H

#include <pic.h>
#include <stdint.h>
#include <pic16f886.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "16F886.h"

typedef union
{
    uint8_t genericFlags;
    struct
    {
        unsigned inteTimer0 : 1;
        unsigned leerEntradas : 1;
        unsigned primeraLecturaB : 1;
        unsigned primeraLecturaC : 1;
    };

} Flags_t;

typedef union{

    uint16_t twoBytes;
    struct 
    {
        unsigned low:8;
        unsigned high:8;
    };
    
}Split_t;


typedef union
{
    uint8_t entradas;
    struct
    {
        unsigned in1 : 1; //LSB
        unsigned in2 : 1;
        unsigned in3 : 2;
        unsigned in4 : 1;
        unsigned in5 : 1;
        unsigned in6 : 1; //
        unsigned in7 : 1; //
        unsigned in8 : 1; //MSB
    };
} Entradas_t;


typedef struct
{
    uint8_t t500useg;
    uint8_t t100mseg;
    uint8_t loco;
    uint8_t t1seg;
} Timers_t; 

typedef struct
{
    uint8_t antirebote;
    uint8_t confirmar220;
    uint8_t intentosArranque;

} Contadores_t;

typedef struct
{
    uint8_t estado;
    Flags_t flags;
    Timers_t tiempos;
    Entradas_t entradaB;
    Entradas_t entradaC;
    Contadores_t contador;
}Monta_t;




#include "funciones.h"

#endif //  _HEADER_H

