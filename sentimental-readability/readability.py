## calculate the approximate grade level to comprehend given text based on Coleman-Liau Index

L = 0
W = 1
S = 0

while True:
    try:
        text = str(input("Text: "))
    except ValueError:
        continue
    break


for letter in text:
    if letter.isalpha():
            L += 1

for word in text:
    if word == ' ' or word == '\n':
        W += 1

for sentence in text:
    if sentence == '.' or sentence == '?' or sentence == '!':
        S += 1

index = round(5.88 * (L/W) - 29.6 * (S/W) - 15.8)


if index >= 16:
    print("Grade 16+")

elif index < 1:
    print("Before Grade 1")

else:
    print("Grade", index)
