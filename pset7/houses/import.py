from sys import argv, exit
from cs50 import SQL
import csv

# separate the name into first and middle and last


def separate_name(name):
    name_parts = name.split()
    return name_parts if len(name_parts) >= 3 else [name_parts[0], None, name_parts[1]]
    

# Check the number of the arguments
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

# the students database
db = SQL("sqlite:///students.db")

csv_location = argv[1]
with open(csv_location) as csv_file:
    csv_reader = csv.DictReader(csv_file)
    for line in csv_reader:
        names = separate_name(line["name"])
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   names[0], names[1], names[2], line["house"], line["birth"])