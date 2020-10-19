import cs50

# Add string name to get the name of the user
s = cs50.get_string("What's your name?\n")

# Prints the output Hello and the name of the user
print("hello, {}".format(s))