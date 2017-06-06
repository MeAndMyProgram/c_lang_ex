#include <stdio.h>
#define MAX 25

int mgetline(char *s, int n);
int mstrend(char *s, char *m);
void mstrcat(char *s, char *m, int n);
int mstrlen(char *s);
void mstrncpy(char *s, char *m);
int mstrcmp(char *s, char *m, int n);
char *alloc(int n);
