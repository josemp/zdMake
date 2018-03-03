# nombre de la biblioteca 

NAME         := ...
LIBRARY_NAME := lib$(NAME).a

# Lista de objetos e includes del proyecto

OBJETOS  := 

INCLUDES  := 


# install directorios

OUTPUT_LIB_INSTALL ?= ...
OUTPUT_INCLUDE_INSTALL ?= ...

# -------- RULES ------------------

all: compila  $(INCLUDES) $(LIBRARY_NAME)

$(LIBRARY_NAME): $(OBJETOS)
	- rm -f $@
	ar -rf $@ $^

compila:
	$(MAKE) -C ...
	$(MAKE) -C ...

clean:
	$(MAKE) -C ... clean
	$(MAKE) -C ... clean
install:
	- mkdir -p $(OUTPUT_LIB_INSTALL)
	- mkdir -p $(OUTPUT_INCLUDE_INSTALL)
	cp $(LIBRARY_NAME) $(OUTPUT_LIB_INSTALL)
	cp $(INCLUDES) $(OUTPUT_INCLUDE_INSTALL)
