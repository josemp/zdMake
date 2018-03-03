
#include <stdio.h>
#include "metaTab.h"

itemChar_t itemChar_tipoTabla_mfGeneric={"tipoTabla","Tipo de la tabla",10};

itemChar_t itemChar_versionTabla_mfGeneric={"versionTabla","Version de la tabla",10};

itemLista_t itemLista_fuentes_mfGeneric={"fuentes","Lista de fuentes",20,100};

itemLista_t itemLista_includesForInstall_mfGeneric={"includesForInstall","Lista de includes para instalar",20,100};

metaTabItem_t metaTabItem_mfGeneric[]={
 {'C',(itemChar_t *) &itemChar_tipoTabla_mfGeneric}
,{'C',(itemChar_t *) &itemChar_versionTabla_mfGeneric}
,{'L',(itemLista_t *) &itemLista_fuentes_mfGeneric}
,{'L',(itemLista_t *) &itemLista_includesForInstall_mfGeneric}

};

metaTab_t metaTab_mfGeneric={
"mfGeneric","",4,metaTabItem_mfGeneric };


metaTab_t *getMetaTab_mfGeneric()
{
 return &metaTab_mfGeneric;
}


