
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mf2.h"
#include "cJSON.h"

// Los campos simples de la raiz

parseString(cJSON *item,mf2_t *mf2)
{ 
 if (strcmp(item->string,"tipoTabla")==0)
       sprintf(mf2->tipoTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"versionTabla")==0)
       sprintf(mf2->versionTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"name")==0)
       sprintf(mf2->name,"%.*s",50,item->valuestring);

 if (strcmp(item->string,"outputLibInstall")==0)
       sprintf(mf2->outputLibInstall,"%.*s",200,item->valuestring);

 if (strcmp(item->string,"outputIncludeInstall")==0)
       sprintf(mf2->outputIncludeInstall,"%.*s",200,item->valuestring);
}

// Los campos de objeto

parseItemObjeto(char *padre, cJSON *item,mf2_t *mf2)
{ }

// Los campos de array

parseItemArray(char *padre, cJSON *item,int contador,mf2_t *mf2)
{ 
 if (    strcmp(padre,"fuentes")==0
     && contador <20)
       sprintf(mf2->fuentes[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"includes")==0
     && contador <20)
       sprintf(mf2->includes[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"proyectos")==0
     && contador <20)
       sprintf(mf2->proyectos[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"outherDirInclude")==0
     && contador <20)
       sprintf(mf2->outherDirInclude[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"includesForInstall")==0
     && contador <20)
       sprintf(mf2->includesForInstall[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"test")==0
     && contador <20)
       sprintf(mf2->test[contador],"%.*s",100,item->valuestring);
}

void parse_object(cJSON *item, char *padre, int tipoPadre,mf2_t *mf2)
{
int contArray=0;
    cJSON *myItem = item;
    while (1)
    {
        // handle subitem
        if (myItem->child)
        {
            parse_object(myItem->child,myItem->string,myItem->type,mf2);
        }
       else
        {
          if (padre==NULL || strcmp(padre,"root")==0)
              parseString(myItem,mf2);
          else if (tipoPadre== cJSON_Object)
              parseItemObjeto(padre,myItem,mf2);
          else if (tipoPadre==cJSON_Array)
            {
              parseItemArray(padre,myItem,contArray,mf2);
              contArray++;
            }
        }

        myItem = myItem->next;
        if (!myItem) break;
    }
}


mf2ParseJson(char *jsonString,mf2_t *mf2)
{

//int ret=leeFile("prueba.json",&jsonString);
//if (ret<0) {printf("no pude leer prueba.json\n");return;}
cJSON * root = cJSON_Parse(jsonString);
if (root==NULL) {return(-1);}
parse_object(root, "root", cJSON_Object, mf2);

free(root);

return(0);

}

