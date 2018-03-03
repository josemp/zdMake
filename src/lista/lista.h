
typedef struct {
  int num;// numero de items
  char nombre[100+1];// nombre de la lista
  int len;
  char *items;
  void *tag;
} lista_t;

lista_t *listaCrea(char * nombre,int len,void *tag);

void *itemLista(lista_t *lista,int num);
void listaAdd(lista_t *lista,void *item);
void listaFree(lista_t *lista);
