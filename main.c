#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

const int year = 2021;
const int DAYS_IN_2021 = 365;
const int number_of_states = 8;
const int number_of_months = 12;

typedef struct prayer_time
{
    char date[20], day[10], fajr[10], shuruq[10], dhuha[10], dhuhur[10], asr[10], magribh[10], isha[10];
} prayer_time;

char *take_state_from_user();
int is_valid_state(char *state, char *valid_states[], int number_of_state);

char *take_district_from_user();
int is_valid_district(char *district, char *valid_districts[], int number_of_districts);

void show_current_time();

prayer_time *get_list_of_prayer_time(char *path);

char *get_current_date();

char *get_searched_date(int month, int date);

prayer_time search_prayer_time(prayer_time *list_of_prayer_time, char *a_date);

void display_salat_times(prayer_time prayer_time_of_searched_day);

char *take_month_from_user();
int is_valid_month(char *valid_months[], char *month, int number_of_months);

int take_date_from_user();
int is_valid_date(int *valid_dates, int date, int number_of_date);

int days_in_month(char *months_with_31_days[], char *months_with_30_days[], int *number_of_months_in_type_of_months,
                  char *month);

int no_of_months(char *valid_months[], char *month, int number_of_months);

int index_of(char *valid_states[], char *sate, int number_of_states);

char *strupr(char *s);

int main()
{
    system("COLOR 6");

    int choice = 1;
    int number_of_days;
    int months_no;

    char *state;
    char *district;
    char *month;
    int date;
    char *curr_date;
    char *searched_date;
    char full_date[10];
    int index_of_state;

    prayer_time *list_of_prayer_time;
    prayer_time prayer_time_of_searched_day;

    char path[200];

    char *valid_states[20] = {"DHAKA", "CHATTOGRAM", "BARISAL", "KHULNA",
                              "RAJSHAHI", "RANGPUR", "SYLHET", "MYMENSINGH"};

    char *valid_districts[10][20] = {
        {"DHAKA", "FARIDPUR", "GAZIPUR", "GOPALGANJ", "KISHOREGANJ", "MADARIPUR", "MANIKGANJ",
         "MUNSHIGANJ", "NARAYANGANJ", "NARSINGDI", "RAJBARI", "SHARIATPUR", "TANGAIL"},
        {"BANDARBAN", "BRAHAMANBARIA", "CHANDPUR", "CHATTOGRAM", "COMILLA", "COX'S BAZAR", "FENI",
         "KHAGRACHHARI", "LAKSHMIPUR", "NOAKHALI", "RANGAMATI"},
        {"BARGUNA", "BARISAL", "BHOLA", "JHALOKATI", "PATUAKHALI", "PIROJPUR"},
        {"BAGERHAT", "CHUADANGA", "JESSORE", "JHENAIDAH", "KHULNA", "KUSHTIA", "MAGURA", "MEHERPUR",
         "NARAIL", "SATKHIRA"},
        {"BOGRA", "JOYPURHAT", "NAOGAON", "NATORE", "NAWABGANJ", "PABNA", "RAJSHAHI", "SIRAJGANJ"},
        {"DINAJPUR", "GAIBANDHA", "KURIGRAM", "LALMONIRHAT", "NILPHAMARI", "PANCHAGARH",
         "RANGPUR", "THAKURGAON"},
        {"HABIGANJ", "MOULVIBAZAR", "SUNAMGANJ", "SYLHET"},
        {"MAYMENSINGH", "NETROKONA", "JAMALPUR", "SHERPUR"}};

    char *valid_months[15] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST",
                              "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

    char *months_with_31_days[7] = {"JANUARY", "MARCH", "MAY", "JULY", "AUGUST", "OCTOBER", "DECEMBER"};

    char *months_with_30_days[4] = {"APRIL", "JUNE", "SPETEMBER", "NOVEMBER"};

    int number_of_months_in_type_of_months[2] = {7, 4};

    int valid_dates[31] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                           21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

    int number_of_districts_in_state[10] = {13, 11, 6, 10, 8, 8, 4, 4};

    printf("\n\t\t\t|| Welcome to Salat Watch Bangladesh 2021 ||\n\n");

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

        printf("\nYou set your Location : (%s, %s)", state, district);
        printf("\nPrayer Times in %s, %s Today - ", state, district);

        curr_date = get_current_date();
        printf("%s", curr_date);

        //show_current_time(); //we can print next and present prayer comparing with current time;

        sprintf(path, "prayer_time_by_district\\%s.txt", district);

        list_of_prayer_time = get_list_of_prayer_time(path);
        prayer_time_of_searched_day = search_prayer_time(list_of_prayer_time, curr_date);

        display_salat_times(prayer_time_of_searched_day);

        printf("\n\nDo You want to see Salat time of Any other day?\n");
        printf("If Yes(Press 1), If No(Press 0): ");
        scanf("%d", &choice);

        while (choice)
        {

            printf("\n\n\t\t\t|| Enter month and date of 2021 you want to serch for || \n");
            printf("\n\nYour option's for month : ");

            for (int i = 0; i < number_of_months; i += 1)
            {
                printf(" %s ", valid_months[i]);
            }

            do
            {
                month = take_month_from_user();
            } while (is_valid_month(valid_months, month, number_of_months) == 0);

            number_of_days = days_in_month(months_with_31_days, months_with_30_days,
                                           number_of_months_in_type_of_months, month);

            printf("\n\nYour option's for date : ");
            for (int i = 0; i < number_of_days; i += 1)
            {
                printf(" %d ", valid_dates[i]);
            }

            do
            {
                date = take_date_from_user();
            } while (is_valid_date(valid_dates, date, number_of_days) == 0);

            months_no = no_of_months(valid_months, month, number_of_months);
            searched_date = get_searched_date(months_no, date);

            list_of_prayer_time = get_list_of_prayer_time(path);
            prayer_time_of_searched_day = search_prayer_time(list_of_prayer_time, searched_date);

            printf("\n\n\nSalat time of %s, %d, 2021", month, date);
            display_salat_times(prayer_time_of_searched_day);

            printf("\n\nDo You want to see Salat time of Any other day?\n");
            printf("If Yes(Press 1), If No(Press 0): ");
            scanf("%d", &choice);
        }

        printf("\n\nSetup again (Press 1) or exit (press 0)   : ");
        scanf("%d", &choice);
    }
    printf("\n\n\t\t\tThanks For All your Patience!");

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

    printf("\n\nDistrict: ");
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

