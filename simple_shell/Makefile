all: libutils.a
	gcc -pedantic -Wall -Werror -Wextra hoshell.c libutils.a -o hoshell

libutils.a:
	gcc -pedantic -Wall -Werror -Wextra -c utils/dir.c utils/path.c utils/print_status.c utils/update_status.c utils/strncat.c utils/get_wd.c utils/get_env.c utils/cd.c utils/setenv.c utils/exit.c utils/free_command.c utils/inttostr.c utils/len.c utils/strcmp.c utils/strtoint.c utils/env.c utils/read_line.c utils/string_copy.c utils/string_split.c utils/utils.h
	ar -rc libutils.a path.o print_status.o exit.o dir.o inttostr.o strtoint.o strncat.o update_status.o cd.o get_wd.o get_env.o len.o setenv.o strcmp.o read_line.o free_command.o string_copy.o string_split.o env.o
	rm path.o print_status.o exit.o inttostr.o strtoint.o dir.o len.o strcmp.o strncat.o update_status.o cd.o get_wd.o get_env.o read_line.o setenv.o string_copy.o string_split.o free_command.o env.o

clean:
	rm hoshell utils/utils.h.gch libutils.a

re: clean all

dbg:
	gcc -g -pedantic -Wall -Werror -Wextra -c utils/path.c utils/dir.c utils/print_status.c utils/update_status.c utils/strncat.c utils/get_wd.c utils/get_env.c utils/cd.c utils/setenv.c utils/exit.c utils/free_command.c utils/inttostr.c utils/len.c utils/strcmp.c utils/strtoint.c utils/env.c utils/read_line.c utils/string_copy.c utils/string_split.c utils/utils.h
	ar -rc libutils.a path.o print_status.o exit.o inttostr.o strtoint.o dir.o strncat.o update_status.o cd.o get_wd.o get_env.o len.o setenv.o strcmp.o read_line.o free_command.o string_copy.o string_split.o env.o
	rm path.o print_status.o exit.o inttostr.o strtoint.o len.o strcmp.o strncat.o dir.o update_status.o cd.o get_wd.o get_env.o read_line.o setenv.o string_copy.o string_split.o free_command.o env.o
	gcc -g -pedantic -Wall -Werror -Wextra hoshell.c libutils.a -o hoshell

pathtest:
	gcc -g -pedantic -Wall -Werror -Wextra -c utils/path-test.c utils/print_status.c utils/update_status.c utils/strncat.c utils/get_wd.c utils/get_env.c utils/cd.c utils/setenv.c utils/exit.c utils/free_command.c utils/inttostr.c utils/len.c utils/strcmp.c utils/strtoint.c utils/env.c utils/read_line.c utils/string_copy.c utils/string_split.c utils/utils.h
	ar -rc libutils.a path-test.o print_status.o exit.o inttostr.o strtoint.o strncat.o update_status.o cd.o get_wd.o get_env.o len.o setenv.o strcmp.o read_line.o free_command.o string_copy.o string_split.o env.o
	rm path-test.o print_status.o exit.o inttostr.o strtoint.o len.o strcmp.o strncat.o update_status.o cd.o get_wd.o get_env.o read_line.o setenv.o string_copy.o string_split.o free_command.o env.o
	gcc -g -pedantic -Wall -Werror -Wextra hoshell.c libutils.a -o hoshell

redbg: clean dbg
