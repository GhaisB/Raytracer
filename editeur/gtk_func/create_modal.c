/*
** create_modal.c for create_modal in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 27 23:35:51 2012 antoine knockaert
** Last update Sat Jun  2 19:14:22 2012 antoine knockaert
*/

#include	"../edit.h"

void		create_modal(char *title, char *text, GtkWindow *parent)
{
  GtkWidget	*pboite;
  GtkWidget	*lbl;

  pboite = gtk_dialog_new_with_buttons(title,
				       GTK_WINDOW(parent),
				       GTK_DIALOG_MODAL,
				       "_Ok", GTK_RESPONSE_OK,
				       NULL);
  lbl = create_label(text, GTK_JUSTIFY_CENTER, NULL);
  if (lbl && pboite)
    {
      gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pboite)->vbox), lbl, TRUE, FALSE,
			 15);
      gtk_widget_show_all(GTK_DIALOG(pboite)->vbox);
      gtk_dialog_run(GTK_DIALOG(pboite));
      gtk_widget_destroy(pboite);
    }
  else
    my_putstr("Gtk: Impossible de créer la boite de dialogue.\n");
}
