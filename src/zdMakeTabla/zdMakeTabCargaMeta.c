
#include <stdio.h>
#include "metaTab.h"

itemChar_t itemChar_tipo={"tipo","tipo de makefile",10};

itemChar_t itemChar_nombre={"nombre","nombre abreviado",20};

itemChar_t itemChar_descripcion={"descripcion","descripcion",50};

itemCallBack_t itemCallBack_generaTabla={"generaTabla","Generar Tabla","int"};

itemCallBack_t itemCallBack_generaMakefile={"generaMakefile","Genera makefile","int"};

metaTabItem_t metaTabItem_zdMakeTab[]={
 {'C',(itemChar_t *) &itemChar_tipo}
,{'C',(itemChar_t *) &itemChar_nombre}
,{'C',(itemChar_t *) &itemChar_descripcion}
,{'Y',(itemCallBack_t *)&itemCallBack_generaTabla}
,{'Y',(itemCallBack_t *)&itemCallBack_generaMakefile}

};

metaTab_t metaTab_zdMakeTab={
"zdMakeTab","",5,metaTabItem_zdMakeTab };


metaTab_t *getMetaTab_zdMakeTab()
{
 return getMeta(&metaTab_zdMakeTab);
}

int getMeta_zdMakeTab(char *label,char *labelItem,itemMeta_t *itemMeta)
{
 return getMeta(&metaTab_zdMakeTab,label,labelItem,itemMeta);
}

