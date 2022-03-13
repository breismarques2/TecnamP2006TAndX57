#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr 22 22:02:29 2021

@author: Bruno
"""

import numpy as np
import matplotlib.pyplot as plt
import pickle
import pandas as pd
import matplotlib.tri as tri
from pylab import *
#from matplotlib.mlab import griddata
import scipy.interpolate as inter
from matplotlib.collections import LineCollection

filenameCL = '/Users/Bruno/Documents/Delft/Courses/2016-2017/Thesis/2ndMethology/Surrogate/NN_Surrogate_Model_MLPRegressor_CL.sav'

# Inputs

Ct = np.genfromtxt('Surrogate_Inputs_Ct.csv', delimiter=',')
Cp = np.genfromtxt('Surrogate_Inputs_Cp.csv', delimiter=',')
#rpm = np.genfromtxt('Surrogate_Inputs_RPM.csv', delimiter=',')
rpm_normalized = np.genfromtxt('Surrogate_Inputs_RPM_Normalized.csv', delimiter=',')
mach = np.genfromtxt('Surrogate_Inputs_Mach.csv', delimiter=',')
#alpha = np.genfromtxt('Surrogate_Inputs_Alpha.csv', delimiter=',')
alpha_normalized = np.genfromtxt('Surrogate_Inputs_Alpha_Normalized.csv', delimiter=',')
#alt = np.genfromtxt('Surrogate_Inputs_Alt.csv', delimiter=',')
alt_normalized = np.genfromtxt('Surrogate_Inputs_Alt_Normalized.csv', delimiter=',')

print(np.max(Cp))

# Results
#CDi = np.genfromtxt('Surrogate_Results_CDi.csv', delimiter=',')
CL = np.genfromtxt('Surrogate_Results_CL.csv', delimiter=',')
#CDi_vs = np.genfromtxt('Surrogate_Results_CDi_VS.csv', delimiter=',')
#CL_vs = np.genfromtxt('Surrogate_Results_CL_VS.csv', delimiter=',')
#CDi_hs = np.genfromtxt('Surrogate_Results_CDi_HS.csv', delimiter=',')
#CL_hs = np.genfromtxt('Surrogate_Results_CL_HS.csv', delimiter=',')
#CDi_wing = np.genfromtxt('Surrogate_Results_CDi_Main_Wing.csv', delimiter=',')
#CL_wing = np.genfromtxt('Surrogate_Results_CL_Main_Wing.csv', delimiter=',')

len_array = 100

# New Arrays

Ct_new=np.random.uniform(np.min(Ct), np.max(Ct), (len_array, ))
Cp_new=np.random.uniform(np.min(Cp), 1.0, (len_array, ))
rpm_normalized_new=np.random.uniform(np.min(rpm_normalized), np.max(rpm_normalized), (len_array, ))
mach_new=np.random.uniform(np.min(mach), np.max(mach), (len_array, ))
alpha_normalized_new=np.random.uniform(np.min(alpha_normalized), np.max(alpha_normalized), (len_array, )) #normalized is alpha/20.0º
alt_normalized_new=np.random.uniform(np.min(alt_normalized), np.max(alt_normalized), (len_array, ))

# Create arrays with the same values except the ones in the contour plot (values taken from line 64 of .csv files taken from SUAVE's iterations)

Ct_new = np.full(shape=len_array, fill_value=0.0770087355568094, dtype=np.float)
Cp_new=np.full(shape=len_array, fill_value=0.0290830111240463, dtype=np.float)
rpm_normalized_new=np.full(shape=len_array, fill_value=0.483333333333333, dtype=np.float) #equals RPM = 2900 (x6000)
alt_normalized_new=np.full(shape=len_array, fill_value=0.8128, dtype=np.float) #equals Alt = 2438.4 m (x3000)

CL_model = pickle.load(open(filenameCL, 'rb'))

Ct_new, Cp_new = np.meshgrid(Ct_new, Cp_new)

mach_new, alpha_normalized_new = np.meshgrid(mach_new, alpha_normalized_new)

rpm_normalized_new, alt_normalized_new = np.meshgrid(rpm_normalized_new, alt_normalized_new)

df = pd.DataFrame(columns=['alt', 'alpha', 'mach', 'rpm', 'cp', 'ct'])

i=0

while i<len(alt_normalized_new.ravel()):
                
    df = df.append({'alt': alt_normalized_new.ravel()[i], 'alpha': alpha_normalized_new.ravel()[i], 'mach': mach_new.ravel()[i], 'rpm': rpm_normalized_new.ravel()[i], 'cp': Cp_new.ravel()[i], 'ct': Ct_new.ravel()[i]}, ignore_index=True)
    print(i)
    i=i+1
            
x_data=df

print(x_data)

CL_new=CL_model.predict(x_data.values)

# Obtain contour plot

fig,ax = plt.subplots()

levelsnr=801

CS = ax.contourf(mach_new, alpha_normalized_new, CL_new.reshape(mach_new.shape), levels=levelsnr, vmin=np.min(CL_new), vmax=np.max(CL_new))
#print(CS.levels)

i=40

while i<641:
    
    print(i)
    CS.collections[i].set_color('black')
    CS.collections[i].set_linewidth(1)
    i= i + 40
    
#CS.collections[50].set_color('black')
#CS.collections[50].set_linewidth(1)
#CS.collections[100].set_color('black')
#CS.collections[100].set_linewidth(1)
#CS.collections[150].set_color('black')
#CS.collections[150].set_linewidth(1)
#CS.collections[350].set_color('black')
#CS.collections[400].set_linewidth(1)
#CS.collections[450].set_color('black')
#CS.collections[500].set_linewidth(1)
#CS.collections[550].set_color('black')
#CS.collections[600].set_linewidth(1)
#CS.collections[650].set_color('black')
#CS.collections[700].set_linewidth(1)
#CS.collections[750].set_color('black')
#CS.collections[320].set_linewidth(1)
#CS.collections[360].set_color('black')
#CS.collections[360].set_linewidth(1)
#CS.collections[400].set_color('black')
#CS.collections[400].set_linewidth(1)
#CS.collections[440].set_color('black')
#CS.collections[440].set_linewidth(1)

cbar = fig.colorbar(CS)
ax.set_title('Surrogate CL')
ax.set_xlabel('Mach')
ax.set_ylabel('AoA Normalized')

# Obtain scatter matrix

fig = plt.figure(figsize=(4,4))

ax = fig.add_subplot(111, projection='3d')

ax.scatter(mach_new,alpha_normalized_new,CL_new) # plot the point (2,3,4) on the figure
ax.set_xlabel('Mach')
ax.set_ylabel('AoA Normalized')
ax.set_zlabel('CL')



plt.show()