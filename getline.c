#include "shell.h"

/**
 * _realloc - Reallocates a memory block
 * @ptr: Pointer to the previous memory block
 * @old_size: Size in bytes of the allocated space for ptr
 * @new_size: New size in bytes of the new memory block
 *
 * Return: Pointer to the new memory block, or NULL if it fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (!ptr)
    {
        return (malloc(new_size));
    }
    if (new_size == old_size)
    {
        return (ptr);
    }

    new_ptr = malloc(new_size);
    if (!new_ptr)
    {
        return (NULL);
    }

    memcpy(new_ptr, ptr, old_size);
    free(ptr);

    return (new_ptr);
}

/**
 * _getline - Reads input from standard input
 * Return: Returns the input string, or NULL on failure
 */
char *_getline(void)
{
    size_t buffer_size = BUFSIZE;
    size_t r = 0;
    ssize_t bytes_read;
    char *buffer = malloc(buffer_size);
    char cmd[BUFSIZE];
    char *temp;

    if (buffer == NULL)
    {
        return (NULL);
    }

    while (1)
    {
        bytes_read = read(STDIN_FILENO, cmd, BUFSIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return (NULL);
        }
        if (bytes_read == 0)
        {
            break;
        }

        if (r + bytes_read >= buffer_size)
        {
            buffer_size += BUFSIZE;
            temp = _realloc(buffer, buffer_size - BUFSIZE, buffer_size);
            if (!temp)
            {
                free(buffer);
                return (NULL);
            }
            buffer = temp;
        }

        memcpy(buffer + r, cmd, bytes_read);
        r += bytes_read;

        if (memchr(cmd, '\n', bytes_read))
        {
            break;
        }
    }

    buffer[r] = '\0';
    return (buffer);
}
