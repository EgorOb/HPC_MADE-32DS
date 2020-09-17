import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates
from sklearn.linear_model import LinearRegression
import datetime

DATA_FOR_PREDICT = np.array([[11, 2020], [6, 2021], [11, 2021]])

DATA_1 = pd.read_csv('1.csv')
DATA_500 = pd.read_csv('500.csv')

BASE_DATA = datetime.datetime(DATA_1['Year'][0], DATA_1['Month'][0], 1)

def get_days_in_data(year, month, day = 1):
    delta = datetime.datetime(year, month, day) - BASE_DATA
    return delta.days

X = list(map(lambda m, y: datetime.datetime(y, m, 1),
                          DATA_1['Month'],
                          DATA_1['Year']))
X_DATA = matplotlib.dates.date2num(X)

Y_1 = np.array(DATA_1['Flops'])/1e12
Y_500 = np.array(DATA_500['Flops'])/1e12

X_TRAIN = np.array(list(map(get_days_in_data, 
                            DATA_1['Year'], 
                            DATA_1['Month']))).reshape((-1, 1))
Y_1_TRAIN = np.log10(Y_1)
Y_500_TRAIN = np.log10(Y_500)

model_1 = LinearRegression()
model_1.fit(X_TRAIN, Y_1_TRAIN)
print('R2 для модели 1 = ', round(model_1.score(X_TRAIN, Y_1_TRAIN), 3))
Y_1_PREDICT = np.power(10, model_1.predict(X_TRAIN))

model_500 = LinearRegression()
model_500.fit(X_TRAIN, Y_500_TRAIN)
print('R2 для модели 500 = ', round(model_500.score(X_TRAIN, Y_500_TRAIN), 3))
Y_500_PREDICT = np.power(10, model_500.predict(X_TRAIN))

fig, ax = plt.subplots(figsize=(10, 5))

ax.set_title('Вычислительная мощность суперкомпьютера')
ax.set_xlabel('Год')
ax.set_ylabel('Мощность, ТФлопс')
ax.set_yscale('log')
ax.xaxis.set_major_formatter(matplotlib.dates.DateFormatter("%Y"))
ax.grid()

ax.scatter(X_DATA, Y_1, color='red', label='1 место')
ax.plot(X_DATA, Y_1_PREDICT, color='red', label='1 место - регрессия')
ax.scatter(X_DATA, Y_500, color='blue', label='500 место')
ax.plot(X_DATA, Y_500_PREDICT, color='blue', label='500 место - регрессия')
ax.legend(loc='upper left')

PRED_1 = np.power(10, model_1.predict(np.array(list(map(get_days_in_data, 
                                                        DATA_FOR_PREDICT[:,1], 
                                                        DATA_FOR_PREDICT[:,0]))).reshape((-1, 1))))


PRED_500 = np.power(10, model_500.predict(np.array(list(map(get_days_in_data, 
                                                            DATA_FOR_PREDICT[:,1], 
                                                            DATA_FOR_PREDICT[:,0]))).reshape((-1, 1))))

fig.savefig('Мощность.jpg')

print('Прогноз')
for i, data in enumerate(DATA_FOR_PREDICT):
    print('На ', data[0], ' месяц ', data[1], ' года')
    print('1-ое место, мощность ', round(PRED_1[i], 3), ' ТФлопс')
    print('500-ое место, мощность ', round(PRED_500[i], 3), ' ТФлопс')




