
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <libgen.h>
#include "mf2.h"
#include "metaTab.h"
#include "zdMakeTabUtil.h"

metaTab_t *getMetaTab_mf2();
int mf2Lee(char *nombre, mf2_t *mf2);
int _mf2GeneraMakefile(mf2_t *mf2,char *nombreFicheroOutput );


int mf2GeneraMakefile(char *nombreFicheroInput, char *nombreFicheroOutput)
{
mf2_t mf2;
memset(&mf2,0, sizeof(mf2_t));
int ret=mf2Lee(nombreFicheroInput,&mf2);
if (ret<0) return(ret);
ret=_mf2GeneraMakefile(&mf2,nombreFicheroOutput);
// Por ahora no controlo el error
return(0);



}
int _mf2GeneraMakefile(mf2_t *mf2,char *nombreFicheroOutput )
{
int i;
printf("al ataquer\n");
FILE *ou= fopen(nombreFicheroOutput,"w");
if (!ou) return(-1);
fprintf(ou,"# output libreria\n\n");

fprintf(ou,"NAME    := %s\n",mf2->name);

fprintf(ou,"\n# fuentes e includes del proyecto\n\n");

fprintf(ou,"FUENTES  := "); 
for(i=0;i<20;i++)
   if (strlen(mf2->fuentes[i])!=0)
      fprintf(ou," %s",mf2->fuentes[i]);
fprintf(ou,"\n\n");

fprintf(ou,"INCLUDES :=");
for(i=0;i<20;i++)
   if (strlen(mf2->includes[i])!=0)
      fprintf(ou," %s",mf2->includes[i]);
fprintf(ou,"\n");

fprintf(ou,"\n# directorios de includes externos\n\n");

fprintf(ou,"OUTHER_DIR_INCLUDE :=");
// los proyectos tambien tienen que ser directorios de include
for(i=0;i<20;i++)
{
   if (strlen(mf2->proyectos[i])<3) continue;
      fprintf(ou," %s",mf2->proyectos[i]);
}

for(i=0;i<20;i++)
   if (strlen(mf2->outherDirInclude[i])!=0)
      fprintf(ou," %s",mf2->outherDirInclude[i]);
fprintf(ou,"\n\n");

fprintf(ou,"INCLUDES_FOR_INSTALL:=");
for(i=0;i<20;i++)
   if (strlen(mf2->includesForInstall[i])!=0)
      fprintf(ou," %s",mf2->includesForInstall[i]);
fprintf(ou,"\n");

fprintf(ou,"\n# install directorios\n\n");

fprintf(ou,"OUTPUT_LIB_INSTALL ?= %s\n",mf2->outputLibInstall);
fprintf(ou,"OUTPUT_INCLUDE_INSTALL ?= %s\n",mf2->outputLibInstall);

fprintf(ou,"\n# variables intermedias\n\n");

fprintf(ou,"\nLIBRARY_NAME := lib$(NAME).a\n\n");
fprintf(ou,"CFLAGS = $(OUTHER_DIR_INCLUDE:%%=-I%%)\n");
fprintf(ou,"OBJETOS      := $(FUENTES:%%.c=%%.o)\n");
fprintf(ou,"\n# -------- RULES ------------------\n\n");
fprintf(ou,"all: $(LIBRARY_NAME)\n");
fprintf(ou,"$(OBJETOS):$(FUENTEOS) $(INCLUDES)\n");

fprintf(ou,"\n$(LIBRARY_NAME): $(OBJETOS)\n");
fprintf(ou,"\t- rm -f $(LIBRARY_NAME)\n");
fprintf(ou,"\t ar -rf $@ $^\n");

fprintf(ou,"\nclean:\n");
fprintf(ou,"\t - rm -f $(OBJETOS) $(LIBRARY_NAME)\n");
// clean los test
for (i=0;i<20;i++)
{

   char sufijoData[200];
   char *sufijo;
   char dirName[200];
   sufijo=pathSufijo(mf2->test[i],"test",sufijoData);
   if (sufijo==NULL) continue; 
   pathDir(mf2->test[i],"test",dirName);
   if (strlen(sufijo)==0)
      fprintf(ou,"\tmake -C %s clean\n",dirName);
   else
      fprintf(ou,"\tmake -C %s -f makefile%s clean\n",dirName,sufijo);
}


fprintf(ou,"install:\n");
fprintf(ou,"\t- mkdir -p $(OUTPUT_LIB_INSTALL)\n");
fprintf(ou,"\t- mkdir -p $(OUTPUT_INCLUDE_INSTALL)\n");
fprintf(ou,"\tcp $(LIBRARY_NAME) $(OUTPUT_LIB_INSTALL)\n");
fprintf(ou,"\tcp $(INCLUDES_FOR_INSTALL) $(OUTPUT_INCLUDE_INSTALL)\n");


// Ahora los test

fprintf(ou,"\ntest: $(LIBRARY_NAME)\n");
for (i=0;i<20;i++)
{
   char sufijoData[200];
   char *sufijo;
   char dirName[200];
   sufijo=pathSufijo(mf2->test[i],"test",sufijoData);
   if (sufijo==NULL) continue; 
   pathDir(mf2->test[i],"test",dirName);
   if (strlen(sufijo)==0)
      fprintf(ou,"\tmake -C %s\n",dirName);
   else
      fprintf(ou,"\tmake -C %s -f makefile%s\n",dirName,sufijo);
}
fclose(ou);
return(0);


}
/*
char *pathSufijo(char *pathOriginal,char *descriError,char *output)
{
 char path[200+1];
 char *sufijo;
   strcpy(path,pathOriginal);
   if (strlen(path)==0) return(NULL);
   if (strlen(path)<6) {printf("%s <%s> no valido\n",descriError,pathOriginal);return(NULL);}
   sufijo=zdMakeSufijo(path);
   if (sufijo==NULL) 
   {printf("%s  = <%s> no valido\n",descriError,pathOriginal);return(NULL);}
   strcpy(output,sufijo);
   return(output);
}
char *pathDir(char *pathOriginal,char *descriError,char *output)
{
 char path[201];
 char *dirName;
 strcpy(path,pathOriginal);
   if (strlen(path)==0) return(NULL);
   if (strlen(path)<6) {printf("%s <%s> no valido\n",descriError,pathOriginal);return(NULL);}
   dirName=dirname(path);
   if (dirName==NULL) 
   {printf("%s  = <%s> no valido\n",descriError,pathOriginal);return(NULL);}
   strcpy(output,dirName);
}
*/

