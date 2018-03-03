
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mf1.h"
#include "cJSON.h"

// Los campos simples de la raiz

parseString(cJSON *item,mf1_t *mf1)
{ 
 if (strcmp(item->string,"tipoTabla")==0)
       sprintf(mf1->tipoTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"versionTabla")==0)
       sprintf(mf1->versionTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"name")==0)
       sprintf(mf1->name,"%.*s",50,item->valuestring);
}

// Los campos de objeto

parseItemObjeto(char *padre, cJSON *item,mf1_t *mf1)
{ }

// Los campos de array

parseItemArray(char *padre, cJSON *item,int contador,mf1_t *mf1)
{ 
 if (    strcmp(padre,"fuentes")==0
     && contador <20)
       sprintf(mf1->fuentes[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"includes")==0
     && contador <20)
       sprintf(mf1->includes[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"outherDirInclude")==0
     && contador <20)
       sprintf(mf1->outherDirInclude[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"outherDirLib")==0
     && contador <20)
       sprintf(mf1->outherDirLib[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"outherLibs")==0
     && contador <20)
       sprintf(mf1->outherLibs[contador],"%.*s",100,item->valuestring);
}

void parse_object(cJSON *item, char *padre, int tipoPadre,mf1_t *mf1)
{
int contArray=0;
    cJSON *myItem = item;
    while (1)
    {
        // handle subitem
        if (myItem->child)
        {
            parse_object(myItem->child,myItem->string,myItem->type,mf1);
        }
       else
        {
          if (padre==NULL || strcmp(padre,"root")==0)
              parseString(myItem,mf1);
          else if (tipoPadre== cJSON_Object)
              parseItemObjeto(padre,myItem,mf1);
          else if (tipoPadre==cJSON_Array)
            {
              parseItemArray(padre,myItem,contArray,mf1);
              contArray++;
            }
        }

        myItem = myItem->next;
        if (!myItem) break;
    }
}


mf1ParseJson(char *jsonString,mf1_t *mf1)
{

//int ret=leeFile("prueba.json",&jsonString);
//if (ret<0) {printf("no pude leer prueba.json\n");return;}
cJSON * root = cJSON_Parse(jsonString);
if (root==NULL) {return(-1);}
parse_object(root, "root", cJSON_Object, mf1);

free(root);

return(0);

}

