# dirs
HDIR	= include
CPPDIR	= src
ODIR	= obj

# compilador
CC		= g++
CFLAGS	=-I$(HDIR) -Wall -Wextra

# dependencias
DEPS	= $(wildcard $(HDIR)/*.h) # esto lo que hace es tomar los archivos que terminen en .h que esten en include (https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html)

# objetos
OBJ 	:= $(patsubst $(CPPDIR)/%.cpp, $(ODIR)/%.o, $(wildcard $(CPPDIR)/*.cpp)) # patsubust modifica los strings obtenidos por lo que precisamos en este caso, de src/.. a obj/.. y .cpp a .o
OBJ 	+= $(ODIR)/main.o

# esto explicado en (https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# este es el que se hace solo escribiendo "make"
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/main.o: main.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# comandos
.PHONY: clean

# borra los .o
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 