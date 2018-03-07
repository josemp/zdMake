
#include <stdio.h>
#include "metaTab.h"

itemChar_t itemChar_tipoTabla_mf1={"tipoTabla","Tipo de la tabla",10};

itemChar_t itemChar_versionTabla_mf1={"versionTabla","Version de la tabla",10};

itemChar_t itemChar_name_mf1={"name","Nombre del output",50};

itemLista_t itemLista_fuentes_mf1={"fuentes","Lista de fuentes",20,100};

itemLista_t itemLista_includes_mf1={"includes","Lista de includes",20,100};

itemLista_t itemLista_proyectos_mf1={"proyectos","Lista de proyectos dependientes",20,100};

itemLista_t itemLista_outherDirInclude_mf1={"outherDirInclude","Lista de otros includes",20,100};

itemLista_t itemLista_outherDirLib_mf1={"outherDirLib","Lista de otros Dir de libreria",20,100};

itemLista_t itemLista_outherLibs_mf1={"outherLibs","Lista de otras librerias",20,100};

metaTabItem_t metaTabItem_mf1[]={
 {'C',(itemChar_t *) &itemChar_tipoTabla_mf1}
,{'C',(itemChar_t *) &itemChar_versionTabla_mf1}
,{'C',(itemChar_t *) &itemChar_name_mf1}
,{'L',(itemLista_t *) &itemLista_fuentes_mf1}
,{'L',(itemLista_t *) &itemLista_includes_mf1}
,{'L',(itemLista_t *) &itemLista_proyectos_mf1}
,{'L',(itemLista_t *) &itemLista_outherDirInclude_mf1}
,{'L',(itemLista_t *) &itemLista_outherDirLib_mf1}
,{'L',(itemLista_t *) &itemLista_outherLibs_mf1}

};

metaTab_t metaTab_mf1={
"mf1","",9,metaTabItem_mf1 };


metaTab_t *getMetaTab_mf1()
{
 return &metaTab_mf1;
}


