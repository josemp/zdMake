
/******************************************/
/*  Estructuras de la tabla mf2  */ 
/******************************************/

/*  Estructura de la tabla mf2  */ 

typedef struct {  
 char tipoTabla[10+1];   
 char versionTabla[10+1];   
 char name[50+1];  
 char fuentes[20][100+1];  
 char includes[20][100+1];  
 char proyectos[20][100+1];  
 char outherDirInclude[20][100+1];  
 char includesForInstall[20][100+1];   
 char outputLibInstall[200+1];   
 char outputIncludeInstall[200+1];  
 char test[20][100+1]; 
} mf2_t;

/*  Estructura de la tabla List mf2  */ 

typedef struct 
{
  int num;
 mf2_t *data;

} mf2Lista_t;
