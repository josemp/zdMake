TITULO  := makefile generado por  zConfig1
NAME    := mfGeneric
VERSION := 1.0.0

FUENTES  :=  mfGenericLee.c mfGeneric2Json.c mfGenericParseJson.c cJSON.c
INCLUDES := mfGeneric.h

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
