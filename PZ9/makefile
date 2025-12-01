CC = gcc
CFLAGS = -Wall -Wextra -std=c11
BINDIR = bin
SRCDIR = .

FILTER_DATE = filter_date.c
ADD_WORD_COUNT = add_word_count.c
COUNT_DIGITS = count_digits.c

FILTER_DATE_EXE = $(BINDIR)/filter_date
ADD_WORD_COUNT_EXE = $(BINDIR)/add_word_count
COUNT_DIGITS_EXE = $(BINDIR)/count_digits

TEMP1 = temp_filtered.txt
TEMP2 = temp_with_words.txt

.PHONY: all clean run

all: $(FILTER_DATE_EXE) $(ADD_WORD_COUNT_EXE) $(COUNT_DIGITS_EXE)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(FILTER_DATE_EXE): $(SRCDIR)/$(FILTER_DATE) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(ADD_WORD_COUNT_EXE): $(SRCDIR)/$(ADD_WORD_COUNT) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

$(COUNT_DIGITS_EXE): $(SRCDIR)/$(COUNT_DIGITS) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $<

run: all
	@echo "=== Step 1: Filtering lines starting with '03.05.2024' ==="
	@$(FILTER_DATE_EXE) < input.txt > $(TEMP1)
	@echo "=== Step 2: Adding word count to each line ==="
	@$(ADD_WORD_COUNT_EXE) < $(TEMP1) > $(TEMP2)
	@echo "=== Step 3: Counting digits in file ==="
	@$(COUNT_DIGITS_EXE) < $(TEMP2)
	@rm -f $(TEMP1) $(TEMP2)

run-pipes: all
	@echo "=== Running all programs sequentially with pipes ==="
	@$(FILTER_DATE_EXE) < input.txt | $(ADD_WORD_COUNT_EXE) | $(COUNT_DIGITS_EXE)

clean:
	@rm -f $(FILTER_DATE_EXE) $(ADD_WORD_COUNT_EXE) $(COUNT_DIGITS_EXE)
	@rm -f $(TEMP1) $(TEMP2)
	@echo "Cleaned up executables and temporary files"

.DEFAULT_GOAL := run

