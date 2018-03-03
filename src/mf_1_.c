
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "mf1.h"
#include "metaTab.h"

metaTab_t *getMetaTab_mf1();
int mf1Lee(char *nombre, mf1_t *mf1);
int _mf1GeneraMakefile(mf1_t *mf1,char *nombreFicheroOutput );


int mf1GeneraMakefile(char *nombreFicheroInput, char *nombreFicheroOutput)
{
mf1_t mf1;
memset(&mf1,0, sizeof(mf1_t));
int ret=mf1Lee(nombreFicheroInput,&mf1);
if (ret<0) return(ret);
ret=_mf1GeneraMakefile(&mf1,nombreFicheroOutput);
// Por ahora no controlo el error
return(0);



}
int _mf1GeneraMakefile(mf1_t *mf1,char *nombreFicheroOutput )
{
int i;
printf("al ataquer\n");
FILE *ou= fopen(nombreFicheroOutput,"w");
if (!ou) return(-1);
fprintf(ou,"# output program\n\n");

fprintf(ou,"NAME    := %s\n",mf1->name);

fprintf(ou,"\n# fuentes e includes del proyecto\n\n");

fprintf(ou,"FUENTES  := "); 
for(i=0;i<20;i++)
   if (strlen(mf1->fuentes[i])!=0)
      fprintf(ou," %s",mf1->fuentes[i]);
fprintf(ou,"\n\n");

fprintf(ou,"INCLUDES :=");
for(i=0;i<20;i++)
   if (strlen(mf1->includes[i])!=0)
      fprintf(ou," %s",mf1->includes[i]);
fprintf(ou,"\n");

fprintf(ou,"\n# directorios de includes externos\n\n");

fprintf(ou,"OUTHER_DIR_INCLUDE :=");
for(i=0;i<20;i++)
   if (strlen(mf1->outherDirInclude[i])!=0)
      fprintf(ou," %s",mf1->outherDirInclude[i]);
fprintf(ou,"\n\n");

fprintf(ou,"OUTHER_DIR_LIB:=");
for(i=0;i<20;i++)
   if (strlen(mf1->outherDirLib[i])!=0)
      fprintf(ou," %s",mf1->outherDirLib[i]);
fprintf(ou,"\n");

fprintf(ou,"\n# librerias utilizadas\n\n");

fprintf(ou,"OUTHER_LIBS:= ");
for(i=0;i<20;i++)
   if (strlen(mf1->outherLibs[i])!=0)
      fprintf(ou," %s",mf1->outherLibs[i]);
fprintf(ou,"\n");

fprintf(ou,"\n# variables intermedias\n\n");


fprintf(ou,"CFLAGS = $(OUTHER_DIR_INCLUDE:%%=-I%%)\n");
fprintf(ou,"LDFLAGS = $(OUTHER_DIR_LIB:%%=-L%%)\n");
fprintf(ou,"LDLIBS =     $(OUTHER_LIBS)\n");
fprintf(ou,"OBJETOS      := $(FUENTES:%%.c=%%.o)\n");
fprintf(ou,"\n# -------- RULES ------------------\n\n");
fprintf(ou,"all: $(NAME)\n");
fprintf(ou,"$(OBJETOS):$(FUENTES) $(INCLUDES)\n");
fprintf(ou,"$(NAME): $(OBJETOS)\n");
fprintf(ou,"\t$(CC) $(LDFLAGS)  $(OBJETOS) $(LDLIBS) -o $(NAME)\n");
fprintf(ou,"\nclean:\n");
fprintf(ou,"\t - rm -f $(OBJETOS) $(PROGRAM_OUTPUT)\n");
fclose(ou);
return(0);


}

int mf1GeneraTabla(char *namefile,char *tipo,char *version)
{
int i,j;
itemChar_t *itemChar;
itemLista_t *itemLista;
itemObjeto_t *itemObjeto;
metaTab_t *tabla=getMetaTab_mf1();
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

