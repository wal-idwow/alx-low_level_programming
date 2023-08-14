#ifndef DOG_H
#define DOG_H

/**
	* struct dog - new type struct dog
	* @name: Dog's name
	* @age: Dog's age
	* @owner: owner's name
	* Description: dog's data
*/

struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
