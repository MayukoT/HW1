#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errono.h>

int errno=0;

struct _arword{
  char word[25];
  char arr[25];
  int len;
  char* next;
};

typedef _arword

//open a file
FILE *open_file(char *name, char* mode)
{
  FILE *stream;
  errno = 0;
  stream = fopen (name, mode);
  fprintf (stderr, "open %s: %s\n", name, strerror (errno));
  return stream;
}

//close a file
void close_file(FILE* stream){
  errno = 0;
  fclose(stream);
  fprintf (stderr, "close %s\n", strerror (errno));
}

int mk_new_dicstr(){

  
}

int mk_newdic(){
fil
}

//receive 16 letters from stdio
int inputletter(){
  char* lt;
  //標準入力から16文字読む
  while(lt=!16){
  printf("Input 16 letters and press return key.\nletters:");
  scanf(lt);
  //ltが文字列でないときの処理(数字などがあるとき)は??後ほど  
  if(strlen(lt)=!16){
    printf("Your input is invalid, please try again.\n")
      }
  }
}


int compareletters(str* a, str* b){
  i
}

main(){

  inputletter();
}
