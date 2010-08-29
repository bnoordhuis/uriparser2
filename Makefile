AR	=ar
CC	=gcc
CFLAGS	=-O2 -fPIC

OBJS	=uriparser2.o uriparser/UriParse.o uriparser/UriParseBase.o uriparser/UriCommon.o uriparser/UriIp4Base.o uriparser/UriIp4.o

all:	lib staticlib

lib:	$(OBJS)
	$(CC) -shared -o liburiparser2.so $(OBJS)

staticlib:	$(OBJS)
	$(AR) cq liburiparser2.a $(OBJS)

clean:
	rm -rf liburiparser2.so liburiparser2.a $(OBJS)
