import logging

# The code supports if you want to designated the logging status from cmd
# --log=INFO
# which utilizes this call to associate the changes to the logging instance
#   getattr(logging, loglevel.upper())
    # assuming loglevel is bound to the string value obtained from the
    # command line argument. Convert to upper case to allow the user to
    # specify --log=DEBUG or --log=debug
#    numeric_level = getattr(logging, loglevel.upper(), None)
#    if not isinstance(numeric_level, int):
#        raise ValueError('Invalid log level: %s' % loglevel)
#    logging.basicConfig(level=numeric_level, ...)


logging.basicConfig(filename='example.log',level=logging.DEBUG) # w/ append
# logging.basicConfig(filename='example.log', filemode='w', level=logging.DEBUG) # w/o append
logging.debug('This message should go to the log file')
logging.info('So should this')
logging.warning('And this, too')