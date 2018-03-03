
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "zdMakeTab.h"

zdMakeTabLee(char *nombreFichero,zdMakeTab_t *zdMakeTab)
{
char buf[2001];
char *pun,*pun1,*resto,*campo,*label;
FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,2000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 zdMakeTabLimpiaBuf(buf);
if (buf[0]=='#')
         continue;
resto=buf;

 
//...


// Etiquetas
label=buf;
pun=memchr(buf,':',strlen(buf));
if(!pun) continue;
*pun=0;
pun++;
resto=pun;
zdMakeTabLimpiaBuf(label); 


// Char tipo
if (strcmp(label,"tipo")==0)
 {
    zdMakeTabTrunca(resto,10);
    zdMakeTabLimpiaBuf(resto);
   strcpy(zdMakeTab->tipo,resto);
   continue;
 }






// Char nombre
if (strcmp(label,"nombre")==0)
 {
    zdMakeTabTrunca(resto,20);
    zdMakeTabLimpiaBuf(resto);
   strcpy(zdMakeTab->nombre,resto);
   continue;
 }






// Char descripcion
if (strcmp(label,"descripcion")==0)
 {
    zdMakeTabTrunca(resto,50);
    zdMakeTabLimpiaBuf(resto);
   strcpy(zdMakeTab->descripcion,resto);
   continue;
 }















continue;
 }


fclose(in);
return(0);
}











// PROGRAMA DE LECTURA DE LISTA

// usage:
//        zdMakeTab_t *zdMakeTabLista;
//       numItems = zdMakeTabLeeLista(nombreFichero,&zdMakeTabLista);
zdMakeTabLeeLista(char *nombreFichero,zdMakeTab_t **zdMakeTabLista)
{
zdMakeTab_t zdMakeTabx;
zdMakeTab_t *zdMakeTab=&zdMakeTabx;
int i;
char buf[20001];
int numItems=0;
char *pun,*pun1,*resto,*campo,*label;

memset(zdMakeTab,0,sizeof(zdMakeTab_t));

FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,20000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 zdMakeTabLimpiaBuf(buf);
if (buf[0]=='#')
         continue;
resto=buf;

 
//...


// Inicia
resto=buf;



// Char tipo
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    zdMakeTabTrunca(campo,10);
    zdMakeTabLimpiaBuf(campo);
   strcpy(zdMakeTab->tipo,campo);





// Char nombre
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    zdMakeTabTrunca(campo,20);
    zdMakeTabLimpiaBuf(campo);
   strcpy(zdMakeTab->nombre,campo);





// Char descripcion
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    zdMakeTabTrunca(campo,50);
    zdMakeTabLimpiaBuf(campo);
   strcpy(zdMakeTab->descripcion,campo);











if (numItems==0) *zdMakeTabLista=malloc(sizeof(zdMakeTab_t));
else *zdMakeTabLista=realloc(*zdMakeTabLista,(numItems+1)*sizeof(zdMakeTab_t));
(*zdMakeTabLista)[numItems]=*zdMakeTab;
memset(zdMakeTab,0,sizeof(zdMakeTab_t));
numItems++;
continue;
}
fclose(in);
return(numItems);
}



// este lee lista alternativo lo he creado para rellenar el zdMakeTabLista_t directamente
//  zdMakeTabLista ha de estar creado y limpio
zdMakeTabLeeLista1(char *nombreFichero,zdMakeTabLista_t *zdMakeTabLista)
{
zdMakeTab_t *zdMakeTab;

int ret=zdMakeTabLeeLista(nombreFichero,&zdMakeTab);
if (ret<0) return(ret);
zdMakeTabLista->num=ret;
zdMakeTabLista->data=zdMakeTab;
}



zdMakeTabPinta(zdMakeTab_t *zdMakeTab)
{
int i;
printf("tipo = %s\n",zdMakeTab->tipo);
printf("nombre = %s\n",zdMakeTab->nombre);
printf("descripcion = %s\n",zdMakeTab->descripcion);
}


int zdMakeTabWrite(zdMakeTab_t *zdMakeTab, char *nameFile)
{
int i;
FILE *ou=fopen(nameFile,"w");
if (ou ==NULL) return(-1);
fprintf(ou,"\n# tipo de makefile\n");
fprintf(ou,"tipo:%s\n",zdMakeTab->tipo);





fprintf(ou,"\n# nombre abreviado\n");
fprintf(ou,"nombre:%s\n",zdMakeTab->nombre);





fprintf(ou,"\n# descripcion\n");
fprintf(ou,"descripcion:%s\n",zdMakeTab->descripcion);















return(0);
}

// Limpieza de buffer personalizado
zdMakeTabLimpiaBuf(char *buf)
{
return(zdMakeTabLimpiaBuffer(buf,strlen(buf)));
}
zdMakeTabLimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=zdMakeTabquita_espacios_iniciales(buf,len);
 ret=zdMakeTabquita_espacios_finales(buf,lenp);
 return(ret);
}
zdMakeTabquita_espacios_iniciales(char *buf ,int len)
{
 int i;
 int lenp=0;
 for (i=0;i<len;i++)
   {
     if (lenp==0 && buf[i]==' ')
               continue;
     buf[lenp]=buf[i];
     lenp++;
   }
 for (i=lenp;i<len;i++)
      buf[i]=0;
 return(lenp);
}
zdMakeTabquita_espacios_finales(char *buf ,int len)
{
 int i;
 int lenp=len;
 for (i=(len)-1;i>=0;i--)
   {
     if (buf[i]==' ')
     { buf[i]=0;lenp--;}
     else
       break;
   }
 return(lenp);
}

// buf es terminado en 0 si su longitud es mayor que len, lo trunca

zdMakeTabTrunca(char *buf,int len)
{
if (strlen(buf)>len)
   buf[len]=0;
}
