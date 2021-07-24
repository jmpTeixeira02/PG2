final: main.o hashTable.o binTree.o dirTree.o fileInfo.o refArray.o strShare.o termFind.o
	gcc -Wall main.o hashTable.o binTree.o dirTree.o fileInfo.o refArray.o strShare.o termFind.o -o final

main.o: main.c
	gcc -c -Wall main.c

hashTable.o: hashTable.c hashTable.h
	gcc -c -Wall hashTable.c hashTable.h

binTree.o: binTree.c binTree.h
	gcc -c -Wall binTree.c binTree.h

dirTree.o: dirTree.c dirTree.h
	gcc -c -Wall dirTree.c dirTree.h

fileInfo.o: fileInfo.c fileInfo.h
	gcc -c -Wall fileInfo.c fileInfo.h

refArray.o: refArray.c refArray.h
	gcc -c -Wall refArray.c refArray.h

strShare.o: strShare.c strShare.h
	gcc -c -Wall strShare.c strShare.h

termFind.o: termFind.c termFind.h
	gcc -c -Wall termFind.c termFind.h

clean:
	rm hashTable.o
	rm binTree.o
	rm dirTree.o
	rm fileInfo.o
	rm refArray.o
	rm strShare.o
	rm termFind.o