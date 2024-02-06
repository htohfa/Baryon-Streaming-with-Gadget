const char * GADGET_COMPILER_SETTINGS = "" \
" mpicc \n "\
" -O3 -g -Wall -ffast-math -march=native -fno-common -fopenmp \n "\
" -isysroot \n "\
" /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk \n "\
" -DVALGRIND \n "\
" -DNO_OPENMP_SPINLOCK \n "\
"";
const char * GADGET_VERSION = "5.0.1.dev1_49ea80f679_dirty";
