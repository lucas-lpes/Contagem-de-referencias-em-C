#include "contaref.h"

int main()
{
    int *v = malloc2(sizeof(int));
    int *w = malloc2(sizeof(int));
    dump();
    w = atrib2(w, v);
    dump();
    char *c = malloc2(sizeof(char));
    dump();
    char *d = malloc2(sizeof(char));
    w = atrib2(w, NULL);
    dump();
    v = atrib2(v, NULL);
    dump();
    c = atrib2(c, NULL);
    dump();
    d = atrib2(d, NULL);
    dump();

    return 0;
}