
#include <stdio.h>
#include "metaTab.h"

itemChar_t itemChar_tipoTabla_mf3={"tipoTabla","Tipo de la tabla",10};

itemChar_t itemChar_versionTabla_mf3={"versionTabla","Version de la tabla",10};

itemChar_t itemChar_name_mf3={"name","Nombre del output",50};

itemLista_t itemLista_fuentes_mf3={"fuentes","Lista de fuentes",20,100};

itemLista_t itemLista_includes_mf3={"includes","Lista de includes",20,100};

itemLista_t itemLista_proyectos_mf3={"proyectos","Lista de  make.tab, proyectos dependientes",100,100};

itemLista_t itemLista_outherDirInclude_mf3={"outherDirInclude","Lista de otros includes",20,100};

itemLista_t itemLista_outherDirLib_mf3={"outherDirLib","Lista de otros Dir de libreria",20,100};

itemLista_t itemLista_outherLibs_mf3={"outherLibs","Lista de otras librerias",20,100};

itemLista_t itemLista_proyectosInstall_mf3={"proyectosInstall","Lista de make.tab, a instalar",20,100};

itemChar_t itemChar_outputInstall_mf3={"outputInstall","Directorio de instalacion",200};

metaTabItem_t metaTabItem_mf3[]={
 {'C',(itemChar_t *) &itemChar_tipoTabla_mf3}
,{'C',(itemChar_t *) &itemChar_versionTabla_mf3}
,{'C',(itemChar_t *) &itemChar_name_mf3}
,{'L',(itemLista_t *) &itemLista_fuentes_mf3}
,{'L',(itemLista_t *) &itemLista_includes_mf3}
,{'L',(itemLista_t *) &itemLista_proyectos_mf3}
,{'L',(itemLista_t *) &itemLista_outherDirInclude_mf3}
,{'L',(itemLista_t *) &itemLista_outherDirLib_mf3}
,{'L',(itemLista_t *) &itemLista_outherLibs_mf3}
,{'L',(itemLista_t *) &itemLista_proyectosInstall_mf3}
,{'C',(itemChar_t *) &itemChar_outputInstall_mf3}

};

metaTab_t metaTab_mf3={
"mf3","",11,metaTabItem_mf3 };


metaTab_t *getMetaTab_mf3()
{
 return &metaTab_mf3;
}


