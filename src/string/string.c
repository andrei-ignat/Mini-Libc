// SPDX-License-Identifier: BSD-3-Clause
#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *destination1 = destination;
	const char *source1 = source;
	size_t i = 0;
	while (source1[i] != '\0'){
	destination1[i] = source1[i];
	i++;
	}
    destination1[i] = '\0';
    return destination1;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;
    while (source[i] != '\0' && i < len) {
        destination[i] = source[i];
        i++;
    }
	if(source[i] == '\0')
	destination[i] = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i = 0 , l = 0;
	while (destination[i] != '\0'){
	i++;
	}
	while (source[l] != '\0'){
	destination[i] = source[l];
	i++;
	l++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	size_t i = 0 , l = 0;
	while (destination[i] != '\0'){
	i++;
	}
	while (source[l] != '\0' && l < len){
	destination[i] = source[l];
	i++;
	l++;
	}
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
	str1++;
	str2++;
	}
    if (*str1 == '\0' && *str2 == '\0')
    return 0;
    else
    if (*str1 > *str2)
    return 1;
    else
    return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;
	while (str1[i] == str2[i] && i < len){
	i++;
	}
	if (i == len)
	return 0;
	else
	if (str1[i] > str2[i])
	return 1;
	else
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i = 0;
	while (str[i] != c && str[i] != '\0') {
	i++;
	}
	if (str[i] == '\0')
	return NULL;
	else
	{
		for (int k=0; k < i; k++){
			str++;
		}
		return (char *)str;
	}
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int l = -1;
	for (int i = 0; i < (int)strlen(str); i++){
	if (str[i] == c)
	l = i;
	}
	if (l == -1)
	return NULL;
	else
	{
		int i = 0;
		while (i != l){
		str++;
		i++;
		}
		return (char *)str;
	}
}

char *strstr(const char *haystack, const char *needle)
{
	int l = 0;
	/* TODO: Implement strstr(). */
	while (*haystack != '\0') {
		size_t nr = 0;
		const char *haystack1 = haystack;
		const char *needle1 = needle;
		while (*needle1 != '\0') {
			if (*haystack1 == *needle1)
			nr++;
			haystack1++;
			needle1++;
		}
		if (nr == strlen(needle) && l == 0){
		return (char *)haystack;
		l = 1;
		}
	 haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	const char *haystack1 = haystack;
	int k = 0, l = -1;
	while (*haystack1 != '\0') {
		size_t nr = 0;
		const char *haystack2 = haystack1;
		const char *needle1 = needle;
		while (*needle1 != '\0') {
			if (*haystack2 == *needle1)
			nr++;
			haystack2++;
			needle1++;
		}
		if (nr == strlen(needle))
		l = k;
		k++;
		haystack1++;
	}
	for (int i = 0;i < l; i++){
	haystack++;
	}
	if(l != -1)
	return (char *)haystack;
	else
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *destination1 = (char *) destination;
	char *source1 = (char *) source;
	for (size_t i = 0; i < num; i++){
	destination1[i] = source1[i];
	}
	destination = destination1;
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *destination1 = (char *) destination;
	char *source1 = (char *) source;
	for (size_t i = 0; i < num; i++){
	destination1[i] = source1[i];
	}
	destination = destination1;
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *string1 = (const char *) ptr1;
	const char *string2 = (const char *) ptr2;
	size_t numar = 0;
	while (numar < num && string1[numar] == string2[numar]){
	numar++;
	}
	if (numar == num)
	return 0;
	else
	if (string1[numar] < string2[numar])
	return -1;
	else
	return 1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *source1 = (char *) source;
	for (size_t i = 0; i < num; i++){
	source1[i] = value;
	}
	source = source1;
	return source;
}
