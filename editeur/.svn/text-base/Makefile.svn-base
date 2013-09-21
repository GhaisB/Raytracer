##
## Makefile for make in /home/knocka_a/lem-in/editeur
## 
## Made by antoine knockaert
## Login   <knocka_a@epitech.net>
## 
## Started on  Thu Mar 29 09:36:44 2012 antoine knockaert
## Last update Sun Jun  3 11:59:24 2012 antoine knockaert
##

NAME=		rt_edit

SRC=		src/main.c \
		src/init_struct.c \
		src/valide_obj.c \
		src/main_window.c \
		src/widget_for_obj.c \
		src/link_main_widget.c \
		src/write_obj_file.c \
		src/pobj_window.c \
		src/link_pobj_widget.c \
		src/open_new_file.c \
		src/add_to_list_obj.c \
		gtk_func/gtk_combo_append.c \
		gtk_func/open_save_dialog.c \
		gtk_func/create_gtk_entry.c \
		gtk_func/change_sensitive.c \
		gtk_func/update_main.c \
		gtk_func/create_window.c \
		gtk_func/create_label.c \
		gtk_func/create_modal.c \
		gtk_func/create_button.c \
		../parsing/main.c \
		../parsing/export_tga.c \
		../parsing/tests.c \
		../parsing/init.c \
		../parsing/add_to_list_obj.c \
		../parsing/add_params_first.c \
		../lib/epur_str.c \
		../lib/read_all.c \
		../lib/my_match.c \
		../lib/xfree.c \
		../lib/concat.c \
		../lib/my_str_to_wordtab.c \
		../lib/hex_to_double.c \
		../lib/init_str.c \
		lib/my_putstr.c \
		lib/my_strlen.c \
		lib/xmalloc.c \
		lib/xappels.c \
		lib/my_strdup.c \

OBJ=		$(SRC:.c=.o)

CFLAGS +=	-W
CFLAGS +=	`pkg-config --cflags --libs gtk+-2.0`
CFLAGS +=	-Wall -ansi -pedantic -g

LDFLAGS=	`pkg-config --cflags --libs gtk+-2.0`

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		clean fclean all