while True:
    s = input("Enter a value: ")
    reverse = s[::-1]

    if s == reverse:
        print("Palindrome")
    else:
        print("Not a Palindrome")

    a = input("Continue to use the program? (y/n): ")

    if a.lower() == "n":
        break
    elif a.lower() != "y":
        print("Invalid option. Please enter 'y' to continue or 'n' to exit.")
