gcc -O2 -o sort1 sort1.c
gcc -O2 -o sort1-merge sort1-merge.c
clang -O2 -o sort1-clang sort1.c
clang -O2 -o sort1-merge-clang sort1-merge.c

gcc -O2 -o sort-plain sort-plain.c
clang -O2 -o sort-plain-clang sort-plain.c

g++ -O2 -o sort2 sort2.cpp
clang++ -O2 -o sort2-clang sort2.cpp

gcc -O2 -o sort-qsort sort-qsort.c
clang -O2 -o sort-qsort-clang sort-qsort.c

g++ -O2 -o sort2-fnptr sort2-fnptr.cpp
clang++ -O2 -o sort2-fnptr-clang sort2-fnptr.cpp


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

#5
echo "gcc plain quicksort"
time ./sort-plain
echo

#6
echo "clang plain quicksort"
time ./sort-plain-clang
echo

#7
echo "gcc qsort"
time ./sort-qsort
echo

#8
echo "clang qsort"
time ./sort-qsort-clang
echo

#9
echo "g++ std::vector std::sort"
time ./sort2
echo

#10
echo "clang++ std::vector std::sort"
time ./sort2-clang
echo

#11
echo "g++ std::vector std::sort fnptr"
time ./sort2-fnptr
echo

#12
echo "clang++ std::vector std::sort fnptr"
time ./sort2-fnptr-clang
echo

rm sort1 sort1-merge sort1-clang sort1-merge-clang \
   sort-plain sort-plain-clang sort2 sort2-clang \
   sort-qsort sort-qsort-clang sort2-fnptr sort2-fnptr-clang
