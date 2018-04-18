
/******************************************/
/*  Estructuras de la tabla mf3  */ 
/******************************************/

/*  Estructura de la tabla mf3  */ 

typedef struct {  
 char tipoTabla[10+1];   
 char versionTabla[10+1];   
 char name[50+1];  
 char fuentes[20][100+1];  
 char includes[20][100+1];  
 char proyectos[100][100+1];  
 char outherDirInclude[20][100+1];  
 char outherDirLib[20][100+1];  
 char outherLibs[20][100+1];  
 char proyectosInstall[20][100+1];   
 char outputInstall[200+1]; 
} mf3_t;

/*  Estructura de la tabla List mf3  */ 

typedef struct 
{
  int num;
 mf3_t *data;

} mf3Lista_t;
