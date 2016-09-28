import math

def findLPFactor(number):
    listofprimes = [1];
    i = 2;
    while(number != 1):
        while (number%i == 0):
            listofprimes.append(i);
            number /= i;
        i+=1;
    print listofprimes;
    return listofprimes.pop();

#print findLPFactor(13195);
print findLPFactor(600851475143);
#print findLPFactor(10);