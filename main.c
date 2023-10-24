#include "funcs.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    return 0; // um argumento é o nome do executavel
  }
  buffer* buf =(buffer *)malloc(sizeof(buffer));

  buf->indice = 0;
  buf->linha = 0;
  buf->flag_acabou = 1;
  buf->flag_descarrega = 0;

  char *linha = allocate_buffer(256);

  buf->lista = linha;

  get_next_char(argv[1],buf);
  deallocate_buffer(linha);
  free(buf);
  
  return 0;
}