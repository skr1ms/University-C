CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BINDIR = bin
SRCDIR = .

CHECK_LOCKS = check_locks.c
CHECK_LOCKS_EXE = $(BINDIR)/check_locks

BOOKS_BIN = books.bin

.PHONY: all clean run

all: $(CHECK_LOCKS_EXE)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(CHECK_LOCKS_EXE): $(SRCDIR)/$(CHECK_LOCKS) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

run: all
	@echo "=== Running check locks program ==="
	@$(CHECK_LOCKS_EXE)

clean:
	@rm -f $(CHECK_LOCKS_EXE)
	@rm -f $(BINDIR)/*
	@rm -f $(BOOKS_BIN)
	@echo "Cleaned up executables and binary files"

.DEFAULT_GOAL := run
