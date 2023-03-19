from keras.models import Sequential
from keras.layers import Dense
from keras.utils.np_utils import to_categorical
import numpy
# fix random seed for reproducibility
numpy.random.seed(0)

#load dataset
dataset = numpy.loadtxt("dati.txt", delimiter = " ")

#split into input(x) and output(y)
X = dataset[:,0:7] # prende le colonne da 0 a 9
Y = dataset[:,7]   # prende la colonna 10

Y_train = to_categorical(Y)

# create model
model = Sequential()
model.add(Dense(50, input_dim=7, init='uniform', activation='relu'))
model.add(Dense(100, init='uniform', activation ='relu'))
model.add(Dense(25, init='uniform', activation ='relu'))
model.add(Dense(5, init='uniform', activation='softmax'))

# Compile model
model.compile(loss='categorical_crossentropy', optimizer='Adam', metrics=['accuracy'])


# Fit the model
model.fit(X, Y_train, epochs=50, batch_size=32, verbose = 2, shuffle = True)

#calculate predictions
predictions = model.predict(X)

print(predictions)
# evaluate the model
scores = model.evaluate(X, Y, verbose = 2)
print("\n%s: %.2f%%" % (model.metrics_names[1], scores[1]*100))
