
/******************************************/
/*  Estructuras de la tabla mfB  */ 
/******************************************/

/*  Estructura de la tabla mfB  */ 

typedef struct {  
 char tipoTabla[10+1];   
 char versionTabla[10+1];   
 char name[50+1];  
 char includesForInstall[20][100+1];  
 char directorios[20][100+1];   
 char outputLibInstall[200+1];   
 char outputIncludeInstall[200+1]; 
} mfB_t;

/*  Estructura de la tabla List mfB  */ 

typedef struct 
{
  int num;
 mfB_t *data;

} mfBLista_t;
