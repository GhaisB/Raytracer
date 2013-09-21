/*
** link_main_widgets.c for link in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat Apr 28 18:08:50 2012 antoine knockaert
** Last update Sun Jun  3 10:41:33 2012 antoine knockaert
*/

#include	"../edit.h"

void		link_main_widget(t_main *main)
{
  gtk_container_add(GTK_CONTAINER(main->pwindow), main->vbox[0]);
  gtk_box_pack_start(GTK_BOX(main->vbox[0]), main->lbl[0], TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(main->vbox[0]), main->hbox[0], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->hbox[0]), main->button[0], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->hbox[0]), main->button[1], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->vbox[0]), main->hbox[1], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->hbox[1]), main->button[2], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->hbox[1]), main->button[3], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->vbox[0]), main->lbl[1], TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(main->vbox[0]), main->lbl[2], TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(main->vbox[0]), main->hbox[2], TRUE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(main->hbox[2]), main->button[4], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->hbox[2]), main->button[5], TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(main->vbox[0]), main->lbl[3], TRUE, FALSE, 10);
}
