#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "utn.h"

int mus_init(sMusico* musLista, int MUS_CANT)
{

    int i = 0;

    for(i = 0; i < MUS_CANT; i++)
    {

        musLista[i].isEmpty = 0;

    }

    return 0;
}
int mus_alta(sMusico* musLista, int MUS_CANT, sOrquesta* orqLista, int ORQ_CANT, sInstrumento* insLista, int INS_CANT)
{

    sMusico musNuevo;
    int indice;
    int ret = -1;
    int isValid = -1;
    int i;

    indice = mus_getFreeSpot(musLista, MUS_CANT);

    if(indice == -1)
    {
        printf("No hay lugar.\n");
        return ret;
    }
    else
    {

        do
        {
            printf("Ingrese nombre de musico: ");
            __fpurge(stdin);
            fgets(musNuevo.nombre, MUS_LEN, stdin);
            quitarSaltoDeLinea(musNuevo.nombre);
            corregirNombreCompuesto(musNuevo.nombre);
            isValid = areCharacters(musNuevo.nombre);
            if(isValid == 1)
            {

                strncpy(musLista[indice].nombre, musNuevo.nombre, MUS_LEN);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese apellido de musico: ");
            __fpurge(stdin);
            fgets(musNuevo.apellido, MUS_LEN, stdin);
            quitarSaltoDeLinea(musNuevo.apellido);
            corregirNombreCompuesto(musNuevo.apellido);
            isValid = areCharacters(musNuevo.apellido);
            if(isValid == 1)
            {

                strncpy(musLista[indice].apellido, musNuevo.apellido, MUS_LEN);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese edad: ");
            __fpurge(stdin);
            fgets(musNuevo.edad, 3, stdin);
            quitarSaltoDeLinea(musNuevo.edad);
            isValid = isInteger(musNuevo.edad);
            if(isValid == 1)
            {

                strncpy(musLista[indice].edad, musNuevo.edad, 3);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese codigo de instrumento: ");
            __fpurge(stdin);
            fgets(musNuevo.idInstrumento, 5, stdin);
            quitarSaltoDeLinea(musNuevo.idInstrumento);
            isValid = isInteger(musNuevo.idInstrumento);
            if(isValid == 1)
            {

                strncpy(musLista[indice].idInstrumento, musNuevo.idInstrumento, 5);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese codigo de orquesta: ");
            __fpurge(stdin);
            fgets(musNuevo.idOrquesta, 5, stdin);
            quitarSaltoDeLinea(musNuevo.idOrquesta);
            isValid = isInteger(musNuevo.idOrquesta);
            if(isValid == 1)
            {

                strncpy(musLista[indice].idOrquesta, musNuevo.idOrquesta, 5);

            }
        }
        while(isValid != 1);

        //Asignacion de tipo
        for(i = 0; i<INS_CANT; i++)
        {
            if(atoi(musLista[indice].idInstrumento) == insLista[i].id)
            {

                strncpy(musLista[indice].descIns, insLista[i].nombre, MUS_LEN);
                break;
            }
        }

        //Asignacion de Orquesta
        for(i = 0; i<ORQ_CANT; i++)
        {
            if(atoi(musLista[indice].idOrquesta) == orqLista[i].id)
            {
                strncpy(musLista[indice].descOrq, orqLista[i].nombre, ORQ_LEN);
                break;
            }
        }

        if(isValid == 1)
        {
            musLista[indice].id = indice + 1;
            musLista[indice].isEmpty = 1;
            printf("Musico cargado exitosamente!\n");
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
        }
        ret = 0;
    }

    return ret;
}

int mus_getFreeSpot(sMusico* musLista, int MUS_CANT)
{

    int index = -1, i=0;

    for(i=0; i<MUS_CANT; i++)
    {

        if( musLista[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int mus_baja(sMusico* musLista, int MUS_CANT)
{

    int id;
    int indice;
    int ret = -1;
    char autorBorrar;
    sMusico musico;

    printf("Ingrese codigo: ");
    scanf("%d", &id);

    indice = mus_findById(musLista, MUS_CANT, id);

    if(indice == -1)
    {

        printf("No hay ningun musico con el id %d\n", id);

    }
    else
    {

        musico = musLista[indice];
        mus_mostrarUno(musico);

        printf("\nConfirma borrado? S/N ");
        __fpurge(stdin);
        scanf("%c", &autorBorrar);
        if(autorBorrar != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {

            musLista[indice].isEmpty = 0;
            printf("Se ha eliminado el musico.\n\n");
            ret = 0;
        }
        __fpurge(stdin);
        printf("Prsione cualquier tecla para continuar...");
        getchar();
    }

    return ret;
}

int mus_findById(sMusico* musLista, int MUS_CANT, int id)
{
    int index = -1;
    int i = 0;

    for(i=0; i < MUS_CANT; i++)
    {
        if( musLista[i].id == id && musLista[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mus_mostrarUno(sMusico musico)
{

    printf("| %4i | %15s | %15s | %25s | %15s |\n", musico.id, musico.nombre, musico.apellido, musico.descOrq, musico.descIns);

}

void mus_mostrarUnoEdit(sMusico musico)
{

    printf("| %4i | %15s | %15s |\n", musico.id, musico.nombre, musico.apellido);

}

void mus_listarTodos(sMusico* musLista, int MUS_CANT)
{
    int i;

    /*printf("==========================================================================================\n"
           "||                                  Listado de Orquestas                                ||\n"
           "==========================================================================================\n"
           "|  ID  |     NOMBRE      |    APELLIDO     |          ORQUESTA         |   INSTRUMENTO   |\n"
           "==========================================================================================\n");*/
    for(i = 0; i < MUS_CANT; i++)
    {

        if(musLista[i].isEmpty == 1)
        {

            mus_mostrarUno(musLista[i]);

        }

    }
    /*printf("==========================================================================================\n");*/

}

void mus_listarTodosEdit(sMusico* musLista, int MUS_CANT)
{
    int i;

    /*printf("==========================================================================================\n"
           "||                                  Listado de Orquestas                                ||\n"
           "==========================================================================================\n"
           "|  ID  |     NOMBRE      |    APELLIDO     |          ORQUESTA         |   INSTRUMENTO   |\n"
           "==========================================================================================\n");*/
    for(i = 0; i < MUS_CANT; i++)
    {

        if(musLista[i].isEmpty == 1)
        {

            mus_mostrarUnoEdit(musLista[i]);

        }

    }
    /*printf("==========================================================================================\n");*/

}

int mus_modificacion(sMusico* musLista, int MUS_CANT, sOrquesta* orqLista, int ORQ_CANT)
{

    int index;
    char idAux[4];
    int isValid;
    int ret = -1;
    int optionEdit = 0;
    int i;
    sMusico musico;

    do
    {
        mus_listarTodosEdit(musLista, MUS_CANT);
        printf("Ingrese id a modificar: ");
        __fpurge(stdin);
        fgets(idAux, 4, stdin);
        quitarSaltoDeLinea(idAux);
        isValid = isInteger(idAux);
    }
    while(isValid != 1);

    index = mus_findById(musLista, MUS_CANT, atoi(idAux));

    if(index == -1)
    {

        printf("No hay ningun musico con el id %s\n", idAux);
        __fpurge(stdin);
        printf("Prsione cualquier tecla para continuar...");
        getchar();
    }
    else
    {
        do
        {
            musico = musLista[index];

            system("clear");
            printf("Musico a modificar: \n");
            mus_mostrarUno(musico);

            printf("1.- Edad.\n");
            printf("2.- Codigo de Orquesta.\n");
            printf("3.- Salir.");

            printf("\nQue desea modificar?\n\n");
            __fpurge(stdin);
            scanf("%d", &optionEdit);

            switch(optionEdit)
            {

            case 1:
                do
                {
                    printf("Ingrese nueva edad: ");
                    __fpurge(stdin);
                    fgets(musico.edad, 3, stdin);
                    quitarSaltoDeLinea(musico.edad);
                    isValid = isInteger(musico.edad);
                    if(isValid == 1)
                    {

                        strncpy(musLista[index].edad, musico.edad, 3);

                    }
                    printf("Edad modificada exitosamente!\n");
                }
                while(isValid != 1);
                break;

            case 2:
                do
                {
                    printf("Ingrese nuevo codigo de orquesta: ");
                    __fpurge(stdin);
                    fgets(musico.idOrquesta, 5, stdin);
                    quitarSaltoDeLinea(musico.idOrquesta);
                    isValid = isInteger(musico.idOrquesta);
                    if(isValid == 1)
                    {

                        strncpy(musLista[index].idOrquesta, musico.idOrquesta, 5);

                    }
                    printf("Codigo modificado exitosamente!\n");
                }
                while(isValid != 1);

                //Asignacion de Orquesta
                for(i = 0; i< ORQ_CANT; i++)
                {
                    if(atoi(musLista[index].idOrquesta) == orqLista[i].id)
                    {
                        strncpy(musLista[index].descOrq, orqLista[i].nombre, ORQ_LEN);
                        break;
                    }
                }
                break;

            case 3:
                break;

            default:
                printf("Error. Las opciones van del 1 al 3.");

            }

        }
        while(optionEdit != 3);
    }

    return ret;

}
