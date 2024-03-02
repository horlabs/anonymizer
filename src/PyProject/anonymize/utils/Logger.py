import sys


class Logger:
    test_errors = []
    test_success = []
    test_warning = []

    def __init__(self, output_lock, success_lock, error_lock, process_lock):
        self.status_msg = None
        self.total_tests = 0
        self.output_lock = output_lock
        self.success_lock = success_lock
        self.error_lock = error_lock
        self.process_lock = process_lock

    def get_success(self):
        return self.test_success

    def get_warnings(self):
        return self.test_warning

    def get_errors(self):
        return self.test_errors

    def status(self, msg, error=False):
        if not error:
            self.output_lock.acquire()
        self.status_msg = msg
        sys.stdout.write(f"\r{msg}")
        sys.stdout.flush()
        if not error:
            self.output_lock.release()

    def end_status(self, msg):
        self.output_lock.acquire()
        sys.stdout.write(f"\r{msg}\n")
        self.status_msg = None
        self.output_lock.release()

    def info(self, msg):
        self.output_lock.acquire()
        if self.status_msg is not None:
            sys.stdout.write("\r")
            sys.stdout.write("\033[K")
            sys.stdout.flush()
        print(f"\r{msg}")
        if self.status_msg is not None:
            self.status(self.status_msg, error=True)
        self.output_lock.release()

    def error(self, msg):
        self.output_lock.acquire()
        if self.status_msg is not None:
            sys.stdout.write("\r")
            sys.stdout.flush()
        print(f"\r{msg}", file=sys.stderr)
        if self.status_msg is not None:
            self.status(self.status_msg, error=True)
        self.output_lock.release()

    def add_error(self, file):
        self.error_lock.acquire()
        self.test_errors.append(file)
        self.error_lock.release()

    def add_warning(self, file):
        self.error_lock.acquire()
        self.test_warning.append(file)
        self.error_lock.release()

    def add_success(self, file):
        self.success_lock.acquire()
        self.test_success.append(file)
        self.success_lock.release()

    def set_total(self, count):
        self.total_tests = count

    def get_total(self):
        return self.total_tests

    def process(self):
        self.process_lock.acquire()
        self.status(f"Test {len(self.test_success + self.test_errors + self.test_warning)} from {self.total_tests} "
                    f"({len(self.test_errors)} errors/{len(self.test_warning)} warnings)")
        self.process_lock.release()

    def get_lock(self):
        return self.output_lock