void show_current_time()
{
    int hours, minutes, seconds, days, months, years;

    time_t now;

    time(&now);

    struct tm *local = localtime(&now);

    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    days = local->tm_mday;
    months = local->tm_mon + 1;
    years = local->tm_year + 1900;

    if (hours < 12)
    {
        printf("\nThe time is now : %02d:%02d:%02d am\n", hours, minutes, seconds);
    }
    else
    {
        printf("\nThe time is now : %02d:%02d:%02d pm\n", hours + 12, minutes, seconds);
    }
}

prayer_time *get_list_of_prayer_time(char *path)
{
    FILE *prayer_time_file;

    prayer_time_file = fopen(path, "r");

    char line[200];

    prayer_time *list_of_prayer_time;
    list_of_prayer_time = (prayer_time *)malloc(sizeof(prayer_time) * 400);

    int index = 0;

    while (fgets(line, 1000, prayer_time_file) != NULL)
    {

        sscanf(line, "%s %s %s %s %s %s %s %s %s",
               list_of_prayer_time[index].date,
               list_of_prayer_time[index].day,
               list_of_prayer_time[index].fajr,
               list_of_prayer_time[index].shuruq,
               list_of_prayer_time[index].dhuha,
               list_of_prayer_time[index].dhuhur,
               list_of_prayer_time[index].asr,
               list_of_prayer_time[index].magribh,
               list_of_prayer_time[index].isha);

        index += 1;
    }

    fclose(prayer_time_file);
    return list_of_prayer_time;
}

char *get_current_date()
{
    char *current_day;
    current_day = (char *)malloc(sizeof(char) * 50);

    int hours, minutes, seconds, days, months, years;

    time_t now;

    time(&now);

    struct tm *local = localtime(&now);

    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;

    days = local->tm_mday;
    months = local->tm_mon + 1;
    years = local->tm_year + 1900;

    sprintf(current_day, "%02d/%02d/%d", days, months, years);
    return current_day;
}

char *get_searched_date(int month, int date)
{
    char *searched_day;
    searched_day = (char *)malloc(sizeof(char) * 50);

    sprintf(searched_day, "%02d/%02d/%d", date, month, year);
    return searched_day;
}

prayer_time search_prayer_time(prayer_time *list_of_prayer_time, char *a_date)
{
    int i;

    for (i = 0; i < DAYS_IN_2021; i += 1)
    {
        if (strcmp(list_of_prayer_time[i].date, a_date) == 0)
        {
            return list_of_prayer_time[i];
        }
    }
}

void display_salat_times(prayer_time prayer_time_of_searched_day)
{
    printf("\n\n\tDate        %s", prayer_time_of_searched_day.date);
    printf("\n\tDay          %s", prayer_time_of_searched_day.day);
    printf("\n\tFajr         %s", prayer_time_of_searched_day.fajr);
    printf("\n\tshuruq       %s", prayer_time_of_searched_day.shuruq);
    printf("\n\tDhuha        %s", prayer_time_of_searched_day.dhuha);
    printf("\n\tDhuhur       %s", prayer_time_of_searched_day.dhuhur);
    printf("\n\tAsr          %s", prayer_time_of_searched_day.asr);
    printf("\n\tMagribh      %s", prayer_time_of_searched_day.magribh);
    printf("\n\tIsha         %s", prayer_time_of_searched_day.isha);
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

int days_in_month(char *months_with_31_days[], char *months_with_30_days[],
                  int *number_of_months_with_31_and_30_days, char *month)
{
    int i, j;

    i = 0;
    for (j = 0; j < number_of_months_with_31_and_30_days[i]; j += 1)
    {
        if (strcmp(months_with_31_days[j], month) == 0)
            return 31;
    }
    i += 1;
    for (j = 0; j < number_of_months_with_31_and_30_days[i]; j += 1)
    {
        if (strcmp(months_with_30_days[j], month) == 0)
            return 30;
    }
    return 28;
}

int no_of_months(char *valid_months[], char *month, int number_of_months)
{
    for (int i = 0; i < number_of_states; i += 1)
    {
        if (strcmp(valid_months[i], month) == 0)
        {
            return i + 1;
        }
    }
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