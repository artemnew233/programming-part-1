#ifndef CALLBACKS_H
#define CALLBACKS_H

typedef double (*FuncIntToDouble)(int);

void print_table(int from, int to, FuncIntToDouble f);

#endif
