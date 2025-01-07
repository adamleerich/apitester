
# Default build task on a tests/cmocka/*.c file needs to 
#   * Compile .exe file if needed
#   * Run .exe file EACH TIME


CC=gcc -I/mingw64/include -L/mingw64/lib

%.exe: %.c FORCE
	@if [ "$@" -ot "$<" ]; then \
		echo "making $@ from $<"; \
		$(CC) -o $@ $< -lcmocka; \
	else \
		echo "$@ is up-to-date."; \
	fi
	@./$@

.PHONY: FORCE 
