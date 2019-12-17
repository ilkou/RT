#
#
CLEAR_LINE=\033[2K
BEGIN_LINE=\033[A
OK_COLOR=\x1b[102;01m
GREEN_COLOR=\x1b[32;01m
NO_COLOR=\x1b[0m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
BUILD_PRINT = $(GREEN_COLOR)libmlx.a successfully compiles$(NO_COLOR)
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
KO_STRING=$(ERROR_COLOR)[KO]$(NO_COLOR)

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "$(CLEAR_LINE)"
	@ar rc $(NOM) $^
	@ranlib $(NOM)
	@echo "$(BUILD_PRINT)"

%.o: %.m
	@echo "$(CLEAR_LINE)Compiling $< ==> $@ $(BEGIN_LINE)"; gcc -c $< -o $@

%.o: %.c
	@echo "$(CLEAR_LINE)Compiling $< ==> $@ $(BEGIN_LINE)"; gcc -c $< -o $@

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
