#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *take_state_from_user();
int is_valid_state(char *state, char *valid_states[], int number_of_state);

char *take_district_from_user();
int is_valid_district(char *district, char *valid_districts[], int number_of_districts);

char *take_month_from_user();
int is_valid_month(char *valid_months[15], char *month, int number_of_months);

int take_date_from_user();
int is_valid_date(int *valid_dates, int date, int number_of_date);

int index_of(char *valid_states[], char *sate, int number_of_states);

char *strupr(char *s);

int main()
{
    int choice = 1;
    int number_of_states = 8;
    int number_of_months = 12;
    int number_of_dates = 31;

    char *state;
    char *district;
    char *month;
    int date;

    int index_of_state;

    char *valid_states[20] = {"DHAKA", "CHATTOGRAM", "BARISAL", "KHULNA",
                              "RAJSHAHI", "RANGPUR", "SYLHET", "MYMENSINGH"};

    char *valid_districts[10][20] = {
        {"DHAKA", "FARIDPUR", "GAZIPUR", "GOPALGANJ", "KISHOREGANJ", "MADARIPUR", "MANIKGANJ",
         "MUNSHIGANJ", "NARAYANGANJ", "NARSINGDI", "RAJBARI", "SHARIATPUR", "TANGAIL"},
        {"BANDARBAN", "BRAHAMANBARIA", "CHANDPUR", "CHATTOGRAM", "COMILLA", "COX'S BAZAR", "FENI",
         "KHAGRACHHARI", "LAKSHMIPUR", "NOAKHALI", "RANGAMATI"},
        {"BARGUNA", "BARISAL", "BHOLA", "JHALOKATI", "PATUAKHALI", "PIROJPUR"},
        {"BAGERHAT", "CHUDANGA", "JESSORE", "JHENAIDAH", "KHULNA", "KUSHTIA", "MAGURA", "MEHERPUR",
         "NARAIL", "SATKHIRA"},
        {"BOGRA", "JOYPURHAT", "NAOGAON", "NATORE", "NAWABGANJ", "PABNA", "RAJSHAHI", "SIRAJGANJ"},
        {"DINAJPUR", "GAIBANDHA", "KURIGRAM", "LALMONIRHAT", "NILPHAMARI", "PANCHAGARH",
         "RANGPUR", "THAKURGAON"},
        {"HABIGANJ", "MAULAVIBAZAR", "SUNAMGANJ", "SYLHET"},
        {"MAYMENSINGH", "NETRAKONA", "JAMALPUR", "SHERPUR"}};

    char *valid_months[15] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST",
                              "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

    int valid_dates[31] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                           21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

    int number_of_districts_in_state[10] = {13, 11, 6, 10, 8, 8, 4, 4};

    printf("\n\t\t\t\tWelcome to Salat Watch Bangladesh\n\n");

    while (choice)
    {
        printf("\nYour option's for state : ");
            for (int i = 0; i < number_of_states; i += 1)
            {
                printf(" %s ", valid_states[i]);
            }
        do
        {
            state = take_state_from_user();
        } while (is_valid_state(state, valid_states, number_of_states) == 0);

        index_of_state = index_of(valid_states, state, number_of_states);

         printf("\nYour option's for district : ");
            for (int i = 0; i < number_of_districts_in_state[index_of_state]; i += 1)
            {
                printf("%s ", *(valid_districts[index_of_state] + i));
            }

        do
        {
            district = take_district_from_user();
        } while (is_valid_district(district, valid_districts[index_of_state], number_of_districts_in_state[index_of_state]) == 0);

        printf("\nYour Location is (%s, %s)", state, district);
        //After successfully input location programm will show salat time of present date
        while (choice)
        {
            printf("\n\nEnter month and date you want to serch for \n");

            printf("\n\nYour option's for month : ");

                for (int i = 0; i < number_of_months; i += 1)
                {
                    printf(" %s ", valid_months[i]);
                }

            do
            {
                month = take_month_from_user();
            } while (is_valid_month(valid_months, month, number_of_months) == 0);

            printf("\n\nYour option's for date : ");
                for (int i = 0; i < number_of_dates; i += 1)
                {
                    printf(" %d ", valid_dates[i]);
                }

            do
            {
                date = take_date_from_user();
            } while (is_valid_date(valid_dates, date, number_of_dates) == 0);

            printf("\n\n\t\t\tSalat time of %s,%d : ", month, date);

            //after successfully inputed month and date program will show time of salat of serched date

            printf("\n\nDo You want to see Salat time of Any other day?\n");
            printf("If Yes(Press 1), If No(Press 0): ");
            scanf("%d", &choice);
        }

        printf("\n\nSetup again (Press 1) or exit (press 0)   : ");
        scanf("%d", &choice);
    }

    return 0;
}

char *take_state_from_user()
{
    char *state;
    state = (char *)malloc(sizeof(20));

    printf("\n\nState: ");
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

char *take_month_from_user()
{
    char *month;
    month = (char *)malloc(sizeof(20));

    printf("\nMonth: ");
    scanf("%s", month);
    strupr(month);
    return month;
}

int is_valid_month(char *valid_months[15], char *month, int number_of_months)
{
    int i;
    for (i = 0; i < number_of_months; i += 1)
    {
        if (strcmp(month, valid_months[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int take_date_from_user()
{
    int date;

    printf("\nDate: ");
    scanf("%d", &date);

    return date;
}

int is_valid_date(int *valid_dates, int date, int number_of_date)
{
    int i;

    for (i = 0; i < number_of_date; i += 1)
    {
        if (date == valid_dates[i])
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