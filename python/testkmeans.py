import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd

from sklearn import datasets
from sklearn.cluster import KMeans
from copy import deepcopy
from mpl_toolkits.mplot3d import Axes3D


iris = datasets.load_iris()

samples = iris.data

target=iris.target

clusters=list(range(1,9))

inertias=[]

for k in clusters:
    model=KMeans(n_clusters=k)
    model.fit(samples)
    inertias.append(model.inertia_)

plt.plot(clusters, inertias, '-o')

plt.xlabel('Number of Cluster (k)')
plt.ylabel('Inertia')

plt.show()

# model=KMeans(n_clusters=3)

# model.fit(samples)

# labels=model.predict(samples)

# x=samples[:,0]
# y=samples[:,1]
# z=samples[:,2]



# species=np.chararray(target.shape, itemsize=150)

# for i in range(len(samples)):
#     if target[i] == 0:
#         species[i] = 'setosa'
#     elif target[i] == 1:
#         species[i] = 'versicolor'
#     elif target[i] == 2:
#         species[i] = 'virginica'

# df=pd.DataFrame({'labels': labels, 'species': species})

# print(df)

# ct=pd.crosstab(df['labels'], df['species'])

# print(ct)

# fignum=1

# fig = plt.figure(fignum, figsize=(6, 5))

# ax = Axes3D(fig, rect=[0, 0, .95, 1], elev=48, azim=134)

# ax.scatter(x, y, z, c=labels, alpha=0.5)

# ax.set_xlabel("sepal length (cm)")
# ax.set_ylabel("sepal width (cm)")
# ax.set_zlabel("petal length (cm)")

# plt.show()

# plt.scatter(x, y, c=labels, alpha=0.5)

# plt.show()

# x = samples[:,0]
# y = samples[:,1]
# z = samples[:,2]

# sepal_length_width = np.array(list(zip(x, y, z)))

# k=3

# centroids_x=np.random.uniform(min(x), max(x), size=k)
# centroids_y=np.random.uniform(min(y), max(y), size=k)
# centroids_z=np.random.uniform(min(z), max(z), size=k)
# centroids=np.array(list(zip(centroids_x, centroids_y, centroids_z)))

# def distance(a, b):
#     one=(b[0]-a[0])**2
#     two=(b[1]-a[1])**2
#     three=(b[2]-a[2])**2
#     distance=(one+two+three)**0.5
#     return distance

# centroids_old=np.zeros(centroids.shape)

# labels=np.zeros(len(sepal_length_width))

# errors=np.zeros(k)
# for i in range(k):
#     errors[i]=distance(centroids[i], centroids_old[i])

# distances=np.zeros(k)

# while errors.all() != 0:
#     for i in range(len(sepal_length_width)):
#         for j in range(k):
#             distances[j]=distance(sepal_length_width[i], centroids[j])
#         labels[i]=np.argmin(distances)

#     centroids_old=deepcopy(centroids)

#     for i in range(k):
#         points=[sepal_length_width[j] for j in range(len(sepal_length_width)) if labels[j]==i]
#         centroids[i]=np.mean(points, axis=0)

#     for i in range(k):
#         errors[i]=distance(centroids[i], centroids_old[i])

# colors=['r', 'g', 'b']

# fignum = 1

# # Plot the ground truthd

# fig = plt.figure(fignum, figsize=(6, 5))

# ax = Axes3D(fig, rect=[0, 0, .95, 1], elev=48, azim=134)

# for i in range(k):
#     points=np.array([sepal_length_width[j] for j in range(len(sepal_length_width)) if labels[j]==i])
#     ax.scatter(points[:,0], points[:,1], points[:,2], c=colors[i], alpha=0.5)

# ax.scatter(centroids[:,0], centroids[:,1], centroids[:,2], marker='D', s=150)

# ax.set_xlabel("sepal length (cm)")
# ax.set_ylabel("sepal width (cm)")
# ax.set_zlabel("petal length (cm)")

# plt.show()

    
