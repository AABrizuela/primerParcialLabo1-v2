#ifndef UTN_H
#define UTN_H_INCLUDED

int isAlphaNumeric(char *cadena);
int areCharacters(char *cadena);
int isInteger(char *cadena);
int isFloat(char *cadena);
int isCharacter(char caracter);
int esDigito(char *cadena);
int isFecha(int day, int month, int year);
int isTelephone(char *cadena);
int isEmail(char *cadena);
char getChain(char *mensaje);
void corregirNombreCompuesto(char *cadena);
void quitarSaltoDeLinea(char *cadena);
char* strlwr(char* s);

#endif // UTN_H_INCLUDED
