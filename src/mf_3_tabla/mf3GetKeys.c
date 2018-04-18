
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mf3.h"

/****************************************************************/
/*  Lectura de parejas key:data y su grabacon en la estructura */
/****************************************************************/
/* El formato de los key's es "label" para los char
                              "label.3" para el 3er item de un array
                              "label.label" para los objetos
*/
int mf3GetKeys(mf3_t *mf3,char *key,char *data)
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
      strncpy(mf3->tipoTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"versionTabla")==0)
    {
      strncpy(mf3->versionTabla,data,10);
      return(0);
    }
if (key1==NULL &&  strcmp(key,"name")==0)
    {
      strncpy(mf3->name,data,50);
      return(0);
    }

if (key1!=NULL &&  strcmp(key,"fuentes")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf3->fuentes[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"includes")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf3->includes[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"proyectos")==0 && atoi(key1)>0 && atoi(key1)<100)
{
      strncpy(mf3->proyectos[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"outherDirInclude")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf3->outherDirInclude[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"outherDirLib")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf3->outherDirLib[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"outherLibs")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf3->outherLibs[atoi(key1)],data,100);
      return(0);
}

if (key1!=NULL &&  strcmp(key,"proyectosInstall")==0 && atoi(key1)>0 && atoi(key1)<20)
{
      strncpy(mf3->proyectosInstall[atoi(key1)],data,100);
      return(0);
}
if (key1==NULL &&  strcmp(key,"outputInstall")==0)
    {
      strncpy(mf3->outputInstall,data,200);
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
mf3ListaAdd(mf3Lista_t *mf3Lista,mf3_t *mf3)
{
if (mf3Lista->num==0) mf3Lista->data=malloc(sizeof(mf3_t));
else mf3Lista->data=realloc(mf3Lista->data,(mf3Lista->num+1)*sizeof(mf3_t));
mf3Lista->data[mf3Lista->num]=*mf3;
mf3Lista->num++;
memset (mf3,0,sizeof(mf3_t));
}

