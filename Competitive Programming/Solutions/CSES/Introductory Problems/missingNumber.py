#initialization
numbers = []
not_found = 1

#takes user input
n = int (input ())

#map is an inbuilt fucntion to take multiple inputs
numbers = list (map (int, input ().split ()))

#.sort is an innbuilt function which sorts the list
numbers.sort()

#condition for all elements except last
for i in range (0,len(numbers)):
    if (numbers [i] != i + 1):
        print(i + 1)
        not_found = 0
        break

#if the the element is not found in the list then the missing number is the last number
if (not_found == 1) :
    print(n) 
