#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>

void read_and_display_read_line_n(int fd, int n);

static int fd = -1;

static void open_file(void)
{
    fd = open("read_and_display_read_line_n.txt", O_RDONLY);
    assert(fd != -1);
    cr_redirect_stdout();
}

static void close_file(void)
{
    if (fd != -1)
        close(fd);
}

Test(read_and_display_read_line_n, should_handle_wrong_fd, .init = open_file, .fini = close_file)
{
    read_and_display_read_line_n(-1, 0);
}

Test(read_and_display_read_line_n, should_handle_empty_read, .init = open_file, .fini = close_file)
{
    read_and_display_read_line_n(fd, 0);
}

Test(read_and_display_read_line_n, should_handle_non_empty_read, .init = open_file, .fini = close_file)
{
    read_and_display_read_line_n(fd, 4);
    cr_assert_stdout_eq_str("read");
}
