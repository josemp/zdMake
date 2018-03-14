
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "mfB.h"


int mfB2JsonFile(char *nombreFichero,mfB_t *mfB)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mfB2Json(ou , mfB);
fclose(ou);
return(0);
}
size_t mfB2JsonBuf(char **buf,mfB_t *mfB)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mfB2Json(ou, mfB );
fclose(ou);
}

mfB2Json(FILE *ou,mfB_t *mfB)
{
int count=0;
int i;
fprintf(ou,"{\n");


if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"tipoTabla\":\"%s\"",mfB->tipoTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"versionTabla\":\"%s\"",mfB->versionTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"name\":\"%s\"",mfB->name);
count++;






if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"includesForInstall\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mfB->includesForInstall[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"directorios\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mfB->directorios[i]);
 }
fprintf(ou,"]");
count++;




if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outputLibInstall\":\"%s\"",mfB->outputLibInstall);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outputIncludeInstall\":\"%s\"",mfB->outputIncludeInstall);
count++;




fprintf(ou,"\n}");

}



// Utilidades para generar la lista

mfBList2Json(FILE *ou,mfBLista_t *mfB)
{
int i;
fprintf(ou,"[\n");
for (i=0;i<mfB->num;i++)
{
 if (i>0)
  fprintf(ou,",");
 mfB2Json(ou,&mfB->data[i]);
}


fprintf(ou,"]\n");
}
int mfBList2JsonFile(char *nombreFichero,mfBLista_t *mfB)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mfBList2Json(ou , mfB);
fclose(ou);
return(0);
}
size_t mfBList2JsonBuf(char **buf,mfBLista_t *mfB)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mfBList2Json(ou, mfB);
fclose(ou);
}

