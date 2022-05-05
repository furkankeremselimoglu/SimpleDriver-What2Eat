#include <stdio.h>

int main() {
    int people = 0;
    int choosenFoods[5];
    int threshold = 5;
    int peopleNo = 1;

    for(int i = 0; i < 5; i++) {
        choosenFoods[i] = 0;
    }

    printf("How many people are you?\n");
    scanf("%d", &people);

    if(people == 1) {
        printf("\nYou are alone, you can eat whatever you want.");
        return 0;
    }

    for (int i = 0; i < people; i++) {
        int points = 5;
        int choice;

        printf("%s %d%s","Person", peopleNo, "'s Preferences:\n");
        printf("What do you want to eat?\n");
        printf("1: Kebab\n2: Burger\n3: Pasta\n4: Lahmacun\n5: Salad\n\n");

        for(int j = 0; j < 5; j++) {
            printf("Write your choice:");
            scanf("%d", &choice);
            if (choice == 1) { // Kebab
                choosenFoods[0] += points;
            } else if (choice == 2) { // Burger
                choosenFoods[1] += points;
            } else if (choice == 3) { // Pasta
                choosenFoods[2] += points;
            } else if (choice == 4) { // Lahmacun
                choosenFoods[3] += points;
            } else if (choice == 5) { // Salad
                choosenFoods[4] += points;
            } else {
                j--;
                points++;
            }
            points--;
        }
        peopleNo++;
    }

    int passedThresholdNo = 0;
    for(int i = 0; i < 5; i++) {
        if(choosenFoods[i] > threshold) {
            passedThresholdNo++;
        }
    }
    int shortFoodList[passedThresholdNo];
    int second_index = 0;
    for(int i = 0; i < 5; i++) {
        if(choosenFoods[i] > threshold) {
            shortFoodList[second_index] = i;
            second_index++;
        }
    }

    if(passedThresholdNo == 0) {
        printf("%s", "\nYou are eating at home/dorm today!");
    } else if(passedThresholdNo == 1) {
        if(shortFoodList[0] == 0) {
            printf("\nYou are eating Kebab.");
        } else if(shortFoodList[0] == 1) {
            printf("\nYou are eating Burger.");
        } else if(shortFoodList[0] == 2) {
            printf("\nYou are eating Pasta.");
        } else if(shortFoodList[0] == 3) {
            printf("\nYou are eating Lahmacun.");
        } else if(shortFoodList[0] == 4) {
            printf("\nYou are eating Salad.");
        }
    } else {
        peopleNo = 1;
        for (int i = 0; i < people; i++) {
            int points = passedThresholdNo;
            int choice;

            printf("%s %d%s","\nPerson", peopleNo, "'s Preferences:\n");
            printf("What do you want to eat, choose from the short list?\n");

            int foodNo = 1;
            for(int j = 0; j < passedThresholdNo; j++) {
                if(shortFoodList[j] == 0) {
                    printf("%d%s", foodNo, ": Kebab\n");
                } else if(shortFoodList[j] == 1) {
                    printf("%d%s", foodNo, ": Burger\n");
                } else if(shortFoodList[j] == 2) {
                    printf("%d%s", foodNo, ": Pasta\n");
                } else if(shortFoodList[j] == 3) {
                    printf("%d%s", foodNo, ": Lahmacun\n");
                } else if(shortFoodList[j] == 4) {
                    printf("%d%s", foodNo, ": Salad\n");
                }
                foodNo++;
            }

            points = 10;
            for(int j = 0; j < passedThresholdNo; j++) {
                printf("Write your choice:");
                scanf("%d", &choice);
                if (choice == 1) { // Kebab
                    choosenFoods[0] += points;
                } else if (choice == 2) { // Burger
                    choosenFoods[1] += points;
                } else if (choice == 3) { // Pasta
                    choosenFoods[2] += points;
                } else if (choice == 4) { // Lahmacun
                    choosenFoods[3] += points;
                } else if (choice == 5) { // Salad
                    choosenFoods[4] += points;
                } else {
                    j--;
                    points = points + 2;
                }
                points = points - 2;
            }
            peopleNo++;
        }
        int max = -1;
        int max_index = -1;
        for(int i = 0; i < 5; i++) {
            if(choosenFoods[i] > max) {
                max = choosenFoods[i];
                max_index = i;
            }
        }

        if(max_index == 0) {
            printf("\nYou are eating Kebab.");
        } else if(max_index == 1) {
            printf("\nYou are eating Burger.");
        } else if(max_index == 2) {
            printf("\nYou are eating Pasta.");
        } else if(max_index == 3) {
            printf("\nYou are eating Lahmacun.");
        } else if(max_index == 4) {
            printf("\nYou are eating Salad.");
        }
    }

    return 0;
}

