# Task Manager in C

A simple command-line task manager written in C that allows you to add, list, delete, and complete tasks. Tasks are automatically saved to a local file so they persist between executions.

---

## Features

- Add new tasks
- List all tasks
- Delete tasks by ID
- Mark tasks as completed
- Persistent storage using a text file (`tasks.txt`)
- Simple terminal interface

---

## Technologies Used

- Language: C
- Standard Libraries:
  - `stdio.h`
  - `stdlib.h`
  - `string.h`

---

## File Structure

```text
.
├── main.c
├── tasks.txt
└── README.md
```

---

## How It Works

Each task contains:

- An ID
- A description
- A completion status

Tasks are stored in memory using a struct:

```c
typedef struct {
    int id;
    char description[MAX_DESC_LENGTH];
    int completed;
} Task;
```

All tasks are saved in `tasks.txt` when the program exits and loaded automatically when the program starts.

---

## Compilation

Use GCC to compile:

```bash
gcc main.c -o task_manager
```

---

## Running the Program

Linux/macOS:

```bash
./task_manager
```

Windows:

```bash
task_manager.exe
```

---

## Menu Options

```text
1. Add Task
2. List Tasks
3. Delete Task
4. Mark Task as Completed
5. Exit
```

---

## Example

```text
-------------
Task Manager
-------------

1. Add Task
2. List Tasks
3. Delete Task
4. Mark Task as Completed
5. Exit

Enter your choice: 1

Enter task description: Finish README

-----------
Task added!
-----------
```

---

## Data Persistence

Tasks are stored in:

```text
tasks.txt
```

Format:

```text
ID COMPLETED DESCRIPTION
```

Example:

```text
1 0 Buy groceries
2 1 Finish homework
```

Where:

- `0` = Not Completed
- `1` = Completed

---

## Limitations

- Maximum of 100 tasks
- Maximum task description length: 100 characters
- No task editing functionality yet
- File format is plain text

---

## Possible Improvements

- Edit existing tasks
- Add task priorities
- Add due dates
- Search/filter tasks
- Colored terminal output
- Better file validation and error handling

---

## License

This project is open-source and free to use for learning purposes.
