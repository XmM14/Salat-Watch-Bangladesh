#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *take_state_from_user();
int is_valid_state(char *state, char *valid_states[], int number_of_state);

char *take_district_from_user();
int is_valid_district(char *district, char *valid_districts[], int number_of_districts);

int index_of(char *valid_states[], char *sate, int number_of_states);

char *strupr(char *s);

int main()
{
    int number_of_states = 8;

    char *state;
    char *district;

    int index_of_state;

    char *valid_states[20] = {"DHAKA", "CHATTAGRAM", "BARISAL", "KHULNA",
                              "RAJSHAHI", "RANGPUR", "SYLHET", "MYMENSINGH"};

    char *valid_districts[10][20] = {
        {"DHAKA", "FARIDPUR", "GAZIPUR", "GOPALGANJ", "KISHOREGANJ", "MADARIPUR", "MANIKGANJ",
         "MUNSHIGANJ", "NARAYANGANJ", "NARSINGDI", "RAJBARI", "SHARIATPUR", "TANGAIL"},
        {"BANDARBAN", "BRAHAMANBARIA", "CHANDPUR", "CHITTAGONG", "COMILLA", "COX'S BAZAR", "FENI",
         "KHAGRACHHARI", "LAKSHMIPUR", "NOAKHALI", "RANGAMATI"},
        {"BARGUNA", "BARISAL", "BHOLA", "JHALOKATI", "PATUAKHALI", "PIROJPUR"},
        {"BAGERHAT", "CHUDANGA", "JESSORE", "JHENAIDAH", "KHULNA", "KUSHTIA", "MAGURA", "MEHERPUR",
         "NARAIL", "SATKHIRA"},
        {"BOGRA", "JOYPURHAT", "NAOGAON", "NATORE", "NAWABGANJ", "PABNA", "RAJSHAHI", "SIRAJGANJ"},
        {"DINAJPUR", "GAIBANDHA", "KURIGRAM", "LALMONIRHAT", "NILPHAMARI", "PANCHAGARH",
         "RANGPUR", "THAKURGAON"},
        {"HABIGANJ", "MAULAVIBAZAR", "SUNAMGANJ", "SYLHET"},
        {"MAYMENSINGH", "NETRAKONA", "JAMALPUR", "SHERPUR"}};

    int number_of_districts_in_state[10] = {13, 11, 6, 10, 8, 8, 4, 4};

    printf("\n\t\t\tWelcome to Salat Watch Bangladesh\n\n");

    do
    {
        state = take_state_from_user();
    } while (is_valid_state(state, valid_states, number_of_states) == 0);

    index_of_state = index_of(valid_states, state, number_of_states);
    
    do
    {  
        district = take_district_from_user();
    } while (is_valid_district(district, valid_districts[index_of_state], number_of_districts_in_state[index_of_state]) == 0);

    printf("\nYour Location is (%s, %s)", state, district);
    return 0;
}

char *take_state_from_user()
{
    char *state;
    state = (char *)malloc(sizeof(20));

    printf("\nState: ");
    scanf("%s", state);
    strupr(state);
    return state;
}

int is_valid_state(char *state, char *valid_states[], int number_of_state)
{
    int i;

    for (i = 0; i < number_of_state; i += 1)
    {
        if (strcmp(state, valid_states[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

char *take_district_from_user()
{

    char *district;
    district = (char *)malloc(sizeof(20));

    printf("\nDistrict: ");
    scanf("%s", district);
    strupr(district);
    return district;
}

int is_valid_district(char *district, char *valid_districts[], int number_of_districts)
{
    int i;
    for (i = 0; i < number_of_districts; i += 1)
    {
        if (strcmp(district, valid_districts[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int index_of(char *valid_states[], char *state, int number_of_states)
{
    for (int i = 0; i < number_of_states; i += 1)
    {
        if (strcmp(valid_states[i], state) == 0)
        {
            return i;
        }      
    }
}

char *strupr(char *s)
{
    char *pc = s;
    while (*pc)
    {
        *pc = toupper(*pc);
        pc += 1;
    }

    return s;
}