
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#include "mfB.h"

mfBLee(char *nombreFichero,mfB_t *mfB)
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
 mfBLimpiaBuf(buf);
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
mfBLimpiaBuf(label); 


// Char tipoTabla
if (strcmp(label,"tipoTabla")==0)
 {
    mfBTrunca(resto,10);
    mfBLimpiaBuf(resto);
   strcpy(mfB->tipoTabla,resto);
   continue;
 }






// Char versionTabla
if (strcmp(label,"versionTabla")==0)
 {
    mfBTrunca(resto,10);
    mfBLimpiaBuf(resto);
   strcpy(mfB->versionTabla,resto);
   continue;
 }






// Char name
if (strcmp(label,"name")==0)
 {
    mfBTrunca(resto,50);
    mfBLimpiaBuf(resto);
   strcpy(mfB->name,resto);
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
    mfBTrunca(campo,100);
    mfBLimpiaBuf(campo);
    strcpy(mfB->includesForInstall[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }







// LISTA directorios
if (strcmp(label,"directorios")==0)
 {
  int i=0;
  while(1)
   {
    campo=resto;
    pun=memchr(resto,':',strlen(resto));
    if(pun) *pun=0;
    mfBTrunca(campo,100);
    mfBLimpiaBuf(campo);
    strcpy(mfB->directorios[i],campo);
    i++;
    if (!pun) break; 
    pun++;
    if (strlen(pun)==0) break;
    resto=pun;
   }// end while
  continue;
 }






// Char outputLibInstall
if (strcmp(label,"outputLibInstall")==0)
 {
    mfBTrunca(resto,200);
    mfBLimpiaBuf(resto);
   strcpy(mfB->outputLibInstall,resto);
   continue;
 }






// Char outputIncludeInstall
if (strcmp(label,"outputIncludeInstall")==0)
 {
    mfBTrunca(resto,200);
    mfBLimpiaBuf(resto);
   strcpy(mfB->outputIncludeInstall,resto);
   continue;
 }





continue;
 }


fclose(in);
return(0);
}











// PROGRAMA DE LECTURA DE LISTA

// usage:
//        mfB_t *mfBLista;
//       numItems = mfBLeeLista(nombreFichero,&mfBLista);
mfBLeeLista(char *nombreFichero,mfB_t **mfBLista)
{
mfB_t mfBx;
mfB_t *mfB=&mfBx;
int i;
char buf[20001];
int numItems=0;
char *pun,*pun1,*resto,*campo,*label;

memset(mfB,0,sizeof(mfB_t));

FILE *in = fopen(nombreFichero,"r");
if (!in) return(-1);
while(1)
{
if (!fgets(buf,20000,in))
         break;
 if (strlen(buf)<3) continue;
 buf[strlen(buf)-1]=0;
 mfBLimpiaBuf(buf);
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
    mfBTrunca(campo,10);
    mfBLimpiaBuf(campo);
   strcpy(mfB->tipoTabla,campo);





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
    mfBTrunca(campo,10);
    mfBLimpiaBuf(campo);
   strcpy(mfB->versionTabla,campo);





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
    mfBTrunca(campo,50);
    mfBLimpiaBuf(campo);
   strcpy(mfB->name,campo);




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

   mfBTrunca(campo,100);
   mfBLimpiaBuf(campo);
   strcpy(mfB->includesForInstall[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  





// LISTA directorios
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

   mfBTrunca(campo,100);
   mfBLimpiaBuf(campo);
   strcpy(mfB->directorios[i],campo);
 }
// si hay un break arriba, hay que hacer un continue, pero sino no hay que hacerlo, pues puede ser el ultimo de la linea, uso el campo para eso
if (!campo) continue;  






// Char outputLibInstall
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mfBTrunca(campo,200);
    mfBLimpiaBuf(campo);
   strcpy(mfB->outputLibInstall,campo);





// Char outputIncludeInstall
if (!resto) continue;  
campo=resto;
pun=memchr(resto,':',strlen(resto));
if (pun)
 {
  *pun=0; pun++; resto=pun;
 }
else
 resto=NULL;
    mfBTrunca(campo,200);
    mfBLimpiaBuf(campo);
   strcpy(mfB->outputIncludeInstall,campo);



if (numItems==0) *mfBLista=malloc(sizeof(mfB_t));
else *mfBLista=realloc(*mfBLista,(numItems+1)*sizeof(mfB_t));
(*mfBLista)[numItems]=*mfB;
memset(mfB,0,sizeof(mfB_t));
numItems++;
continue;
}
fclose(in);
return(numItems);
}



// este lee lista alternativo lo he creado para rellenar el mfBLista_t directamente
//  mfBLista ha de estar creado y limpio
mfBLeeLista1(char *nombreFichero,mfBLista_t *mfBLista)
{
mfB_t *mfB;

int ret=mfBLeeLista(nombreFichero,&mfB);
if (ret<0) return(ret);
mfBLista->num=ret;
mfBLista->data=mfB;
}



mfBPinta(mfB_t *mfB)
{
int i;
printf("tipoTabla = %s\n",mfB->tipoTabla);
printf("versionTabla = %s\n",mfB->versionTabla);
printf("name = %s\n",mfB->name);
for (i=0;i<20;i++)
  printf("includesForInstall[i] = %s\n",mfB->includesForInstall[i]);
for (i=0;i<20;i++)
  printf("directorios[i] = %s\n",mfB->directorios[i]);
printf("outputLibInstall = %s\n",mfB->outputLibInstall);
printf("outputIncludeInstall = %s\n",mfB->outputIncludeInstall);
}


int mfBWrite(mfB_t *mfB, char *nameFile)
{
int i;
FILE *ou=fopen(nameFile,"w");
if (ou ==NULL) return(-1);
fprintf(ou,"\n# Tipo de la tabla\n");
fprintf(ou,"tipoTabla:%s\n",mfB->tipoTabla);





fprintf(ou,"\n# Version de la tabla\n");
fprintf(ou,"versionTabla:%s\n",mfB->versionTabla);





fprintf(ou,"\n# Nombre de la libreria\n");
fprintf(ou,"name:%s\n",mfB->name);





fprintf(ou,"\n# Lista de includes (fuera de proyectos) para instalar[20]\n");
fprintf(ou,"includesForInstall");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mfB->includesForInstall[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Lista de fuentes[20]\n");
fprintf(ou,"directorios");
for (i=0;i<20;i++)
  fprintf(ou,":%s",mfB->directorios[i]);
fprintf(ou,"\n");





fprintf(ou,"\n# Directorio de instalacion\n");
fprintf(ou,"outputLibInstall:%s\n",mfB->outputLibInstall);





fprintf(ou,"\n# Directorio de inst includes\n");
fprintf(ou,"outputIncludeInstall:%s\n",mfB->outputIncludeInstall);





return(0);
}

// Limpieza de buffer personalizado
mfBLimpiaBuf(char *buf)
{
return(mfBLimpiaBuffer(buf,strlen(buf)));
}
mfBLimpiaBuffer(char *buf,int len)
{
 int lenp,ret;
 lenp=mfBquita_espacios_iniciales(buf,len);
 ret=mfBquita_espacios_finales(buf,lenp);
 return(ret);
}
mfBquita_espacios_iniciales(char *buf ,int len)
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
mfBquita_espacios_finales(char *buf ,int len)
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

mfBTrunca(char *buf,int len)
{
if (strlen(buf)>len)
   buf[len]=0;
}
