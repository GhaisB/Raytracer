/*
** main.c for my_select in /home/boell_g/projets/my_select
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Fri Jan  6 14:21:53 2012 guillaume boell
** Last update Sat Jun  2 14:11:13 2012 antoine knockaert
*/
#include <unistd.h>
#include <termios.h>
#include "../rt.h"

int			show_main_menu(void)
{
  int			key_pressed;

  key_pressed = 0;
  my_putstr("       == MAIN MENU ==\n");
  my_putstr("1 - Calculer rendu raytracing\n");
  my_putstr("2 - Calculer rendu pathtracing\n");
  my_putstr("ESC - Quitter\n");
  xread(0, &key_pressed, 4);
  return (key_pressed);
}

void			go_menu(char *filename)
{
  int			key;

  key = 0;
  activ_cap("cl");
  while ((key = show_main_menu()) != ECHAP && key != ECHAP)
    {
      if (key == '1')
	{
	  activ_cap("cl");
	  go_rayt(filename);
	}
      if (key == '2')
	{
	  activ_cap("cl");
	  go_patht(filename);
	}
      activ_cap("cl");
    }
}

int			main(int argc, char **argv, char **envp)
{
  struct termios	term;

  if (argc == 2)
    {
      xtgetent(get_term_name(envp));
      if (tcgetattr(0, &term) == -1)
	return (0);
      param_term(&term, 0);
      go_menu(argv[1]);
      activ_cap("cl");
      param_term(&term, 0);
    }
  else if (argc == 3 && my_match(argv[1], "--server"))
    {
      my_putstr("Not available now !\n");
    }
  else
    my_putstr("Usage : ./rt [[scene filename] | --server ip]\n");
  return (0);
}
