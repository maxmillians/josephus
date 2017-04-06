/*
  Arquivo: LLAPP.C
  Autor: Roberto Bauer
  Observacoes:
              Dados especificos da aplicacaoh p/ lista encadeada
*/

#define __LLAPP_C__

#include "main.h"


void *
CreateData (void *data)
{
  SNODEDATA *pNewData;

  // aloca sua estrutura de dados
  pNewData = (SNODEDATA *) malloc (sizeof (SNODEDATA));
  if (pNewData == NULL)
    return (NULL);

  // move os valores para a estrutura de dados
  pNewData->uPos = *((int *) data);

  // retorna o endereco da estrutura
  return (pNewData);
}

BOOL
DeleteData (void *data)
{
  // neste caso NodeData consiste em : um inteiro.
  // O inteiro retorna para a memoria quando o noh eh liberado
  // naoh precisando de processamento adicional
  free (data);
  return TRUE;
}

// Note que estah funcaoh deve retornar um dos seguintes valores
//      0   um erro aconteceu
//      1   apagar o noh duplicado
//      2   inserir o noh duplicado
int
DuplicatedNode (SLINK slkNewNode, SLINK slkListNode)
{
  // nunca serah chamada
  return 2;
}

int
NodeDataCmp (void *first, void *second)
{
  // nunca serah chamada
  return (0);
}
