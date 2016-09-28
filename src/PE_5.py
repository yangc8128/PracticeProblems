import math

def LCM_Range(upperBound):
    retVal = [1,2,3];
    # Prime Factors of [4,upperBound + 1]
    for i in range(4, upperBound + 1):
        temp = primeFactors(i);
        # Compare counts in retVal and in temp of J
        for j in temp:
            countJ = temp.count(j);
            countJ_LCM = retVal.count(j)
            if (countJ > countJ_LCM):
                retVal.extend([j] * (countJ - countJ_LCM) );
    retVal.sort();
    return retVal;
    
def primeFactors(number):
    listofprimes = [1];
    i = 2;
    while(number != 1):
        while (number%i == 0):
            listofprimes.append(i);
            number /= i;
        i += 1;
    return listofprimes;

print LCM_Range(10);
print LCM_Range(20);