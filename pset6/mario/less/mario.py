import cs50

# If the height is >= 1 or n <= 8 means between 1 and 8 included, break the loop
while True:
    # Get the height from the user
    n = cs50.get_int("Height: ")
    if n >= 1 and n <= 8:
        break

# Iterate from 1 through the height int
# Iteration i, print i hashes and then a newline    
for i in range(n):
    # Iteration j, print j hashes and i spaces and then a newline
    for j in range(n):
        if i + j >= n - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()

