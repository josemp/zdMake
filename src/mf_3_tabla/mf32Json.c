
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "mf3.h"


int mf32JsonFile(char *nombreFichero,mf3_t *mf3)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mf32Json(ou , mf3);
fclose(ou);
return(0);
}
size_t mf32JsonBuf(char **buf,mf3_t *mf3)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mf32Json(ou, mf3 );
fclose(ou);
}

mf32Json(FILE *ou,mf3_t *mf3)
{
int count=0;
int i;
fprintf(ou,"{\n");


if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"tipoTabla\":\"%s\"",mf3->tipoTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"versionTabla\":\"%s\"",mf3->versionTabla);
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"name\":\"%s\"",mf3->name);
count++;






if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"fuentes\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf3->fuentes[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"includes\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf3->includes[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"proyectos\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf3->proyectos[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outherDirInclude\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf3->outherDirInclude[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outherDirLib\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf3->outherDirLib[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outherLibs\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf3->outherLibs[i]);
 }
fprintf(ou,"]");
count++;





if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"proyectosInstall\":[");
for (i=0;i<20;i++)
 {
  if (i>0) fprintf(ou,",");
  fprintf(ou,"\"%s\"",mf3->proyectosInstall[i]);
 }
fprintf(ou,"]");
count++;




if (count==0) fprintf(ou,"\n"); else fprintf(ou,",\n");
fprintf(ou,"\"outputInstall\":\"%s\"",mf3->outputInstall);
count++;




fprintf(ou,"\n}");

}



// Utilidades para generar la lista

mf3List2Json(FILE *ou,mf3Lista_t *mf3)
{
int i;
fprintf(ou,"[\n");
for (i=0;i<mf3->num;i++)
{
 if (i>0)
  fprintf(ou,",");
 mf32Json(ou,&mf3->data[i]);
}


fprintf(ou,"]\n");
}
int mf3List2JsonFile(char *nombreFichero,mf3Lista_t *mf3)
{
FILE *ou = fopen(nombreFichero,"w");
if (!ou) return(-1);
mf3List2Json(ou , mf3);
fclose(ou);
return(0);
}
size_t mf3List2JsonBuf(char **buf,mf3Lista_t *mf3)
{
size_t size=0;
FILE *ou=open_memstream (buf, &size);
if (!ou) return(-1);
mf3List2Json(ou, mf3);
fclose(ou);
}

