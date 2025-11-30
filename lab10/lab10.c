#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 50
#define MAX_TYPE_LENGTH 20
#define FILENAME "rooms.dat"

typedef struct
{
    int number;
    char type[MAX_TYPE_LENGTH];
    double price_per_night;
    bool is_occupied;
} Room;

void print_room(const Room *room);
void write_initial_data(void);
void read_all_rooms(Room rooms[], int *count);
void search_by_type(const char *type);
void delete_room_by_number(int room_number);
void append_new_room(const Room *new_room);

void print_room(const Room *room)
{
    printf(" %-6d  %-10s  %-15.2f  %-10s \n",
           room->number, room->type, room->price_per_night,
           room->is_occupied ? "Occupied" : "Available");
}

void write_initial_data(void)
{
    Room initial_rooms[] = {
        {101, "single", 50.00, false},
        {102, "double", 80.00, true},
        {201, "suite", 150.00, false},
        {202, "double", 80.00, false},
        {301, "single", 55.00, true}};
    int count = sizeof(initial_rooms) / sizeof(Room);

    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    fwrite(initial_rooms, sizeof(Room), count, file);
    fclose(file);
    printf("Initial %d rooms written to %s.\n", count, FILENAME);
}

void read_all_rooms(Room rooms[], int *count)
{
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        *count = 0;
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    *count = file_size / sizeof(Room);
    if (*count > MAX_ROOMS)
        *count = MAX_ROOMS;

    fread(rooms, sizeof(Room), *count, file);
    fclose(file);

    printf("\nAll Rooms (%d records)\n", *count);
    printf(" %-6s  %-10s  %-15s  %-10s \n", "Number", "Type", "Price/Night", "Status");
    for (int i = 0; i < *count; i++)
    {
        print_room(&rooms[i]);
    }
}

void search_by_type(const char *type)
{
    Room rooms[MAX_ROOMS];
    int count;
    read_all_rooms(rooms, &count);

    printf("\nSearch Results for Type: %s\n", type);
    printf(" %-6s  %-10s  %-15s  %-10s \n", "Number", "Type", "Price/Night", "Status");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(rooms[i].type, type) == 0)
        {
            print_room(&rooms[i]);
            found++;
        }
    }
    if (found == 0)
    {
        printf("No rooms of type '%s' found.\n", type);
    }
}

void delete_room_by_number(int room_number)
{
    Room rooms[MAX_ROOMS];
    int count;
    read_all_rooms(rooms, &count);

    int delete_index = -1;
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].number == room_number)
        {
            delete_index = i;
            break;
        }
    }

    if (delete_index == -1)
    {
        printf("Error: Room %d not found for deletion.\n", room_number);
        return;
    }

    for (int i = delete_index; i < count - 1; i++)
    {
        rooms[i] = rooms[i + 1];
    }
    count--;

    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
        perror("Error opening file for rewriting");
        return;
    }
    fwrite(rooms, sizeof(Room), count, file);
    fclose(file);
    printf("Room %d successfully deleted. New room count: %d\n", room_number, count);
}

void append_new_room(const Room *new_room)
{
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL)
    {
        perror("Error opening file for appending");
        return;
    }

    fwrite(new_room, sizeof(Room), 1, file);
    fclose(file);
    printf("New room %d appended to %s.\n", new_room->number, FILENAME);
}

int main()
{
    write_initial_data();

    Room all_rooms[MAX_ROOMS];
    int room_count;
    read_all_rooms(all_rooms, &room_count);

    search_by_type("double");

    Room new_room = {401, "single", 60.00, false};
    append_new_room(&new_room);

    delete_room_by_number(102);

    read_all_rooms(all_rooms, &room_count);

    return 0;
}
