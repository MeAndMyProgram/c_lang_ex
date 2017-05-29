#include <stdio.h>
#define MAX 32

void escape (char s[], char t[]);
void reescape (char  d[], char g[]);
void make_arr(char  m[]);



main()
{
	char s[MAX], t[MAX];
      	make_arr(s);
	escape(s, t);

  }

void escape (char s[], char t[])
{
  int i, j;

	j = 0;
	for (i = 0; s[i] != '\0'; ++i) {
	  switch (s[i]) {
	    case '\t':
	      t[j] = '\\';
	      ++j;
	      t[j] = 't';
	      ++j;
	      break;
	    case '\n':
	      t[j] = '\\';
	      ++j;
	      t[j] = 'n';
	      ++j;
	      break;
	    default:
	      t[j] =s[i];
	      ++j;
	      break;
}}
        printf("%d\n",  j);
	
	for (i = 0;  i <= j; ++i) 
	  printf("%c", s[i]);
	printf("\n");
}

void reescape(char s[], char t[])
  {
	int i, j;
	j = 0;
	for (i = 0; s[i] != '\0'; ++i) {
	  switch (s[i]) {
	    case '\\':
	      ++i;
	      switch (s[i]) {
		case 't':
		  t[j] = '\t';
		  ++j;
		  break;
		case 'n':
		  t[j] = '\n';
		  ++j;
		  break;
		  }
	      break;
	    default:
	      t[j] = s[i];
	      ++j;
	      break;
	      }
}
	
for (i = 0;  i != '\0'; ++i) 
      printf("%d",  s[i]);
    printf("\n");
    
  }

void make_arr(char s[])
  {
    char c;
    int i =0;
    while ((c = getchar()) != EOF) {
      s[i] = c;
	++i;
}
      s[i] ='\n';
      ++i;
      s[i] = '\0';
}




   
    

