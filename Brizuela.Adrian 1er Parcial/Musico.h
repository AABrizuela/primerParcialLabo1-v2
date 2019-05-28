#ifndef MUSICO_H
#define MUSICO_H

#include "Instrumento.h"

#define MUS_LEN 51

typedef struct{

    int id;
    char nombre[MUS_LEN];
    char apellido[MUS_LEN];
    char edad[3];
    char idOrquesta[5];
    char idInstrumento[5];
    int isEmpty;
    char descIns[MUS_LEN];
    char descOrq[MUS_LEN];

}sMusico;

int mus_init(sMusico* musLista, int MUS_CAN);
int mus_alta(sMusico* musLista, int MUS_CANT, sOrquesta* orqLista, int ORQ_CANT, sInstrumento* insLista, int INS_CANT);
int mus_getFreeSpot(sMusico* musLista, int MUS_CAN);
int mus_baja(sMusico* musLista, int MUS_CAN);
int mus_findById(sMusico* musLista, int MUS_CAN, int id);
void mus_mostrarUno(sMusico musico);
void mus_listarTodos(sMusico* musLista, int MUS_CAN);
int mus_modificacion(sMusico* musLista, int MUS_CANT, sOrquesta* orqLista, int ORQ_CANT);
void mus_mostrarUnoEdit(sMusico musico);
void mus_listarTodosEdit(sMusico* musLista, int MUS_CANT);

#endif // MUSICO_H
