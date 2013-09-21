/*
** my_putchar.c for my_putchar in /home/duez_a//igraph
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Fri Nov 11 11:22:42 2011 guillaume duez
** Last update Tue Apr 24 17:17:55 2012 guillaume boell
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char c)
{
  int	r;

  r = write(1, &c, 1);
  if (r == - 1)
    exit(0);
}
