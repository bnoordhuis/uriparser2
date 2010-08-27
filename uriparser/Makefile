AR	=ar
CC	=gcc
CFLAGS	=-O2

OBJS	=UriCommon.o UriCompare.o UriEscape.o UriFile.o UriIp4Base.o UriIp4.o UriNormalizeBase.o UriNormalize.o UriParseBase.o UriParse.o UriQuery.o UriRecompose.o UriResolve.o UriShorten.o
ARCHIVE	=uriparser.a

all:	lib

lib:	$(OBJS)
	$(AR) cq uriparser.a $(OBJS)

clean:
	rm -rf uriparser.a $(OBJS)
