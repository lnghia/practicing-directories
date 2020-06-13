import numpy as np
from matplotlib import pyplot as plt
from sklearn import datasets
from sklearn.cluster import KMeans

digits=datasets.load_digits()
#print(digits)

# print(digits.data)
# print(digits.target)

# plt.gray()
# plt.matshow(digits.images[100])
# plt.show()

# print(digits.target[100])


model=KMeans(n_clusters=10, random_state=42)
model.fit(digits.data)

new_samples=np.array([
[0.00,0.00,0.00,0.00,0.00,0.00,0.53,2.74,0.00,0.00,0.00,0.68,3.73,5.94,4.64,7.62,0.00,1.82,4.95,7.32,7.55,5.56,4.10,7.62,2.50,7.62,7.62,6.70,3.20,1.98,4.18,7.62,1.90,6.63,7.62,7.62,7.62,7.62,7.62,7.31,0.00,0.00,0.08,0.76,0.76,1.52,5.78,6.70,0.00,0.00,0.00,0.00,0.00,0.00,6.16,5.40,0.00,0.00,0.00,0.00,0.00,0.00,6.78,4.72],
[0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,2.36,1.90,6.63,1.37,0.00,0.00,0.45,5.55,7.62,5.55,7.62,2.20,0.00,0.83,6.24,7.47,3.26,3.42,7.62,0.75,0.00,6.23,7.62,6.09,3.81,5.78,7.47,0.15,0.00,4.79,6.10,6.70,6.86,7.47,7.62,1.67,0.00,0.00,0.00,0.00,0.00,6.09,5.48,0.00,0.00,0.00,0.00,0.00,0.00,6.55,5.10,0.00],
[0.00,0.00,0.00,0.00,0.08,0.46,0.53,0.00,0.00,0.00,0.00,0.07,5.02,7.16,7.47,2.58,0.00,0.00,0.00,4.02,7.62,4.48,7.62,3.04,0.00,0.00,2.12,7.54,4.78,1.21,7.62,2.66,0.00,0.83,7.00,7.00,1.90,3.04,7.62,2.51,0.00,2.28,7.62,7.62,7.62,7.62,7.62,7.62,0.00,0.00,0.76,1.52,1.52,5.02,7.39,2.29,0.00,0.00,0.00,0.00,0.00,5.02,6.24,0.00],
[0.00,0.00,0.00,0.00,1.51,1.21,0.53,0.00,0.00,0.00,0.07,3.35,7.54,7.46,7.47,0.45,0.00,1.06,5.48,7.62,5.18,4.86,7.31,0.15,3.04,7.39,7.24,3.04,0.07,7.01,5.25,0.00,7.39,7.54,4.49,3.81,4.11,7.62,4.33,0.00,5.86,6.86,6.86,7.09,7.62,7.62,7.47,0.38,0.00,0.00,0.00,0.00,4.79,7.08,0.53,0.00,0.00,0.00,0.00,0.00,5.33,6.09,0.00,0.00]
])

new_labels=model.predict(new_samples)

for i in range(len(new_labels)):
  if new_labels[i] == 0:
    print(0, end='')
  elif new_labels[i] == 1:
    print(9, end='')
  elif new_labels[i] == 2:
    print(2, end='')
  elif new_labels[i] == 3:
    print(1, end='')
  elif new_labels[i] == 4:
    print(6, end='')
  elif new_labels[i] == 5:
    print(8, end='')
  elif new_labels[i] == 6:
    print(4, end='')
  elif new_labels[i] == 7:
    print(5, end='')
  elif new_labels[i] == 8:
    print(7, end='')
  elif new_labels[i] == 9:
    print(3, end='')

fig1=plt.figure(1, figsize=(8, 3))
fig1.suptitle('cluster center images', fontsize=14, fontweight='bold')

for i in range(10):
  ax=fig1.add_subplot(2, 5, 1+i)
  ax.imshow(model.cluster_centers_[i].reshape((8, 8)), cmap=plt.cm.binary)

fig1.show()


# Figure size (width, height)

fig = plt.figure(2, figsize=(6, 6))

# Adjust the subplots 

fig.subplots_adjust(left=0, right=1, bottom=0, top=1, hspace=0.05, wspace=0.05)

# For each of the 64 images

for i in range(64):

    # Initialize the subplots: add a subplot in the grid of 8 by 8, at the i+1-th position

    ax = fig.add_subplot(8, 8, i+1, xticks=[], yticks=[])

    # Display an image at the i-th position

    ax.imshow(digits.images[i], cmap=plt.cm.binary, interpolation='nearest')

    # Label the image with the target value

    ax.text(0, 7, str(digits.target[i]))

fig.show()

input()