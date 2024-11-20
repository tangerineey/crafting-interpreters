.PHONY = clean

CC = gcc
CFLAGS = -Wall -Werror -Wpedantic -std=c99
EXEC = doubly

$(EXEC): $(EXEC).c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXEC)
