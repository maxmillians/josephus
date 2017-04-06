/*
  Arquivo: LLAPP.H
  Autor: Roberto Bauer
  Observacoes:
              Dados especificos da aplicacaoh p/ lista encadeada
*/


#ifndef __LLAPP_H__
#define __LLAPP_H__

#undef EXTERN
#ifdef __LLAPP_C__
#define EXTERN
#else
#define EXTERN  extern
#endif


// A lista de noh consiste em:
typedef struct tagSNODEDATA
{
  unsigned int uPos;            // posicaoh da pessoa na fila
} SNODEDATA;

typedef SNODEDATA *pND;

EXTERN void *CreateData (void *);
EXTERN BOOL DeleteData (void *);
EXTERN int DuplicatedNode (SLINK, SLINK);
EXTERN int NodeDataCmp (void *, void *);




#endif // #define __LLAPP_H__
