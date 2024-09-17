#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_DESC_LENGTH 100
#define FILENAME "tasks.txt"

typedef struct {
    int id;
    char description[MAX_DESC_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

// Function prototypes
void load_tasks();
void save_tasks();
void add_task();
void list_tasks();
void delete_task();
void complete_task();
int get_new_id();

int main() {
    int choice;
    load_tasks();  // Load tasks from file at the start
    
    while (1) {
        printf("\n-------------\n");
        printf("Task Manager\n");
        printf("-------------\n\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Mark Task as Completed\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                complete_task();
                break;
            case 5:
                save_tasks();  // Save tasks before exiting
                exit(0);
            default:
                printf("\nInvalid option, please try again.\n");
        }
    }

    return 0;
}

void load_tasks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        // If the file doesn't exist, no tasks are loaded
        return;
    }

    while (fscanf(file, "%d %d %[^\n]", &tasks[task_count].id, &tasks[task_count].completed, tasks[task_count].description) != EOF) {
        task_count++;
    }

    fclose(file);
}

void save_tasks() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving tasks.\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        // Save each task in the format: ID CompletedFlag Description
        fprintf(file, "%d %d %s\n", tasks[i].id, tasks[i].completed, tasks[i].description);
    }

    fclose(file);
}

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }

    Task new_task;
    new_task.id = get_new_id();
    printf("\nEnter task description: ");
    fgets(new_task.description, MAX_DESC_LENGTH, stdin);
    new_task.description[strcspn(new_task.description, "\n")] = '\0';  // Remove newline
    new_task.completed = 0;  // Task is not completed by default

    tasks[task_count++] = new_task;
    printf("\n-----------\n");
    printf("Task added!\n");
    printf("-----------\n");
}

void list_tasks() {
    if (task_count == 0) {
        printf("\nNo tasks available.\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s [%s]\n", tasks[i].id, tasks[i].description, tasks[i].completed ? "Completed" : "Not Completed");
    }
}

void delete_task() {
    int id, found = 0;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            found = 1;
            for (int j = i; j < task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            task_count--;
            printf("Task deleted.\n");
            break;
        }
    }

    if (!found) {
        printf("Task not found.\n");
    }
}

void complete_task() {
    int id, found = 0;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &id);

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            printf("Task marked as completed.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Task not found.\n");
    }
}

int get_new_id() {
    int max_id = 0;
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id > max_id) {
            max_id = tasks[i].id;
        }
    }
    return max_id + 1;
}
