NAME	=	Robots_Ricochet

SRC	=	deplacements.c  main.c  map_1.c  map_2.c  map_1multi.c  map_2multi.c  mode_solo.c  mode_multi.c  plateau.c map_perso.c high_score.c map_random.c
OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -march=native -g
#-O0 -fomit-frame-pointer -g
LIBS	=	-lncurses

all: 	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIRS) $(LIBS) -o $(NAME)

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

clean:
	rm -f $(NAME) *.o *.d

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	gcc -MM $(CFLAGS) $*.c > $*.d

