
#output program

NAME    := zdMake

# fuentes e includes del proyecto

FUENTES  :=  zdMake.c zdMakeTabLista.c mf_1_.c mf_2_.c mf_3_.c mf_B_.c zdMakeTabUtil.c

INCLUDES :=  zdMakeTabLista.h  mf_1_.h mf_2_.h mf_3_.h  mf_B_.h zdMakeTabUtil.h

# directorios e includes externos

OUTHER_DIR_INCLUDE := zdMakeTabla mf_1_tabla mf_2_tabla mf_3_tabla mf_B_tabla mfGenericTabla
OUTHER_DIR_LIB:= mf_1_tabla mf_2_tabla mf_3_tabla mf_B_tabla mfGenericTabla

# librerias utilizadas

OUTHER_LIBS:= -lmf1 -lmf2 -lmf3  -lmfB -lmfGeneric

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

install:
	cp $(NAME) /usr/local/bin
