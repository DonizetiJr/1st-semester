CC=gcc
SRC=src/matrix.c src/crypt.c src/file.c
INCLUDE=./include
LIBS=-lm

all:
	$(CC) -o key-generator src/key-generator.c $(SRC) -I$(INCLUDE) $(LIBS)
	$(CC) -o cryptfile src/cryptfile.c $(SRC) -I$(INCLUDE) $(LIBS)
	$(CC) -o decryptfile src/decryptfile.c $(SRC) -I$(INCLUDE) $(LIBS)

key:
	./key-generator key.dat

crypt:
	./cryptfile key.dat plaintext.dat crypted.dat

decrypt:
	./decryptfile key.dat crypted.dat decrypted.dat

clean:
	find -name "*~" -exec rm -rf {} \;
	rm -rf key-generator cryptfile decryptfile

full: clean all key crypt decrypt

