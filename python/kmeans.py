#import codecademylib3_seaborn
import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets
from copy import deepcopy

iris = datasets.load_iris()

samples = iris.data

x = samples[:,0]
y = samples[:,1]

sepal_length_width = np.array(list(zip(x, y)))

# Step 1: Place K random centroids

k = 3

centroids_x = np.random.uniform(min(x), max(x), size=k)
centroids_y = np.random.uniform(min(y), max(y), size=k)

centroids = np.array(list(zip(centroids_x, centroids_y)))

def distance(a, b):
  one = (a[0] - b[0]) ** 2
  two = (a[1] - b[1]) ** 2
  distance = (one + two) ** 0.5
  return distance

# To store the value of centroids when it updates
centroids_old = np.zeros(centroids.shape)

# Cluster labeles (either 0, 1, or 2)
labels = np.zeros(len(samples))

distances = np.zeros(3)

# Initialize error:

error = np.zeros(k)
for i in range (k):
  error[i]=distance(centroids[i], centroids_old[i])

# Repeat Steps 2 and 3 until convergence:
while error.all() != 0:
  # Step 2: Assign samples to nearest centroid

  for i in range(len(samples)):
    distances[0] = distance(sepal_length_width[i], centroids[0])
    distances[1] = distance(sepal_length_width[i], centroids[1])
    distances[2] = distance(sepal_length_width[i], centroids[2])
    cluster = np.argmin(distances)
    labels[i] = cluster

  # Step 3: Update centroids

  centroids_old = deepcopy(centroids)

  for i in range(3):
    points = [sepal_length_width[j] for j in range(len(sepal_length_width)) if labels[j] == i]
    centroids[i] = np.mean(points, axis=0)

  for i in range (k):
    error[i]=distance(centroids[i], centroids_old[i])


# draw the result 
colors = ['r', 'g', 'b']

for i in range (k):
  points = np.array([sepal_length_width[j] for j in range(len(sepal_length_width)) if labels[j] == i])
  # points = []
  # for j in range(len(sepal_length_width)):
  #   if labels[j] == i:
  #     points.append(sepal_length_width[j])

  # points=np.array(points)
  plt.scatter(points[:, 0], points[:, 1], c=colors[i], alpha=0.5)

# print(centroids)
plt.scatter(centroids[:, 0], centroids[:, 1], marker='D', s=150)

plt.xlabel('sepal length (cm)')
plt.ylabel('sepal width (cm)')

plt.show()
  
  
  
  