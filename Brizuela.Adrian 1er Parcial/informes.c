#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "hardcode.h"
#include "utn.h"
#include "informes.h"

void inf_subMenu(sOrquesta* orqLista, int ORQ_CANT, sMusico* musLista, int MUS_CANT, sInstrumento* insLista, int INS_CANT)
{
    int optionSubMenu = 0;

    do
    {
        system("clear");
        printf("*** BIENVENIDO ***\n\n");

        printf("\t1.- Listar las orquestas de un lugar en particular ingresado por el usuario.\n");
        printf("\t2.- Listar los musicos de menos de 25 anios.\n");
        printf("\t3.- Listar las orquestas con menos de 6 musicos.\n");
        printf("\t4.- Listar todos los instrumentos de una orquesta determinada (por ID).\n");
        printf("\t5.- Listar orquestas completas.\n");
        printf("\t6.- Listar la orquesta con menos musicos.\n");
        printf("\t7.- Listar el promedio de instrumentos por orquesta.\n");
        printf("\t8.- Listar musicos que NO toquen instrumentos de viento.\n");
        printf("\t9.- Volver.\n\n");


        printf("Ingrese opcion: ");
        scanf("%d", &optionSubMenu);
        printf("\n");

        switch(optionSubMenu)
        {

        case 1:
            inf_puntoA(orqLista, ORQ_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 2:
            inf_puntoB(orqLista, ORQ_CANT, insLista, INS_CANT, musLista, MUS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 3:
            inf_puntoC(orqLista, ORQ_CANT, musLista, MUS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 4:
            inf_puntoD(musLista, MUS_CANT, insLista, INS_CANT, orqLista, ORQ_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 5:
            inf_puntoE(orqLista, ORQ_CANT, musLista, MUS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 6:
            inf_puntoF(orqLista, ORQ_CANT, musLista, MUS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 7:
            inf_puntoG(musLista, MUS_CANT, orqLista, ORQ_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 8:
            inf_puntoH(musLista, MUS_CANT, insLista, INS_CANT);
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        case 9:
            break;

        default:
            printf("Las opciones correctas van del 1 al 9. Reingrese.");
            __fpurge(stdin);
            printf("Prsione cualquier tecla para continuar...");
            getchar();
            break;

        }
    }
    while(optionSubMenu != 9);
}

void inf_puntoA(sOrquesta* orqLista, int ORQ_CANT)
{

    char lugarAux[ORQ_LEN];
    int i;
    int isValid;
    //int value;

    printf("Ingrese lugar de la orquesta: ");
    __fpurge(stdin);
    fgets(lugarAux, ORQ_LEN, stdin);
    quitarSaltoDeLinea(lugarAux);
    corregirNombreCompuesto(lugarAux);
    isValid = isAlphaNumeric(lugarAux);

    if(isValid == 1)
    {
        for(i = 0; i < ORQ_CANT; i++)
        {

            if(strncmp(orqLista[i].lugar, lugarAux, ORQ_LEN) == 0 && orqLista[i].isEmpty == 1)
            {

                printf("| %2i | %25s | %15s | %15s |\n", orqLista[i].id, orqLista[i].nombre, orqLista[i].desc, orqLista[i].lugar);

            }
        }
    }
}

void inf_puntoB(sOrquesta* orqLista, int ORQ_CANT, sInstrumento* insLista, int INS_CANT, sMusico* musLista, int MUS_CANT)
{
    int i;

    for(i = 0; i < MUS_CANT; i++)
    {

        if(atoi(musLista[i].edad) < 25 && musLista[i].isEmpty == 1)
        {

            printf("| %2i | %10s | %10s | %3s | %10s | %25s |\n", musLista[i].id, musLista[i].nombre, musLista[i].apellido, musLista[i].edad, musLista[i].descIns, musLista[i].descOrq);

        }
    }
}

void inf_puntoC(sOrquesta* orqLista, int ORQ_CANT, sMusico* musLista, int MUS_CANT)
{

    int i;
    int j;
    int contadorOrq = 0;

    for(j=0; j < ORQ_CANT; j++)
    {
        for(i=0; i < MUS_CANT; i++)
        {

            if(atoi(musLista[i].idOrquesta) == orqLista[j].id && musLista[i].isEmpty == 1 && orqLista[j].isEmpty == 1)
            {
                contadorOrq++;
            }

        }

        if(contadorOrq < 6)
        {

            printf("| %2i | %10s | %15s | %10s |\n", orqLista[j].id, orqLista[j].nombre, orqLista[j].desc, orqLista[j].lugar);
            contadorOrq = 0;
        }
    }

}

void inf_puntoD(sMusico* musLista, int MUS_CANT, sInstrumento* insLista, int INS_CANT, sOrquesta* orqLista, int ORQ_CANT)
{

    char idAux[2];
    char auxTipo[INS_LEN];
    int i;
    int j;
    int k;
    int isValid;

    printf("Ingrese id de la orquesta: ");
    __fpurge(stdin);
    fgets(idAux, 2, stdin);
    quitarSaltoDeLinea(idAux);
    isValid = isInteger(idAux);

    if(isValid == 1)
    {
        for(i = 0; i < ORQ_CANT; i++)
        {
            if(orqLista[i].id == atoi(idAux) && orqLista[i].isEmpty == 1)
            {
                for(j=0; j < MUS_CANT; j++)
                {
                    if(atoi(musLista[j].idOrquesta) == orqLista[i].id && musLista[j].isEmpty == 1)
                    {
                        for(k=0; k < INS_CANT; k++)
                        {
                            if(atoi(musLista[j].idInstrumento) == insLista[k].id && insLista[k].isEmpty == 1)
                            {

                                strncpy(auxTipo, insLista[k].desc, MUS_LEN);
                                printf("| %10s | %15s | %10s |\n", musLista[j].descIns, auxTipo, musLista[j].nombre);
                            }
                        }
                    }
                }
            }
        }
    }
}

void inf_puntoE(sOrquesta* orqLista, int ORQ_CANT, sMusico* musLista, int MUS_CANT)
{

    int i;
    int j;
    int contadorPerc = 0;
    int contadorCuer = 0;
    int contadorVien = 0;

    for(j=0; j < ORQ_CANT; j++)
    {
        for(i=0; i < MUS_CANT; i++)
        {
            if(orqLista[j].id == atoi(musLista[i].idOrquesta) && atoi(musLista[i].idInstrumento) == 1 && musLista[i].isEmpty == 1 && orqLista[j].isEmpty == 1)
            {
                contadorCuer++;

            }
            else if(orqLista[j].id == atoi(musLista[i].idOrquesta) && (atoi(musLista[i].idInstrumento) == 2 || atoi(musLista[i].idInstrumento) == 3) && musLista[i].isEmpty == 1 && orqLista[j].isEmpty == 1)
            {
                contadorVien++;

            }
            else if(orqLista[j].id == atoi(musLista[i].idOrquesta) && atoi(musLista[i].idInstrumento) == 4 && musLista[i].isEmpty == 1 && orqLista[j].isEmpty == 1)
            {
                contadorPerc++;
            }
        }

        if(contadorCuer > 4 && contadorVien > 4 && contadorPerc > 0)
        {

            printf("| %2i | %10s | %15s | %10s |\n", orqLista[j].id, orqLista[j].nombre, orqLista[j].desc, orqLista[j].lugar);
            contadorCuer = 0;
            contadorPerc = 0;
            contadorVien = 0;
        }
    }

}

void inf_puntoF(sOrquesta* orqLista, int ORQ_CANT, sMusico* musLista, int MUS_CANT)
{

    int i;
    int j;
    int contadorMusicos = 0;
    int menor = 0;
    int flag = 0;

    for(j=0; j < ORQ_CANT; j++)
    {
        for(i=0; i < MUS_CANT; i++)
        {
            if(orqLista[j].id == atoi(musLista[i].idOrquesta) && musLista[i].isEmpty == 1 && orqLista[j].isEmpty == 1)
            {
                contadorMusicos++;
            }
        }

        if (contadorMusicos >= 0 && flag == 0)
        {

            menor = contadorMusicos;
            flag = 1;

        }else if(contadorMusicos < menor){

            menor = contadorMusicos;

        }

        if(contadorMusicos <= menor && orqLista[j].isEmpty == 1)
        {

            printf("| %2i | %10s | %15s | %10s | Cant musicos: %2i |\n", orqLista[j].id, orqLista[j].nombre, orqLista[j].desc, orqLista[j].lugar, contadorMusicos);
            contadorMusicos = 0;
        }
    }
    flag = 0;
}

void inf_puntoG(sMusico* musLista, int MUS_CANT, sOrquesta* orqLista, int ORQ_CANT){

    int i;
    int j;
    int contOrq = 0;
    int contMus = 0;
    int promedio;

    for(i = 0; i < ORQ_CANT; i++){

        if(orqLista[i].isEmpty == 1){
            contOrq++;
        }
    }

    for(i = 0; i < MUS_CANT; i++){

        if(musLista[i].isEmpty == 1){
            contMus++;
        }
    }

    promedio = contMus / contOrq;

    printf("El promedio de instrumentos por orquesta es: %i\n", promedio);

}

void inf_puntoH(sMusico* musLista, int MUS_CANT, sInstrumento* insLista, int INS_CANT)
{

    int i;
    int j;
    char tipoAux[INS_LEN];

    for(i = 0; i < MUS_CANT; i++)
    {
        for(j = 0; j < INS_CANT; j++)
        {
            if(strncmp(insLista[j].desc, "Viento-madera", MUS_LEN) != 0 && strncmp(insLista[j].desc, "Viento-metal", MUS_LEN) != 0 && musLista[i].isEmpty == 1)
            {
                strncpy(tipoAux, insLista[j].desc, INS_LEN);
                printf("| %10s | %10s | %2s | %10s |\n", musLista[i].nombre, musLista[i].apellido, musLista[i].edad, tipoAux);
                break;
            }
        }
    }

}
