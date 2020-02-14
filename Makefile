IDIR=include/
LDIR=lib/
ODIR=obj/

PP=g++
FLAGS=-Wall -I $(IDIR)

_DEPS=cailcal.h
DEPS=$(patsubst %, $(IDIR)%, $(_DEPS))

_OBJS=cailcal.o
OBJS=$(patsubst %, $(ODIR)%, $(_OBJS))

TARGET=cailcal

$(ODIR)%.o: $(LDIR)%.cc $(DEPS)
	$(PP) -c -o $@ $< $(FLAGS)

$(TARGET): $(OBJS)
	$(PP) -o $@ $^ $(FLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)*.o $(TARGET)
