import pandas as pd
import matplotlib.pyplot as plt 
import numpy as np

from sklearn.cluster import KMeans

# load dataset

digits=pd.read_csv("http://archive.ics.uci.edu/ml/machine-learning-databases/optdigits/optdigits.tra", header=None)

print(type(digits))