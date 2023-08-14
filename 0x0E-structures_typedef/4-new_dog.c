#include "dog.h"
#include <stdlib.h>

/**
	* _strlen - gets a length of string
	* @str: string to get the length
	* Return: length of @str
*/

int _strlen(const char *str)
{
	int length = 0;

	while (*str++)
		length++;
	return (length);
}

/**
	* *_strcopy - returns @dest with a copy of aa string from @src
	* @src: string to copy
	* @dest: copy string here
	* Return: @dest
*/

char *_strcopy(char *dest, char *src)
{
	int d;

	for (d = 0; src[d]; d++)
		dest[d] = src[d];
	dest[d] = '\0';

	return (dest);
}

/**
	* *new_dog - creat a new dog
	* @name: dogs name
	* @age: dog's age
	* @owner: dog's owner
	* Return: struct pointer dog
	*	NULL if function fails
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	/*return null if the dog's name,age,owner is less than zero*/
	if (!name || age < 0 || !owner)
		return (NULL);

	dog = (dog_t *) malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if ((*dog).name == NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if ((*dog).owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	dog->name = _strcopy(dog->name, name);
	dog->age = age;
	dog->owner = _strcopy(dog->owner, owner);

	return (dog);
}
