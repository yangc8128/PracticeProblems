# To clear the console screen quick key (CTRL + L)

# We are going to use the Dataset "faithful" which is a built
# in data set for R and R-Studio

# Loads data into to project
data("faithful")
# View help page for dataset faithful
help(faithful)
# Makes faithful accessable by name 
attach(faithful)
# Gets/Sets names of an Object
names(faithful)

# eruptions is a name from faithful this obtains its length
length(eruptions)
# Histogram for eruptions, 20 IDK?
hist(eruptions,20)

mean(eruptions)
sd(eruptions)

# Loads the values for mean and sd into project
emean=mean(eruptions)
esd=sd(eruptions)

# Number/Percent of observations within a single standard deviation
sum(eruptions > emean-esd & eruptions < emean+esd)
sum(eruptions > emean-esd & eruptions < emean+esd)/length(eruptions)

# The percent of observations within a single standard deviation
# is around 55.15% != 68%. Therefore does NOT satisfy empirical rule.
# i.e. not normally distributed

# Questions
