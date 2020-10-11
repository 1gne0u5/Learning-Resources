#initialization
repetitions = 1
maxRepetitions = 1

#takes user input
sequence = str (input ())

#iterates through the string
for i in range (len (sequence) - 1):
    #checks if current character is equal to the next character
    if (sequence [i] == sequence [i + 1]):
        repetitions += 1
    else:
        repetitions = 1

#if repetition of any character is greater than previous characters change maxRepetitions
    if maxRepetitions < repetitions:
        maxRepetitions = repetitions

print(maxRepetitions)