int mf2GeneraTabla(char *namefile,char *tipo,char *version)
{
int i,j;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
metaTab_t *tabla=getMetaTab_mf2();
//char namefile[200];
//sprintf(namefile,"%s.tab",nombre);
FILE *ou = fopen(namefile,"w");
if (!ou) return(-1);


for (i=0;i<tabla->numItems;i++)
{
 if (tabla->item[i].tipo=='C')
  {
      itemChar=tabla->item[i].data;
      if (strcmp(itemChar->nombre,"tipoTabla")==0)
          fprintf(ou,"%s: %s\n",itemChar->nombre,tipo);
      else if (strcmp(itemChar->nombre,"versionTabla")==0)
          fprintf(ou,"%s: %s\n",itemChar->nombre,version);
      else    
          fprintf(ou,"%s: ...\n",itemChar->nombre);

  }

 if (tabla->item[i].tipo=='L')
  {
      itemLista=tabla->item[i].data;
      fprintf(ou,"#%s\n",itemLista->descri);
      fprintf(ou,"%s: ... : ...\n",itemLista->nombre);
  }

 if (tabla->item[i].tipo=='O')
    {
      itemObjeto=tabla->item[i].data;
      fprintf(ou,"%s",itemObjeto->nombre);
      for (j=0;j<itemObjeto->numItems;j++)
       {
         fprintf(ou,":%s",itemObjeto->item[j].nombre);
       }
      fprintf(ou,"\n");

    }
/*
 if (tabla->item[i].tipo=='Y')
    {
      itemLista=tabla->item[i].data;
      fprintf(ou,"%s: miCb : eventoCallBack \n",itemLista->nombre);
    }
*/
}
fclose(ou);
return(0);

}

