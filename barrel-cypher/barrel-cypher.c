#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

FILE *fp;

int main(int argc, char *argv[])
{
  int line_number = 1;
  int pos = 0;
  int keysize = 0;
  int key[5000];
  int keypos = 0;
  int ascdsc = 1;
  int numtests = 0;
  char line[5000];
  char outchar;
  int linesize = 0;
  fp = fopen(argv[1], "rt");

  numtests = atoi(fgets(line, 1024, fp));
  while(fgets(line, 5000, fp) != NULL)
  {
    if(line_number > (2 * numtests))
      return 0;
    linesize = strlen(line);
    if(line_number % 2 == 0)
    {
      for(pos = 0; pos < linesize; pos++)
      {
        if(isspace(line[pos]))
        {
          printf("%c", line[pos]);
        } else {
          outchar = line[pos] - key[keypos];
          if((int)outchar < 97)
            outchar = outchar + 26;
          if((int)outchar > 126)
            outchar = outchar - 26;
          printf("%c", outchar);
          if(pos == 0 || ascdsc)
            keypos++;
          else
            keypos--;
          if(keypos == -1)
          {
            keypos++;
            ascdsc = 1;
          }
          if(keypos == keysize)
          {
            keypos--;
            ascdsc = 0;
          }
        }
      }
    } else {
      keysize = linesize - 1;
      for(pos = 0; pos < keysize; pos++)
      {
        key[pos] = line[pos] - '0';
      }
    }
    keypos = 0;
    ascdsc = 1;
    line_number++;
  }
}

