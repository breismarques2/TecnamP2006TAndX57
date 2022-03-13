#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Dec  1 21:24:09 2020

@author: Bruno
"""
import pandas as pd
import numpy as np
import pylab as plt
import pickle
import sys
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.neural_network import MLPRegressor
from sklearn.metrics import confusion_matrix
from sklearn.metrics import mean_squared_error
from pandas.plotting import scatter_matrix
from sklearn.model_selection import GridSearchCV


def main():   
    vel_sound_range = [325.0, 345.0] #(m/s)
    rho_range       = [0.85, 1.3]
    alpha_range     = [0.0, 20.0] #º
    mach_range      = [0.0, 0.3] 
    rpm_range       = [0.0, 6000.0]
    cp_range        = [0.0, 0.8]
    ct_range        = [0.0, 0.5]
    flap_range      = [0.0, 30.0] #º



    x_data = pd.read_csv("x_4.csv")
    x_data = x_data[['vel_sound','rho', 'alpha', 'mach', 'rpm', 'cp', 'ct', 'flap']]
    
    ## Drag Data
    
    # Skin Friction Drag Coefficient (Estimated parasite drag) Breakdown
    
    cdo_fuselage_data = pd.read_csv("Fuselage_CDo_4.csv")
    cdo_fuselage_data = cdo_fuselage_data[['Fuselage_CDo']]
    cdo_hs_data = pd.read_csv("Horizontal_Stab_CDo_4.csv")
    cdo_hs_data = cdo_hs_data[['Horizontal_Stab_CDo']]
    cdo_vs_data = pd.read_csv("Vertical_Stab_CDo_4.csv")
    cdo_vs_data = cdo_vs_data[['Vertical_Stab_CDo']]
    cdo_wing_data = pd.read_csv("Main_Wing_CDo_4.csv")
    cdo_wing_data = cdo_wing_data[['Main_Wing_CDo']]
    
    # Integrated Induced Drag Coefficient Breakdown
    
    cdi_fuselage_data = pd.read_csv("Fuselage_CDi_4.csv")
    cdi_fuselage_data = cdi_fuselage_data[['Fuselage_CDi']]
    cdi_hs_data = pd.read_csv("Horizontal_Stab_CDi_4.csv")
    cdi_hs_data = cdi_hs_data[['Horizontal_Stab_CDi']]
    cdi_vs_data = pd.read_csv("Vertical_Stab_CDi_4.csv")
    cdi_vs_data = cdi_vs_data[['Vertical_Stab_CDi']]
    cdi_wing_data = pd.read_csv("Main_Wing_CDi_4.csv")
    cdi_wing_data = cdi_wing_data[['Main_Wing_CDi']]
    
    # Total Aircraft Drag
    
    cdo_total_data = pd.read_csv("CDo_4.csv")
    cdo_total_data = cdo_total_data[['CDo']]
    cdi_total_data = pd.read_csv("CDi_4.csv")
    cdi_total_data = cdi_total_data[['CDi']]
    cd_total_data = pd.read_csv("CDtotal_4.csv")
    cd_total_data = cd_total_data[['CDtotal']]
    
    ## Lift Data
    
    # Lift Breakdown
    
    cl_fuselage_data = pd.read_csv("Fuselage_CL_4.csv")
    cl_fuselage_data = cl_fuselage_data[['Fuselage_CL']]
    cl_hs_data = pd.read_csv("Horizontal_Stab_CL_4.csv")
    cl_hs_data = cl_hs_data[['Horizontal_Stab_CL']]
    cl_vs_data = pd.read_csv("Vertical_Stab_CL_4.csv")
    cl_vs_data = cl_vs_data[['Vertical_Stab_CL']]
    cl_wing_data = pd.read_csv("Main_Wing_CL_4.csv")
    cl_wing_data = cl_wing_data[['Main_Wing_CL']]
    
    # Total Aircraft Lift
    
    cl_total_data = pd.read_csv("CL_4.csv")
    cl_total_data = cl_total_data[['CL']]

    #sc = StandardScaler()
    #x_data = sc.fit_transform(x_data)

    ## Normalize data between 0 and 1

    x_data.values[:,0]=x_data.values[:,0]/vel_sound_range[1]
    x_data.values[:,1]=x_data.values[:,1]/rho_range[1]
    x_data.values[:,2]=x_data.values[:,2]/alpha_range[1]
    #x_data.values[:,3]=x_data.values[:,3]/mach_range[1]
    x_data.values[:,4]=x_data.values[:,4]/rpm_range[1]
    #x_data.values[:,5]=x_data.values[:,5]/cp_range[1]
    #x_data.values[:,6]=x_data.values[:,6]/ct_range[1]
    x_data.values[:,7]=x_data.values[:,7]/flap_range[1]

    #Adding the ouptput to the x_data vector

    #x_data['Fuselage_CDo'] = cdo_fuselage_data
    #x_data['Horizontal_Stab_CDo'] = cdo_hs_data
    #x_data['Vertical_Stab_CDo'] = cdo_vs_data
    #x_data['Main_Wing_CDo'] = cdo_wing_data
    #x_data['Fuselage_CDi'] = cdi_fuselage_data
    x_data['Horizontal_Stab_CDi'] = cdi_hs_data
    x_data['Vertical_Stab_CDi'] = cdi_vs_data
    x_data['Main_Wing_CDi'] = cdi_wing_data
    #x_data['Fuselage_CL'] = cl_fuselage_data
    x_data['Horizontal_Stab_CL'] = cl_hs_data
    x_data['Vertical_Stab_CL'] = cl_vs_data
    x_data['Main_Wing_CL'] = cl_wing_data
    #x_data['CDo'] = cdo_total_data
    x_data['CDi'] = cdi_total_data
    x_data['CDtotal']=cd_total_data
    x_data['CL']=cl_total_data   
    
    #Count number of outliers in x_data array
    
    outliers = pd.DataFrame((x_data['CL'] > 4) | (x_data['CL'] < 0) | (x_data['CDtotal'] > 0.3) | (x_data['CDtotal'] < 0))
    outliers.describe()

    print(outliers[False].value_counts())
    
    #Remove the outliers

    x_data_out = x_data.mask((x_data['CL'] > 4) | (x_data['CL'] < 0) | (x_data['CDtotal'] > 0.3) | (x_data['CDtotal'] < 0)).dropna()    
    
    #Splitting the dataset into training and validation sets

    training_set, validation_set = train_test_split(x_data_out, test_size = 0.2, random_state = 21)

    #classifying the predictors and target variables as X and Y

    X_train = training_set.iloc[:,0:-9].values
    Y_train_cdi_hs = training_set.iloc[:,-9].values
    Y_train_cdi_vs = training_set.iloc[:,-8].values
    Y_train_cdi_wing = training_set.iloc[:,-7].values
    Y_train_cl_hs = training_set.iloc[:,-6].values
    Y_train_cl_vs = training_set.iloc[:,-5].values
    Y_train_cl_wing = training_set.iloc[:,-4].values
    Y_train_cdi_total = training_set.iloc[:,-3].values
    Y_train_cd_total = training_set.iloc[:,-2].values
    Y_train_cl_total = training_set.iloc[:,-1].values

    X_val = validation_set.iloc[:,0:-9].values
    Y_val_cdi_hs = validation_set.iloc[:,-9].values
    Y_val_cdi_vs = validation_set.iloc[:,-8].values
    Y_val_cdi_wing = validation_set.iloc[:,-7].values
    Y_val_cl_hs = validation_set.iloc[:,-6].values
    Y_val_cl_vs = validation_set.iloc[:,-5].values
    Y_val_cl_wing = validation_set.iloc[:,-4].values
    Y_val_cdi_total = validation_set.iloc[:,-3].values
    Y_val_cd_total = validation_set.iloc[:,-2].values
    Y_val_cl_total = validation_set.iloc[:,-1].values

    #Initializing the classifier
    
    regr_cdi_hs = MLPRegressor(activation= 'relu', solver='adam', tol=1e-55, alpha=1e-25, max_iter=30500, random_state=1, beta_1 = 0.99, beta_2 = 0.99, epsilon=1e-20)
    regr_cdi_vs = MLPRegressor(activation= 'relu', solver='lbfgs', tol=1e-170, alpha=1e-140, max_iter=140500, random_state=1)
    regr_cdi_wing = MLPRegressor(activation= 'relu', solver='lbfgs', tol=1e-15, alpha=1e-15, max_iter=18500, random_state=1)
    regr_cl_hs = MLPRegressor(activation= 'relu', solver='lbfgs', tol=1e-10, alpha=1e-10, max_iter=13500, random_state=1)
    regr_cl_vs = MLPRegressor(activation= 'relu', solver='adam', tol=1e-55, alpha=1e-25, max_iter=30500, random_state=1, beta_1 = 0.99, beta_2 = 0.99, epsilon=1e-20)
    regr_cl_wing = MLPRegressor(activation= 'relu', solver='lbfgs', tol=1e-10, alpha=1e-10, max_iter=13500, random_state=1)
    regr_cdi_total = MLPRegressor(activation= 'relu', solver='lbfgs', tol=1e-25, alpha=1e-135, max_iter=20500, random_state=1)
    regr_cd_total = MLPRegressor(activation= 'relu', solver='lbfgs', tol=1e-10, alpha=1e-10, max_iter=13500, random_state=1)
    regr_cl_total = MLPRegressor(activation= 'relu', solver='lbfgs', tol=1e-10, alpha=1e-10, max_iter=8500, random_state=1)
    
    #param_grid = {'activation': ['identity', 'logistic', 'tanh', 'relu'], 
    #              'solver':['lbfgs', 'sgd', 'adam'], 
    #              'tol':[1e-5, 1e-10], 
    #              'alpha':[1e-10], 
    #              'max_iter':[13500], 
    #              'random_state':[1]}
    
    #regr_cd_2 = GridSearchCV(regr_cd, param_grid=param_grid ,cv=10, verbose=True, pre_dispatch='2*n_jobs', return_train_score=True)
    
    

    #Fitting the training data
    
    regr_cdi_hs.fit(X_train, Y_train_cdi_hs)
    regr_cdi_vs.fit(X_train, Y_train_cdi_vs)
    regr_cdi_wing.fit(X_train, Y_train_cdi_wing)
    regr_cl_hs.fit(X_train, Y_train_cl_hs)
    regr_cl_vs.fit(X_train, Y_train_cl_vs)
    regr_cl_wing.fit(X_train, Y_train_cl_wing)
    regr_cdi_total.fit(X_train, Y_train_cdi_total)
    regr_cd_total.fit(X_train, Y_train_cd_total)
    regr_cl_total.fit(X_train, Y_train_cl_total)

    #Predicting for the validation set
    
    # load the model from disk
    #regr_cl2 = pickle.load(open(filenameCL, 'rb'))
    #regr_cd2 = pickle.load(open(filenameCD, 'rb'))
    
    y_pred_cdi_hs = regr_cdi_hs.predict(X_val)
    y_pred_cdi_vs = regr_cdi_vs.predict(X_val)
    y_pred_cdi_wing = regr_cdi_wing.predict(X_val)
    y_pred_cl_hs = regr_cl_hs.predict(X_val)
    y_pred_cl_vs = regr_cl_vs.predict(X_val)
    y_pred_cl_wing = regr_cl_wing.predict(X_val)
    y_pred_cdi_total = regr_cdi_total.predict(X_val)
    y_pred_cd_total = regr_cd_total.predict(X_val)
    y_pred_cl_total = regr_cl_total.predict(X_val)

    #Calculating accuracy of model
    
    #print("Best GridSearch Params")
    #print(regr_cd_2.best_params_)
    
    #print("Best GridSearch Score")
    #print(regr_cd_2.best_score_)
    
    print("VALIDATION SET CDi HS")
    print(Y_val_cdi_hs)
    
    print("PREDICTED CDi HS")
    print(y_pred_cdi_hs)
    
    print("VALIDATION SET CDi VS")
    print(Y_val_cdi_vs)
    
    print("PREDICTED CDi VS")
    print(y_pred_cdi_vs)
    
    print("VALIDATION SET CDi Wing")
    print(Y_val_cdi_wing)
    
    print("PREDICTED CDi Wing")
    print(y_pred_cdi_wing)
    
    print("VALIDATION SET CL HS")
    print(Y_val_cl_hs)
    
    print("PREDICTED CL HS")
    print(y_pred_cl_hs)
    
    print("VALIDATION SET CL VS")
    print(Y_val_cl_vs)
    
    print("PREDICTED CL VS")
    print(y_pred_cl_vs)
    
    print("VALIDATION SET CL Wing")
    print(Y_val_cl_wing)
    
    print("PREDICTED CL Wing")
    print(y_pred_cl_wing)
    
    print("VALIDATION SET CDi")
    print(Y_val_cdi_total)
    
    print("PREDICTED CDi")
    print(y_pred_cdi_total)
    
    print("VALIDATION SET CD")
    print(Y_val_cd_total)
    
    print("PREDICTED CD")
    print(y_pred_cd_total)
    
    print("VALIDATION SET CL")
    print(Y_val_cl_total)
    
    print("PREDICTED CL")
    print(y_pred_cl_total)
    
    print("SCORE CDi HS = ", regr_cdi_hs.score(X_val, Y_val_cdi_hs))
    print("SCORE CDi VS = ", regr_cdi_vs.score(X_val, Y_val_cdi_vs))
    print("SCORE CDi Wing = ", regr_cdi_wing.score(X_val, Y_val_cdi_wing))
    print("SCORE CL HS = ", regr_cl_hs.score(X_val, Y_val_cl_hs))
    print("SCORE CL VS = ", regr_cl_vs.score(X_val, Y_val_cl_vs))
    print("SCORE CL Wing = ", regr_cl_wing.score(X_val, Y_val_cl_wing))
    print("SCORE CDi = ", regr_cdi_total.score(X_val, Y_val_cdi_total))
    print("SCORE CD = ", regr_cd_total.score(X_val, Y_val_cd_total))
    print("SCORE CL = ", regr_cl_total.score(X_val, Y_val_cl_total))
    
    
    #print("ACCURACY CL = ", accuracy_average(Y_val_cl, y_pred_cl))
    #print("ACCURACY CD = ", accuracy_average(Y_val_cd, y_pred_cd))
    
    print("MSE CDi HS = ", mean_squared_error(Y_val_cdi_hs, y_pred_cdi_hs, squared=True))
    print("MSE CDi VS = ", mean_squared_error(Y_val_cdi_vs, y_pred_cdi_vs, squared=True))
    print("MSE CDi Wing = ", mean_squared_error(Y_val_cdi_wing, y_pred_cdi_wing, squared=True))
    print("MSE CL HS = ", mean_squared_error(Y_val_cl_hs, y_pred_cl_hs, squared=True))
    print("MSE CL VS = ", mean_squared_error(Y_val_cl_vs, y_pred_cl_vs, squared=True))
    print("MSE CL Wing = ", mean_squared_error(Y_val_cl_wing, y_pred_cl_wing, squared=True))
    print("MSE CDi = ", mean_squared_error(Y_val_cdi_total, y_pred_cdi_total, squared=True))
    print("MSE CD = ", mean_squared_error(Y_val_cd_total, y_pred_cd_total, squared=True))
    print("MSE CL = ", mean_squared_error(Y_val_cl_total, y_pred_cl_total, squared=True))
    
    print("RMSE CDi HS = ", mean_squared_error(Y_val_cdi_hs, y_pred_cdi_hs, squared=False))
    print("RMSE CDi VS = ", mean_squared_error(Y_val_cdi_vs, y_pred_cdi_vs, squared=False))
    print("RMSE CDi Wing = ", mean_squared_error(Y_val_cdi_wing, y_pred_cdi_wing, squared=False))
    print("RMSE CL HS = ", mean_squared_error(Y_val_cl_hs, y_pred_cl_hs, squared=False))
    print("RMSE CL VS = ", mean_squared_error(Y_val_cl_vs, y_pred_cl_vs, squared=False))
    print("RMSE CL Wing = ", mean_squared_error(Y_val_cl_wing, y_pred_cl_wing, squared=False))
    print("RMSE CDi = ", mean_squared_error(Y_val_cdi_total, y_pred_cdi_total, squared=False))
    print("RMSE CD = ", mean_squared_error(Y_val_cd_total, y_pred_cd_total, squared=False))
    print("RMSE CL = ", mean_squared_error(Y_val_cl_total, y_pred_cl_total, squared=False))
    
    #scatter_matrix(x_data_out, figsize=(15,10))
    
    #plt.show()
    
    # save the model to disk
    filename = 'NN_Surrogate_Model_MLPRegressor_CDi_HS.sav'
    pickle.dump(regr_cdi_hs, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CDi_VS.sav'
    pickle.dump(regr_cdi_vs, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CDi_Wing.sav'
    pickle.dump(regr_cdi_wing, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CL_HS.sav'
    pickle.dump(regr_cl_hs, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CL_VS.sav'
    pickle.dump(regr_cl_vs, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CL_Wing.sav'
    pickle.dump(regr_cl_wing, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CDi.sav'
    pickle.dump(regr_cdi_total, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CD.sav'
    pickle.dump(regr_cd_total, open(filename, 'wb'))
    
    filename = 'NN_Surrogate_Model_MLPRegressor_CL.sav'
    pickle.dump(regr_cl_total, open(filename, 'wb'))
    
    return



def accuracy_average(val,pred):
    
    data_len = len(val)
    i=0
    difference_per = np.zeros([data_len,1])
    
    while i<data_len:
        difference_per[i]=(pred[i]-val[i])/pred[i]
        i=i+1
    
    return np.mean(difference_per)


main()





