
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zdMakeTab.h"
#include "cJSON.h"

// Los campos simples de la raiz

parseString(cJSON *item,zdMakeTab_t *zdMakeTab)
{ 
 if (strcmp(item->string,"tipo")==0)
       sprintf(zdMakeTab->tipo,"%.*s",10,item->valuestring);

 if (strcmp(item->string,"nombre")==0)
       sprintf(zdMakeTab->nombre,"%.*s",20,item->valuestring);

 if (strcmp(item->string,"descripcion")==0)
       sprintf(zdMakeTab->descripcion,"%.*s",50,item->valuestring);
}

// Los campos de objeto

parseItemObjeto(char *padre, cJSON *item,zdMakeTab_t *zdMakeTab)
{ }

// Los campos de array

parseItemArray(char *padre, cJSON *item,int contador,zdMakeTab_t *zdMakeTab)
{ }

void parse_object(cJSON *item, char *padre, int tipoPadre,zdMakeTab_t *zdMakeTab)
{
int contArray=0;
    cJSON *myItem = item;
    while (1)
    {
        // handle subitem
        if (myItem->child)
        {
            parse_object(myItem->child,myItem->string,myItem->type,zdMakeTab);
        }
       else
        {
          if (padre==NULL || strcmp(padre,"root")==0)
              parseString(myItem,zdMakeTab);
          else if (tipoPadre== cJSON_Object)
              parseItemObjeto(padre,myItem,zdMakeTab);
          else if (tipoPadre==cJSON_Array)
            {
              parseItemArray(padre,myItem,contArray,zdMakeTab);
              contArray++;
            }
        }

        myItem = myItem->next;
        if (!myItem) break;
    }
}


zdMakeTabParseJson(char *jsonString,zdMakeTab_t *zdMakeTab)
{

//int ret=leeFile("prueba.json",&jsonString);
//if (ret<0) {printf("no pude leer prueba.json\n");return;}
cJSON * root = cJSON_Parse(jsonString);
if (root==NULL) {return(-1);}
parse_object(root, "root", cJSON_Object, zdMakeTab);

free(root);

return(0);

}

