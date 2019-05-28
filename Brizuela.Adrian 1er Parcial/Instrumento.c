#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "Instrumento.h"
#include "utn.h"

int ins_init(sInstrumento* insLista, int INS_CANT)
{

    int i = 0;

    for(i = 0; i < INS_CANT; i++)
    {

        insLista[i].isEmpty = 0;

    }

    return 0;
}

int ins_alta(sInstrumento* insLista, int INS_CANT)
{

    sInstrumento insNuevo;
    int indice;
    int ret = -1;
    int isValid = -1;
    //char isIntAux[50];

    indice = ins_getFreeSpot(insLista, INS_CANT);

    if(indice == -1)
    {
        printf("No hay lugar.\n");
        return ret;
    }
    else
    {

        do
        {
            printf("Ingrese nombre del instrumento: ");
            __fpurge(stdin);
            fgets(insNuevo.nombre, INS_LEN, stdin);
            quitarSaltoDeLinea(insNuevo.nombre);
            corregirNombreCompuesto(insNuevo.nombre);
            isValid = areCharacters(insNuevo.nombre);
            if(isValid == 1)
            {

                strncpy(insLista[indice].nombre, insNuevo.nombre, INS_LEN);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese codigo de tipo: ");
            __fpurge(stdin);
            fgets(insNuevo.tipo, 2, stdin);
            quitarSaltoDeLinea(insNuevo.tipo);
            isValid = isInteger(insNuevo.tipo);
            if(isValid == 1)
            {

                strncpy(insLista[indice].tipo, insNuevo.tipo, 2);
            }
        }
        while(isValid != 1);

        if(atoi(insLista[indice].tipo) == 1)
        {
            strncpy(insLista[indice].desc, "Cuerdas", INS_LEN);
        }
        else if(atoi(insLista[indice].tipo) == 2)
        {
            strncpy(insLista[indice].desc, "Viento-madera", INS_LEN);
        }
        else if(atoi(insLista[indice].tipo) == 3)
        {
            strncpy(insLista[indice].desc, "Viento-metal", INS_LEN);
        }
        else if(atoi(insLista[indice].tipo) == 4)
        {
            strncpy(insLista[indice].desc, "Percusion", INS_LEN);
        }

        if(isValid == 1)
        {
            insLista[indice].id = indice + 1;
            insLista[indice].isEmpty = 1;
            printf("Orquesta cargada exitosamente!\n");
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
        }
        ret = 0;
    }

    return ret;
}

int ins_getFreeSpot(sInstrumento* insLista, int INS_CANT)
{

    int index = -1, i=0;

    for(i=0; i<INS_CANT; i++)
    {

        if( insLista[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int ins_findById(sInstrumento* insLista, int INS_CANT, int id)
{

    int index = -1;
    int i = 0;

    for(i=0; i < INS_CANT; i++)
    {
        if( insLista[i].id == id && insLista[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void ins_mostrarUno(sInstrumento instrumento)
{

    printf("| %2i | %15s | %15s |\n", instrumento.id, instrumento.nombre, instrumento.desc);
}

void ins_listarTodos(sInstrumento* insLista, int INS_CANT)
{

    int i;

    /*printf("=====================================================================\n"
           "||                        Listado de Orquestas                     ||\n"
           "=====================================================================\n");*/
    for(i = 0; i < INS_CANT; i++)
    {

        if(insLista[i].isEmpty == 1)
        {

            ins_mostrarUno(insLista[i]);

        }

    }
    /*printf("=====================================================================\n");*/
}
