
#include <stdio.h>
#include "metaTab.h"

itemChar_t itemChar_tipoTabla_mfB={"tipoTabla","Tipo de la tabla",10};

itemChar_t itemChar_versionTabla_mfB={"versionTabla","Version de la tabla",10};

itemChar_t itemChar_name_mfB={"name","Nombre de la libreria",50};

itemLista_t itemLista_directorios_mfB={"directorios","Lista de fuentes",20,100};

itemChar_t itemChar_outputLibInstall_mfB={"outputLibInstall","Directorio de instalacion",200};

itemChar_t itemChar_outputIncludeInstall_mfB={"outputIncludeInstall","Directorio de inst includes",200};

metaTabItem_t metaTabItem_mfB[]={
 {'C',(itemChar_t *) &itemChar_tipoTabla_mfB}
,{'C',(itemChar_t *) &itemChar_versionTabla_mfB}
,{'C',(itemChar_t *) &itemChar_name_mfB}
,{'L',(itemLista_t *) &itemLista_directorios_mfB}
,{'C',(itemChar_t *) &itemChar_outputLibInstall_mfB}
,{'C',(itemChar_t *) &itemChar_outputIncludeInstall_mfB}

};

metaTab_t metaTab_mfB={
"mfB","",6,metaTabItem_mfB };


metaTab_t *getMetaTab_mfB()
{
 return &metaTab_mfB;
}


