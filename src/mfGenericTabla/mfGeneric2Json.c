
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "mfGeneric.h"


int mfGeneric2JsonFile(char *nombreFichero,mfGeneric_t *mfGeneric)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mfGeneric2Json(ou , mfGeneric);
fclose(ou);
return(0);
}
size_t mfGeneric2JsonBuf(char **buf,mfGeneric_t *mfGeneric)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mfGeneric2Json(ou, mfGeneric );
fclose(ou);
}

mfGeneric2Json(FILE *ou,mfGeneric_t *mfGeneric)
{
int count=0;
int i;
fprintf(ou,"{\n");


if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"tipoTabla\":\"%s\"",mfGeneric->tipoTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"versionTabla\":\"%s\"",mfGeneric->versionTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"name\":\"%s\"",mfGeneric->name);
count++;






if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"fuentes\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mfGeneric->fuentes[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"includesForInstall\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mfGeneric->includesForInstall[i]);
 }
fprintf(ou,"]");
count++;



fprintf(ou,"\n}");

}



// Utilidades para generar la lista

mfGenericList2Json(FILE *ou,mfGenericLista_t *mfGeneric)
{
int i;
fprintf(ou,"[\n");
for (i=0;i<mfGeneric->num;i++)
{
 if (i>0)
  fprintf(ou,",");
 mfGeneric2Json(ou,&mfGeneric->data[i]);
}


fprintf(ou,"]\n");
}
int mfGenericList2JsonFile(char *nombreFichero,mfGenericLista_t *mfGeneric)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mfGenericList2Json(ou , mfGeneric);
fclose(ou);
return(0);
}
size_t mfGenericList2JsonBuf(char **buf,mfGenericLista_t *mfGeneric)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mfGenericList2Json(ou, mfGeneric);
fclose(ou);
}

