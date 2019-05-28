#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "hardcode.h"
#include "utn.h"

void orq_hardcode(sOrquesta* orqLista, int ORQ_CANT, int auxId, char* auxNombre, char* auxLugar, char* auxTipo, char* auxDesc)
{
    int index = orq_getFreeSpot(orqLista, ORQ_CANT);

    orqLista[index].id = auxId;
    strncpy(orqLista[index].nombre, auxNombre, ORQ_LEN);
    strncpy(orqLista[index].lugar, auxLugar, ORQ_LEN);
    strncpy(orqLista[index].tipo, auxTipo, 2);
    strncpy(orqLista[index].desc, auxDesc, ORQ_LEN);
    orqLista[index].isEmpty = 1;

    //Asignacion de tipo
        if(atoi(orqLista[index].tipo) == 1)
        {

            strncpy(orqLista[index].desc, "Sinfonica", ORQ_LEN);

        }
        else if(atoi(orqLista[index].tipo) == 2)
        {

            strncpy(orqLista[index].desc, "Filarmonica", ORQ_LEN);

        }
        else if(atoi(orqLista[index].tipo) == 3)
        {

            strncpy(orqLista[index].desc, "Camara", ORQ_LEN);

        }

}

void mus_hardcode(sInstrumento* insLista, int INS_CANT, sOrquesta* orqLista, int ORQ_CANT, sMusico* musLista, int MUS_CANT, int auxId, char* auxNombre, char* auxApellido, char* auxEdad, char* auxIdOrquesta, char* auxDescOrq, char* auxIdInstrumento, char* auxDescIns)
{

    int index = mus_getFreeSpot(musLista, MUS_CANT);
    int i;

    musLista[index].id = auxId;
    strncpy(musLista[index].nombre, auxNombre, MUS_LEN);
    strncpy(musLista[index].apellido, auxApellido, MUS_LEN);
    strncpy(musLista[index].edad, auxEdad, 3);
    strncpy(musLista[index].descIns, auxDescIns, MUS_LEN);
    strncpy(musLista[index].descOrq, auxDescOrq, MUS_LEN);
    strncpy(musLista[index].idOrquesta, auxIdOrquesta, 5);
    strncpy(musLista[index].idInstrumento, auxIdInstrumento, 5);
    musLista[index].isEmpty = 1;

    //Asignacion de tipo
        for(i = 0; i<INS_CANT; i++)
        {
            if(atoi(musLista[index].idInstrumento) == insLista[i].id)
            {
                strncpy(musLista[index].descIns, insLista[i].nombre, MUS_LEN);
                break;
            }
        }

        //Asignacion de Orquesta
        for(i = 0; i<ORQ_CANT; i++)
        {
            if(atoi(musLista[index].idOrquesta) == orqLista[i].id)
            {
                strncpy(musLista[index].descOrq, orqLista[i].nombre, ORQ_LEN);
                break;
            }
        }

}

void ins_hardcode(sInstrumento* insLista, int INS_CANT, int auxId, char* auxNombre, char* auxTipo, char* auxDesc){

    int index = ins_getFreeSpot(insLista, INS_CANT);

    insLista[index].id = auxId;
    strncpy(insLista[index].nombre, auxNombre, INS_LEN);
    strncpy(insLista[index].tipo, auxTipo, INS_LEN);
    strncpy(insLista[index].desc, auxDesc, INS_LEN);
    insLista[index].isEmpty = 1;

    if(atoi(insLista[index].tipo) == 1)
        {
            strncpy(insLista[index].desc, "Cuerdas", INS_LEN);
        }
        else if(atoi(insLista[index].tipo) == 2)
        {
            strncpy(insLista[index].desc, "Viento-madera", INS_LEN);
        }
        else if(atoi(insLista[index].tipo) == 3)
        {
            strncpy(insLista[index].desc, "Viento-metal", INS_LEN);
        }
        else if(atoi(insLista[index].tipo) == 4)
        {
            strncpy(insLista[index].desc, "Percusion", INS_LEN);
        }

}
