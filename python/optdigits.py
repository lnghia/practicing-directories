import pandas as pd
import matplotlib.pyplot as plt 
import numpy as np

from sklearn.cluster import KMeans
from sklearn import datasets
from mpl_toolkits.mplot3d import Axes3D

# load dataset

_digits=datasets.load_digits()

samples=_digits.data
target=_digits.target

# k=10

clusters=list(range(1, 11))
inertias=[]

for k in clusters:
    model=KMeans(n_clusters=k)
    model.fit(samples)
    inertias.append(model.inertia_)

plt.plot(clusters, inertias, '-o')

plt.xlabel('Number of Cluster (k)')
plt.ylabel('Inertia')

plt.show()


# model=KMeans(n_clusters=k)

# model.fit(samples)

# labels=model.predict(samples)

# df=pd.DataFrame({'labels': labels, 'classes':target})

# ct=pd.crosstab(df['labels'], df['classes'])

# print(ct)

# plt.scatter(samples[:,0], samples[:,1], c=labels, alpha=0.5)

# plt.show()



# digits=pd.read_csv("http://archive.ics.uci.edu/ml/machine-learning-databases/optdigits/optdigits.tra", header=None)
# _digits=pd.read_csv("E:\\AI_ML\\datasets\\optdigits-orig.tra\\optdigits-orig.tra", header=None)

# digits=digits.to_numpy()
# _digits=_digits.to_numpy()

# print(_digits)

# print(len(digits[0]))



# model=KMeans(n_clusters=k)

# model.fit(digits)

# labels=model.predict(digits)

# fignum=1

# fig = plt.figure(fignum, figsize=(7, 6))

# ax = Axes3D(fig, rect=[0, 0, .95, 1], elev=48, azim=134)

# ax.scatter(samples[:,0], samples[:,1], samples[:,2], c=labels, alpha=0.5)

# plt.show()

# plt.gray() 
# plt.matshow(_digits.images[0]) 
# plt.show() 