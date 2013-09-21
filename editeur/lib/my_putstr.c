/*
** my_putstr.c for my_putstr in /home/duez_a//rtv1/tp
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Feb 14 16:09:32 2012 guillaume duez
** Last update Fri Apr 27 23:44:36 2012 antoine knockaert
*/

#include <stdlib.h>
#include <unistd.h>
#include "../edit.h"

void	my_putstr(char *str)
{
  int	r;

  r = write(1, str, my_strlen(str));
  if (r == - 1)
    {
      my_putstr("error write");
      exit(0);
    }
}
