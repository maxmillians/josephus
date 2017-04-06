# makefile for building a generic linked list solution for Josephus's problem

IDIR=./include
SDIR=./src
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=./lib

LIBS=-lm

_DEPS=	lldriver.h \
	llapp.h \
	llgen.h \
	main.h

DEPS=$(addprefix $(IDIR)/, $(_DEPS))

_OBJ=	main.o \
	llapp.o \
	llgen.o \
	lldriver.o 

OBJ=$(addprefix $(ODIR)/, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

josephus: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

all: $(OBJ)

$(OBJ): | $(ODIR)

$(ODIR):
	mkdir -p $(ODIR)

.PHONY:	clean

clean: 
	rm -fr $(ODIR) josephus* *~ $(IDIR)/*~ $(SDIR)/*~

