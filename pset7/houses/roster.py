from sys import argv, exit
from cs50 import SQL

# Check the number of the arguments
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

# the students database
db = SQL("sqlite:///students.db")

house = argv[1]

lines = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)

for line in lines:
    first, middle, last, birth = line["first"], line["middle"], line["last"], line["birth"]
    # prints the out puts
    print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")