# $Id: Makefile,v 1.11 2015-02-03 18:27:45-08 - - $
# Garrett Stoll gstoll

MKFILE    = Makefile
NOINCLUDE = ci clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
GMAKE     = gmake --no-print-directory

GCC       = gcc -g -O0 -Wall -Wextra -std=gnu11

CSOURCE   = graph01.c intList.c
CHEADER   = intList.h
OBJECTS   = ${CSOURCE:.c=.o}
EXECBIN   = graph01
SOURCES   = ${CHEADER} ${CSOURCE} ${MKFILE}
LISTING   = Listing.ps

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GCC} -o $@ ${OBJECTS}

%.o : %.c
	${GCC} -c $<


ci : ${SOURCES}
	cid + ${SOURCES}
	checksource ${SOURCES}

lis : ${SOURCES} ${DEPSFILE}
	mkpspdf ${LISTING} ${SOURCES}

clean :
	- rm  ${OBJECTS} core

spotless : clean
	- rm ${EXECBIN} ${LISTING} ${LISTING:.ps=.pdf}

deps : ${CSOURCE} ${CHEADER}
	@ echo "#  created `date`" >
	 ${CSOURCE} >>$


again :
	${GMAKE} spotless deps ci all lis

ifeq "${NEEDINCL}" ""
endif

