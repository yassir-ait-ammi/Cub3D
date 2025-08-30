CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -lX11 -lXext -lm

LIBHB_PATH = libhb/
LIBHB = $(LIBHB_PATH)libhb.a

NAME = cub3D
BONUS_NAME = cub3D_bonus

SRCS = mandatory/main.c mandatory/parsing.c mandatory/is.c mandatory/valid_map.c mandatory/flood_fill.c \
	mandatory/valid_texcture.c mandatory/cub3d.c mandatory/dda.c mandatory/render.c mandatory/keys.c \
	mandatory/ft_exit.c mandatory/textures.c mandatory/init_data.c mandatory/move_player.c

OBJS = $(SRCS:.c=.o)

BONUS = bonus/main_bonus.c bonus/parsing_bonus.c bonus/is_bonus.c bonus/valid_map_bonus.c \
	bonus/flood_fill_bonus.c bonus/valid_texcture_bonus.c bonus/cub3d_bonus.c bonus/dda_bonus.c \
	bonus/render_bonus.c bonus/keys_bonus.c bonus/ft_exit_bonus.c bonus/textures_bonus.c bonus/mini_map_bonus.c \
	bonus/mouse_bonus.c bonus/init_data_bonus.c bonus/move_player_bonus.c bonus/extra_mini_map_bonus.c \
	bonus/portal_bonus.c

BOB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBHB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBHB) $(LDFLAGS) -o $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(BOB) $(LIBHB)
	@$(CC) $(CFLAGS) $(BOB) $(LIBHB) $(LDFLAGS) -o $(BONUS_NAME)

$(LIBHB):
	@make -C $(LIBHB_PATH) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BOB)
	@make -C $(LIBHB_PATH) clean --no-print-directory

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBHB_PATH) fclean --no-print-directory

re: fclean all

.PHONY: clean fclean re all
