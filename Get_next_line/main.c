int     main(void)
{
    int     fd;
    char    *line;
    fd = open("file1.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Open failed\n");
        return (-1);
    }
    while (get_next_line(fd, &line) > 0)
        printf("%s\n", line);
    printf("%s\n", line);
        if (close(fd) == -1)
    {
        printf("Close file failed\n");
        return (-1);
    }
    return (0);
}
