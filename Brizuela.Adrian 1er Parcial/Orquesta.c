#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "Orquesta.h"
#include "utn.h"

int orq_init(sOrquesta* orqLista, int ORQ_CANT)
{

    int i = 0;

    for(i = 0; i < ORQ_CANT; i++)
    {

        orqLista[i].isEmpty = 0;

    }

    return 0;
}

int orq_alta(sOrquesta* orqLista, int ORQ_CANT)
{

    sOrquesta orqNueva;
    int indice;
    int ret = -1;
    int isValid = -1;


    indice = orq_getFreeSpot(orqLista, ORQ_CANT);

    if(indice == -1)
    {
        printf("No hay lugar.\n");
        return ret;
    }
    else
    {

        do
        {
            printf("Ingrese nombre de orquesta: ");
            __fpurge(stdin);
            fgets(orqNueva.nombre, ORQ_LEN, stdin);
            quitarSaltoDeLinea(orqNueva.nombre);
            corregirNombreCompuesto(orqNueva.nombre);
            isValid = areCharacters(orqNueva.nombre);
            if(isValid == 1)
            {

                strncpy(orqLista[indice].nombre, orqNueva.nombre, ORQ_LEN);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese lugar de orquesta: ");
            __fpurge(stdin);
            fgets(orqNueva.lugar, ORQ_LEN, stdin);
            quitarSaltoDeLinea(orqNueva.lugar);
            corregirNombreCompuesto(orqNueva.lugar);
            isValid = areCharacters(orqNueva.lugar);
            if(isValid == 1)
            {

                strncpy(orqLista[indice].lugar, orqNueva.lugar, ORQ_LEN);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese codigo de tipo: ");
            __fpurge(stdin);
            fgets(orqNueva.tipo, 2, stdin);
            quitarSaltoDeLinea(orqNueva.tipo);
            isValid = isInteger(orqNueva.tipo);
            if(isValid == 1)
            {

                strncpy(orqLista[indice].tipo, orqNueva.tipo, 2);
            }
        }
        while(isValid != 1);

        //asignacion de tipo
        if(atoi(orqLista[indice].tipo) == 1)
        {

            strncpy(orqLista[indice].desc, "Sinfonica", ORQ_LEN);

        }
        else if(atoi(orqLista[indice].tipo) == 2)
        {

            strncpy(orqLista[indice].desc, "Filarmonica", ORQ_LEN);

        }
        else if(atoi(orqLista[indice].tipo) == 3)
        {

            strncpy(orqLista[indice].desc, "Camara", ORQ_LEN);

        }

        if(isValid == 1)
        {
            orqLista[indice].id = indice + 1;
            orqLista[indice].isEmpty = 1;
            printf("Orquesta cargada exitosamente!\n");

        }
        ret = 0;
    }

    return ret;

}

int orq_getFreeSpot(sOrquesta* orqLista, int ORQ_CANT)
{

    int index = -1, i=0;

    for(i=0; i<ORQ_CANT; i++)
    {

        if( orqLista[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

}

int orq_baja(sOrquesta* orqLista, int ORQ_CANT)
{

    int id;
    int indice;
    int ret = -1;
    char autorBorrar;
    sOrquesta orquesta;

    printf("Ingrese codigo: ");
    scanf("%d", &id);

    indice = orq_findById(orqLista, ORQ_CANT, id);

    if(indice == -1)
    {

        printf("No hay ninguna orquesta con el id %d\n", id);

    }
    else
    {

        orquesta = orqLista[indice];
        orq_mostrarUno(orquesta);

        printf("\nConfirma borrado? S/N ");
        __fpurge(stdin);
        scanf("%c", &autorBorrar);
        if(autorBorrar != 's')
        {
            printf("Borrado cancelado.\n\n");
        }
        else
        {

            orqLista[indice].isEmpty = 0;
            printf("Se ha eliminado el orquesta.\n\n");
            ret = 0;
        }
        __fpurge(stdin);
        printf("Prsione cualquier tecla para continuar...");
        getchar();
    }

    return ret;
}

int orq_findById(sOrquesta* orqLista, int ORQ_CANT, int id)
{

    int index = -1;
    int i = 0;

    for(i=0; i < ORQ_CANT; i++)
    {
        if( orqLista[i].id == id && orqLista[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void orq_mostrarUno(sOrquesta orquesta)
{

    printf("| %2i | %25s | %10s | %15s |\n", orquesta.id, orquesta.nombre, orquesta.lugar, orquesta.desc);
}

void orq_listarTodos(sOrquesta* orqLista, int ORQ_CANT)
{

    int i;

    /*printf("=====================================================================\n"
           "||                        Listado de Orquestas                     ||\n"
           "=====================================================================\n");*/
    for(i = 0; i < ORQ_CANT; i++)
    {

        if(orqLista[i].isEmpty == 1)
        {

            orq_mostrarUno(orqLista[i]);

        }

    }

    /*printf("=====================================================================\n");*/

}

