TITULO  := makefile generado por  zConfig1
NAME    := mf3
VERSION := 1.0.0

FUENTES  :=  mf3Lee.c mf32Json.c mf3ParseJson.c cJSON.c  mf3CargaMeta.c
INCLUDES := mf3.h

OUTHER_DIR_INCLUDE  :=

INCLUDES_FOR_OUTPUT :=

LIBRARY_NAME := lib$(NAME).a
CFLAGS = $(OUTHER_DIR_INCLUDE)
OBJETOS      := $(FUENTES:%.c=%.o)

# -------- RULES ------------------

all: compila test

compila: $(LIBRARY_NAME)

$(OBJETOS):$(FUENTES) $(INCLUDES)

$(LIBRARY_NAME): $(OBJETOS)
	- rm -f $(LIBRARY_NAME)
	ar -rf $@ $^

clean:
	- rm -f $(OBJETOS) $(LIBRARY_NAME)

test:
	make -f makefileTest
