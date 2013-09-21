/*
** update_main.c for update_main in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  9 09:50:18 2012 antoine knockaert
** Last update Sun Jun  3 10:10:32 2012 antoine knockaert
*/

#include	"../edit.h"

void		update_main(t_glob *glob, t_main *main)
{
  gboolean	value;

  if (glob->filename)
    {
      gtk_label_set_text (GTK_LABEL(main->lbl[2]), glob->filename);
      value = TRUE;
    }
  else
    {
      gtk_label_set_text (GTK_LABEL(main->lbl[2]), LBL_NO_FILE);
      value = FALSE;
    }
  change_sensitive(main->button[0], 1, value);
  change_sensitive(main->button[1], 1, FALSE);
  change_sensitive(main->button[2], 1, FALSE);
  change_sensitive(main->button[3], 1, FALSE);
}
