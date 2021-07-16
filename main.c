#include<stdio.h>
#include<string.h>

void setup_state(char state[]);
void setup_district(char district[]);

int main ()
{
    char state[20];
    char district[20];
    
    printf("\n          Welcome to Salat Watch Bangladesh              \n\n");
    printf("                    Plz Set Up                      \n\n");

    printf("State (Use capital letter) : ");
    scanf("%s", state);
    setup_state(state);
    printf("\n\nDistrict (Use capital letter) : ");
    scanf("%s", district);
    setup_district(district);

    printf("\n\nYour Location is : (%s, %s)", state, district);
    return 0;
}

void setup_state(char state [])
{
    int i;
    
    char location_state[16][20] = { "DHAKA", "Dhaka", "CHATTAGRAM", "Chattagram", " BARISAL", "Barisal",
                               "KHULNA", "Khulna", "RAJSHAHI", "Rajshahi", "RANGPUR", "Rangpur",
                               "SYLHET", "Sylhet", "MYMENSINGH", "Mymensingh"}; 

if(1)
{
    for ( i = 0; i < 16; i += 1 )   
    {
        if(strcmp(state, location_state[i]) == 0)
        break;
    }
        printf("\n\nPlz Enter a valid State (Use capital letter) : ");
        scanf("%s", state);
}
}    

void setup_district(char district[])
{
    int i;
    char location_district[64][20] = {"BARGUNA", "BARISAL", "BHOLA", "JHALOKATI", "PATUAKHALI", "PIROJPUR", "BANDARBAN", 
                              "BRAHAMANBARIA", "CHANDPUR", "CHITTAGONG", "COMILLA", "COX'S BAZAR", "FENI", "KHAGRACHHARI", 
                              "LAKSHMIPUR", "NOAKHALI", "RANGAMATI", "DHAKA", "FARIDPUR", "GAZIPUR", "GOPALGANJ", "JAMALPUR", 
                              "KISHOREGANJ", "MADARIPUR", "MANIKGANJ", "MUNSHIGANJ","MAYMENSINGH", "NARAYANGANJ", "NARSINGDI", 
                              "NETRAKONA", "RAJBARI", "SHARIATPUR", "SHERPUR", "TANGAIL", "BAGERHAT", "CHUDANGA", "JESSORE", 
                              "JHENAIDAH", "KHULNA", "KUSHTIA", "MAGURA", "MEHERPUR", "NARAIL", "SATKHIRA", "BOGRA", "JOYPURHAT", 
                              "NAOGAON", "NATORE", "NAWABGANJ", "PABNA", "RAJSHAHI", "SIRAJGANJ", "DINAJPUR", "GAIBANDHA", 
                              "KURIGRAM", "LALMONIRHAT", "NILPHAMARI","PANCHAGARH", "RANGPUR", "THAKURGAON", "HABIGANJ", 
                              "MAULAVIBAZAR", "SUNAMGANJ", "SYLHET"};
                    
if(1)
{
    for ( i = 0; i < 16; i += 1 )   
    {
        if(strcmp(district, location_district[i]) == 0)
        break;
    }
        printf("\n\nPlz Enter a valid district (Use capital letter) : ");
        scanf("%s", district);
}
}