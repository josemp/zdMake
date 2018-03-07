#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <libgen.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <libgen.h>

/* busca el sufijo de un fichero makeSufijo.tab */
char *zdMakeSufijo(char *path)
{
char *baseName;
char *sufijo;
   if (strlen(path)<6) return(0);
   baseName=basename(path);
   if (memcmp(baseName,"make",4)!=0) return(NULL);
   if (memcmp(baseName+strlen(baseName)-4,".tab",4)!=0)
      return(NULL);
   baseName[strlen(baseName)-4]=0; /* el . lo substituimos por 0 */
   sufijo=baseName+4;
   return(sufijo);
}

/* Busca el sufijo, pero sin modificar el pathOriginal y enviando error si lo hay */
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
/* basicamente es un dirname pero sin cambiar el path original */
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

