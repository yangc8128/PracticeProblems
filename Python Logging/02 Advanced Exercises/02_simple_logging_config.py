import logging
from logging.config import fileConfig

# "logging.conf" not only has to exist but also has to be filled
fileConfig("logging.conf")

# create logger
logger = logging.getLogger('simpleExample')

# DEFAULTS handler/formatter

# 'application' code
logger.debug('debug message')
logger.info('info message')
logger.warn('warn message')
logger.error('error message')
logger.critical('critical message')

# shutdowns all loggers and their components
logging.shutdown()