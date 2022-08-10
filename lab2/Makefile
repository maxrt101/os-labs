
export TOPDIR := $(shell pwd)
export BINDIR := $(TOPDIR)/bin
export CC     := gcc

SRC := src/read.c src/open.c src/open2.c src/open3.c src/fork.c src/fork2.c src/wait.c src/wait2.c src/wait3.c

.PHONY: all

all: prepare
	for file in $(SRC); do \
		$(CC) $$file -o $(BINDIR)/$$(basename $${file%.*}); \
	done

prepare:
	mkdir -p $(BINDIR)

clean:
	rm -f $(BINDIR)

$(V).SILENT:
