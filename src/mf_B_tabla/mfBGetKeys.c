
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mfB.h"

/****************************************************************/
/*  Lectura de parejas key:data y su grabacon en la estructura */
/****************************************************************/
/* El formato de los key's es "label" para los char
                              "label.3" para el 3er item de un array
                              "label.label" para los objetos
*/
int mfBGetKeys(mfB_t *mfB,char *key,char *data)
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
      strncpy(mfB->tipoTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"versionTabla")==0)
    {
      strncpy(mfB->versionTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"name")==0)
    {
      strncpy(mfB->name,data,50);
      return(0);
    }

if (key1!=NULL &&  strcmp(key,"includesForInstall")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mfB->includesForInstall[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"directorios")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mfB->directorios[atoi(key1)],data,100);
      return(0);
}
if (key1==NULL &&  strcmp(key,"outputLibInstall")==0)
    {
      strncpy(mfB->outputLibInstall,data,200);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"outputIncludeInstall")==0)
    {
      strncpy(mfB->outputIncludeInstall,data,200);
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
mfBListaAdd(mfBLista_t *mfBLista,mfB_t *mfB)
{
if (mfBLista->num==0) mfBLista->data=malloc(sizeof(mfB_t));
else mfBLista->data=realloc(mfBLista->data,(mfBLista->num+1)*sizeof(mfB_t));
mfBLista->data[mfBLista->num]=*mfB;
mfBLista->num++;
memset (mfB,0,sizeof(mfB_t));
}

