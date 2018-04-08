/* Fichero con la lista de tipo de makes */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <zdMakeTab.h>
int mf1GeneraMakefile();
int mf1GeneraTabla();
int mf2GeneraMakefile();
int mf2GeneraTabla();
int mf3GeneraMakefile();
int mf3GeneraTabla();
int mfBGeneraMakefile();
int mfBGeneraTabla();
zdMakeTab_t zdMakeTabList[]=
{
{"1","normal","makefile normal",mf1GeneraTabla,mf1GeneraMakefile},
{"2","lib","libreria",mf2GeneraTabla,mf2GeneraMakefile},
{"3","binario","binario instalable",mf3GeneraTabla,mf3GeneraMakefile},
{"B","bib","biblioteka",mfBGeneraTabla,mfBGeneraMakefile}
};


zdMakeTabLista_t zdMakeTabLista=
{
4, zdMakeTabList
};

zdMakeTabLista_t *zdMakeListaGet()
{
   return(&zdMakeTabLista);
}

zdMakeTab_t *zdMakeTabListaBusca(char * tipo)
{
int i;
for (i=0;i<zdMakeTabLista.num;i++)
   if (strcmp(tipo,zdMakeTabLista.data[i].tipo)==0)
     return(&zdMakeTabLista.data[i]);
  return(NULL);
}

