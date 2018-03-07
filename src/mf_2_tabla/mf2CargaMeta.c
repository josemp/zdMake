
#include <stdio.h>
#include "metaTab.h"

itemChar_t itemChar_tipoTabla_mf2={"tipoTabla","Tipo de la tabla",10};

itemChar_t itemChar_versionTabla_mf2={"versionTabla","Version de la tabla",10};

itemChar_t itemChar_name_mf2={"name","Nombre del output",50};

itemLista_t itemLista_fuentes_mf2={"fuentes","Lista de fuentes",20,100};

itemLista_t itemLista_includes_mf2={"includes","Lista de includes",20,100};

itemLista_t itemLista_proyectos_mf2={"proyectos","Lista de directorios de proyectos dependientes",20,100};

itemLista_t itemLista_outherDirInclude_mf2={"outherDirInclude","Lista de otros includes",20,100};

itemLista_t itemLista_includesForInstall_mf2={"includesForInstall","Lista de includes para instalar",20,100};

itemChar_t itemChar_outputLibInstall_mf2={"outputLibInstall","Directorio de instalacion",200};

itemChar_t itemChar_outputIncludeInstall_mf2={"outputIncludeInstall","Directorio de inst includes",200};

itemLista_t itemLista_test_mf2={"test","Lista de files *.tab que compila test",20,100};

metaTabItem_t metaTabItem_mf2[]={
 {'C',(itemChar_t *) &itemChar_tipoTabla_mf2}
,{'C',(itemChar_t *) &itemChar_versionTabla_mf2}
,{'C',(itemChar_t *) &itemChar_name_mf2}
,{'L',(itemLista_t *) &itemLista_fuentes_mf2}
,{'L',(itemLista_t *) &itemLista_includes_mf2}
,{'L',(itemLista_t *) &itemLista_proyectos_mf2}
,{'L',(itemLista_t *) &itemLista_outherDirInclude_mf2}
,{'L',(itemLista_t *) &itemLista_includesForInstall_mf2}
,{'C',(itemChar_t *) &itemChar_outputLibInstall_mf2}
,{'C',(itemChar_t *) &itemChar_outputIncludeInstall_mf2}
,{'L',(itemLista_t *) &itemLista_test_mf2}

};

metaTab_t metaTab_mf2={
"mf2","",11,metaTabItem_mf2 };


metaTab_t *getMetaTab_mf2()
{
 return &metaTab_mf2;
}


