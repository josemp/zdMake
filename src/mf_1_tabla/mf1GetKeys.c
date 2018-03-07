
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mf1.h"

/****************************************************************/
/*  Lectura de parejas key:data y su grabacon en la estructura */
/****************************************************************/
/* El formato de los key's es "label" para los char
                              "label.3" para el 3er item de un array
                              "label.label" para los objetos
*/
int mf1GetKeys(mf1_t *mf1,char *key,char *data)
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
      strncpy(mf1->tipoTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"versionTabla")==0)
    {
      strncpy(mf1->versionTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"name")==0)
    {
      strncpy(mf1->name,data,50);
      return(0);
    }

if (key1!=NULL &&  strcmp(key,"fuentes")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf1->fuentes[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"includes")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf1->includes[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"proyectos")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf1->proyectos[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"outherDirInclude")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf1->outherDirInclude[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"outherDirLib")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf1->outherDirLib[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"outherLibs")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf1->outherLibs[atoi(key1)],data,100);
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
mf1ListaAdd(mf1Lista_t *mf1Lista,mf1_t *mf1)
{
if (mf1Lista->num==0) mf1Lista->data=malloc(sizeof(mf1_t));
else mf1Lista->data=realloc(mf1Lista->data,(mf1Lista->num+1)*sizeof(mf1_t));
mf1Lista->data[mf1Lista->num]=*mf1;
mf1Lista->num++;
memset (mf1,0,sizeof(mf1_t));
}

