import multiprocessing
from abc import ABC, abstractmethod


class SharedCounter(ABC):
    """
    Shared Counter Class to save global attack progress, value is number of evasion instances,
    success is number of succesfull evasions, nosuccess and error are ...
    """

    def __init__(self):
        pass

    @abstractmethod
    def decrement(self):
        pass

    @abstractmethod
    def value(self):
        pass

    @abstractmethod
    def increment_success(self):
        pass

    @abstractmethod
    def increment_nosuccess(self):
        pass

    @abstractmethod
    def increment_misclass(self):
        pass

    @abstractmethod
    def increment_error(self):
        pass

    @abstractmethod
    def get_stats(self):
        pass


class SharedCounterParallel(SharedCounter):
    """
    Shared Counter that works with multiprocessing and where values can be saved/retrieved safely.
    """

    def __init__(self, initval=0):
        super(SharedCounterParallel, self).__init__()
        self.val = multiprocessing.Value('i', initval)
        self.success = multiprocessing.Value('i', 0)
        self.nosuccess = multiprocessing.Value('i', 0)
        self.error = multiprocessing.Value('i', 0)
        self.misclass = multiprocessing.Value("i", 0)
        self.lock = multiprocessing.Lock()

    def decrement(self):
        with self.lock:
            self.val.value -= 1

    def value(self):
        with self.lock:
            return self.val.value

    def increment_success(self):
        with self.lock:
            self.success.value += 1

    def increment_nosuccess(self):
        with self.lock:
            self.nosuccess.value += 1

    def increment_misclass(self):
        with self.lock:
            self.misclass.value += 1

    def increment_error(self):
        with self.lock:
            self.error.value += 1

    def get_stats(self):
        with self.lock:
            return self.success.value, self.nosuccess.value, self.misclass.value, self.error.value


class SharedCounterSingle(SharedCounter):
    """
    # no need to use locks if we do not have any multiprocessing
    """
    def __init__(self, initval=0):
        super(SharedCounterSingle, self).__init__()
        self.val = initval
        self.success = 0
        self.nosuccess = 0
        self.error = 0
        self.misclass = 0

    def decrement(self):
        self.val -= 1

    def value(self):
        return self.val

    def increment_success(self):
        self.success += 1

    def increment_nosuccess(self):
        self.nosuccess += 1

    def increment_misclass(self):
        self.misclass += 1

    def increment_error(self):
        self.error += 1

    def get_stats(self):
        return self.success, self.nosuccess, self.misclass, self.error