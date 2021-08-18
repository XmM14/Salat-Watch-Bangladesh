#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

const int year = 2021;
const int DAYS_IN_2021 = 365;
const int Number_of_states = 8;

typedef struct prayer_time
{
    char date[20], day[10], fajr[10], shuruq[10], dhuha[10], dhuhur[10], asr[10], magribh[10], isha[10];
} prayer_time;

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

char *get_current_time()
{
    char *current_time;
    current_time = (char *)malloc(sizeof(char) * 50);

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

    sprintf(current_time, "%02d:%02d", hours, minutes);
    return current_time;
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
    for (int i = 0; i < Number_of_states; i += 1)
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