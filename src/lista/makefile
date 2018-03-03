# output program

NAME    := listaTest

# fuentes e includes del proyecto

FUENTES  :=  lista.c listaTest.c

INCLUDES := lista.h

# directorios de includes externos

OUTHER_DIR_INCLUDE :=

OUTHER_DIR_LIB:=

# librerias utilizadas

OUTHER_LIBS:= 

# variables intermedias

CFLAGS = $(OUTHER_DIR_INCLUDE:%=-I%)
LDFLAGS = $(OUTHER_DIR_LIB:%=-L%)
LDLIBS =     $(OUTHER_LIBS)
OBJETOS      := $(FUENTES:%.c=%.o)

# -------- RULES ------------------

all: $(NAME)
$(OBJETOS):$(FUENTES) $(INCLUDES)
$(NAME): $(OBJETOS)
	$(CC) $(LDFLAGS)  $(OBJETOS) $(LDLIBS) -o $(NAME)

clean:
	 - rm -f $(OBJETOS) $(PROGRAM_OUTPUT)
