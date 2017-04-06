/*
  Arquivo: LLDRIVER.H
  Autor: Roberto Bauer
  Observacoes:
                Recebe como entrada uma quantidade de pessoas e o
                valor para a sequencia de eliminação.
*/

#ifndef __LLDRIVER_H__
#define __LLDRIVER_H__

#undef EXTERN
#ifdef __LLDRIVER_C__
#define EXTERN
#else
#define EXTERN  extern
#endif

EXTERN int LLDriver (int argc, char *argv[]);


#endif // #define __LLDRIVER_H__
