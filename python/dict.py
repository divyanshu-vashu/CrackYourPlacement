def count_letters(string):
    letter_count = {} 
    for char in string:
        if char.isalpha():
            if char in letter_count:
                letter_count[char] += 1  # Increment count if already in dictionary
            else:
                letter_count[char] = 1  # Initialize count if not in dictionary
    
    return letter_count

# Test the function
input_string = "vellore college"
result = count_letters(input_string)

# Print the letter counts
for letter, count in result.items():
    print(f"'{letter}': {count}")
