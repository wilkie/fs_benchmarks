
PROGRAMS=postmark

all: $(PROGRAMS)

#CC=gcc
CC=../buildtools/local/bin/x86_64-pc-xomb-gcc
CFLAGS = -O2 -g -Wall -pipe

LFLAGS = -L../xomb/user/c/lib -L../xomb/runtimes/mindrt -l:drt0.a -l:syscall.a -l:mindrt.a

MAINSRC=postmark-1.51.c

postmark: $(MAINSRC)
	$(CC) $(CFLAGS) $(MAINSRC) $(OBJS) -o postmark $(LFLAGS)

install:
	mkdir -p $(DESTDIR)/usr/bin
	strip postmark
	cp $(PROGRAMS) $(DESTDIR)/usr/bin

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROGRAMS) build-stamp install-stamp build
	rm -rf debian/tmp err out
