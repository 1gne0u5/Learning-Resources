n = int (input ())
print (n , end = " ")

#repeats the steps untill we get 1

while (n != 1) :
    if (n % 2 == 0) :
                
        #checks if n is even
                    
        n = int (n / 2)
        print (n , end = " ")

        #end = " " for printing elements in same line
    else :
        n = int (3 * n + 1)
        print (n, end = " ")
