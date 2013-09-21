/*
** write_obj_file.c for write_obj_file in /home/knocka_a/repositories/rt/editeu
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May 30 15:40:31 2012 antoine knockaert
** Last update Sat Jun  2 19:39:47 2012 antoine knockaert
*/

#include	"../edit.h"

void		write_obj(FILE *file, t_glob *glob)
{
  t_sph		*obj_a;

  obj_a = glob->obj_a;
  while (obj_a)
    {
      fprintf(file, "%s\n", obj_a->name);
      fprintf(file, "%.4X\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",
	      (unsigned int) obj_a->color, obj_a->x, obj_a->y, obj_a->z,
	      obj_a->r, obj_a->xro, obj_a->yro, obj_a->zro, obj_a->bri);
      fprintf(file, "%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",
	      obj_a->trans, obj_a->ref, obj_a->ck, obj_a->a[0], obj_a->a[1],
	      obj_a->a[2], obj_a->b[0], obj_a->b[1], obj_a->b[2]);
      fprintf(file, "%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",
	      obj_a->c[0], obj_a->c[1], obj_a->c[2], obj_a->cons, obj_a->cons2,
	      obj_a->mat_type, obj_a->damier, obj_a->ref_flou);
      fprintf(file, "%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",
	      obj_a->limit_min[0], obj_a->limit_min[1], obj_a->limit_min[2],
	      obj_a->limit_max[0], obj_a->limit_max[1], obj_a->limit_max[2],
	      obj_a->perturb[0], obj_a->perturb[1], obj_a->perturb[2]);
      fprintf(file, "%.2f\n%.2f\n0\n",
	      (double) obj_a->damier_color[0], (double) obj_a->damier_color[1]);
      obj_a = obj_a->nt;
    }
}

static void	write_oeil(FILE *file, t_glob *glob)
{
  fprintf(file, "OEIL\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n",
	  glob->oeil->l_o[0], glob->oeil->l_o[1], glob->oeil->l_o[2],
	  glob->oeil->l_o[3], glob->oeil->l_o[4], glob->oeil->l_o[5],
	  glob->init->dist_focus, glob->init->scale_focus,
	  glob->init->blur_power);
}

void		write_obj_file(t_glob *glob)
{
  FILE		*file;

  file = fopen(glob->filename, "w");
  if (file != NULL)
    {
      write_oeil(file, glob);
      write_obj(file, glob);
      fclose(file);
    }
  else
    printf("Cannot open file %s.\n", glob->filename);
}
