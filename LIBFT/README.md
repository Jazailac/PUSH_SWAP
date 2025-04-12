# Libft

Your very first own library! This project is about understanding the way these functions work, implementing and learning to use them. You will create your own library. It will be helpful since you will use it in your next C school assignments.

## 📝 Project Overview

Libft is a project that requires you to re-create some standard C library functions including some additional ones that can be useful for future projects. The goal is to create a library called libft.a made up of coded functions from scratch.

## 🛠️ Mandatory Functions

### Memory Functions
```c
void    *ft_memset(void *s, int c, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memccpy(void *dest, const void *src, int c, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
```

### String Functions
```c
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char    *ft_strnstr(const char *big, const char *little, size_t len);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_atoi(const char *nptr);
```

### Character Functions
```c
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
```

### Memory Allocation Functions
```c
void    *ft_calloc(size_t nmemb, size_t size);
char    *ft_strdup(const char *s);
```

### Additional Functions
```c
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
char    *ft_itoa(int n);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
```


## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make
- Git

### Installation
```bash
git clone https://github.com/[your-username]/libft.git
cd libft
make
```

This will create the `libft.a` library file.

### Usage
```c
#include "libft.h"

int main(void)
{
    char *str = "Hello, World!";
    ft_putstr_fd(str, 1);
    return (0);
}
```

Compile with:
```bash
gcc -L. -lft your_program.c
```

## 📚 Testing

It's recommended to use various test programs to verify your functions work correctly:
- [libft-unit-test](https://github.com/alelievr/libft-unit-test)
- [libft-war-machine](https://github.com/ska42/libft-war-machine)
- [libftTester](https://github.com/Tripouille/libftTester)

## 📋 Project Structure

```
libft/
├── Makefile
├── libft.h
├── ft_*.c (source files)
└── README.md
```

## 🔍 Evaluation

The project will be evaluated on:
1. Norm compliance
2. Undefined behavior handling
3. Memory management
4. Mandatory functions implementation
5. Bonus functions implementation (optional)

## ⚠️ Norm Requirements

Your code must comply with the 42 Norm:
- No more than 25 lines per function
- No more than 5 functions per file
- Only use allowed functions
- Follow naming conventions
