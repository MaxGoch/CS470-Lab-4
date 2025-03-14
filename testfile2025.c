#include "Max_Gochenour_libFS.h"
#include <ctype.h>  // For tolower()

// Function to display the menu
void displayMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Create a file\n");
    printf("2. Open a file\n");
    printf("3. Write to a file\n");
    printf("4. Read from a file\n");
    printf("5. Close a file\n");
    printf("6. Delete a file\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to wait for user input to continue
void waitForUser() {
    printf("\nPress Enter to continue...");
    getchar();  // Wait for Enter key
    getchar();  // Clear the newline character from the buffer
}

int main() {
    char filename[MAX_FILENAME];
    char introduction[] = "Hello, my name is Max Gochenour.\n\n"
                          "I am a computer science student passionate about Machine learning.\n"
                          "This project involves creating a file system library in C.\n"
                          "I hope you find my implementation useful!";
    int file_index = -1;  // Track the currently open file
    int choice;
    char buffer[MAX_FILE_SIZE];

    while (1) {
        displayMenu();
        scanf("%d", &choice);  // Get user choice
        getchar();  // Clear the newline character from the buffer

        switch (choice) {
            case 1:  // Create a file
                printf("Enter the filename to create: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = '\0';  // Remove newline
                if (fileCreate(filename) != 0) {
                    printf("Error creating file.\n");
                }
                waitForUser();
                break;

            case 2:  // Open a file
                printf("Enter the filename to open: ");
                fgets(filename, MAX_FILENAME, stdin);
                filename[strcspn(filename, "\n")] = '\0';  // Remove newline
                file_index = fileOpen(filename);
                if (file_index == -1) {
                    printf("Error opening file.\n");
                }
                waitForUser();
                break;

            case 3:  // Write to a file
                if (file_index == -1) {
                    printf("Error: No file is open. Please open a file first.\n");
                } else {
                    printf("Writing introduction to file '%s'...\n", filename);
                    if (fileWrite(file_index, introduction) != 0) {
                        printf("Error writing to file.\n");
                    }
                }
                waitForUser();
                break;

            case 4:  // Read from a file 
                if(file_index == -1){
                    printf("Error: No file is open. Please open a file first. \n");
                } else {
                    if (fileRead(file_index, buffer, MAX_FILE_SIZE) != 0){
                        printf("Error reading file %s", filename);
                    } 
                }
                waitForUser();
                break;

            case 5: //close file
                if(file_index == -1){
                    printf("Error: No file is open. Please open a file first. \n");
                }
                file_index = fileClose(file_index);
                waitForUser();
                break;

            case 6: //delete a file
                char file_name[MAX_FILENAME];
                printf("Enter the filename to delete: ");
                fgets(file_name, MAX_FILENAME, stdin);
                file_name[strcspn(file_name, "\n")] = '\0';  // Remove newline
                if (fileDelete(file_name) != 0) {
                    printf("Error deleting file.\n");
                }
                waitForUser();
                break;

            case 7:  // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                waitForUser();
                break;
        }
    }

    return 0;
}