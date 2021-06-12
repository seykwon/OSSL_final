#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h> 
#include <string.h>
#include <math.h>

void show_menu();
int get_command();
void set_list(char* filename);
void add_menu(char* filename);
void show_list(char* filename);
void choose_menu(char* filename);

typedef struct strs {
    char str[20];
}strs;

int main(void) {

    int cmd;

    while (1) {
        cmd = get_command();
        if (cmd == 1) set_list("menu_list.txt");
        else if (cmd == 2) add_menu("menu_list.txt");
        else if (cmd == 3) show_list("menu_list.txt");
        else if (cmd == 4) choose_menu("menu_list.txt");
        else if (cmd == 5) {
            printf("Good Bye!\n");
            break;
        }
        else {
            printf("\n\n Invalid command, try again, please.\n\n");
        }
    }
    return 0;
}

void show_menu() {
    printf("\n- - MENU - -\n");
    printf("1. Set the menu list\n");
    printf("2. Add more menu into the list\n");
    printf("3. Show the list\n");
    printf("4. Pick the random menu\n");
    printf("5. Quit\n");
    printf("\nSelect a Command: ");
}

int get_command() {
    int tcmd;

    show_menu();
    scanf("%d", &tcmd);

    return tcmd;
}

void set_list(char* filename) {
    FILE* fp = fopen(filename, "w");
    //char menu[20];

    printf("\n(Type \"done\" if you added all)\n");
    printf("Enter the menus:\n");
    
    while(1){
        char menu[20];
        scanf("%s", menu);
        
        if (strcmp(menu,"done") == 0)
            break;

        fprintf(fp, "%s\n", menu);
    }
    printf("\nMenu list is made!\n");
    fclose(fp);
}

void add_menu(char* filename) {
    FILE* fp = fopen(filename, "a");
    char menu[20];

    printf("\nWhat menu?\n");
    scanf("%s", menu);

    fprintf(fp, "%s\n", menu);
    printf("\nNew menu added!\n");

    fclose(fp);
}

void show_list(char* filename) {
    FILE* fp = fopen(filename, "r");

    char list[20];

    int count_number = 0;

    printf("\n Number     Menu\n");

    while (fscanf(fp, "%s\n", list) != EOF){
        count_number++;
        printf("   %d       %s\n", count_number, list);
    }

    fclose(fp);
}

void choose_menu(char* filename) {
    FILE* fp = fopen(filename, "r");

    char menu[20];
    int i = 0;

    strs list[20];

    while (fscanf(fp, "%s\n", menu) != EOF)
    {
        if (menu != EOF) {
            strcpy(list[i].str, menu);
        }
        else
            break;
        i++;
    }

    strcpy(menu, list[rand() % i].str);

    printf("\nThe random menu: %s\n", menu);
}
