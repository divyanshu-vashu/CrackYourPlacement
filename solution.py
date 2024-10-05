import re
import sys

# Function to extract doctor details
def extract_doctor_details(filename):
    with open(filename, 'r') as file:
        text = file.read()

    # Regular expression pattern to capture Doctor's Name, ID, and email
    pattern = r'(?:Doctor|doctor)\s+(\w+)\s+(\d+)\s+([\w\.-]+@[\w\.-]+)'

    # Find all matches in the text
    matches = re.findall(pattern, text)

    # Print the extracted details in the required format
    for match in matches:
        name, id_number, email = match
        print(f"Doctor Name: {name}, ID Number: {id_number}, Email Id: {email}")

# Check if the script is being run from the command line
if __name__ == "__main__":
    # Ensure a filename is passed as a command line argument
    if len(sys.argv) < 2:
        print("Please provide the input file name.")
    else:
        input_file = sys.argv[1]
        extract_doctor_details(input_file)