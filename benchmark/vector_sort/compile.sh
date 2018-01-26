gcc -O2 -o sort1 sort1.c
gcc -O2 -o sort1-merge sort1-merge.c
clang -O2 -o sort1-clang sort1.c
clang -O2 -o sort1-merge-clang sort1-merge.c

#1
echo "gcc quicksort"
time ./sort1
echo

#2
echo "gcc mergesort"
time ./sort1-merge
echo

#3
echo "clang quicksort"
time ./sort1-clang
echo

#4
echo "clang mergesort"
time ./sort1-merge-clang
echo

rm sort1 sort1-merge sort1-clang sort1-merge-clang
