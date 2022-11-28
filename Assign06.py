import statistics

array = []

for i in range(30):
    n = int(input("enter an integer or enter -1 to exit: "))
    if n == -1:
        break    
    array.append(n)
    print("\nNumber of entries:\t",len(array),
          "\nMin value:\t",min(array),
          "\nMax value:\t",max(array),
          "\nRange:\t",min(array)," - ",max(array),
          "\nArithmetic Mean:\t",statistics.mean(array),
          "\nVariance:\t",statistics.variance(array),
          "\nStd. Deviation:\t",statistics.stdev(array)
          )