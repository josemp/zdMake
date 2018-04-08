
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mf3.h"
#include "cJSON.h"

// Los campos simples de la raiz

parseString(cJSON *item,mf3_t *mf3)
{ 
 if (strcmp(item->string,"tipoTabla")==0)
       sprintf(mf3->tipoTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"versionTabla")==0)
       sprintf(mf3->versionTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"name")==0)
       sprintf(mf3->name,"%.*s",50,item->valuestring);

 if (strcmp(item->string,"outputInstall")==0)
       sprintf(mf3->outputInstall,"%.*s",200,item->valuestring);
}

// Los campos de objeto

parseItemObjeto(char *padre, cJSON *item,mf3_t *mf3)
{ }

// Los campos de array

parseItemArray(char *padre, cJSON *item,int contador,mf3_t *mf3)
{ 
 if (    strcmp(padre,"fuentes")==0
     && contador <20)
       sprintf(mf3->fuentes[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"includes")==0
     && contador <20)
       sprintf(mf3->includes[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"proyectos")==0
     && contador <20)
       sprintf(mf3->proyectos[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"outherDirInclude")==0
     && contador <20)
       sprintf(mf3->outherDirInclude[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"outherDirLib")==0
     && contador <20)
       sprintf(mf3->outherDirLib[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"outherLibs")==0
     && contador <20)
       sprintf(mf3->outherLibs[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"proyectosInstall")==0
     && contador <20)
       sprintf(mf3->proyectosInstall[contador],"%.*s",100,item->valuestring);
}

void parse_object(cJSON *item, char *padre, int tipoPadre,mf3_t *mf3)
{
int contArray=0;
    cJSON *myItem = item;
    while (1)
    {
        // handle subitem
        if (myItem->child)
        {
            parse_object(myItem->child,myItem->string,myItem->type,mf3);
        }
       else
        {
          if (padre==NULL || strcmp(padre,"root")==0)
              parseString(myItem,mf3);
          else if (tipoPadre== cJSON_Object)
              parseItemObjeto(padre,myItem,mf3);
          else if (tipoPadre==cJSON_Array)
            {
              parseItemArray(padre,myItem,contArray,mf3);
              contArray++;
            }
        }

        myItem = myItem->next;
        if (!myItem) break;
    }
}


mf3ParseJson(char *jsonString,mf3_t *mf3)
{

//int ret=leeFile("prueba.json",&jsonString);
//if (ret<0) {printf("no pude leer prueba.json\n");return;}
cJSON * root = cJSON_Parse(jsonString);
if (root==NULL) {return(-1);}
parse_object(root, "root", cJSON_Object, mf3);

free(root);

return(0);

}

