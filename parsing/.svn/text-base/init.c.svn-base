/*
** init.c for rt in /home/boell_g/Documents/projets/rt
** 
** Made by guillaume boell
** Login   <boell_g@epitech.net>
** 
** Started on  Fri Jun  1 18:50:45 2012 guillaume boell
** Last update Sat Jun  2 11:11:44 2012 guillaume duez
*/

#include	"../rt.h"

void		stock_oeil(t_pars *pars, t_cod *cor, t_mlx *init)
{
  cor->l_o[0] = pars->oeil[0];
  cor->l_o[1] = pars->oeil[1];
  cor->l_o[2] = pars->oeil[2];
  cor->l_o[3] = pars->oeil[3];
  cor->l_o[4] = pars->oeil[4];
  cor->l_o[5] = pars->oeil[5];
  init->dist_focus = pars->oeil[6];
  init->scale_focus = pars->oeil[7];
  init->blur_power = pars->oeil[8];
}

void		init_types(t_pars *pars)
{
  pars->types[0] = my_strdup("NOTHING");
  pars->types[1] = my_strdup("SPHERE");
  pars->types[2] = my_strdup("PLAN");
  pars->types[3] = my_strdup("CYLINDRE");
  pars->types[4] = my_strdup("CONE");
  pars->types[5] = my_strdup("PARABOLOIDE");
  pars->types[6] = my_strdup("DISQUE");
  pars->types[7] = my_strdup("SELLE");
  pars->types[8] = my_strdup("PARALELLOGRAMME");
  pars->types[9] = my_strdup("TRIANGLE");
  pars->types[10] = my_strdup("LAMPE");
  pars->types[11] = my_strdup("TORE");
  pars->types[12] = my_strdup("CUBETROUE");
  pars->types[13] = NULL;
}

int		init(t_pars *pars, char *filename)
{
  int		fd;
  int		i;

  i = 0;
  fd = -1;
  if (filename)
    {
      pars->filename = filename;
      fd = open(filename, O_RDONLY);
      if (fd == -1)
	{
	  my_putstr("Impossible d'ouvrir le fichier.\n");
	  exit(EXIT_FAILURE);
	}
    }
  while (i < 9)
    pars->oeil[i++] = -1;
  pars->obj_a = NULL;
  init_types(pars);
  return (fd);
}
