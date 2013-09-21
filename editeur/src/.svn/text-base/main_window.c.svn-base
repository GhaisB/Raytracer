/*
** main_window.c for mauin\ in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat Apr 28 11:44:00 2012 antoine knockaert
** Last update Sun Jun  3 10:40:51 2012 antoine knockaert
*/

#include	"../edit.h"

static void	fill_button_main(t_main	*main)
{
  main->button[0] = create_button(2, BUTTON_MAIN_CREATE_OBJ);
  main->button[1] = create_button(2, BUTTON_MAIN_EDIT_OBJ);
  main->button[2] = create_button(2, BUTTON_MAIN_PREVIEW);
  main->button[3] = create_button(2, BUTTON_MAIN_CLUSTER);
  main->button[4] = create_button(2, BUTTON_MAIN_OPEN_FILE);
  main->button[5] = create_button(2, BUTTON_MAIN_NEW_FILE);
  change_sensitive(main->button[0], 1, FALSE);
  change_sensitive(main->button[1], 1, FALSE);
  change_sensitive(main->button[2], 1, FALSE);
  change_sensitive(main->button[3], 1, FALSE);
}

static void	fill_widgets_main(t_main *main)
{
  int		size[2];

  size[0] = WIDTH_MAIN_WINDOW;
  size[1] = HEIGHT_MAIN_WINDOW;
  main->pwindow = create_window(TITLE_MAIN_WINDOW, GTK_WINDOW_TOPLEVEL,
				GTK_WIN_POS_CENTER, size);
  main->lbl[0] = create_label(LBL_TITLE_MAIN_WINDOW, GTK_JUSTIFY_LEFT, NULL);
  main->lbl[1] = create_label(LBL_FILE, GTK_JUSTIFY_LEFT, NULL);
  main->lbl[2] = create_label(LBL_NO_FILE, GTK_JUSTIFY_LEFT, NULL);
  main->lbl[3] = create_label(LBL_COPY, GTK_JUSTIFY_LEFT, NULL);
  fill_button_main(main);
  main->vbox[0] = gtk_vbox_new(FALSE, 0);
  main->vbox[1] = gtk_vbox_new(TRUE, 0);
  main->vbox[2] = gtk_vbox_new(TRUE, 0);
  main->hbox[0] = gtk_hbox_new(TRUE, 0);
  main->hbox[1] = gtk_hbox_new(TRUE, 0);
  main->hbox[2] = gtk_hbox_new(TRUE, 0);
}

void		connect_signal_main(t_glob *glob)
{
  g_signal_connect(G_OBJECT(glob->main->button[0]), "clicked",
		   G_CALLBACK(pobj_window), glob);
  g_signal_connect(G_OBJECT(glob->main->button[4]), "clicked",
		   G_CALLBACK(open_file), glob);
  g_signal_connect(G_OBJECT(glob->main->button[5]), "clicked",
		   G_CALLBACK(new_file), glob);
  g_signal_connect(G_OBJECT(glob->main->pwindow), "destroy",
		   (gtk_main_quit), NULL);
}

void		main_window(t_glob *glob)
{
  glob->main = xmalloc(sizeof(t_main));
  fill_widgets_main(glob->main);
  link_main_widget(glob->main);
  connect_signal_main(glob);
  gtk_widget_show_all(glob->main->pwindow);
}
