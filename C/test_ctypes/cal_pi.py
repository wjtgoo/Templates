import ctypes
import numpy as np
import time
# import math
terms = 10000000
## call C
# Load the shared library into Python
lib = ctypes.CDLL('./libcal_pi.so')  # Use './matrix_mul.dll' for Windows

lib.calculate_pi.argtypes = [ctypes.c_int]
lib.calculate_pi.restype = ctypes.c_double

start = time.perf_counter()
result = lib.calculate_pi(terms)
end = time.perf_counter()

print(f"Call C in Python: \n out: {result:.15f}, time used: {end-start:.4e}s\n")


## naive python
def calculate_pi(terms):
    pi = 0.0

    for i in range(terms):
        pi += pow(-1, i) / (2.0 * i + 1.0)
    return pi*4

start = time.perf_counter()
result = calculate_pi(terms)
end = time.perf_counter()
print(f"Call naive Python: \n out: {result:.15f}, time used: {end-start:.4e}s\n")