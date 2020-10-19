from sys import argv, exit
import csv


#The number of times any particular STR repeats
def STR_repeat_count(dna_string, STR):
    
    answer = [0] * len(dna_string)
    
    for i in range(len(dna_string) - len(STR), -1, -1):
        if dna_string[i: i + len(STR)] == STR:
            if i + len(STR) > len(dna_string) - 1:
                answer[i] = 1
            else:
                answer[i] = 1 + answer[i + len(STR)]
                
    return max(answer)

def print_the_match(csv_reader, result):
    for line in csv_reader:
        person = line[0]
        value

def main():
    csv_location = argv[1]
    
    with open(csv_location) as csv_file:
        csv_reader = csv.reader(csv_file)
        # for line in csv_reader:
        #     print(line)
        
        text_location = argv[2]
        with open(text_location) as text_file:
            dna_string = text_location.read()
            result = [STR_repeat_count(dna_string, sequence) for sequence in sequences]
            
    print_the_match(csv_reader, result)