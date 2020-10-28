n = int ( input ())
#user input
    
for i in range (1, n + 1):
    #total number of ways for placing two knights
    totalWays = (i * i)*((i * i) - 1)
    
    
    #Outer Boundary#
    #places night can attack when placed at corner
    outerCorner = 4 * 2
    
    #places knight can attack when placed in place adjacent to corner
    adjCorner = 8 *3
    
    #places knight can attack when placed at any place except corner and adjacent along the outer boundary
    outerBoundary = (i - 4) * 4 * 4
    
    
    #Inner Boundary#
    
    #palces knight can attack when placed at inner boundary corner
    innerCorner = 4 * 4
    
    #places knight can attack when placed in square adjacent to inner boundary corner
    innerAdjcorner = (i - 4) * 6 * 4

    #places knight can attack when placed anywhere except above conditions 
    other = (i - 4) * (i - 4) * 8
    
    #as each place is considered twice for each knight divide by two
    possiblePlaces = int((totalWays - adjCorner - outerCorner - outerBoundary - innerCorner - innerAdjcorner - other) / 2)
    
    print (possiblePlaces)
