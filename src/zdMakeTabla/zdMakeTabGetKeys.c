
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "zdMakeTab.h"

/****************************************************************/
/*  Lectura de parejas key:data y su grabacon en la estructura */
/****************************************************************/
/* El formato de los key's es "label" para los char
                              "label.3" para el 3er item de un array
                              "label.label" para los objetos
*/
int zdMakeTabGetKeys(zdMakeTab_t *zdMakeTab,char *key,char *data)
{
char *key0;
char *key1;
key0=key;
key1=memchr(key0,'.',strlen(key0));
if (key1!=NULL && strlen(key1)==1)
  key1=NULL;
if (key1!=NULL)
{
 *key1=0;
 key1++;
}
if (key1==NULL &&  strcmp(key,"tipo")==0)
    {
      strncpy(zdMakeTab->tipo,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"nombre")==0)
    {
      strncpy(zdMakeTab->nombre,data,20);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"descripcion")==0)
    {
      strncpy(zdMakeTab->descripcion,data,50);
      return(0);
    }



}// End function


/****************************************************************/
/*  Callback para añadir items a la lista                      */
/****************************************************************/
/* Los dos tienen que estar creados
   Es importante el 'borrar' la estructura para que le
   LLege limpio al siguiente item
*/
zdMakeTabListaAdd(zdMakeTabLista_t *zdMakeTabLista,zdMakeTab_t *zdMakeTab)
{
if (zdMakeTabLista->num==0) zdMakeTabLista->data=malloc(sizeof(zdMakeTab_t));
else zdMakeTabLista->data=realloc(zdMakeTabLista->data,(zdMakeTabLista->num+1)*sizeof(zdMakeTab_t));
zdMakeTabLista->data[zdMakeTabLista->num]=*zdMakeTab;
zdMakeTabLista->num++;
memset (zdMakeTab,0,sizeof(zdMakeTab_t));
}

