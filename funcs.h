#include <stdio.h>
#include <stdlib.h>

typedef struct buffer {

  int indice;
  char *lista;
  int linha;
  int flag_acabou;
  int flag_descarrega;

} buffer;

extern char *allocate_buffer(int);

extern void deallocate_buffer(char *);

extern void replace_print(char *, char *, int);

extern int get_next_char(char *, buffer *);

extern void reseta(char*);
