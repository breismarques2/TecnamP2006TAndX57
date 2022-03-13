#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 29 21:46:12 2020

@author: Bruno
"""

# Python Imports
import numpy as np  
import time      #
import pylab as plt
import math
from subprocess import call
from smt.sampling_methods import LHS

# SUAVE Imports
import SUAVE
from SUAVE.Core import Data, Units
from SUAVE.Plots.Mission_Plots import *
from SUAVE.Methods.Propulsion import propeller_design
from SUAVE.Input_Output.Results import  print_parasite_drag,  \
     print_compress_drag, \
     print_engine_data,   \
     print_mission_breakdown, \
     print_weight_breakdown
     
from SUAVE.Input_Output.OpenVSP import vspaero_Tecnam_simple
     
     
print(SUAVE.__file__)
    
alt_range       = [0.0, 3000.0]
alpha_range     = [-5.0, 0.0] #º
mach_range      = [0.0, 0.3] 
rpm_range       = [-2000, 0.0]
cp_range        = [-0.8, 0.0]
ct_range        = [-0.5, 0.0]
    
xlimits = np.array([alt_range, alpha_range, mach_range, rpm_range, cp_range, ct_range])
sampling = LHS(xlimits=xlimits)

num = 5000
x = sampling(num)

data_len = num
CL = np.zeros([data_len,1])
CDi = np.zeros([data_len,1])
CDo = np.zeros([data_len,1])
CDtotal = np.zeros([data_len,1])
main_wing_cl = np.zeros([data_len,1])
horizontal_stabilizer_cl = np.zeros([data_len,1])
vertical_stabilizer_cl = np.zeros([data_len,1])
fuselage_cl = np.zeros([data_len,1])
main_wing_cdi = np.zeros([data_len,1])
horizontal_stabilizer_cdi = np.zeros([data_len,1])
vertical_stabilizer_cdi = np.zeros([data_len,1])
fuselage_cdi = np.zeros([data_len,1])
main_wing_cdo = np.zeros([data_len,1])
horizontal_stabilizer_cdo = np.zeros([data_len,1])
vertical_stabilizer_cdo = np.zeros([data_len,1])
fuselage_cdo = np.zeros([data_len,1])
wing_lift_distribution = np.zeros([data_len,22])
wing_drag_distribution = np.zeros([data_len,22])

tag = "takeoff"
iters = 10
engines_number_tot = 2

i=0

while i < num:
    print('GOING TO SIMULATION NUMBER: '+str(i+1))
    CL[i], CDi[i], CDo[i], \
    main_wing_cl[i], horizontal_stabilizer_cl[i], vertical_stabilizer_cl[i], fuselage_cl[i], \
    main_wing_cdi[i], horizontal_stabilizer_cdi[i], vertical_stabilizer_cdi[i], fuselage_cdi[i], \
    main_wing_cdo[i], horizontal_stabilizer_cdo[i], vertical_stabilizer_cdo[i], fuselage_cdo[i], \
    wing_lift_distribution[i], wing_drag_distribution[i] = vspaero_Tecnam_simple(tag + ".vsp3", x[i][0], math.radians(x[i][1]), x[i][2], iters, x[i][3], engines_number_tot, x[i][4], x[i][5])
    CDtotal[i] =  CDi[i] + CDo[i]
    print ('CL='+str(CL[i]))
    print ('CDi='+str(CDi[i]))
    #print ('CD0='+str(CDo[i]))
    #print ('CDtotal='+str(CDtotal[i]))
    #print('Main_wing_CL='+str(main_wing_cl[i]))
    #print('Horizontal_stabilizer_CL='+str(horizontal_stabilizer_cl[i]))
    #print('Vertical_stabilizer_CL='+str(vertical_stabilizer_cl[i]))
    #print('Fuselage_CL='+str(fuselage_cl[i]))
    #print('Main_wing_CDi='+str(main_wing_cdi[i]))
    #print('Horizontal_stabilizer_CDi='+str(horizontal_stabilizer_cdi[i]))
    #print('Vertical_stabilizer_CDi='+str(vertical_stabilizer_cdi[i]))
    #print('Fuselage_CDi='+str(fuselage_cdi[i]))
    #print('Main_wing_CD0='+str(main_wing_cdo[i]))
    #print('Horizontal_stabilizer_CD0='+str(horizontal_stabilizer_cdo[i]))
    #print('Vertical_stabilizer_CD0='+str(vertical_stabilizer_cdo[i]))
    #print('Fuselage_CD0='+str(fuselage_cdo[i]))
    #print ('WingCl='+str(wing_lift_distribution[i]))
    #print ('WingCd='+str(wing_drag_distribution[i]))
    i=i+1
    

print('SURROGATE CALCULATIONS FINISHED')

