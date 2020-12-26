import pandas as pd
import numpy as np
import pickle

def main():
  raw_data = pd.read_excel("./test.xlsx", usecols="B:K") # the test data file named 'test.xlsx' is in the same directory as 'load_model'

  with open("./trained_model.pkl", 'rb') as file:
    trained_model = pickle.load(file) # the saved model file named 'trained_model.pkl' is in the same directory as 'load_model'

  obj_to_num = dict()

  obj_to_num['ISLAND'] = 0
  obj_to_num['NEAR OCEAN'] = 1
  obj_to_num['NEAR BAY'] = 1
  obj_to_num['<1H OCEAN'] = 2
  obj_to_num['INLAND'] = 3

  numerical_data = raw_data.replace(obj_to_num)
  numerical_data.dropna(inplace=True)

  target = numerical_data['target']
  feature = numerical_data.drop('target', axis='columns')

  feature['households'] = np.log(feature['households'])
  feature['total_bedrooms'] = np.log(feature['total_bedrooms'])
  feature['total_rooms'] = np.log(feature['total_rooms'])
  feature['population'] = np.log(feature['population'])

  pred = trained_model.predict(feature)

  RMSE = np.sqrt(np.sum((target-pred)**2)/len(pred))

  print("RMSE:", RMSE)

main()