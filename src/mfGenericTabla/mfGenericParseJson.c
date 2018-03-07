
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mfGeneric.h"
#include "cJSON.h"

// Los campos simples de la raiz

parseString(cJSON *item,mfGeneric_t *mfGeneric)
{ 
 if (strcmp(item->string,"tipoTabla")==0)
       sprintf(mfGeneric->tipoTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"versionTabla")==0)
       sprintf(mfGeneric->versionTabla,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"name")==0)
       sprintf(mfGeneric->name,"%.*s",50,item->valuestring);
}

// Los campos de objeto

parseItemObjeto(char *padre, cJSON *item,mfGeneric_t *mfGeneric)
{ }

// Los campos de array

parseItemArray(char *padre, cJSON *item,int contador,mfGeneric_t *mfGeneric)
{ 
 if (    strcmp(padre,"fuentes")==0
     && contador <20)
       sprintf(mfGeneric->fuentes[contador],"%.*s",100,item->valuestring);

 if (    strcmp(padre,"includesForInstall")==0
     && contador <20)
       sprintf(mfGeneric->includesForInstall[contador],"%.*s",100,item->valuestring);
}

void parse_object(cJSON *item, char *padre, int tipoPadre,mfGeneric_t *mfGeneric)
{
int contArray=0;
    cJSON *myItem = item;
    while (1)
    {
        // handle subitem
        if (myItem->child)
        {
            parse_object(myItem->child,myItem->string,myItem->type,mfGeneric);
        }
       else
        {
          if (padre==NULL || strcmp(padre,"root")==0)
              parseString(myItem,mfGeneric);
          else if (tipoPadre== cJSON_Object)
              parseItemObjeto(padre,myItem,mfGeneric);
          else if (tipoPadre==cJSON_Array)
            {
              parseItemArray(padre,myItem,contArray,mfGeneric);
              contArray++;
            }
        }

        myItem = myItem->next;
        if (!myItem) break;
    }
}


mfGenericParseJson(char *jsonString,mfGeneric_t *mfGeneric)
{

//int ret=leeFile("prueba.json",&jsonString);
//if (ret<0) {printf("no pude leer prueba.json\n");return;}
cJSON * root = cJSON_Parse(jsonString);
if (root==NULL) {return(-1);}
parse_object(root, "root", cJSON_Object, mfGeneric);

free(root);

return(0);

}

