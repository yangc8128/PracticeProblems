import logging
logging.basicConfig(format='%(levelname)s:%(message)s', level=logging.DEBUG)
logging.debug('This message should appear on the console')
logging.info('So should this')
logging.warning('And this, too')

# Notice that the standard output like:
# DEBUG:root: ****
# INFO:root: ****
# WARNING:root: ****

# Is not so this time. As you can when running the
# root is missing from the message since the default
# format of the message has been alterted in configuration