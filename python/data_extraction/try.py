import pandas as pd

filename = 'data.txt'
mywidths = [8, 5, 3, 19, 19, 11, 11, 14, 14]
data = pd.read_fwf(filename,widths=mywidths,header=None,skiprows=3)
print(data)
