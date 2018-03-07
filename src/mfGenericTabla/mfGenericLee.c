
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "mfGeneric.h"

mfGenericLee(char *nombreFichero,mfGeneric_t *mfGeneric)
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
 mfGenericLimpiaBuf(buf);
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
mfGenericLimpiaBuf(label); 


// Char tipoTabla
if (strcmp(label,"tipoTabla")==0)
 {
    mfGenericTrunca(resto,10);
    mfGenericLimpiaBuf(resto);
   strcpy(mfGeneric->tipoTabla,resto);
   continue;
 }






// Char versionTabla
if (strcmp(label,"versionTabla")==0)
 {
    mfGenericTrunca(resto,10);
    mfGenericLimpiaBuf(resto);
   strcpy(mfGeneric->versionTabla,resto);
   continue;
 }






// Char name
if (strcmp(label,"name")==0)
 {
    mfGenericTrunca(resto,50);
    mfGenericLimpiaBuf(resto);
   strcpy(mfGeneric->name,resto);
   continue;
 }







// LISTA fuentes
if (strcmp(label,"fuentes")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mfGenericTrunca(campo,100);
    mfGenericLimpiaBuf(campo);
    strcpy(mfGeneric->fuentes[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA includesForInstall
if (strcmp(label,"includesForInstall")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mfGenericTrunca(campo,100);
    mfGenericLimpiaBuf(campo);
    strcpy(mfGeneric->includesForInstall[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }





continue;
 }


fclose(in);
return(0);
}











// PROGRAMA DE LECTURA DE LISTA

// usage:
//        mfGeneric_t *mfGenericLista;
//       numItems = mfGenericLeeLista(nombreFichero,&mfGenericLista);
mfGenericLeeLista(char *nombreFichero,mfGeneric_t **mfGenericLista)
{
mfGeneric_t mfGenericx;
mfGeneric_t *mfGeneric=&mfGenericx;
int i;
char buf[20001];
int numItems=0;
char *pun,*pun1,*resto,*campo,*label;

memset(mfGeneric,0,sizeof(mfGeneric_t));

FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,20000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 mfGenericLimpiaBuf(buf);
if (buf[0]=='#')
         continue;
resto=buf;

 
//...


// Inicia
resto=buf;



// Char tipoTabla
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mfGenericTrunca(campo,10);
    mfGenericLimpiaBuf(campo);
   strcpy(mfGeneric->tipoTabla,campo);





// Char versionTabla
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mfGenericTrunca(campo,10);
    mfGenericLimpiaBuf(campo);
   strcpy(mfGeneric->versionTabla,campo);





// Char name
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mfGenericTrunca(campo,50);
    mfGenericLimpiaBuf(campo);
   strcpy(mfGeneric->name,campo);




// LISTA fuentes
for (i=0;i<20;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   mfGenericTrunca(campo,100);
   mfGenericLimpiaBuf(campo);
   strcpy(mfGeneric->fuentes[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA includesForInstall
for (i=0;i<20;i++)
 {
   campo=resto; // esto para chequear el break despues del for
   if (!resto) break;  
   campo=resto;
   pun=memchr(resto,':',strlen(resto));
   if (pun)
    {
     *pun=0;
     pun++;
     resto=pun;
    }
   else
    resto=NULL;

   mfGenericTrunca(campo,100);
   mfGenericLimpiaBuf(campo);
   strcpy(mfGeneric->includesForInstall[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  




if (numItems==0) *mfGenericLista=malloc(sizeof(mfGeneric_t));
else *mfGenericLista=realloc(*mfGenericLista,(numItems+1)*sizeof(mfGeneric_t));
(*mfGenericLista)[numItems]=*mfGeneric;
memset(mfGeneric,0,sizeof(mfGeneric_t));
numItems++;
continue;
}
fclose(in);
return(numItems);
}



// este lee lista alternativo lo he creado para rellenar el mfGenericLista_t directamente
//  mfGenericLista ha de estar creado y limpio
mfGenericLeeLista1(char *nombreFichero,mfGenericLista_t *mfGenericLista)
{
mfGeneric_t *mfGeneric;

int ret=mfGenericLeeLista(nombreFichero,&mfGeneric);
if (ret<0) return(ret);
mfGenericLista->num=ret;
mfGenericLista->data=mfGeneric;
}



mfGenericPinta(mfGeneric_t *mfGeneric)
{
int i;
printf("tipoTabla = %s\n",mfGeneric->tipoTabla);
printf("versionTabla = %s\n",mfGeneric->versionTabla);
printf("name = %s\n",mfGeneric->name);
for (i=0;i<20;i++)
  printf("fuentes[i] = %s\n",mfGeneric->fuentes[i]);
for (i=0;i<20;i++)
  printf("includesForInstall[i] = %s\n",mfGeneric->includesForInstall[i]);
}


int mfGenericWrite(mfGeneric_t *mfGeneric, char *nameFile)
{
int i;
FILE *ou=fopen(nameFile,"w");
if (ou ==NULL) return(-1);
fprintf(ou,"\n# Tipo de la tabla\n");
fprintf(ou,"tipoTabla:%s\n",mfGeneric->tipoTabla);





fprintf(ou,"\n# Version de la tabla\n");
fprintf(ou,"versionTabla:%s\n",mfGeneric->versionTabla);





fprintf(ou,"\n# Nombre del output\n");
fprintf(ou,"name:%s\n",mfGeneric->name);





fprintf(ou,"\n# Lista de fuentes[20]\n");
fprintf(ou,"fuentes");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mfGeneric->fuentes[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de includes para instalar[20]\n");
fprintf(ou,"includesForInstall");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mfGeneric->includesForInstall[i]);
fprintf(ou,"\n");





return(0);
}

// Limpieza de buffer personalizado
mfGenericLimpiaBuf(char *buf)
{
return(mfGenericLimpiaBuffer(buf,strlen(buf)));
}
mfGenericLimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=mfGenericquita_espacios_iniciales(buf,len);
 ret=mfGenericquita_espacios_finales(buf,lenp);
 return(ret);
}
mfGenericquita_espacios_iniciales(char *buf ,int len)
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
mfGenericquita_espacios_finales(char *buf ,int len)
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

mfGenericTrunca(char *buf,int len)
{
if (strlen(buf)>len)
   buf[len]=0;
}
