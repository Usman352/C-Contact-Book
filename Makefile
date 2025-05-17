all:
	gcc -g -o contact-book main.c contact.c

clean:
	rm -f contact-book