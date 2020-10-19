from cs50 import get_float

while True:
    # Get the value from the user
    dollars = get_float("Changed owed: ")
    if dollars >= 0:
        break
    
    
# Round the dollars to cents
cents = round(dollars * 100)
coins = 0

# While cents more than or equal to 25 subtract 25 and increment the coins by 1
while cents >= 25:
    cents -= 25
    coins += 1
    
# While cents more than or equal to 10 subtract 10 and increment the coins by 1
while cents >= 10:
    cents -= 10
    coins += 1
    
# While cents more than or equal to 5 subtract 5 and increment the coins by 1
while cents >= 5:
    cents -= 5
    coins += 1
    
# While cents more than or equal to 1 subtract 1 and increment the coins by 1
while cents >= 1:
    cents -= 1
    coins += 1
    

# Print the number of coins
print(coins)