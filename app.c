#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <errno.h>

static const char short_opts[] = "N:t:p:w:m:h";
static const struct option long_opts[] = {
    {"Name",  1, 0, 'N'},
    {"time",  1, 0, 't'},
    {"place", 1, 0, 'p'},
    {"mode",  1, 0, 'm'},
    {"help",  0, 0, 'h'},
    {0, 0, 0, 0}
};

static void help(void)
{
    static const char const *help_msg[] = {
        "This is just a test app",
        "",
        "  -N, --Name   set Name",
        "  -t, --time   set time",
        "  -p, --place  set place",
        "  -w,          set when",
        "  -m, --mode   set mode",
        "  -h, --help   show this help",
        "",
        0
    };
    const char const **p = help_msg;

    printf("Usage: ./app option\n");
    while (*p) {
        printf("%s\n", *p++);
    }
}

int main(int argc, char **argv)
{
    int Name = 0;
    int time = 0;
    int place = 0;
    int when = 0;
    int mode = 0;
    int optc;
    int long_indx = -1;
    char *stop = NULL;

    while (true) {
        optc = getopt_long(argc, argv, short_opts, long_opts, &long_indx);
        if (-1 == optc) {
            break;
        }
        switch (optc) {
        case 'N':
            Name = strtoul(optarg, &stop, 0);
            if (*stop != '\0' || EINVAL == errno ) {
                printf("Wrong Name\n");
                exit(1);
            }
            break;
        case 't':
            time = strtoul(optarg, &stop, 0);
            if (*stop != '\0' || EINVAL == errno ) {
                printf("Wrong time\n");
                exit(1);
            }
            break;
        case 'p':
            place = strtoul(optarg, &stop, 0);
            if (*stop != '\0' || EINVAL == errno ) {
                printf("Wrong place\n");
                exit(1);
            }
            break;
        case 'w':
            when = strtoul(optarg, &stop, 0);
            if (*stop != '\0' || EINVAL == errno ) {
                printf("Wrong when\n");
                exit(1);
            }
            break;
        case 'm':
            mode = strtoul(optarg, &stop, 0);
            if (*stop != '\0' || EINVAL == errno ) {
                printf("Wrong Name\n");
                exit(1);
            }
            break;
        case 'h':
            help();
            exit(0);
            break;
        default:
            help();
            exit(0);
            break;
        }
    }
    printf("Name is %d\n", Name);
    printf("time is %d\n", time);
    printf("place is %d\n", place);
    printf("when is %d\n", when);
    printf("mode is %d\n", mode);

    return 0;
}
