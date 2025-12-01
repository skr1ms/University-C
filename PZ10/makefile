CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BINDIR = bin
SRCDIR = .

FILE_LOCKING = file_locking.c
FILE_LOCKING_EXE = $(BINDIR)/file_locking

BOOKS_BIN = books.bin

.PHONY: all clean run

all: $(FILE_LOCKING_EXE)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(FILE_LOCKING_EXE): $(SRCDIR)/$(FILE_LOCKING) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

run: all
	@echo "=== Running file locking program ==="
	@$(FILE_LOCKING_EXE)

clean:
	@rm -f $(FILE_LOCKING_EXE)
	@rm -f $(BOOKS_BIN)
	@echo "Cleaned up executables and binary files"

.DEFAULT_GOAL := run

