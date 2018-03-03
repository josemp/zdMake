/**
  @file leeMetaTab.c
  @brief Lectura de ficheros meta de configuracion z
  @author Jose Miguel Parra
  @date 8/2017
  
  Esta lista, copia los datos, no pueden borrarse items

  Using:
  suponemos una lista de estructuras de tipo prueba_t

  crear: lista de estructuras typedef struct prueba_t
  lista_t * lista=listaCrea("lista de nombres",sizeof(prueba_t),NULL);
  
  add: añadimos un  elemento a la lista (prueba_t uno)
   listaAdd(lista,&uno); 

  bucle:
    for (i=0;i<lista->num;i++)
      prueba_t *item=itemLista(lista,i);

  free:
    listaFree(lista);

*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "lista.h"


lista_t *listaCrea(char * nombre,int len,void *tag)
{
lista_t *lista =malloc(sizeof(lista_t));
memset(lista,0,sizeof(lista_t));
strcpy(lista->nombre,nombre);
lista->len=len;
lista->tag=tag;
lista->items=malloc(1);
return(lista);
}
void *itemLista(lista_t *lista,int num)
{
  return(lista->items+num*lista->len);
}
void listaAdd(lista_t *lista,void *item)
{
int pos =lista->num;

lista->items=realloc(lista->items,lista->len *(pos+1));
memcpy(lista->items+(pos*lista->len),item,lista->len);
lista->num++;
}
void listaFree(lista_t *lista)
{
free(lista->items);
free(lista);

}
