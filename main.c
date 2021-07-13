#include<stdio.h>
#include<string.h>
int main ()
{
    char state[20];
    char district[20];
    char location1[20] = {"Dhaka"}; // temporary variable for state
    char location2[20] = {"Dhaka"}; // temporary variable for district
    
    {
        printf("                Salat Watch Bangladesh              \n");
        printf("                    Plz Set Up                      \n");
        printf("State : ");
        scanf("%s", state);
        if(strcmp(state, location1) != 0/*any state name*/);
        {
            do
            {
                printf("\nPlz Enter a valid State : ");
                scanf("%s", state);
            } while (strcmp( state, location1) != 0);
            
        }
        printf("\nDistrict : ");
        scanf("%s", district);
        if(strcmp(district, location2) != 0/*any district name*/);
        {
            do
            {
                printf("\nPlz Enter a valid District : ");
                scanf("%s", district);
            } while (strcmp( district, location2) != 0);
            
        }
        printf("\nYour Location is : (%s, %s)", district, state);
    }
    
    return 0;
}