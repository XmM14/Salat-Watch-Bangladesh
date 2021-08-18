typedef struct prayer_time
{
    char date[20], day[10], fajr[10], shuruq[10], dhuha[10], dhuhur[10], asr[10], magribh[10], isha[10];
} prayer_time;

char *take_state_from_user();
int is_valid_state(char *state, char *valid_states[], int number_of_state);

char *take_district_from_user();
int is_valid_district(char *district, char *valid_districts[], int number_of_districts);

prayer_time *get_list_of_prayer_time(char *path);

char *get_current_date();
char *get_current_time();
char *get_searched_date(int month, int date);

prayer_time search_prayer_time(prayer_time *list_of_prayer_time, char *a_date);

void display_salat_times_for_a_date(prayer_time prayer_time_of_a_day);
void display_current_and_present_salat(prayer_time prayer_time_of_current_day, char *current_time);

char *take_month_from_user();
int is_valid_month(char *valid_months[], char *month, int number_of_months);

int take_date_from_user();
int is_valid_date(int *valid_dates, int date, int number_of_date);

int days_in_month(char *months_with_31_days[], char *months_with_30_days[], int *number_of_months_in_type_of_months,
                  char *month);

int no_of_months(char *valid_months[], char *month, int number_of_months);

int index_of(char *valid_states[], char *sate, int number_of_states);

char *strupr(char *s);
