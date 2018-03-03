#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct {
char nombre[20];
int edad;
} prueba_t;



int main()
{

lista_t * lista=listaCrea("lista de nombres",sizeof(prueba_t),NULL);
prueba_t uno;
strcpy(uno.nombre,"uno");
uno.edad=10;
listaAdd(lista,&uno);
prueba_t dos;
strcpy(dos.nombre,"dos");
dos.edad=20;
printf("vaaaaaaos xxx\n");fflush(stdout);
listaAdd(lista,&dos);
printf("vaaaaaaaaaaaamos\n");fflush(stdout);


prueba_t * x=itemLista(lista,0);
printf("a ver <%s>\n", x->nombre);

listaFree(lista);
printf("vaaaaaaaaaaaamos1\n");fflush(stdout);
 return(0);
}
