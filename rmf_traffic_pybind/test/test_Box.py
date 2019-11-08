# content of test_sample.py
import py_rmf_traffic as py

box = py.Box(3,3)
# assert(box.get_x_length() == 2) # Fails
assert(box.get_x_length() == 3)