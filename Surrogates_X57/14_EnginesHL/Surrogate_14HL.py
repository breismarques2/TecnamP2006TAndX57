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
import pandas as pd

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
     
from SUAVE.Input_Output.OpenVSP import vspaero_X57
     
     
print(SUAVE.__file__)
    
alt_range          = [0.0, 3000.0]
alpha_range        = [-5.0, 18.0] #º
mach_range         = [0.0, 0.3] 
rpm_forward_range  = [-2000, 6000.0]
rpm_lift_range     = [-2000, 6000.0]
cp_forward_range   = [-0.9, 0.9]
cp_lift_range      = [-0.9, 0.9]
ct_forward_range   = [-0.8, 0.8]
ct_lift_range      = [-0.8, 0.8]
    
xlimits = np.array([alt_range, alpha_range, mach_range, rpm_forward_range, rpm_lift_range, cp_forward_range, cp_lift_range, ct_forward_range, ct_lift_range])
sampling = LHS(xlimits=xlimits)

num = 15000
x = sampling(num)

j=0
file=open('Xvector.txt', 'w+')
file.write('Alt  Alpha  Mach  RPM_For  RPM_ Lif  CP_For  CP_Lif  CT_For  CT_Lif \n\n')

while j < num:
    
    file.write(str(j+1) + ' - ' + str(x[j])+'\n')
    j=j+1
    
file.close()

j=0

pd.DataFrame(x).to_csv('x.csv', index=False, header = ['alt', 'alpha','mach', 'rpm_forward', 'rpm_lift', 'cp_forward', 'cp_lift', 'ct_forward', 'ct_lift'])

aux = np.array([])

CL_csv = 'CL.csv'
CDi_csv = 'CDi.csv'
CDo_csv = 'CDo.csv'
CDtotal_csv = 'CDtotal.csv'
Fuselage_CDi_csv = 'Fuselage_CDi.csv'
Fuselage_CDo_csv = 'Fuselage_CDo.csv'
Fuselage_CL_csv = 'Fuselage_CL.csv'
Horizontal_Stab_CDi_csv = 'Horizontal_Stab_CDi.csv'
Horizontal_Stab_CDo_csv = 'Horizontal_Stab_CDo.csv'
Horizontal_Stab_CL_csv = 'Horizontal_Stab_CL.csv'
Main_Wing_CDi_csv = 'Main_Wing_CDi.csv'
Main_Wing_CDo_csv = 'Main_Wing_CDo.csv'
Main_Wing_CL_csv = 'Main_Wing_CL.csv'
Vertical_Stab_CDi_csv = 'Vertical_Stab_CDi.csv'
Vertical_Stab_CDo_csv = 'Vertical_Stab_CDo.csv'
Vertical_Stab_CL_csv = 'Vertical_Stab_CL.csv'
Wing_CL_Distribution_csv = 'Wing_CL_Distribution.csv'
Wing_CD_Distribution_csv = 'Wing_CD_Distribution.csv'


CL_pd=pd.DataFrame(aux).to_csv(CL_csv, index=False, header = ['CL'])
CDi_pd=pd.DataFrame(aux).to_csv(CDi_csv, index=False, header = ['CDi'])
CDo_pd=pd.DataFrame(aux).to_csv(CDo_csv, index=False, header = ['CDo'])
CDtotal_pd=pd.DataFrame(aux).to_csv(CDtotal_csv, index=False, header = ['CDtotal'])
Fuselage_CDi_pd=pd.DataFrame(aux).to_csv(Fuselage_CDi_csv, index=False, header = ['Fuselage_CDi'])
Fuselage_CDo_pd=pd.DataFrame(aux).to_csv(Fuselage_CDo_csv, index=False, header = ['Fuselage_CDo'])
Fuselage_CL_pd=pd.DataFrame(aux).to_csv(Fuselage_CL_csv, index=False, header = ['Fuselage_CL'])
Horizontal_Stab_CDi_pd=pd.DataFrame(aux).to_csv(Horizontal_Stab_CDi_csv, index=False, header = ['Horizontal_Stab_CDi'])
Horizontal_Stab_CDo_pd=pd.DataFrame(aux).to_csv(Horizontal_Stab_CDo_csv, index=False, header = ['Horizontal_Stab_CDo'])
Horizontal_Stab_CL_pd=pd.DataFrame(aux).to_csv(Horizontal_Stab_CL_csv, index=False, header = ['Horizontal_Stab_CL'])
Main_Wing_CDi_pd=pd.DataFrame(aux).to_csv(Main_Wing_CDi_csv, index=False, header = ['Main_Wing_CDi'])
Main_Wing_CDo_pd=pd.DataFrame(aux).to_csv(Main_Wing_CDo_csv, index=False, header = ['Main_Wing_CDo'])
Main_Wing_CL_pd=pd.DataFrame(aux).to_csv(Main_Wing_CL_csv, index=False, header = ['Main_Wing_CL'])
Vertical_Stab_CDi_pd=pd.DataFrame(aux).to_csv(Vertical_Stab_CDi_csv, index=False, header = ['Vertical_Stab_CDi'])
Vertical_Stab_CDo_pd=pd.DataFrame(aux).to_csv(Vertical_Stab_CDo_csv, index=False, header = ['Vertical_Stab_CDo'])
Vertical_Stab_CL_pd=pd.DataFrame(aux).to_csv(Vertical_Stab_CL_csv, index=False, header = ['Vertical_Stab_CL'])
Wing_CL_Distribution_pd=pd.DataFrame(aux).to_csv(Wing_CL_Distribution_csv, index=False, header = ['Wing_CL_Distribution'])
Wing_CD_Distribution_pd=pd.DataFrame(aux).to_csv(Wing_CD_Distribution_csv, index=False, header = ['Wing_CD_Distribution'])

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

