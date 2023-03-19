from keras.models import Sequential
from keras.layers import Dense
from keras.utils.np_utils import to_categorical
import numpy
# fix random seed for reproducibility
numpy.random.seed(0)

#load dataset
dataset = numpy.loadtxt("dati.txt", delimiter = ",")

#split into input(x) and output(y)
X = dataset[:,0] # prende la clonna 0
Y = dataset[:,1]   # prende la colonna 1

Y_train = to_categorical(Y)

# create model
model = Sequential()
model.add(Dense(400, input_dim=1, activation="relu", kernel_initializer="uniform"))
model.add(Dense(800, activation="relu", kernel_initializer="uniform"))
model.add(Dense(1600, activation="relu", kernel_initializer="uniform"))
model.add(Dense(800, activation="relu", kernel_initializer="uniform"))
model.add(Dense(400, activation="relu", kernel_initializer="uniform"))
model.add(Dense(2, activation="softmax", kernel_initializer="uniform"))

# Compile model
model.compile(loss='categorical_crossentropy', optimizer='Adam', metrics=['accuracy'])


# Fit the model
model.fit(X, Y_train, epochs=50, batch_size=32, verbose = 2, shuffle = True)

#calculate predictions
predictions = model.predict(X)

print(predictions)
# evaluate the model
scores = model.evaluate(X, Y_train, verbose = 2)
print("\n%s: %.2f%%" % (model.metrics_names[1], scores[1]*100))
