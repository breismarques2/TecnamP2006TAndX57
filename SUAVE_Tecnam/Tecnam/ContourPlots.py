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

print(rpm_normalized_new)
print(rpm_normalized_new.ravel())

df = pd.DataFrame(columns=['alt', 'alpha', 'mach', 'rpm', 'cp', 'ct'])

print(rpm_normalized_new)

print(rpm_normalized_new.ravel()[1])

print(len(alt_normalized_new.ravel()))

i=0

while i<len(alt_normalized_new.ravel()):
                
    df = df.append({'alt': alt_normalized_new.ravel()[i], 'alpha': alpha_normalized_new.ravel()[i], 'mach': mach_new.ravel()[i], 'rpm': rpm_normalized_new.ravel()[i], 'cp': Cp_new.ravel()[i], 'ct': Ct_new.ravel()[i]}, ignore_index=True)
    print(i)
    i=i+1
            
x_data=df

print(x_data)

CL_new=CL_model.predict(x_data.values)

fig,ax = plt.subplots()

print()

CS = ax.contourf(mach_new, alpha_normalized_new, CL_new.reshape(mach_new.shape), levels=400, vmin=np.min(CL_new), vmax=np.max(CL_new))
plt.clabel(CS, inline=1, fontsize=10)
cbar = fig.colorbar(CS)
#cbar.set_clim( np.min(CL_new), np.max(CL_new) )
ax.set_title('Surrogate CL')
ax.set_xlabel('Mach')
ax.set_ylabel('AoA Normalized')


#X, Y = np.meshgrid(mach_new, alpha_normalized_new)


#Z = np.c_[ np.ravel(X), np.ravel(Y) ]

#array_aux= np.zeros((len(CL_new),len(CL_new)))

#for i,_ in enumerate(CL_new):
    
#    for j,_ in enumerate(CL_new):
    
#        array_aux[i][j]= CL_new[j]

#print(CL_new)

#print(mach_new)

#print(alpha_normalized_new)
#x=np.random.uniform(-2, 2, (5000, ))
#print(x)

#mach_new , alpha_normalized_new = np.meshgrid(mach_new, alpha_normalized_new)

#zgrid = inter.griddata((mach,alpha_normalized),CL, (mach_new, alpha_normalized_new))

#mach_new = np.array([1,2,3])
#y = np.array([1,2,3])

print('Mach')
print(mach_new)
print('Alpha_Normalized')
print(alpha_normalized_new)


#mach_new, alpha_normalized_new = np.meshgrid(mach_new, alpha_normalized_new)
#X_grid = np.c_[ np.ravel(xx), np.ravel(yy) ]
#z = f(X_grid)

print('After Meshgrid')
print('Mach')
print(mach_new)
print('Alpha_Normalized')
print(alpha_normalized_new)
#ax = plt.subplot(111, polar=True)
#contourf(mach_new, alpha_normalized_new, zgrid) 

#fig,ax = plt.subplots(1)

# creating the segments
#points = np.array([mach_new, alpha_normalized_new]).T.reshape(-1, 1, 2)
#segments = np.concatenate([points[:-1], points[1:]], axis=1)

# creating LineCollection object
#lc = LineCollection(segments, cmap=plt.get_cmap('jet'),norm=plt.Normalize(0, 1))
#lc.set_array(CL_new)
#lc.set_linewidth(2)

# add LineCollection to plot
#ax.add_collection(lc)
  

#fig, ax = plt.subplots()
#ax.tricontour(mach_new.flatten(), alpha_normalized_new.flatten(), CL_new.flatten())
#ax.tricontourf(mach_new.flatten(), alpha_normalized_new.flatten(), CL_new.flatten())
#fig.colorbar(CS)
#ax.set_title('Surrogate CL')
#ax.set_xlabel('Mach')
#ax.set_ylabel('AoA Normalized')

#print(Ct_new)

fig = plt.figure(figsize=(4,4))

ax = fig.add_subplot(111, projection='3d')

ax.scatter(mach_new,alpha_normalized_new,CL_new) # plot the point (2,3,4) on the figure

plt.show()

#plot.contour([CL, alpha,] CL, [plot.MaxNLocator])