tag = "takeoff_X57_14"
iters = 10
engines_number_tot = 16

i=0

while i < num:
    print('GOING TO SIMULATION NUMBER: '+str(i+1))
    CL[i], CDi[i], CDo[i], \
    main_wing_cl[i], horizontal_stabilizer_cl[i], vertical_stabilizer_cl[i], fuselage_cl[i], \
    main_wing_cdi[i], horizontal_stabilizer_cdi[i], vertical_stabilizer_cdi[i], fuselage_cdi[i], \
    main_wing_cdo[i], horizontal_stabilizer_cdo[i], vertical_stabilizer_cdo[i], fuselage_cdo[i], \
    wing_lift_distribution[i], wing_drag_distribution[i] = vspaero_X57(tag + ".vsp3", x[i][0], math.radians(x[i][1]), x[i][2], iters, engines_number_tot, x[i][3], x[i][4], x[i][5], x[i][6], x[i][7], x[i][8])
    CDtotal[i] =  CDi[i] + CDo[i]
    
    pd.DataFrame(CL[i]).to_csv(CL_csv, mode='a', index=False, header=False)
    pd.DataFrame(CDi[i]).to_csv(CDi_csv, mode='a', index=False, header=False)
    pd.DataFrame(CDo[i]).to_csv(CDo_csv, mode='a', index=False, header=False)
    pd.DataFrame(CDtotal[i]).to_csv(CDtotal_csv, mode='a', index=False, header=False)
    pd.DataFrame(main_wing_cdi[i]).to_csv(Main_Wing_CDi_csv, mode='a', index=False, header=False)
    pd.DataFrame(main_wing_cdo[i]).to_csv(Main_Wing_CDo_csv, mode='a', index=False, header=False)
    pd.DataFrame(main_wing_cl[i]).to_csv(Main_Wing_CL_csv, mode='a', index=False, header=False)
    pd.DataFrame(horizontal_stabilizer_cdi[i]).to_csv(Horizontal_Stab_CDi_csv, mode='a', index=False, header=False)
    pd.DataFrame(horizontal_stabilizer_cdo[i]).to_csv(Horizontal_Stab_CDo_csv, mode='a', index=False, header=False)
    pd.DataFrame(horizontal_stabilizer_cl[i]).to_csv(Horizontal_Stab_CL_csv, mode='a', index=False, header=False)
    pd.DataFrame(vertical_stabilizer_cdi[i]).to_csv(Vertical_Stab_CDi_csv, mode='a', index=False, header=False)
    pd.DataFrame(vertical_stabilizer_cdo[i]).to_csv(Vertical_Stab_CDo_csv, mode='a', index=False, header=False)
    pd.DataFrame(vertical_stabilizer_cl[i]).to_csv(Vertical_Stab_CL_csv, mode='a', index=False, header=False)
    pd.DataFrame(fuselage_cdi[i]).to_csv(Fuselage_CDi_csv, mode='a', index=False, header=False)
    pd.DataFrame(fuselage_cdo[i]).to_csv(Fuselage_CDo_csv, mode='a', index=False, header=False)
    pd.DataFrame(fuselage_cl[i]).to_csv(Fuselage_CL_csv, mode='a', index=False, header=False)
    pd.DataFrame(wing_lift_distribution[i].reshape(1,22)).to_csv(Wing_CL_Distribution_csv, mode='a', index=False, header=False)
    pd.DataFrame(wing_drag_distribution[i].reshape(1,22)).to_csv(Wing_CD_Distribution_csv, mode='a', index=False, header=False)
    
    
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

