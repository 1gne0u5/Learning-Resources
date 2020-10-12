#initialization
array = []
turn = 0

#taking user input
size = int (input ())
array = list (map  (int, input ().split ()))

#iterating through the array
for i in range (1, size):

    #checking if previous element is greater than the current
    if (array [i] < array [i - 1]):
        turn += array [i - 1] - array [i]
        array [i] = array [i - 1]

print (turn)
