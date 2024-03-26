gcc -c NWD.c -o NWD.o
gcc -c NWW.c -o NWW.o
gcc -c fibonacci.c -o fibonacci.o
gcc -c factorial.c -o factorial.o
ar r lib_arytm.a NWD.o NWW.o fibonacci.o factorial.o 2> /dev/null
gcc -c test_bibl.c -o test_bibl.o
gcc test_bibl.o lib_arytm.a -o test_bibl.out
echo "Biblioteka statyczna:"
./test_bibl.out

gcc -c -Wall -fPIC -D_GNU_SOURCE NWD.c
gcc -c -Wall -fPIC -D_GNU_SOURCE NWW.c
gcc -c -Wall -fPIC -D_GNU_SOURCE factorial.c
gcc -c -Wall -fPIC -D_GNU_SOURCE fibonacci.c
gcc NWD.o NWW.o factorial.o fibonacci.o -shared -o lib_arytmdyn.so
gcc -c test_bibldyn.c -o test_bibldyn.o
gcc test_bibldyn.o -L. -l_arytmdyn -o test_bibldyn.out
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:."
echo "Biblioteka dynamiczna:"
./test_bibldyn.out

rm -f *.o *.a *.so *.out