from sys import argv, exit
import csv


# The number of times any particular STR repeats
def STR_repeat_count(dna_string, STR):
    answer = [0] * len(dna_string)
    for i in range(len(dna_string) - len(STR), -1, -1):
        if dna_string[i: i + len(STR)] == STR:
            if i + len(STR) > len(dna_string) - 1:
                answer[i] = 1
            else:
                answer[i] = 1 + answer[i + len(STR)]

    return max(answer)


# Print the match after comparing
def print_the_match(csv_reader, result):
    for line in csv_reader:
        person = line[0]
        values = [int(value) for value in line[1:]]
        if values == result:
            print(person)
            return
    print("No match")


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
    # Open the csv
    csv_location = argv[1]
    with open(csv_location) as csv_file:
        csv_reader = csv.reader(csv_file)
        # Skip the first line in the csv file
        sequences = next(csv_reader)[1:]
        # Open the text file
        text_location = argv[2]
        with open(text_location) as text_file:
            dna_string = text_file.read()
            result = [STR_repeat_count(dna_string, sequence) for sequence in sequences]
        print_the_match(csv_reader, result)


# to call the main function
if __name__ == "__main__":
    main()