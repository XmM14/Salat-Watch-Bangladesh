#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "library.h"

const int number_of_states = 8;
const int number_of_months = 12;

int main()
{
    system("COLOR 6");

    int choice = 1;
    int number_of_days;
    int months_no;
    int index_of_state;

    char *state;
    char *district;
    char *month;
    int date;
    char *current_date;
    char *current_time;
    char *searched_date;
    char full_date[10];

    prayer_time *list_of_prayer_time;
    prayer_time prayer_time_of_searched_day;
    prayer_time prayer_time_of_current_day;

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
        printf("\n\nPrayer Times in %s, %s, Today - ", state, district);

        current_date = get_current_date();
        current_time = get_current_time();

        printf("%s", current_date);
        sprintf(path, "prayer_time_by_district\\%s.txt", district);

        list_of_prayer_time = get_list_of_prayer_time(path);
        prayer_time_of_current_day = search_prayer_time(list_of_prayer_time, current_date);

        display_salat_times_for_a_date(prayer_time_of_current_day);  // For current day

        printf("\n\nThe time is Now  %s", current_time);
        display_current_and_present_salat(prayer_time_of_current_day, current_time); 

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
            display_salat_times_for_a_date(prayer_time_of_searched_day); // For searched day

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

