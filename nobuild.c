#define NOBUILD_IMPLEMENTATION
#include "./nobuild.h"

#define CFLAGS 	"-Wall", \
				"-Wextra", \
				"-std=c2x", \
				"-pedantic", \
				"-pedantic-errors", \
				"-O3"
	
#define SOURCE "moon.c"
#define BIN "moon"
#define CC "clang"
#define PREFIX "/usrl/local/bin"

int posix_main(int argc, char *argv[]){
    if (argc == 1){
    	CMD(CC, "-o", BIN, SOURCE, CFLAGS, NULL);
		return EXIT_SUCCESS;
	}

    if (argc > 1){
        if (strcmp(argv[1], "run") == 0){
            CMD("./"BIN);
        }else if (strcmp(argv[1], "install") == 0){
			CMD("doas", "cp", BIN, PREFIX);
        }else if (strcmp(argv[1], "remove") == 0){
			CMD("doas", "rm", "-v", PREFIX"/"BIN);
        }else if (strcmp(argv[1], "clean") == 0){
			CMD("rm -i", BIN);
        }else{
            PANIC("%s is unknown subcommand", argv[1]);
        }
    }
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    GO_REBUILD_URSELF(argc, argv);

	posix_main(argc, argv);

    return EXIT_SUCCESS;
}
