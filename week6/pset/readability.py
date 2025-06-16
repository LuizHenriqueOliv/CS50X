from cs50 import get_string

text = get_string("Text: ")

letters = 0
spaces = 0
sentences = 0

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    elif text[i].isspace():
        spaces += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1

words = spaces + 1

L = (letters / float(words)) * 100
S = (sentences / float(words)) * 100

grade = (int) (0.0588 * L - 0.296 * S - 15.8 + 0.5)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
