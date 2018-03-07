
/**
  @brief recoje un path a un fichero descriptor zdMake y nos dice si corresponde a un makeSufijo.tab y cual es el dirname y el basename y el sufijo

  @param path el path que vamos a investigar
  @returns NULL si no es un makeSufijo.tab. Puntero al sufijo si es un makeSufijo.tab

  Nota: El original path no se puede volver a utilizar,
        Pero si utilizamos dirname(path) despues de utilizar esta funcion, el resultado es el correcto
  Nota: No chequea si el contenido es correcto.
*/


char *zdMakeSufijo(char *path);

char *pathSufijo(char *pathOriginal,char *descriError,char *output);
/* basicamente es un dirname pero sin cambiar el path original */
char *pathDir(char *pathOriginal,char *descriError,char *output);

