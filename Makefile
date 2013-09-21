##
## Makefile for rt in /home/knocka_a/repositories/rt
## 
## Made by antoine knockaert
## Login   <knocka_a@epitech.net>
## 
## Started on  Sun Jun  3 11:43:19 2012 antoine knockaert
## Last update Sun Jun  3 19:45:03 2012 florian dell'aiera
##

NAME=	rt

SRC=	src/main.c							\
	src/termcap_work.c						\
	src/setenv.c							\
	pathtracer/begin.c						\
	pathtracer/calc.c						\
	pathtracer/vect_work.c						\
	pathtracer/my_pixel_put_to_image.c				\
	pathtracer/col_work.c						\
	pathtracer/raylaunch.c						\
	pathtracer/light.c						\
	pathtracer/light_calc.c						\
	raytracer/init_ptr_func.c					\
	raytracer/tore.c						\
	raytracer/multi_light.c						\
	raytracer/tore_shadow.c						\
	raytracer/goodies.c						\
	raytracer/save_original_data.c					\
	raytracer/cube_hole_shadow.c					\
	raytracer/cube_hole.c						\
	raytracer/ferari.c						\
	raytracer/intersection_shadow.c					\
	raytracer/inter_shadow.c					\
	raytracer/malloc_calc.c						\
	raytracer/func_download.c					\
	raytracer/modif_p_l.c						\
	raytracer/import_bmp.c						\
	raytracer/func_for_calc.c					\
	raytracer/calc_n_for_cyl.c					\
	raytracer/objet_limited.c					\
	raytracer/free_for_list.c					\
	raytracer/error_func.c						\
	raytracer/intersection.c					\
	raytracer/intersection2.c					\
	raytracer/func_spot.c						\
	raytracer/calc_rot_trans.c					\
	raytracer/func_for_coordonne.c					\
	raytracer/calc_p_intersection_normale.c				\
	raytracer/calc_p_intersection_normale2.c			\
	raytracer/calc_p_intersection_normale3.c			\
	raytracer/cardran.c						\
	raytracer/begin.c						\
	raytracer/func_list.c						\
	raytracer/my_pixel_put_to_image.c				\
	raytracer/my_pixel_put_to_image_bmp.c				\
	raytracer/my_exit.c						\
	parsing/main.c							\
	parsing/export_tga.c						\
	parsing/tests.c							\
	parsing/init.c							\
	parsing/add_to_list_obj.c					\
	parsing/add_params_first.c					\
	export/export.c							\
	export/my_putchar_file.c					\
	export/my_putstr_file.c						\
	export/put_map.c						\
	export/make_decalage.c						\
	export/aliasing.c						\
	export/get_tab.c						\
	lib/xappels.c							\
	lib/my_putchar.c						\
	lib/my_strdup.c							\
	lib/hex_to_double.c						\
	lib/my_putstr.c 						\
	lib/xmalloc.c 							\
	lib/my_getnbr.c 						\
	lib/xfree.c							\
	lib/my_str_to_wordtab.c						\
	lib/my_put_nbr.c						\
	lib/epur_str.c							\
	lib/concat.c							\
	lib/my_match.c							\
	lib/read_all.c							\
	lib/my_strlen.c							\
	lib/init_str.c

OBJ=		$(SRC:.c=.o)

CFLAGS=  	-W -Wall -g -O2

LIB=		-lcurses -L minilibx/ -lmlx -l X11 -l Xext -lm -lpthread -g

all:		$(NAME)

$(NAME): 	$(OBJ)
		cc $(OBJ) -o $(NAME) $(LIB)
		cd editeur ; make

count:
		cat $(SRC) | wc -l

clean:
		rm -f $(OBJ)
		cd editeur ; make clean

fclean:		clean
		rm -f $(NAME)
		cd editeur ; make fclean


re:		fclean all
