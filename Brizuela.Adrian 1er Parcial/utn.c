#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

/** \brief Toma una cadena de caracteres para validarlo como solo caracteres
 *
 * \param char cadena[]
 * \return devuelve 1 si es solo son caracteres o 0 si no lo es
 *
 */
int areCharacters(char *cadena)
{
    int retorno = 1, i = 0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Toma una cadena de numeros para validarlo como entero
 *
 * \param char cadena[]
 * \return devuelve 1 si es entero o 0 si no lo es
 *
 */
int isInteger(char *cadena)
{
    int retorno = 1, i = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] < '0' || cadena[i] > '9')
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Toma una cadena de numeros para validarlo como flotante
 *
 * \param char cadena[]
 * \return devuelve 1 si es flotante o 0 si no lo es
 *
 */
int isFloat(char *cadena)
{
    int retorno = 1, i = 0, cantidadPuntos=0;
    while(cadena[i] != '\0')
    {
        if (cadena[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;
        }
        if(cadena[i] < '0' || cadena[i] > '9')
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Toma un caracter para validarlo como de acuerdo a letra(s) especificada(s)
 *
 * \param char caracter
 * \return devuelve 1 si el valor es el esperado o 0 si no lo es
 *
 */
int isCharacter(char caracter)
{
    //Utilizado para validar sexo
    int retorno = 0;
    strlwr(&caracter);
    if ((caracter == 'f') || (caracter == 'm'))
        retorno = 1;
    return retorno;
}

/** \brief Toma una cadena de caracteres para validarlo como caracteres & numeros
 *
 * \param char cadena[]
 * \return devuelve 1 si es solo son caracteres & numeros o 0 si no lo es
 *
 */
int isAlphaNumeric(char *cadena)
{
    int retorno = 1, i = 0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9'))
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param cadena
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int isTelephone(char *cadena)
{
    int i = 0, retorno;
    int contadorGuiones = 0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != '+') && (cadena[i] != '-') && (cadena[i] < '0' || cadena[i] > '9'))
            retorno = 0;
        if(cadena[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones) // debe tener un guion
        retorno = 1;
    return retorno;
}

int isEmail(char *cadena)
{
    int i = 0, retorno;
    int contadorArroba = 0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != '.') && (cadena[i] != '-') && (cadena[i] != '_') && (cadena[i] != '@') && (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            retorno = 0;
        }
        if(cadena[i] == '@')
        {
            contadorArroba++;
        }
        i++;
    }
    if(contadorArroba == 1)
    {
        retorno = 1;
    }
    return retorno;
}

/** \brief Valida los tres enteros ingresados como fecha.
 *
 * \param day
 * \param month
 * \param year
 * \return Retorna 1 si es valida o 0 si no lo es.
 *
 */
int isFecha(int day, int month, int year)
{
    int retorno = 0;
    if (month >= 1 && month <= 12)
    {
        switch (month)
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if (day >= 1 && day <= 31)
                retorno = 1;
            break;
        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( day >= 1 && day <= 30 )
                retorno = 1;
            break;
        case  2 :
            if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
            {
                if ( day >= 1 && day <= 29 )
                {
                    retorno = 1;
                }
            }
            else if ( day >= 1 && day <= 28 )
                retorno = 1;
        }
    }
    return retorno;
}

/** \brief Plancha toda la string y pone en Mayuscula la primer letra de cada nombre ingresado
 *
 * \param char *cadena
 * \return no envia retorno
 *
 */
void corregirNombreCompuesto(char *cadena)
{
    int i, largo = strlen(cadena);
    strlwr(cadena);
    for(i=0; i <= largo; i++)
    {
        if(cadena[i] == ' ')
            cadena[i+1] = toupper(cadena[i+1]);
    }
    cadena[0] = toupper(cadena[0]);
}

/** \brief Quita el salto de linea que toma la funcion fgets
 *
 * \param char *cadena
 * \return sin return
 *
 */
void quitarSaltoDeLinea(char *cadena)
{
    if (cadena[strlen(cadena)-1]=='\n')
        cadena[strlen(cadena)-1]='\0';
}

int esDigito(char *cadena)
{
    int retorno = 1, i, cantidad;
    cantidad = strlen(cadena);
    for(i=0; i<cantidad; i++)
    {
        if(!isdigit(cadena[i]))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

char* strlwr(char* s)
{
    char* tmp = s;

    for (;*tmp;++tmp) {
        *tmp = tolower((unsigned char) *tmp);
    }

    return s;
}

