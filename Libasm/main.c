#include <stdio.h>		// In order to use printf()
#include <string.h> 	// In order to use original strcpy() and strcmp()
#include <unistd.h>		// In order to use open() and close() functions
#include <fcntl.h>		// In order to use open() and close() functions
#include <errno.h>		// In order to use 'errno' variable
#include "libasm.h"

void	test_ft_strlen(int argc);
void	test_ft_strcpy(int argc);
void	test_ft_strcmp(int argc);
void	test_ft_write();
void	test_ft_read();
void	test_ft_strdup(int argc);

int	main(int argc, char **argv)
{
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen(argc);
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy(argc);
	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp(argc);
	if (argc == 1 || !strcmp(argv[1], "ft_write"))
		test_ft_write();
	if (argc == 1 || !strcmp(argv[1], "ft_read"))
		test_ft_read();
	if (argc == 1 || !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup(argc);
	return (0);
}

void	test_ft_strlen(int argc)
{
	printf("\n");
	printf("*********************************************************************\n");
	printf("**                       FT_STRLEN  TEST                           **\n");
	printf("*********************************************************************\n");
	printf("\n");
	printf("Test 1 -> String: 'Hello'\n");
	printf("   * strlen:    %li\n", strlen("Hello"));
	printf("   * ft_strlen: %li\n", ft_strlen("Hello"));
	printf("\n");
	printf("Test 2 -> String: 'Hello\t1234567890 *#/@]}'\n");
	printf("   * strlen:    %li\n", strlen("Hello\t1234567890 *#/@]}"));
	printf("   * ft_strlen: %li\n", ft_strlen("Hello\t1234567890 *#/@]}"));
	printf("\n");
	printf("Test 3 -> String: '       '\n");
	printf("   * strlen:    %li\n", strlen("       "));
	printf("   * ft_strlen: %li\n", ft_strlen("       "));
	printf("\n");
	printf("Test 4 -> String: ''\n");
	printf("   * strlen:    %li\n", strlen(""));
	printf("   * ft_strlen: %li\n", ft_strlen(""));
	printf("\n");
	printf("Test 5 -> String: 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.'\n");
	printf("   * strlen:    %li\n", strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam."));
	printf("   * ft_strlen: %li\n", ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam."));
	printf("\n");
	if (argc == 2)
	{
		printf("Test 6 -> String: 'NULL'\n");
		printf("   * strlen:    %s\n", "SEG_FAULT");
		printf("   * ft_strlen: %li\n", ft_strlen(NULL));
		printf("\n");
	}
}

void	test_ft_strcpy(int argc)
{
	char dst[100];

	printf("\n");
	printf("*********************************************************************\n");
	printf("**                       FT_STRCPY  TEST                           **\n");
	printf("*********************************************************************\n");
	printf("\n");
	printf("Test 1 -> String: 'Hello'\n");
	printf("   * strcpy:       %s\n", strcpy(dst, "Hello"));
	printf("   * ft_strcpy:    %s\n", ft_strcpy(dst, "Hello"));
	printf("\n");
	printf("Test 2 -> String: 'Hello  -1234567890 *#/@]}'\n");
	printf("   * strcpy:       %s\n", strcpy(dst, "Hello  -1234567890 *#/@]}"));
	printf("   * ft_strcpy:    %s\n", ft_strcpy(dst, "Hello  -1234567890 *#/@]}"));
	printf("\n");
	printf("Test 3 -> String: '       '\n");
	printf("   * strcpy:       %s\n", strcpy(dst, "       "));
	printf("   * ft_strcpy:    %s\n", ft_strcpy(dst, "       "));
	printf("\n");
	printf("Test 4 -> String: ''\n");
	printf("   * strcpy:       %s\n", strcpy(dst, ""));
	printf("   * ft_strcpy:    %s\n", ft_strcpy(dst, ""));
	printf("\n");
	if (argc == 2)
	{
		printf("Test 5 -> String: 'NULL'\n");
		printf("   * strcpy:       %s\n", "SEG_FAULT");
		printf("   * ft_strcpy:    %s\n", ft_strcpy(dst, NULL));
		printf("\n");
	}
}

void	test_ft_strcmp(int argc)
{
	int i;
	if (argc){i = 0;}

	printf("\n");
	printf("*********************************************************************\n");
	printf("**                       FT_STRCMP  TEST                           **\n");
	printf("*********************************************************************\n");
	printf("\n");
	printf("Test 1 -> String 1: 'Hello'\n");
	printf("       -> String 2: 'Hello'\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("Hello", "Hello"));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("Hello", "Hello"));
	printf("\n");
	printf("Test 2 -> String 1: '    '\n");
	printf("       -> String 2: '    '\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("    ", "    "));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("    ", "    "));
	printf("\n");
	printf("Test 3 -> String 1: ''\n");
	printf("       -> String 2: ''\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("", ""));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("", ""));
	printf("\n");
	printf("Test 4 -> String 1: 'Hello'\n");
	printf("       -> String 2: ''\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("Hello", ""));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("Hello", ""));
	printf("\n");
	printf("Test 5 -> String 1: ''\n");
	printf("       -> String 2: 'Hello'\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("", "Hello"));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("", "Hello"));
	printf("\n");
	printf("Test 6 -> String 1: 'Hello'\n");
	printf("       -> String 2: 'Bye'\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("Hello", "Bye"));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("Hello", "Bye"));
	printf("\n");
	printf("Test 7 -> String 1: '\xff\xff'\n");
	printf("       -> String 2: '\xff\xff'\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("\xff\xff", "\xff\xff"));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("\xff\xff", "\xff\xff"));
	printf("\n");
	printf("Test 8 -> String 1: '\xff\x80'\n");
	printf("       -> String 2: '\xff\x80'\n");
	printf("   * strcmp:     ret_value -> %i\n", i = strcmp("\xff\x80", "\xff\x00"));
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("\xff\x80", "\xff\x00"));
	printf("\n");

	if (argc == 2)
	{
	printf("Test 9 -> String 1: 'Hello'\n");
	printf("       -> String 2: 'NULL'\n");
	printf("   * strcmp:     ret_value -> %s\n", "SEG_FAULT");
	printf("   * ft_strcmp:  ret_value -> %i\n", i = ft_strcmp("Hello", NULL));
	printf("\n");
	}
}

void	test_ft_write()
{
	int 			i;
	unsigned int	fd;
	char 			buf[20];

	printf("\n");
	printf("*********************************************************************\n");
	printf("**                        FT_WRITE  TEST                           **\n");
	printf("*********************************************************************\n");
	printf("\n");

	printf("Test 1 ->   (1, 'Hello', 5)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(1, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(1, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 2 ->   (1, 'Hello', 3)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(1, "Hello", 3));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(1, "Hello", 3));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 3 ->   (1, '', 0)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(1, "", 0));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(1, "", 0));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 4 ->   (1, 'Hello', 8)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(1, "Hello", 8));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(1, "Hello", 8));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 5 ->   (1, 'NULL', 3)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(1, NULL, 3));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(1, NULL, 3));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 6 ->   (0, 'Hello', 5)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(0, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(0, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 7 ->   (42, 'Hello', 5)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(42, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(42, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 8 ->   (-1, 'Hello', 5)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(-1, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(-1, "Hello", 5));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 9 ->   (1, 'Hello', -3)\n");
	write(1, "   * write:     ", 16);
	printf("   -> ret_value: %2i", i = write(1, "Hello", -3));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	write(1, "   * ft_write:  ", 16);
	printf("   -> ret_value: %2i", i = ft_write(1, "Hello", -3));
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

		printf("Test 10 ->   (fd, 'Nice to meet you', 16)\n");
	fd = open("ft_write_test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	i = write(fd, "Nice to meet you", 16);
	close(fd);
	memset(buf, 0, 20);
	fd = open("ft_write_test.txt", O_RDONLY);
	read(fd, buf, 16);
	printf("   * write:      %s   -> ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	close(fd);
	remove("ft_write_test.txt");
	memset(buf, 0, 20);
	fd = open("ft_write_test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	i = ft_write(fd, "Nice to meet you", 16);
	close(fd);
	fd = open("ft_write_test.txt", O_RDONLY);
	read(fd, buf, 16);
	printf("   * ft_write:   %s   -> ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	close(fd);
	remove("ft_write_test.txt");
	printf("\n");
}

void	test_ft_read()
{
	int 			i;
	unsigned int	fd;
	char 			buf[20];

	printf("\n");
	printf("*********************************************************************\n");
	printf("**                        FT_READ  TEST                            **\n");
	printf("*********************************************************************\n");
	printf("\n");

	printf("Test 1 ->   Read 10 bytes from a file  -> (fd, buf, 10)\n");
	fd = open("ft_read_test.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	write(fd, "0123456789", 10);
	close(fd);
	memset(buf, 0, 20);
	fd = open("ft_read_test.txt", O_RDONLY);
	i = read(fd, buf, 10);
	close(fd);
	printf("   * read:      %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	memset(buf, 0, 20);
	fd = open("ft_read_test.txt", O_RDONLY);
	i = ft_read(fd, buf, 10);
	close(fd);
	printf("   * ft_read:   %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 2 ->  Reading 0 bytes -> (fd, buf, 0)\n");
	memset(buf, 0, 20);
	fd = open("ft_read_test.txt", O_RDONLY);
	i = read(fd, buf, 0);
	close(fd);
	printf("   * read:      %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	memset(buf, 0, 20);
	fd = open("ft_read_test.txt", O_RDONLY);
	i = ft_read(fd, buf, 0);
	close(fd);
	printf("   * ft_read:   %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 3 ->  Tryng to read more bytes than those contained by the file -> (fd, buf, 15)\n");
	memset(buf, 0, 20);
	fd = open("ft_read_test.txt", O_RDONLY);
	i = read(fd, buf, 15);
	close(fd);
	printf("   * read:      %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	memset(buf, 0, 20);
	fd = open("ft_read_test.txt", O_RDONLY);
	i = ft_read(fd, buf, 15);
	close(fd);
	printf("   * ft_read:   %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");

	printf("Test 4 ->  Use read() with NULL buf -> (fd, NULL, 15)\n");
	memset(buf, 0, 20);
	fd = open("ft_read_test.txt", O_RDONLY);
	i = read(fd, NULL, 15);
	close(fd);
	printf("   * read:      %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	fd = open("ft_read_test.txt", O_RDONLY);
	i = ft_read(fd, NULL, 15);
	close(fd);
	printf("   * ft_read:   %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");
	remove("ft_read_test.txt");

	printf("Test 5 ->   Trying to read 10 bytes from an empty file  -> (fd, buf, 10)\n");
	fd = open("empty_file.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	memset(buf, 0, 20);
	i = read(fd, buf, 10);
	close(fd);
	printf("   * read:      %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	memset(buf, 0, 20);
	fd = open("empty_file.txt", O_RDONLY);
	i = ft_read(fd, buf, 10);
	close(fd);
	printf("   * ft_read:   %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");
	remove("empty_file.txt");

	printf("Test 6 ->   Trying to read from non-existent fd  -> (142, buf, 10)\n");
	i = read(142, buf, 10);
	printf("   * read:      %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	memset(buf, 0, 20);
	i = ft_read(142, buf, 10);
	printf("   * ft_read:   %s  ->  ret_value: %2i", buf, i);
	if (i == -1)
		printf("  -> errno_value: %i\n", errno);
	else
		printf("\n");
	printf("\n");
}

void	test_ft_strdup(int argc)
{
	printf("\n");
	printf("*********************************************************************\n");
	printf("**                       FT_STRDUP  TEST                           **\n");
	printf("*********************************************************************\n");
	printf("\n");
	printf("Test 1 -> String: 'Hello'\n");
	printf("   * strdup:       %s\n", strdup("Hello"));
	printf("   * ft_strdup:    %s\n", ft_strdup("Hello"));
	printf("\n");
	printf("Test 2 -> String: 'Hello  -1234567890 *#/@]}'\n");
	printf("   * strdup:       %s\n", strdup("Hello  -1234567890 *#/@]}"));
	printf("   * ft_strdup:    %s\n", ft_strdup("Hello  -1234567890 *#/@]}"));
	printf("\n");
	printf("Test 3 -> String: '       '\n");
	printf("   * strdup:       %s\n", strdup("       "));
	printf("   * ft_strdup:    %s\n", ft_strdup("       "));
	printf("\n");
	printf("Test 4 -> String: ''\n");
	printf("   * strdup:       %s\n", strdup(""));
	printf("   * ft_strdup:    %s\n", ft_strdup(""));
	printf("\n");
	printf("Test 5 -> String: 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.'\n");
	printf("   * strdup:       %s\n", strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam."));
	printf("   * ft_strdup:    %s\n", ft_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam."));
	printf("\n");
	if (argc == 2)
	{
		printf("Test 6 -> String: 'NULL'\n");
		printf("   * strdup:       %s\n", "SEG_FAULT");
		printf("   * ft_strdup:    %s\n", ft_strdup(NULL));
		printf("\n");
	}
}

