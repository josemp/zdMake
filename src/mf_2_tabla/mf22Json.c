
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "mf2.h"


int mf22JsonFile(char *nombreFichero,mf2_t *mf2)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mf22Json(ou , mf2);
fclose(ou);
return(0);
}
size_t mf22JsonBuf(char **buf,mf2_t *mf2)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mf22Json(ou, mf2 );
fclose(ou);
}

mf22Json(FILE *ou,mf2_t *mf2)
{
int count=0;
int i;
fprintf(ou,"{\n");


if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"tipoTabla\":\"%s\"",mf2->tipoTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"versionTabla\":\"%s\"",mf2->versionTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"name\":\"%s\"",mf2->name);
count++;






if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"fuentes\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf2->fuentes[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"includes\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf2->includes[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"proyectos\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf2->proyectos[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outherDirInclude\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf2->outherDirInclude[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"includesForInstall\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf2->includesForInstall[i]);
 }
fprintf(ou,"]");
count++;




if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outputLibInstall\":\"%s\"",mf2->outputLibInstall);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outputIncludeInstall\":\"%s\"",mf2->outputIncludeInstall);
count++;






if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"test\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf2->test[i]);
 }
fprintf(ou,"]");
count++;



fprintf(ou,"\n}");

}



// Utilidades para generar la lista

mf2List2Json(FILE *ou,mf2Lista_t *mf2)
{
int i;
fprintf(ou,"[\n");
for (i=0;i<mf2->num;i++)
{
 if (i>0)
  fprintf(ou,",");
 mf22Json(ou,&mf2->data[i]);
}


fprintf(ou,"]\n");
}
int mf2List2JsonFile(char *nombreFichero,mf2Lista_t *mf2)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mf2List2Json(ou , mf2);
fclose(ou);
return(0);
}
size_t mf2List2JsonBuf(char **buf,mf2Lista_t *mf2)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mf2List2Json(ou, mf2);
fclose(ou);
}

