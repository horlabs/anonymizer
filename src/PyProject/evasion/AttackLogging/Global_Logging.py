import multiprocessing
import logging
from logging.handlers import QueueListener
import os


##
## Here, we define our multiprocessing logger, != Attack_Logging.py, this logger logs the attack progress over
## all attack instances, not each individual evasion attack
## With sequential, we get a logger, but cannot use Python's multiprocessing.
## With logger_parallel_init, we get a multiprocessing-safe logger.
##


# Logging is a little bit more compilicated with Python's multiprocessing
# Our logging if multiprocessing is used is based on
#   https://stackoverflow.com/questions/641420/how-should-i-log-while-using-multiprocessing-in-python
# Thanks a lot!

# In blackbox_attack, e.g., we use the global parallel_logger, and in each attack instance, we have an own
# logger that logs more information to the source-target-author directory.

def logger_parallel_init(logfilepath):
    if not os.path.exists(logfilepath):
        os.makedirs(logfilepath)

    q = multiprocessing.Queue()
    # this is the handler for all log records
    # handler = logging.StreamHandler()
    handler = logging.FileHandler(os.path.join(logfilepath, 'info_all.log'), mode="w+")
    handler.setFormatter(logging.Formatter("%(levelname)s: %(asctime)s - %(process)s - %(message)s"))

    # ql gets records from the queue and sends them to the handler
    ql = QueueListener(q, handler)
    ql.start()

    logger = logging.getLogger("parallel_logger")
    logger.setLevel(logging.DEBUG)
    # add the handler to the logger so records from this process are handled
    logger.addHandler(handler)

    return ql, q


def logger_sequential_init(logfilepath, logfile_name: str = 'info_all.log'):
    if not os.path.exists(logfilepath):
        os.makedirs(logfilepath)

    handler = logging.FileHandler(os.path.join(logfilepath, logfile_name), mode="w+")
    handler.setFormatter(logging.Formatter("%(levelname)s: %(asctime)s - %(process)s - %(message)s"))

    logger = logging.getLogger("parallel_logger")
    logger.setLevel(logging.DEBUG)
    # add the handler to the logger so records from this process are handled
    logger.addHandler(handler)

    return logger


def close_logger_sequential(logger):
    handlers = logger.handlers[:]
    for handler in handlers:
        handler.close()
        logger.removeHandler(handler)

