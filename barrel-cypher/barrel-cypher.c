#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
  int fp,size,i,j;
  int ln=1;
  int k[5000];
  int ks=0;
  int ki=0;
  int ad=1;
  unsigned long num;
  char out,c,*map,*end;
  struct stat st;
  stat(argv[1],&st);
  size=st.st_size;
  fp=open(argv[1],O_RDONLY);

  map=mmap(NULL,9999999,PROT_READ,MAP_SHARED,fp,0);
  num=strtoul(map, &end, 0);
  i=(end-map)+1;
  while(i < size)
  {
    c=map[i];
    if(c==10)
    {
      if(ln%2==0)
        putchar(c);
      ks=ki;
      ln++; i++;
      ki=0;
      ad=1;
      continue;
    }
    if(ln%2==0)
    {
      if(c==32)
      {
        putchar(c);
      } else {
        out=c-k[ki];
        if((int)out<97)
          out+=26;
        if((int)out>126)
          out-=26;
        putchar(out);
        if(ad)
          ki++;
        else
          ki--;
        if(ki==-1)
        {
          ki=0;
          ad=1;
        }
        if(ki==ks)
        {
          ki--;
          ad=0;
        }
      }
    } else {
      k[ki]=(c-'0');
      ki++;
    }
    i++;
  }
  exit(0);
}

