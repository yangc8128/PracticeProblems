# In this cass maxLimit = 4.e+6
def findN(maxLimit):
    phi = (1 + 5**(.5))/2
    psi = 1 - phi
    n = 0
    F_n = 2
    while F_n <= maxLimit:
        n += 3
        F_n = round((phi**n - psi**n)/5**(.5))
    return n-3

def sumFib(n):
    phi = (1 + 5**(.5))/2
    psi = 1 - phi
    return round((phi**(n + 2) - psi**(n+2))/5**(.5)) - 1

n = findN(4000000)
print sumFib(n)/2
# 4613732


# Find n s.t. Fib(n) < 4.e+6
#
# If 3|n
#   return sumFib(n)/2
#
# else (3|n not)
#   if 3|(n-1)
#       return sumFib(n-1)/2
#   else (3|n-2)
#       return sumFib(n-2)/2
