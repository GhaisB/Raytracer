/*
** my_put_nbr.c for my_put_nbr in /home/duez_a/
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Oct 11 12:21:16 2011 guillaume duez
** Last update Tue Apr 24 22:49:10 2012 antoine knockaert
*/

#include "../rt.h"

int	neg(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  return (nb);
}

void	my_put_nbr(int nb)
{
  int	nbis;
  int	n;
  int	x;
  int	nb2;
  int	division;

  division = 1;
  n = 1;
  x = 0;
  nb = neg(nb);
  nbis = nb / 10;
  while (nbis > 0)
    {
      n = n + 1;
      nbis = nbis / 10;
      division = division * 10;
    }
  while (x < n)
    {
      nb2 = nb / division;
      my_putchar(nb2 + '0');
      nb = nb % division;
      x = x + 1;
      division = division / 10;
    }
}
