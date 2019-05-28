#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"

void orq_hardcode(sOrquesta* orqLista, int ORQ_CANT, int auxId, char* auxNombre, char* auxLugar, char* auxTipo, char* auxDesc);
void mus_hardcode(sInstrumento* insLista, int INS_CANT, sOrquesta* orqLista, int ORQ_CANT, sMusico* musLista, int MUS_CANT, int auxId, char* auxNombre, char* auxApellido, char* auxEdad, char* auxIdOrquesta, char* auxDescOrq, char* auxIdInstrumento, char* auxDescIns);
void ins_hardcode(sInstrumento* insLista, int INS_CANT, int auxId, char* auxNombre, char* auxTipo, char* auxDesc);

