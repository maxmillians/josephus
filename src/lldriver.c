/*
  Arquivo: LLDRIVER.C
  Autor: Roberto Bauer
  Observacoes:
                Recebe como entrada uma quantidade de pessoas e o
                valor para a sequencia de eliminação.
*/

#define __LLDRIVER_C__

#include "main.h"

BOOL Josephus (int, int, int *, int *);


int
LLDriver (int argc, char *argv[])
{
  int iPerson, iSeq, iLast, iSecLast;

  if (argc != 3)
    {
      fprintf (stderr, "ERRO! Uso: josephus [pessoas] [sequencia]\n");
      return (EXIT_FAILURE);
    }
  else
    {
      iPerson = atoi (argv[1]);
      iSeq = atoi (argv[2]);

      if (iPerson == 0 || iSeq == 0)
        {
          fprintf (stderr, "ERRO! Entrada invalida\n");
          return (EXIT_FAILURE);
        }
    }

  if (Josephus (iPerson, iSeq, &iLast, &iSecLast))
    {
      printf ("penultimo: %d\n", iSecLast);
      printf ("ultimo:    %d\n", iLast);
      return (EXIT_SUCCESS);
    }
  else
    {
      return (EXIT_FAILURE);
    }
}


BOOL
Josephus (int iPerson, int iSeq, int *pLast, int *pSecLast)
{
  SLIST *L;
  int iCount;
  SLINK slQueue, slDel;
  BOOL bErr = FALSE;

  // configura a estrutura de dados da lista encadeada
  L = CreateLList (CreateData, DeleteData, DuplicatedNode, NodeDataCmp);

  if (L == NULL)
    {
      fprintf (stderr, "Erro criando lista encadeada\n");
      return FALSE;
    }

  // adiciona a representacaoh numerica de cada pessoa na fila circular
  for (iCount = 1; iCount <= iPerson; ++iCount)
    {
      // adiciona o nó com a contagem
      if (!AddNodeAtHead (L, &iCount))
        {
          fprintf (stderr, "AVISO! Erro ao adicionar noh em L.\n");
          bErr = TRUE;
        }
    }

  if (bErr)
    {
      *pLast = *pSecLast = 0;
    }
  else
    {
      slQueue = L->slkTail;
      iCount = 1;
      // enquanto houver nohs na lista
      while (L->uiCount)
        {
          printf ("%d ", ((pND) (slQueue->pdata))->uPos);

          slDel = slQueue;
          // avancah para o proximo noh
          slQueue = slQueue->prior;
          // terminou de percorrer a lista
          if (slQueue == NULL)
            {
              // transforma a lista em uma fila circular
              slQueue = L->slkTail;
              printf ("\n");
            }

          // conta ateh achar o valor da sequencia
          if (iCount++ == iSeq)
            {
              // reinicia a contagem
              iCount = 1;

              if (L->uiCount == 1)
                *pLast = ((pND) slDel->pdata)->uPos;
              else if (L->uiCount == 2)
                *pSecLast = ((pND) slDel->pdata)->uPos;

              // elimina o numero da lista
              DeleteNode (L, slDel);
            }
        }
    }

  DestroyLList (L);

  return (!bErr);
}
