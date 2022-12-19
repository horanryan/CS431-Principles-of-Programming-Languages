"""
Ryan Horan
December 9,2022
Python 3.10
Accepts up to 30 values from the keyboard for each of two variables (use arrays, vectors or
lists as appropriate), then compute and print the following for each of the two sequences:
a. the number of entries
b. the minimum value
c. the maximum value
d. the range
e. the arithmetic mean
f. the variance
g. the standard deviation  
    
"""

import statistics

list = []
#keep entering numbers until 30 inputs is entered
for i in range(30):
    n = int(input("enter an integer or enter -1 to stop entering integers: "))
    if n == -1:
        break    
    list.append(n)
#calculate and print data
print("\nNumber of entries:\t",len(list),
          "\nMin value:\t",min(list),
          "\nMax value:\t",max(list),
          "\nRange:\t",max(list)-min(list),
          "\nArithmetic Mean:\t",statistics.mean(list),
          "\nVariance:\t",statistics.pvariance(list),
          "\nStd. Deviation:\t",statistics.pstdev(list)
          )