import logging
#logging.basicConfig(format='%(asctime)s %(message)s')
#logging.warning('is when this event was logged.')

logging.basicConfig(format='%(asctime)s %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p')
logging.warning('is when this event was logged.')

# There cannot be two basicConfig calls done, the second will be ignored