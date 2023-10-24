#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(int tam) {
  char *buffer = NULL;
  buffer = (char *)malloc(tam * sizeof(char));
  return buffer;
}

void deallocate_buffer(char *buffer) { free(buffer); }

void replace_print(char *buffer, char *arquivo, int tam) {
  int i = 0;
  int j;
  char ref;

  FILE *texto = fopen(arquivo, "r");

  if (texto == NULL) {
    // erro
  } else {

    while (!feof(texto)) {
      ref = fgetc(texto);

      if (ref == 'a' || ref == 'e' || ref == 'i' || ref == 'o' || ref == 'u') {
        ref = ref - 32;
      }

      if (i == tam || feof(texto)) {
        j = 0;
        for (j = 0; j < i; j++) {
          printf("%c", buffer[j]);
        }
        i = 0;
      }
      buffer[i] = ref;
      i++;
    }
  }
}

int get_next_char(char *arquivo, buffer *buf) {

  FILE *texto = fopen(arquivo, "r");

  if (texto == NULL) {
    return -1;
  }
  reseta(buf->lista);

  while (!feof(texto)) {

    char *result = fgets(buf->lista, 256, texto);
    if (result != NULL) {
      if (buf->lista[255] == '\n' || buf->lista[255] == 0) {
        buf->flag_acabou = 1;
        // leu toda linha
        buf->linha++;

      } else {
        buf->flag_acabou = 0;
        // não leu toda linha
      }
    }
    int i = 0;
    while (buf->lista[i] != '\0') { // 0 ==  NULL
      if (buf->lista[i] == 'm') {
        printf("ERRO linha :%i indice :%i \n", buf->linha, buf->indice);
        return -1;
      } else {
        printf("%c", buf->lista[i]); // consome o caracter
        buf->lista[i] = '\0';
        i++;
      }
    }
    if (buf->flag_acabou == 1) {
      buf->indice = 0;
    } else {
      buf->indice += i;
    }
  }
  return 0;
}

void reseta(char *vet) {
  int i;
  for (i = 0; i < 255; i++) {
    vet[i] = '\0';
  }
}