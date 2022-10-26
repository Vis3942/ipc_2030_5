#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>

int number_log_messages = 0;

// char* log_file_name = "xxxx_logs.txt"; // leave this variable as null if you want to write to console
char * log_file_name = NULL;

int console_log(char *message,...)
{
  FILE * log_fp;
  va_list arglist;
  time_t now;
  struct tm *tm_now;
  char buffer[80];

  if (log_file_name != NULL) {
    number_log_messages ++;
    if (number_log_messages >= 25000)
    {
      number_log_messages = 0;
      log_fp = fopen(log_file_name,"w");
    }
    else
    {
      log_fp = fopen(log_file_name,"a+");
    }
  }
  else 
  {
    log_fp = NULL;
  }

  // if (log_fp == NULL)
  //     return 0;

  now = time(NULL);
  tm_now = localtime(&now);
  strftime (buffer, 80, "[%Y-%m-%d %H:%M:%S]", tm_now);
  fprintf(log_fp,"%s",buffer);
  va_start(arglist,message);
  if (log_fp == NULL) {
    vfprintf(stdout,message,arglist);
  }
  else {
    vfprintf(log_fp,message,arglist);
  }
  va_end(arglist);
  //fprintf(log_fp," \n");
  fclose(log_fp);
  return 1;

}
