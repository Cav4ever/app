.PHONY: clean
all: clean app
app: app.c
	gcc -g $^ -o $@
clean:
	-rm -f app
