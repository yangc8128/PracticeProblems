import math

def findNth_Prime(n):
    primeList = [];
    i = 2;
    while(len(primeList) != n):
        if(isPrime(i)):
            primeList.append(i);
        i += 1;
    return primeList.pop(); 
 
def isPrime(number):
    i = 2;
    while(i != number):
        if (number%i == 0):
            return False
        i+=1;
    return True;
 
""" number = 29;
if(isPrime(number)):
    print number; """
 
#print isPrime(2);   
print findNth_Prime(100);