# Lab 10 — Lab Work Report

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Smeliantsev Artem  
**Date:** 30.11.2025

---

## Task Description

The objective of this lab was to implement a **Hotel Room Management** system using binary file operations in C for **Variant 12**. The system required defining a struct for a room and implementing functions for reading, searching, deleting, and appending records to a binary file.

### System Components

| Component | File Operation | C Function |
| :--- | :--- | :--- |
| **Data Structure** | Binary Record | `Room` struct |
| **Initialization** | Write initial data | `fwrite` (mode `"wb"`) |
| **Display** | Read all records | `fread` (mode `"rb"`) |
| **Search** | Search by room type | `fread` + `strcmp` |
| **Deletion** | Delete by room number | Load all, shift array, rewrite file |
| **Addition** | Append new record | `fwrite` (mode `"ab"`) |

## Report

The goal of this lab was to gain practical experience with binary file input/output in C, specifically managing a database of structured records.

In this lab, I completed the following tasks:

1.  **Defined** the `Room` struct to store room details (number, type, price, occupancy).
2.  **Implemented** functions to write initial data and append new records using the binary modes `"wb"` and `"ab"`.
3.  **Implemented** the `read_all_rooms` function to load all data from the file into a memory array for processing.
4.  **Implemented** the `search_by_type` function to filter and display records based on a specific room type.
5.  **Implemented** the `delete_room_by_number` function using the simple strategy of loading all records, removing the target record from the array, and rewriting the entire modified array back to the file.

### Runtime Output

The program was tested with a sequence of operations to demonstrate all required functions.

```text
Initial 5 rooms written to rooms.dat.

All Rooms (5 records)
 Number  Type        Price/Night      Status     
 101     single      50.00            Available  
 102     double      80.00            Occupied   
 201     suite       150.00           Available  
 202     double      80.00            Available  
 301     single      55.00            Occupied   

All Rooms (5 records)
 Number  Type        Price/Night      Status     
 101     single      50.00            Available  
 102     double      80.00            Occupied   
 201     suite       150.00           Available  
 202     double      80.00            Available  
 301     single      55.00            Occupied   

Search Results for Type: double
 Number  Type        Price/Night      Status     
 102     double      80.00            Occupied   
 202     double      80.00            Available  
New room 401 appended to rooms.dat.

All Rooms (6 records)
 Number  Type        Price/Night      Status     
 101     single      50.00            Available  
 102     double      80.00            Occupied   
 201     suite       150.00           Available  
 202     double      80.00            Available  
 301     single      55.00            Occupied   
 401     single      60.00            Available  
Room 102 successfully deleted. New room count: 5

All Rooms (5 records)
 Number  Type        Price/Night      Status     
 101     single      50.00            Available  
 201     suite       150.00           Available  
 202     double      80.00            Available  
 301     single      55.00            Occupied   
 401     single      60.00            Available
 ```
