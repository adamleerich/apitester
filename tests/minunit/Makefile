
# Default build task on a tests/minunit/*.c file needs to 
#   * Compile .exe file if needed
#   * Run .exe file EACH TIME


# CC=gcc -I/mingw64/include -I/c/home/git/R/r-source/include -L/mingw64/lib -L/c/home/git/R/r-source/bin/x64
CC=gcc -I/c/home/git/R/r-source/include -L/c/home/git/R/r-source/bin/x64

%.exe: %.c FORCE
	@if [ "$@" -ot "$<" ]; then \
		echo "making $@ from $<"; \
		$(CC) -o $@ $< -lR; \
	else \
		echo "$@ is up-to-date."; \
	fi
	@./$@

.PHONY: FORCE 
