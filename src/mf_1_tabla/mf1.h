
/******************************************/
/*  Estructuras de la tabla mf1  */ 
/******************************************/

/*  Estructura de la tabla mf1  */ 

typedef struct {  
 char tipoTabla[10+1];   
 char versionTabla[10+1];   
 char name[50+1];  
 char fuentes[20][100+1];  
 char includes[20][100+1];  
 char proyectos[20][100+1];  
 char outherDirInclude[20][100+1];  
 char outherDirLib[20][100+1];  
 char outherLibs[20][100+1]; 
} mf1_t;

/*  Estructura de la tabla List mf1  */ 

typedef struct 
{
  int num;
 mf1_t *data;

} mf1Lista_t;
