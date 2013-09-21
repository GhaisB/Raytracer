/*
** open_new_file.c for new_file in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon May 21 13:58:00 2012 antoine knockaert
** Last update Sun Jun  3 10:24:08 2012 antoine knockaert
*/

#include	"../edit.h"

static void	init_oeil(t_cod **oeil, t_mlx **init)
{
  *oeil = xmalloc(sizeof(t_cod));
  *init = xmalloc(sizeof(t_mlx));
  (*oeil)->l_o = xmalloc(6 * sizeof(double));
  (*oeil)->l_o[0] = 0;
  (*oeil)->l_o[1] = 0;
  (*oeil)->l_o[2] = 0;
  (*oeil)->l_o[3] = 0;
  (*oeil)->l_o[4] = 0;
  (*oeil)->l_o[5] = 0;
}

static void	set_params_file(t_glob *glob, t_sph *obj, t_cod *oeil,
				t_mlx *init)
{
  glob->obj_a = obj;
  glob->oeil = oeil;
  glob->init = init;
}

void		open_file(GtkWidget *widget, gpointer data)
{
  t_glob	*glob;
  char		*filename;
  t_sph		*obj_a;
  t_cod		*oeil;
  t_mlx		*init;

  glob = (t_glob *) data;
  widget = widget;
  filename = NULL;
  filename = open_save_dialog(TXT_CHOOSE_FILE, glob->main->pwindow,
			      GTK_FILE_CHOOSER_ACTION_OPEN, NULL);
  if (filename)
    {
      init_oeil(&oeil, &init);
      obj_a = parse(filename, oeil, init, NULL);
      if (!obj_a)
	create_modal("Erreur", TXT_INVALID_FILE,
		     GTK_WINDOW(glob->main->pwindow));
      else
	{
	  glob->filename = filename;
	  set_params_file(glob, obj_a, oeil, init);
	  update_main(glob, glob->main);
	}
    }
}

void		new_file(GtkWidget *widget, gpointer data)
{
  t_glob	*glob;
  char		*filename;
  t_cod		*oeil;
  t_mlx		*init;

  glob = (t_glob *) data;
  widget = widget;
  filename = NULL;
  filename = open_save_dialog(TXT_CHOOSE_FILE, glob->main->pwindow,
			      GTK_FILE_CHOOSER_ACTION_SAVE, NULL);
  if (filename)
    {
      init_oeil(&oeil, &init);
      glob->obj_a = NULL;
      glob->filename = filename;
      glob->oeil = oeil;
      glob->init = init;
      update_main(glob, glob->main);
    }
}
