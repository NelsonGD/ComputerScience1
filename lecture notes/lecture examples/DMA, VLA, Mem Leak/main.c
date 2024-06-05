#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Location
{
    int lat;
    int lon;
    char* name; // size of name can change
        /* Can't store anything wihtout creating size for it.
            You need to give it the size it needs and the starting address of the string. */
} Location;

createArrayOfLocPointers(char names[][100], int numLocations)
{
    // to get an array, call malloc. You can skip casting since its dones automatically
    Location* locs = malloc(numLocations * sizeof(Location*));

    for(int i = 0; i < numLocations; i++)
    {
        // to get a location use malloc, you can call create location instead of using malloc each time.
        // locs[i] is a location pointer
        locs[i] = createLocation(names[i]);

    }
}

/*
write a function that can create one location, fill up the lat and
lon with random int between 1 and 100, and copy the name passed to 
this function into the name property.
*/ 

/*
Write a function that recieves an array of names of locations,
and size of the array, and then dynamically allocate an aray of location, 
fill up the array with random lats and lons and with the passsed
names and return the array.
*/

Location* createLocArray(char name[][50], int numLocation)
{
    // Creates boxes that EACH contain lat, lon, and name. locs is representing this array.
    Location *locs = (Location*)malloc((numLocation * sizeof(Location)));

    // locs is a Location pointer, BUT when you say loc[i] this is a array ELEMENTS or better said, their location.
    // This just fills up the array with random numbers.
    for(int i = 0; i < numLocation; i++)
    {
        locs[i].lat = 1 + rand() % 100;
        locs[i].lon = 1 + rand() % 100;
        int len = strlen(name[i]) + 1;// Gives i-th location length, then you get the array.
        locs[i].name = malloc(len*sizeof(char)); 
        strcpy(locs[i].name, name[i]);
    }

    return createLocArray;
}

/* You are making a box with lat, lon, and name. 
You are sending the string for name to the function*/

Location* createLocation(char locName[])
{
    // Creates the box with lat, lon, and name, which is the size of the box. Return void pointer. So you make the pointer of Location type.
    Location* loc = (Location*)malloc(sizeof(Location));
    // lan and lon boxes are cretaed , but name can't becuase no size for that yet.
    loc -> lat = 1 + rand()%100;
    loc -> lon = 1 + rand()%100;
    
    // need lenght for the name
    int len = strlen(locName)+1; // Now len is equal to the length of name plus 1 for the terminator.
    
    /*now you allocate memory for the name
    we make it point to the name pointer in struct with line to the left of equallity */
    loc -> name = malloc(len*sizeof(char)); // Multiplying by char becuase you are allocating space for characters.
    
    // now you need to copy the name in locName[] into the struct name
    strcpy(loc->name, locName);

    return loc;
}

void displayLocation(Location *loc)
{
    printf("\nlat = %d lon = %d Name = %s\n", loc->lat, loc->lon, loc->name);
}

void free_memory(Location *locs, int size)
{
    for(int i = 0; i < size; i++)
    {
        free(locs[i]->name);
        free(locs[i]);
    }
    free(locs);
}

int main(void)
{
    // variable declaration
    srand(time(0));
    char Names[][100] = 
    {
        "UCF",
        "Walmart Neighboorhood Oviedo",
        "Publix UCF"
    };

    // Location* ls = createLocArray(Names, 3);

    Location ** ls = createArrayOfLocPointers(Names, 3);

    for(int i = 0; i < 3; i++)
    {
        displayLocation(&ls[i]);
    }

    //free_memory(ls, 3);


    // Function returns starting address of Location box, So you need a location pointer to store that address.
    // Location* l = createLocation(Name);
        // Now you have an l box that points to Location box which also has the name box.

    //displayLocation(l);

    /* Of course there's memory leak, since nothing has been freed. 
    You need to go from last to first, so name is the last thing that is dynamically allocated,
    then we get to free anything that cam after from last to first.*/
    // free(l -> name);
    // free(l);

    return 0;
}