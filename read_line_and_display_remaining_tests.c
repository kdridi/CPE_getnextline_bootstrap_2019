#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>

char *read_line_and_display_remaining(int fd, int n);

static int fd = -1;

static void open_file(void)
{
    fd = open("read_line_and_display_remaining.txt", O_RDONLY);
    assert(fd != -1);
    cr_redirect_stdout();
}

static void close_file(void)
{
    if (fd != -1)
        close(fd);
}

Test(read_line_and_display_remaining, should_handle_wrong_fd, .init = open_file, .fini = close_file)
{
    cr_assert_null(read_line_and_display_remaining(-1, 0));
}

Test(read_line_and_display_remaining, should_handle_empty_read, .init = open_file, .fini = close_file)
{
    cr_assert_null(read_line_and_display_remaining(fd, 0));
}

Test(read_line_and_display_remaining, should_handle_non_empty_read, .init = open_file, .fini = close_file)
{
    char *str = read_line_and_display_remaining(fd, 4);
    cr_assert_not_null(str);
    cr_assert_str_eq("read", str);
    cr_assert_stdout_eq_str("_line_and_display_remaining");
    free(str);
}

Test(read_line_and_display_remaining, should_handle_read_all, .init = open_file, .fini = close_file)
{
    char *str = read_line_and_display_remaining(fd, 31);
    cr_assert_not_null(str);
    cr_assert_str_eq("read_line_and_display_remaining", str);
    cr_assert_stdout_eq_str("");
    free(str);
}
