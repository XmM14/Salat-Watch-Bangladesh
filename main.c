#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* take_state_from_user();
int is_valid_state(char* state);

char* take_district_from_user();
int is_valid_district(char* district);

int main() {
    char *state;
    char *district;

    printf("\n\t\t\tWelcome to Salat Watch Bangladesh\n\n");

    do {
        state = take_state_from_user();
    } while (is_valid_state(state) == 0);

    do {
        district = take_district_from_user();
    } while (is_valid_district(district) == 0);
    
    printf("\nYour Location is (%s, %s)", state, district);
    return 0;
}

char* take_state_from_user() {
    char* state;
    state = (char*)malloc(sizeof(20));

    printf("\nState: ");
    scanf("%s", state);
    strupr(state);
    return state;
}

int is_valid_state(char* state) {
    char valid_states[8][20] = {
                                "DHAKA", "CHATTAGRAM", " BARISAL", "KHULNA", "RAJSHAHI", "RANGPUR", "SYLHET",
                                "MYMENSINGH"
                               };
    int i;

    for (i = 0; i < 8; i += 1) {
        if (strcmp(state, valid_states[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

char* take_district_from_user() {
    
    
    char* district;
    district = (char*)malloc(sizeof(20));

    printf("\nDistrict: ");
    scanf("%s", district);
    strupr(district);
    return district;
}

int is_valid_district(char* district) {
    char valid_districts[64][20] = {
                                      "BARGUNA", "BARISAL", "BHOLA", "JHALOKATI", "PATUAKHALI", "PIROJPUR", "BANDARBAN","BRAHAMANBARIA", 
                                      "CHANDPUR", "CHITTAGONG", "COMILLA", "COX'S BAZAR", "FENI", "KHAGRACHHARI", "LAKSHMIPUR", "NOAKHALI", 
                                      "RANGAMATI", "DHAKA", "FARIDPUR", "GAZIPUR", "GOPALGANJ", "JAMALPUR","KISHOREGANJ", "MADARIPUR", 
                                      "MANIKGANJ", "MUNSHIGANJ", "MAYMENSINGH", "NARAYANGANJ", "NARSINGDI", "NETRAKONA", "RAJBARI", 
                                      "SHARIATPUR", "SHERPUR", "TANGAIL", "BAGERHAT", "CHUDANGA", "JESSORE", "JHENAIDAH", "KHULNA", 
                                      "KUSHTIA", "MAGURA", "MEHERPUR", "NARAIL", "SATKHIRA", "BOGRA", "JOYPURHAT", "NAOGAON", 
                                      "NATORE", "NAWABGANJ", "PABNA", "RAJSHAHI", "SIRAJGANJ", "DINAJPUR", "GAIBANDHA","KURIGRAM", 
                                      "LALMONIRHAT", "NILPHAMARI", "PANCHAGARH", "RANGPUR", "THAKURGAON", "HABIGANJ", "MAULAVIBAZAR",
                                      "SUNAMGANJ", "SYLHET"
                                    };
    int i;

    for (i = 0; i < 64; i += 1) {
        if (strcmp(district, valid_districts[i]) == 0) {
            return 1;
        }
    }
    return 0;
}



