# Hello World program in Python
    
# Palindrome produced by a product of two 3-digit numbers
# Max number 999 * 999 = 998001
# Possible ranges of each element 100 - 999
# I want a list of 999 - 100

# Oversight will not cover largest palindromes just the first possible with
# larger starting values.
def main():
    # Reverse traversal from 999 to 100
    for x in xrange(99999, 90000, -1):
        for y in xrange(99999, 90000, -1):
            if palindrome(x*y):
                print x
                print y
                print x*y
                return 0
        
# Is palindrome?
def palindrome(blah):
    temp = str(blah)[::-1]
    if int(temp) == blah:
        #print temp
        #print blah
        return True
    return False

main()