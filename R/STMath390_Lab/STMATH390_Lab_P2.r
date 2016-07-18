# Requires z to have a number
# pnorm(z,mean=0,sd=1) > pnorm(1,mean=0,sd=1)

# Loading in some data
data("airquality")

# Confusing to use
# attach(airquality) #detach(airquality)

# Instead use this
with(airquality, {
  #names(airquality)
  # Normalizing the data, using T-distribution
  zwind = (Wind - mean(Wind))/sd(Wind)
  } )

hist(zwind,prob=T) # Error Prob is not a graphica parameter

# Number/Percent of observations within a single standard deviation
print( sum(zwind > -1 & zwind < 1) )
print( sum(zwind > -1 & zwind < 1)/length(zwind) )
# Number/Percent of observations within a 1.5 standard deviation
print( sum(zwind > -1.5 & zwind < 1.5)/length(zwind) )

# Questions