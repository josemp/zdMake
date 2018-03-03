
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mf2.h"

/****************************************************************/
/*  Lectura de parejas key:data y su grabacon en la estructura */
/****************************************************************/
/* El formato de los key's es "label" para los char
                              "label.3" para el 3er item de un array
                              "label.label" para los objetos
*/
int mf2GetKeys(mf2_t *mf2,char *key,char *data)
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
      strncpy(mf2->tipoTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"versionTabla")==0)
    {
      strncpy(mf2->versionTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"name")==0)
    {
      strncpy(mf2->name,data,50);
      return(0);
    }

if (key1!=NULL &&  strcmp(key,"fuentes")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf2->fuentes[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"includes")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf2->includes[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"outherDirInclude")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf2->outherDirInclude[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"includesForInstall")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf2->includesForInstall[atoi(key1)],data,100);
      return(0);
}
if (key1==NULL &&  strcmp(key,"outputLibInstall")==0)
    {
      strncpy(mf2->outputLibInstall,data,200);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"outputIncludeInstall")==0)
    {
      strncpy(mf2->outputIncludeInstall,data,200);
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
mf2ListaAdd(mf2Lista_t *mf2Lista,mf2_t *mf2)
{
if (mf2Lista->num==0) mf2Lista->data=malloc(sizeof(mf2_t));
else mf2Lista->data=realloc(mf2Lista->data,(mf2Lista->num+1)*sizeof(mf2_t));
mf2Lista->data[mf2Lista->num]=*mf2;
mf2Lista->num++;
memset (mf2,0,sizeof(mf2_t));
}

