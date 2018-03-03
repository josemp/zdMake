
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mfGeneric.h"

/****************************************************************/
/*  Lectura de parejas key:data y su grabacon en la estructura */
/****************************************************************/
/* El formato de los key's es "label" para los char
                              "label.3" para el 3er item de un array
                              "label.label" para los objetos
*/
int mfGenericGetKeys(mfGeneric_t *mfGeneric,char *key,char *data)
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
if (key1==NULL &&  strcmp(key,"tipoTabla")==0)
    {
      strncpy(mfGeneric->tipoTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"versionTabla")==0)
    {
      strncpy(mfGeneric->versionTabla,data,10);
      return(0);
    }

if (key1!=NULL &&  strcmp(key,"fuentes")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mfGeneric->fuentes[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"includesForInstall")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mfGeneric->includesForInstall[atoi(key1)],data,100);
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
mfGenericListaAdd(mfGenericLista_t *mfGenericLista,mfGeneric_t *mfGeneric)
{
if (mfGenericLista->num==0) mfGenericLista->data=malloc(sizeof(mfGeneric_t));
else mfGenericLista->data=realloc(mfGenericLista->data,(mfGenericLista->num+1)*sizeof(mfGeneric_t));
mfGenericLista->data[mfGenericLista->num]=*mfGeneric;
mfGenericLista->num++;
memset (mfGeneric,0,sizeof(mfGeneric_t));
}

