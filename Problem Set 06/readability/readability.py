from cs50 import get_string

# Get the value from the user
text = get_string("Text: ").strip()

numberOfWords = 0
numberOfSentences = 0
numberOfLetters = 0

textLength = len(text)


for i in range(textLength):
    # if it's a letter according to the isalpha function so it increments the numberOfLetters accordingly
    if text[i].isalpha():
        numberOfLetters += 1

    # Checking the number of words if there's space after and before the letter or there's no letters and the letter
    if (i != textLength - 1 and text[i] == ' ' and text[i + 1] != ' ') or (i == 0 and text[i] != ' '):
        numberOfWords += 1

    # If there's a . or ! or ? so it increments the numberOfSentences
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        numberOfSentences += 1


# L is the average number of letters per 100 words in the text
L = numberOfLetters / numberOfWords * 100
# S is the average number of sentences per 100 words in the text
S = numberOfSentences / numberOfWords * 100


# The Coleman-Liau index formula
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")