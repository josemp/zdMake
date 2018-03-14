
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mfB.h"
#include "cJSON.h"

// Los campos simples de la raiz

parseString(cJSON *item,mfB_t *mfB)
{ 
 if (strcmp(item->string,"tipoTabla")==0)
       sprintf(mfB->tipoTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"versionTabla")==0)
       sprintf(mfB->versionTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"name")==0)
       sprintf(mfB->name,"%.*s",50,item->valuestring);

 if (strcmp(item->string,"outputLibInstall")==0)
       sprintf(mfB->outputLibInstall,"%.*s",200,item->valuestring);

 if (strcmp(item->string,"outputIncludeInstall")==0)
       sprintf(mfB->outputIncludeInstall,"%.*s",200,item->valuestring);
}

// Los campos de objeto

parseItemObjeto(char *padre, cJSON *item,mfB_t *mfB)
{ }

// Los campos de array

parseItemArray(char *padre, cJSON *item,int contador,mfB_t *mfB)
{ 
 if (    strcmp(padre,"includesForInstall")==0
     && contador <20)
       sprintf(mfB->includesForInstall[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"directorios")==0
     && contador <20)
       sprintf(mfB->directorios[contador],"%.*s",100,item->valuestring);
}

void parse_object(cJSON *item, char *padre, int tipoPadre,mfB_t *mfB)
{
int contArray=0;
    cJSON *myItem = item;
    while (1)
    {
        // handle subitem
        if (myItem->child)
        {
            parse_object(myItem->child,myItem->string,myItem->type,mfB);
        }
       else
        {
          if (padre==NULL || strcmp(padre,"root")==0)
              parseString(myItem,mfB);
          else if (tipoPadre== cJSON_Object)
              parseItemObjeto(padre,myItem,mfB);
          else if (tipoPadre==cJSON_Array)
            {
              parseItemArray(padre,myItem,contArray,mfB);
              contArray++;
            }
        }

        myItem = myItem->next;
        if (!myItem) break;
    }
}


mfBParseJson(char *jsonString,mfB_t *mfB)
{

//int ret=leeFile("prueba.json",&jsonString);
//if (ret<0) {printf("no pude leer prueba.json\n");return;}
cJSON * root = cJSON_Parse(jsonString);
if (root==NULL) {return(-1);}
parse_object(root, "root", cJSON_Object, mfB);

free(root);

return(0);

}

