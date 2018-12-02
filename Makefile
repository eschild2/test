
all:
	@make -C lib  all
	@make -C tests all

run: all
	@make -C tests run

clean:
	@make -C lib clean
	@make -C tests clean
