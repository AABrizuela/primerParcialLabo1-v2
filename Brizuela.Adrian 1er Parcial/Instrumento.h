#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#define INS_LEN 51

typedef struct{

    int id;
    char nombre[INS_LEN];
    char tipo[2];
    int isEmpty;
    char desc[INS_LEN];

}sInstrumento;

int ins_init(sInstrumento* insLista, int INS_CANT);
int ins_alta(sInstrumento* insLista, int INS_CANT);
int ins_getFreeSpot(sInstrumento* insLista, int INS_CANT);
int ins_findById(sInstrumento* insLista, int INS_CANT, int id);
void ins_mostrarUno(sInstrumento instrumento);
void ins_listarTodos(sInstrumento* insLista, int INS_CANT);

#endif // INSTRUMENTO_H
