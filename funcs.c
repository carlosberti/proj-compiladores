#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(int tam)
{
  char *buffer = NULL;
  buffer = (char *)malloc(tam * sizeof(char));
  return buffer;
}

void deallocate_buffer(char *buffer)
{
  free(buffer);
}

void replace_print(char *buffer, char *arquivo, int tam)
{
  int i = 0;
  int j;
  char ref;

  FILE *texto = fopen(arquivo, "r");

  if (texto == NULL)
  {
    // erro
  }
  else
  {

    while (!feof(texto))
    {
      ref = fgetc(texto);

      if (ref == 'a' || ref == 'e' || ref == 'i' || ref == 'o' || ref == 'u')
      {
        ref = ref - 32;
      }

      if (i == tam || feof(texto))
      {
        j = 0;
        for (j = 0; j < i; j++)
        {
          printf("%c", buffer[j]);
        }
        i = 0;
      }
      buffer[i] = ref;
      i++;
    }
  }
}

int get_next_char(char *arquivo, buffer *buf)
{

  FILE *texto = fopen(arquivo, "r");

  if (texto == NULL)
  {
    printf("Failed to open the file %s\n", arquivo);
    return -1;
  }

  reset(buf->lista);

  while (!feof(texto))
  {

    fgets(buf->lista, 256, texto);

    if (buf->lista == NULL)
    {
      return EOF;
    }
    if (buf->lista[255] == '\n' || buf->lista[255] == 0)
    {
      buf->flag_acabou = 1;
      // leu toda linha
      buf->linha++;
      buf->indice = 0;
    }
    else
    {
      buf->flag_acabou = 0;
      // não leu toda linha
    }

    int i = 0;

    while (buf->lista[i] != '\0')
    {
      buf->indice = i;

      if (buf->lista[i] == 'm')
      {
        pprintf("ERRO linha: %i indice: %i\n", buf->linha, buf->indice);
        return -1;
      }
      else
      {
        printf("%c", buf->lista[i]); // consome o caracter
        buf->lista[i] = '\0';
        i++;
      }
    }
  }
  return 0;
}

void reset(char *vet)
{
  int i;
  for (i = 0; i < 255; i++)
  {
    vet[i] = '\0';
  }
}