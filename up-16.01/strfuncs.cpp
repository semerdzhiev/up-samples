// strfuncs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>

// this is assumed a constant string in Visual Studio
// when target compilation is Debug
char* cstr = "sample string to operate on";

int main() {
  // find length of string
  printf("string length : %d \n", strlen(cstr));

  // allocating memory - the odlskool way
  char* mystr = (char*) malloc(1024);

  // copy data - the quick approach
  memcpy(mystr, cstr, strlen(cstr) + 1);

  // find susbtring and character occurance
  printf("first occurance of operate : %s  \n", strstr(mystr, "oper"));
  printf("first occurance of char [t] : %s  \n", strchr(mystr, 't'));

  // concatenationa nd tokenisation example
  char* rstr = (char*) malloc(128);  
  char* ntoken;

  // determine which string function to use - Microsoft's or GNU's
#ifdef __GNUC__
  strcpy(rstr, "some string");
  strcat(rstr, "... and even more");
#else
  strcpy_s(rstr, 128, "some string");
  strcat_s(rstr, 128, "... and even more");
#endif

  printf("wat? : %s \n", rstr);

#ifdef __GNUC__
  char *pch = strtok (rstr, " ,.-");

  while (pch != NULL) {
    printf ("token : %s\n",pch);
    pch = strtok(NULL, " ,.-");
  }
#else
  char *pch = strtok_s (rstr, " ,.-", &ntoken);

  while (pch != NULL) {
    printf ("token : %s\n",pch);
    pch = strtok_s (NULL, " ,.-", &ntoken);
  }
#endif

  /* -------------------------------------------------------- */

  // size_t is the recommended type when dealing with number of bytes
  size_t maxbytes = 1024;
  void *ptr = malloc(maxbytes);

  int* mynums = (int*) ptr;  

  // this is like int* ary = new int[256]
  int* ary = (int*)calloc(256, sizeof(int)); 
  int* ary2 = new int[256];

  /* how we should use this memory ? */

  for (int i=0; i < maxbytes / sizeof(int); i++) {
    mynums[i] = i;
    printf("%d ", mynums[i]);
  }

  // free memory after using it
  free(ptr);
  free(ary);

  return 0;
}

