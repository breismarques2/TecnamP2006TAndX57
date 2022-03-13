# ----------------------------------------------------------------------
#   Imports
# ----------------------------------------------------------------------

# Python Imports
import numpy as np  
import time      #
import pylab as plt
from subprocess import call
import csv

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

# ----------------------------------------------------------------------
#   Main
# ----------------------------------------------------------------------

def main():
    
    print(SUAVE.__file__)
    
    #open("flapsangle.txt", "w+")
    
    #file=open('PlottedResults.txt', 'a+')

    configs, analyses = full_setup()

    simple_sizing(configs)

    configs.finalize()
    analyses.finalize()

    # weight analysis
    weights = analyses.configs.base.weights
    breakdown = weights.evaluate()      

    # mission analysis
    mission = analyses.missions.base
    print('Mission Analysis')
    results = mission.evaluate()
    
    np.savetxt("Surrogate_Inputs_Alt.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alt, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_Alt_Normalized.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alt_normalized, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_Alpha.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alpha, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_Alpha_Normalized.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alpha_normalized, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_Mach.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_mach, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_RPM.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_rpm, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_RPM_Normalized.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_rpm_normalized, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_Cp.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_cp, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Inputs_Ct.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_ct, delimiter =", ", fmt = '%.18f')
    
    np.savetxt("Surrogate_Results_CL_HS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl_hs, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Results_CDi_HS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi_hs, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Results_CL_VS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl_vs, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Results_CDi_VS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi_vs, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Results_CL_Main_Wing.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl_main_wing, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Results_CDi_Main_Wing.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi_main_wing, delimiter =", ", fmt = '%.18f')    
    np.savetxt("Surrogate_Results_CL.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl, delimiter =", ", fmt = '%.18f')
    np.savetxt("Surrogate_Results_CDi.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi, delimiter =", ", fmt = '%.18f')

    # print weight breakdown
    print_weight_breakdown(configs.base,filename = 'P2006T_weight_breakdown.dat')
    

    # print engine data into file
    #print_engine_data(configs.base,filename = 'P2006T_engine_data.dat')

    # print parasite drag data into file
    # define reference condition for parasite drag
    ref_condition = Data()
    ref_condition.mach_number =  0.21
    ref_condition.reynolds_number = 7.26e6   
    print_parasite_drag(ref_condition,configs.cruise,analyses,'P2006T_parasite_drag.dat')

    # print compressibility drag data into file
    #print_compress_drag(configs.cruise,analyses,filename = 'P2006T_compress_drag.dat')

    # print mission breakdown
    print_mission_breakdown(results,filename='P2006T_mission_breakdown.dat')

    
    #print vehicle_setup()
    
    #geom=vsp.GetGeomTypes()
    
    #print geom
    
    
    

    # plt the old results
    plot_mission(results)
    
    #call(["/Users/Bruno/OpenVSP/build/_CPack_Packages/MacOS/ZIP/OpenVSP-3.13.3-MacOS/vsp","open","Tecnam_P2006T.vsp3"])
    

    return

# ----------------------------------------------------------------------
#   Analysis Setup
# ----------------------------------------------------------------------

def full_setup():

    # vehicle data
    vehicle  = vehicle_setup()
    configs  = configs_setup(vehicle)

    # vehicle analyses
    configs_analyses = analyses_setup(configs)

    # mission analyses
    mission  = mission_setup(configs_analyses)
    missions_analyses = missions_setup(mission)

    analyses = SUAVE.Analyses.Analysis.Container()
    analyses.configs  = configs_analyses
    analyses.missions = missions_analyses

    return configs, analyses

# ----------------------------------------------------------------------
#   Define the Vehicle Analyses
# ----------------------------------------------------------------------

def analyses_setup(configs):

    analyses = SUAVE.Analyses.Analysis.Container()

    # build a base analysis for each config
    for tag,config in configs.items():
        analysis = base_analysis(config)
        analyses[tag] = analysis

    return analyses

def base_analysis(vehicle):

    # ------------------------------------------------------------------
    #   Initialize the Analyses
    # ------------------------------------------------------------------     
    analyses = SUAVE.Analyses.Vehicle()

    # ------------------------------------------------------------------
    #  Basic Geometry Relations
    sizing = SUAVE.Analyses.Sizing.Sizing()
    sizing.features.vehicle = vehicle
    analyses.append(sizing)

    # ------------------------------------------------------------------
    #  Weights
    weights = SUAVE.Analyses.Weights.Weights_General_Aviation()
    weights.vehicle = vehicle
    analyses.append(weights)

    # ------------------------------------------------------------------
    #  Aerodynamics Analysis
    aerodynamics = SUAVE.Analyses.Aerodynamics.Open_VSP_Analysis_Tecnam_Updated()
    aerodynamics.geometry = vehicle
    analyses.append(aerodynamics)

    # ------------------------------------------------------------------
    #  Stability Analysis
    stability = SUAVE.Analyses.Stability.Fidelity_Zero()
    stability.geometry = vehicle
    analyses.append(stability)

    # ------------------------------------------------------------------
    #  Energy
    energy= SUAVE.Analyses.Energy.Energy()
    energy.network = vehicle.propulsors 
    analyses.append(energy)

    # ------------------------------------------------------------------
    #  Planet Analysis
    planet = SUAVE.Analyses.Planets.Planet()
    analyses.append(planet)

    # ------------------------------------------------------------------
    #  Atmosphere Analysis
    atmosphere = SUAVE.Analyses.Atmospheric.US_Standard_1976()
    atmosphere.features.planet = planet.features
    analyses.append(atmosphere)   

    return analyses    

# ----------------------------------------------------------------------
#   Define the Vehicle
# ----------------------------------------------------------------------

def vehicle_setup():
    
    # ------------------------------------------------------------------
    #   Initialize the Vehicle
    # ------------------------------------------------------------------    
    
    vehicle = SUAVE.Vehicle()
    vehicle.tag = 'Tecnam_P2006T'    
    
    # ------------------------------------------------------------------
    #   Vehicle-level Properties
    # ------------------------------------------------------------------    

    # mass properties
    vehicle.mass_properties.max_takeoff               = 1230 * Units.kilogram 
    vehicle.mass_properties.takeoff                   = 1230 * Units.kilogram   
    vehicle.mass_properties.operating_empty           = 819 * Units.kilogram  
    vehicle.mass_properties.max_zero_fuel             = 750 * Units.kilogram
    vehicle.mass_properties.zero_fuel_center_of_gravity = np.array([[3.356*Units.meter,0.0,0.346*Units.meter]]) #IMPORTANT
    #vehicle.mass_properties.fuel             = 151 * Units.kilogram
    #vehicle.mass_properties.cargo                     = 80  * Units.kilogram   
    
    # design
    vehicle.design_dynamic_pressure = 1976.0 * Units.pascal
    vehicle.design_mach_number = 0.21
    
    # envelope properties
    vehicle.envelope.ultimate_load = 3.8
    vehicle.envelope.limit_load    = 2.5333

    # basic parameters
    vehicle.reference_area         = 73 * Units['meters**2']  
    vehicle.passengers             = 4
    vehicle.systems.control        = "fully powered" 
    vehicle.systems.accessories    = "medium range"
    
    # ------------------------------------------------------------------        
    #   Fuel (only for weight analysis)
    # ------------------------------------------------------------------        
    
    fuel = Data()
    fuel.mass_properties = Data()
    fuel.tag = 'fuel'
    
    fuel.origin = np.array([[2.986*Units.meter,0.0,1.077* Units.meter]]) #IMPORTANT #IMPORTANT
    fuel.mass_properties.mass = 151.0 * Units.kilogram #IMPORTANT
    fuel.mass_properties.center_of_gravity = np.array([[3.711*Units.meter,0.0,1.077* Units.meter]]) #IMPORTANT
    fuel.number_of_tanks = 2 #IMPORTANT
    fuel.internal_volume = 0.2 * Units['meters**3'] #IMPORTANT
    fuel.density = 755 * (Units.kilogram/Units['meters**3']) #IMPORTANT
    
    # add to vehicle
    vehicle.fuel = fuel
    
    # ------------------------------------------------------------------
    #  Avionics (only for weight analysis)
    # ------------------------------------------------------------------ 
    
    avionics = Data()
    avionics.mass_properties = Data()
    avionics.tag = 'avionics'  
    
    avionics.mass_properties.uninstalled = 17.0 * Units.kilogram
    
    # add to vehicle
    vehicle.avionics = avionics

    # ------------------------------------------------------------------        
    #  Landing Gear
    # ------------------------------------------------------------------        
    # used for noise calculations
    landing_gear = SUAVE.Components.Landing_Gear.Landing_Gear()
    landing_gear.tag = "main_landing_gear"
    
    landing_gear.main_tire_diameter = 0.423 * Units.m
    landing_gear.nose_tire_diameter = 0.3625 * Units.m
    landing_gear.main_strut_length  = 0.4833 * Units.m
    landing_gear.nose_strut_length  = 0.3625 * Units.m
    landing_gear.main_units  = 2    #number of main landing gear units
    landing_gear.nose_units  = 1    #number of nose landing gear
    landing_gear.main_wheels = 1    #number of wheels on the main landing gear
    landing_gear.nose_wheels = 1    #number of wheels on the nose landing gear      
    vehicle.landing_gear = landing_gear

    # ------------------------------------------------------------------        
    #   Main Wing
    # ------------------------------------------------------------------        
    
    wing = SUAVE.Components.Wings.Main_Wing()
    wing.tag = 'main_wing'
    
    wing.aspect_ratio            = 8.80
    #wing.sweeps.quarter_chord    = 0 * Units.deg
    wing.thickness_to_chord      = 0.15
    wing.taper                   = 0.621
    wing.span_efficiency         = 0.965
    wing.spans.projected         = 11.4 * Units.meter
    wing.chords.root             = 1.45 * Units.meter
    wing.chords.tip              = 0.90 * Units.meter
    wing.chords.mean_aerodynamic = 1.34 * Units.meter
    wing.areas.reference         = 14.80 * Units['meters**2']  
    wing.twists.root             = 0 * Units.degrees
    wing.twists.tip              = 0 * Units.degrees
    wing.dihedral= 1 * Units.degrees
    wing.origin                  = [[2.85* Units.meter,0,1.077* Units.meter]] # meters
    wing.aerodynamic_center      = [3.571*Units.meter,0.0,1.146*Units.meter] #IMPORTANT
    wing.vertical                = False
    wing.symmetric               = True
    wing.high_lift               = True
    wing.dynamic_pressure_ratio  = 1.0
    
    
    segment = SUAVE.Components.Wings.Segment()
    
    segment.tag                   = 'root'
    segment.percent_span_location = 0.0
    segment.twist                 = 0. * Units.deg
    segment.root_chord_percent    = 1.
    segment.dihedral_outboard     = 1. * Units.degrees
    segment.sweeps.quarter_chord  = 0. * Units.degrees
    segment.thickness_to_chord    = 0.15
    
    
    #segment airfoil
    
    airfoil = SUAVE.Components.Wings.Airfoils.Airfoil()
    airfoil.coordinate_file       = '/Users/Bruno/Documents/Delft/Courses/2016-2017/Thesis/Code/Airfoils/naca642415.dat'
    
    segment.append_airfoil(airfoil)
    
    
    wing.Segments.append(segment)
    
    segment = SUAVE.Components.Wings.Segment()
    
    segment.tag                   = 'mid'
    segment.percent_span_location = 0.53
    segment.twist                 = 0. * Units.deg
    segment.root_chord_percent    = 1.
    segment.dihedral_outboard     = 1. * Units.degrees
    segment.sweeps.quarter_chord  = 0. * Units.degrees
    segment.thickness_to_chord    = 0.15
    
    #segment airfoil
    
    airfoil = SUAVE.Components.Wings.Airfoils.Airfoil()
    airfoil.coordinate_file       = '/Users/Bruno/Documents/Delft/Courses/2016-2017/Thesis/Code/Airfoils/naca642415.dat'
    
    segment.append_airfoil(airfoil)
    
    wing.Segments.append(segment)
    
    segment = SUAVE.Components.Wings.Segment()
    
    segment.tag                   = 'tip'
    segment.percent_span_location = 1.0
    segment.twist                 = 0. * Units.deg
    segment.root_chord_percent    = 0.621
    segment.dihedral_outboard     = 1. * Units.degrees
    segment.sweeps.quarter_chord  = 0. * Units.degrees
    segment.thickness_to_chord    = 0.15
    
    #segment airfoil
    
    airfoil = SUAVE.Components.Wings.Airfoils.Airfoil()
    airfoil.coordinate_file       = '/Users/Bruno/Documents/Delft/Courses/2016-2017/Thesis/Code/Airfoils/naca642415.dat'
    
    segment.append_airfoil(airfoil)
    
    wing.Segments.append(segment)
    
    
    
    
    
    # ------------------------------------------------------------------
    #   Flaps
    # ------------------------------------------------------------------
    #wing.flaps.chord      =  0.20   
    #wing.flaps.span_start =  0.1053
    #wing.flaps.span_end   =  0.6842
    #wing.flaps.type       = 'single_slotted'
    
    
    flap                       = SUAVE.Components.Wings.Control_Surfaces.Flap() 
    flap.tag                   = 'flap' 
    flap.span_fraction_start   = 0.1053
    flap.span_fraction_end     = 0.6842 
    flap.deflection            = 0.0 * Units.degrees
    # Flap configuration types are used in computing maximum CL and noise
    flap.configuration_type    = 'single_slotted'
    flap.chord_fraction        = 0.20   
    wing.append_control_surface(flap)

    # add to vehicle
    vehicle.append_component(wing)

    # ------------------------------------------------------------------        
    #  Horizontal Stabilizer
    # ------------------------------------------------------------------        
    
    wing = SUAVE.Components.Wings.Horizontal_Tail()
    wing.tag = 'horizontal_stabilizer'
    
    wing.aspect_ratio            = 4.193     
    wing.sweeps.quarter_chord    = 0.0 * Units.deg
    wing.thickness_to_chord      = 0.12
    wing.taper                   = 1.0
    wing.span_efficiency         = 0.733
    wing.spans.projected         = 3.3 * Units.meter
    wing.chords.root             = 0.787 * Units.meter
    wing.chords.tip              = 0.787 * Units.meter
    wing.chords.mean_aerodynamic = (wing.chords.root*(2.0/3.0)*((1.0+wing.taper+wing.taper**2.0)/(1.0+wing.taper))) * Units.meter
    wing.areas.reference         = 2.5971 * Units['meters**2']  
    wing.areas.exposed           = 4.0 * Units['meters**2']  
    wing.areas.wetted            = 4.0 * Units['meters**2']  
    wing.twists.root             = 0.0 * Units.degrees
    wing.twists.tip              = 0.0 * Units.degrees  
    wing.origin                  = [[7.789 * Units.meter,0.0,0.3314 * Units.meter]] # meters
    wing.aerodynamic_center      = [8.116 * Units.meter,0.0,0.331 *Units.meter] #IMPORTANT
    wing.vertical                = False 
    wing.symmetric               = True
    wing.dynamic_pressure_ratio  = 0.9  
    
    # add to vehicle
    vehicle.append_component(wing)
    
    # ------------------------------------------------------------------
    #   Vertical Stabilizer
    # ------------------------------------------------------------------
    
    wing = SUAVE.Components.Wings.Vertical_Tail()
    wing.tag = 'vertical_stabilizer'    

    wing.aspect_ratio            = 1.407
    wing.sweeps.quarter_chord    = 38.75 * Units.deg
    wing.thickness_to_chord      = 0.12
    wing.taper                   = 0.414
    wing.span_efficiency         = -0.107
    wing.spans.projected         = 1.574 * Units.meter
    wing.chords.root             = 1.2 * Units.meter
    wing.chords.tip              = 0.497 * Units.meter
    wing.chords.mean_aerodynamic = (wing.chords.root*(2.0/3.0)*((1.0+wing.taper+wing.taper**2.0)/(1.0+wing.taper))) * Units.meter
    wing.areas.reference         = 1.761 * Units['meters**2']  
    wing.twists.root             = 0.0 * Units.degrees
    wing.twists.tip              = 0.0 * Units.degrees  
    wing.origin                  = [[7.25,0,0.497]] # meters
    wing.aerodynamic_center      = [8.176*Units.meter,0.0,1.081 * Units.meter] #IMPORTANT
    wing.vertical                = True 
    wing.symmetric               = False
    wing.t_tail                  = False
    wing.dynamic_pressure_ratio  = 1.0
        
    # add to vehicle
    vehicle.append_component(wing)

    # ------------------------------------------------------------------
    #  Fuselage
    # ------------------------------------------------------------------
    
    fuselage = SUAVE.Components.Fuselages.Fuselage()
    
    
    
    
    
    fuselage.tag = 'fuselage'
    
    fuselage.time = time.time()
    
    #fuselage.aerodynamic_center= [2.986,0,1.077]
    
    fuselage.number_coach_seats    = vehicle.passengers
    fuselage.seats_abreast         = 2
    fuselage.seat_pitch            = 0.995     * Units.meter
    fuselage.fineness.nose         = 1.27
    fuselage.fineness.tail         = 1  #3.31
    fuselage.lengths.nose          = 1.16  * Units.meter
    fuselage.lengths.tail          = 4.637 * Units.meter
    fuselage.lengths.cabin         = 2.653 * Units.meter
    fuselage.lengths.total         = 8.45 * Units.meter
    fuselage.lengths.fore_space    =  0.0   * Units.meter
    fuselage.lengths.aft_space     =  0.0   * Units.meter
    fuselage.width                 = 1.22  * Units.meter
    fuselage.heights.maximum       = 1.41  * Units.meter
    fuselage.effective_diameter    =  2 * Units.meter
    fuselage.areas.side_projected  = 7.46  * Units['meters**2'] 
    fuselage.areas.wetted          = 25.0  * Units['meters**2'] 
    fuselage.areas.front_projected = 1.54 * Units['meters**2'] 
    fuselage.differential_pressure = 31216.46 * Units.pascal # Maximum differential pressure
    fuselage.mass_properties.volume = 2.0388 * Units['meters**3'] #IMPORTANT
    
    fuselage.heights.at_quarter_length          = 1.077 * Units.meter
    fuselage.heights.at_three_quarters_length   =  0.5 * Units.meter   #0.621 * Units.meter
    fuselage.heights.at_wing_root_quarter_chord = 1.45218  * Units.meter
    
    
    ## OpenVSP Design
    
    fuselage.OpenVSP_values = Data() # VSP uses degrees directly
    
    #Nose Section
    
    fuselage.OpenVSP_values.nose = Data()
    fuselage.OpenVSP_values.nose.top = Data()
    fuselage.OpenVSP_values.nose.side = Data()
    fuselage.OpenVSP_values.nose.top.angle = 75.0
    fuselage.OpenVSP_values.nose.top.strength = 0.40
    fuselage.OpenVSP_values.nose.side.angle = 45.0
    fuselage.OpenVSP_values.nose.side.strength = 0.75  
    fuselage.OpenVSP_values.nose.TB_Sym = True
    fuselage.OpenVSP_values.nose.z_pos = 0.0
    
    #MidFuselage1 Section
    
    fuselage.OpenVSP_values.midfus1 = Data()
    fuselage.OpenVSP_values.midfus1.top = Data()
    fuselage.OpenVSP_values.midfus1.bottom = Data()
    fuselage.OpenVSP_values.midfus1.top.angle = 20.0
    fuselage.OpenVSP_values.midfus1.bottom.strength = 0.0
    fuselage.OpenVSP_values.midfus1.bottom.angle = 0.43
    fuselage.OpenVSP_values.midfus1.z_pos=0.03
    
    #MidFuselage2 Section
    
    fuselage.OpenVSP_values.midfus2 = Data()
    fuselage.OpenVSP_values.midfus2.z_pos=0.051
    
    #MidFuselage3 Section
    
    fuselage.OpenVSP_values.midfus3 = Data()
    fuselage.OpenVSP_values.midfus3.z_pos=0.045
    fuselage.OpenVSP_values.midfus3.width=0.51
    
    #Tail Section
    
    fuselage.OpenVSP_values.tail = Data()
    fuselage.OpenVSP_values.tail.top = Data() 
    fuselage.OpenVSP_values.tail.bottom = Data()
    fuselage.OpenVSP_values.tail.z_pos = 0.05147
    #fuselage.OpenVSP_values.tail.top.angle = 75.0
    #fuselage.OpenVSP_values.tail.top.strength = 0.40
    
    
    #Values for surrogate
    
    fuselage.OpenVSP_values.surrogate_alt = []
    fuselage.OpenVSP_values.surrogate_alt_normalized = []
    fuselage.OpenVSP_values.surrogate_alpha = []
    fuselage.OpenVSP_values.surrogate_alpha_normalized = []
    fuselage.OpenVSP_values.surrogate_mach = []   
    fuselage.OpenVSP_values.surrogate_rpm = []
    fuselage.OpenVSP_values.surrogate_rpm_normalized = []
    fuselage.OpenVSP_values.surrogate_cp = []
    fuselage.OpenVSP_values.surrogate_ct = []
    
    fuselage.OpenVSP_values.cl_hs = []
    fuselage.OpenVSP_values.cdi_hs = []
    fuselage.OpenVSP_values.cl_vs = []
    fuselage.OpenVSP_values.cdi_vs = []
    fuselage.OpenVSP_values.cl_main_wing = []
    fuselage.OpenVSP_values.cdi_main_wing = []
    fuselage.OpenVSP_values.cl = []
    fuselage.OpenVSP_values.cdi = []
    
    
    
    ## Sections for fuselage
    
    # Section 1
    
    #body=SUAVE.Components.Lofted_Body
    #body.points=[[0,1,1],[0,-1,-1],[0,1,-1],[0,-1,1]]
    #body.points.append()
    
    
    #fuselage.Section.append(body)
    
    # Section 2
    
    #curve=SUAVE.Components.Lofted_Body.Curve
    #curve.points=[[7,1,1],[7,-1,-1],[7,1,-1],[7,-1,1]]
    
    #section=SUAVE.Components.Lofted_Body
    #section.Curves=curve
    
    #fuselage.Section.append(section)
    
         
    # add to vehicle
    vehicle.append_component(fuselage)

    # ------------------------------------------------------------------
    #  Internal Combustion Propeller
    # ------------------------------------------------------------------    
    
    
    #instantiate internal combustion propeller network
    #internalprop = SUAVE.Components.Energy.Networks.Internal_Combustion_Propeller()
    internalprop = SUAVE.Components.Energy.Networks.Internal_Combustion_Propeller_Lo_Fid()
    internalprop.tag = 'internal_combustion'
    
    # setup
    internalprop.number_of_engines = 2
    internalprop.engine_length     = 1.74 * Units.meter
    internalprop.thrust_angle      = 0.0 * Units.degrees
    internalprop.rated_speed       = 3400.0 * Units['rpm']
    internalprop.rated_power       = 149139.9744 * Units.watts #For Weight Analysis
    internalprop.nacelle_diameter = 0.58
    
    #compute engine areas
    internalprop.areas.wetted      = 1.1*np.pi*internalprop.nacelle_diameter*internalprop.engine_length
    
    
    # ------------------------------------------------------------------
    #   Component 1 - Propeller
    
    # Design the Propeller
    #prop_attributes = SUAVE.Components.Energy.Converters.Propeller()
    #prop_attributes.number_blades       = 2
    #prop_attributes.freestream_velocity = 77.17 * Units['m/s'] # freestream m/s
    #prop_attributes.angular_velocity    = 607.38 * Units['rad/s'] # For 20x10 prop
    #prop_attributes.tip_radius          = 0.89 * Units.meter
    #prop_attributes.hub_radius          = 0.124 * Units.meter
    #prop_attributes.design_Cl           = 1.35
    #prop_attributes.design_altitude     = 2000.0 * Units.meter
    #prop_attributes.design_thrust       = None
    #prop_attributes.design_power        = 74569.9872 * Units.watts  #59600
    #prop_attributes.origin              = [[2.494* Units.meter,1.6* Units.meter,1.077* Units.meter]]
    
    prop_attributes = SUAVE.Components.Energy.Converters.Propeller_Lo_Fid()
    prop_attributes.tip_radius       = 0.89 * Units.meter
    prop_attributes.propulsive_efficiency = 0.9   #0.95
    prop_attributes.origin              = [[2.494* Units.meter,1.6* Units.meter,1.077* Units.meter]]
    prop_attributes.number_blades       = 2
    prop_attributes.freestream_velocity = 77.17 * Units['m/s'] # freestream m/s
    prop_attributes.angular_velocity    = 607.38 * Units['rad/s'] # For 20x10 prop
    #prop_attributes.tip_radius          = 0.89 * Units.meter
    prop_attributes.hub_radius          = 0.124 * Units.meter
    prop_attributes.design_Cl           = 1.35
    prop_attributes.design_altitude     = 2000.0 * Units.meter
    prop_attributes.design_thrust       = None
    prop_attributes.design_power        = 74569.9872 * Units.watts #74569.9872 #59600
    
    prop_attributes.airfoil_geometry    = None
    
    #w=3 
    #h=internalprop.number_of_engines/2
    #Matrix = [[0 for x in range(w)] for y in range(h)]
    
    #Matrix[0][0]=2.486
    #Matrix[0][1]=1.5
    #Matrix[0][2]=0.911
    #Matrix[1][0]=2.486
    #Matrix[1][1]=3.5
    #Matrix[1][2]=0.911
    #Matrix[2][0]=2.486
    #Matrix[2][1]=5.5
    #Matrix[2][2]=0.911
          
    #prop_attributes.position            = Matrix
    
    
    prop_attributes                     = propeller_design(prop_attributes)
    
    #prop = SUAVE.Components.Energy.Converters.Propeller_variable_pitch()
    #prop.prop_attributes = prop_attributes
    internalprop.propeller = prop_attributes 
    
    # ------------------------------------------------------------------
    #   Component 2 - Engine
    
    engine = SUAVE.Components.Energy.Converters.Internal_Combustion_Engine()
    engine.sea_level_power    = 149139.9744 * Units.watts
    engine.flat_rate_altitude = 0. * Units.meter
    engine.speed              = 2400.0 * Units['rpm']  #5800
    engine.power_specific_fuel_consumption     =  0.83454*2.60 #0.83454 #4.19
    
    internalprop.engine = engine
    
    # ------------------------------------------------------------------
    #   Vehicle Definition Complete
    # ------------------------------------------------------------------
    
    # add the energy network to the vehicle
    vehicle.append_component(internalprop)
    
    #print vehicle

    return vehicle

# ----------------------------------------------------------------------
#   Define the Configurations
# ---------------------------------------------------------------------

def configs_setup(vehicle):
    
    # ------------------------------------------------------------------
    #   Initialize Configurations
    # ------------------------------------------------------------------
    configs = SUAVE.Components.Configs.Config.Container()

    base_config = SUAVE.Components.Configs.Config(vehicle)
    base_config.tag = 'base'
    configs.append(base_config)

    # ------------------------------------------------------------------
    #   Cruise Configuration
    # ------------------------------------------------------------------
    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'cruise'
    config.wings['main_wing'].control_surfaces.flap.deflection = 0.0 * Units.deg
    configs.append(config)

    # ------------------------------------------------------------------
    #   Takeoff Configuration
    # ------------------------------------------------------------------
    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'takeoff'
    config.wings['main_wing'].control_surfaces.flap.deflection = 0. * Units.deg
    #config.max_lift_coefficient_factor    = 1.

    configs.append(config)
    
    # ------------------------------------------------------------------
    #   Cutback Configuration
    # ------------------------------------------------------------------
    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'cutback'
    config.wings['main_wing'].control_surfaces.flap.deflection = 0. * Units.deg
    config.max_lift_coefficient_factor    = 1. #0.95

    configs.append(config)    

    # ------------------------------------------------------------------
    #   Landing Configuration
    # ------------------------------------------------------------------

    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'landing'

    config.wings['main_wing'].control_surfaces.flap.deflection = 0. * Units.deg  
    #config.max_lift_coefficient_factor    = 1. #0.95

    configs.append(config)

    # ------------------------------------------------------------------
    #   Short Field Takeoff Configuration
    # ------------------------------------------------------------------ 

    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'short_field_takeoff'
    
    config.wings['main_wing'].control_surfaces.flap.deflection = 30. * Units.deg
    config.max_lift_coefficient_factor    = 1. #0.95
  
    configs.append(config)

    return configs

def simple_sizing(configs):

    base = configs.base
    base.pull_base()

    # zero fuel weight
    base.mass_properties.max_zero_fuel = 0.9 * base.mass_properties.max_takeoff 

    # wing areas
    for wing in base.wings:
        wing.areas.wetted   = 2.0 * wing.areas.reference
        wing.areas.exposed  = 0.8 * wing.areas.wetted
        wing.areas.affected = 0.6 * wing.areas.wetted

    # diff the new data
    base.store_diff()

    # ------------------------------------------------------------------
    #   Landing Configuration
    # ------------------------------------------------------------------
    landing = configs.landing

    # make sure base data is current
    landing.pull_base()

    # landing weight
    landing.mass_properties.landing = 0.85 * base.mass_properties.takeoff

    # diff the new data
    landing.store_diff()

    return

# ----------------------------------------------------------------------
#   Define the Mission
# ----------------------------------------------------------------------

def mission_setup(analyses):

    # ------------------------------------------------------------------
    #   Initialize the Mission
    # ------------------------------------------------------------------
    
    mission = SUAVE.Analyses.Mission.Vary_Cruise.Given_Weight()
    #mission = SUAVE.Analyses.Mission.Sequential_Segments()
    mission.tag = 'the_mission'
    mission.planet      = SUAVE.Attributes.Planets.Earth()
    
    # the cruise tag to vary cruise distance
    mission.cruise_tag = 'cruise'
    #print (analyses.base.weights.vehicle.mass_properties.operating_empty)
    mission.target_landing_weight = analyses.base.weights.vehicle.mass_properties.operating_empty

    #airport
    airport = SUAVE.Attributes.Airports.Airport()
    airport.altitude   =  0.0  * Units.meter
    airport.delta_isa  =  0.0
    airport.atmosphere = SUAVE.Attributes.Atmospheres.Earth.US_Standard_1976()

    mission.airport = airport    

    # unpack Segments module
    Segments = SUAVE.Analyses.Mission.Segments

    # base segment
    base_segment = Segments.Segment()
    base_segment.state.numerics.number_control_points = 8
    base_segment.process.iterate.conditions.stability      = SUAVE.Methods.skip
    base_segment.process.finalize.post_process.stability   = SUAVE.Methods.skip

    # ------------------------------------------------------------------
    #   First Climb Segment: Constant Speed, Constant Rate
    # ------------------------------------------------------------------

    #segment = Segments.Climb.Constant_Speed_Constant_Rate(base_segment)
    #segment.tag = "climb"

    #segment.analyses.extend( analyses.base )
    
    #segment.altitude_start = 0.0   * Units.meter
    #segment.altitude_end   = 2438.4   * Units.meter
    #segment.air_speed      = 37.0 * Units.knots
    #segment.climb_rate     = 2.0 * Units['m/s']
    
    segment = Segments.Climb.Linear_Mach_Constant_Rate(base_segment)
    segment.tag = "climb"

    segment.analyses.extend( analyses.base )
    
    segment.altitude_start = 0.0   * Units.meter
    segment.altitude_end   = 2438.4   * Units.meter
    segment.climb_rate     = 1.0 * Units['m/s']
    segment.mach_start     = 0.065    #0.05
    segment.mach_end       = 0.105        #0.111    #0.1
    #segment.air_speed_start    = 32 *Units.knots
    #segment.air_speed_end   = 65 *Units.knots

    # add to misison
    mission.append_segment(segment)


    # ------------------------------------------------------------------    
    #   Cruise Segment: Constant Speed, Constant Altitude
    # ------------------------------------------------------------------  

    #segment = Segments.Cruise.Constant_Speed_Constant_Altitude(base_segment)
    #segment.tag = "cruise" 

    #segment.analyses.extend( analyses.cruise )
    
    #segment.air_speed  = 80. * Units.knots
    #segment.distance   = 400.0 * Units.nautical_miles
    
    segment = Segments.Cruise.Constant_Mach_Constant_Altitude(base_segment)
    segment.tag = "cruise" 

    segment.analyses.extend( analyses.cruise )
    
    segment.mach  = 0.092                               #0.105  #0.077       #0.099
    segment.distance   = 400.0 * Units.nautical_miles

    # add to mission
    mission.append_segment(segment)


    # ------------------------------------------------------------------
    #   Second Descent Segment: Constant Speed, Constant Rate
    # ------------------------------------------------------------------

    #segment = Segments.Descent.Constant_Speed_Constant_Rate(base_segment)
    #segment.tag = "descent"

    #segment.analyses.extend( analyses.base )
    #analyses.landing.aerodynamics.settings.spoiler_drag_increment = 0.00
    

    #segment.altitude_end = 0.0   * Units.meter
    #segment.air_speed    = 46.0 * Units.knots
    #segment.descent_rate = 1.0 * Units['m/s']
    
    #segment = Segments.Descent.Linear_Mach_Constant_Rate(base_segment)
    #segment.tag = "descent"

    #segment.analyses.extend( analyses.base )
    #analyses.landing.aerodynamics.settings.spoiler_drag_increment = 0.00
    

    #segment.altitude_end = 0.0   * Units.meter
    #segment.descent_rate = 2.0 * Units['m/s']
    #segment.mach_start     = 0.106      #0.094 #0.073     #0.091
    #segment.mach_end       = 0.0701     #0.055

    # add to mission
    #mission.append_segment(segment)


    # ------------------------------------------------------------------
    #   Mission definition complete    
    # ------------------------------------------------------------------

    return mission

def missions_setup(base_mission):

    # the mission container
    missions = SUAVE.Analyses.Mission.Mission.Container()

    # ------------------------------------------------------------------
    #   Base Mission
    # ------------------------------------------------------------------

    missions.base = base_mission

    return missions  

# ----------------------------------------------------------------------
#   Plot Mission
# ----------------------------------------------------------------------

def plot_mission(results,line_style='bo-'):
    """This function plots the results of the mission analysis and saves those results to 
    png files."""
    
    file=open('PlottedResults.txt', 'w+')

    # Plot Flight Conditions 
    plot_flight_conditions(results, line_style)
    
    # Plot Aerodynamic Forces 
    plot_aerodynamic_forces(results, line_style)
    
    # Plot Aerodynamic Coefficients 
    plot_aerodynamic_coefficients(results, line_style)
    
    # Drag Components
    plot_drag_components(results, line_style)
    
    # Plot Altitude, sfc, vehicle weight 
    plot_altitude_sfc_weight(results, line_style)
    
    # Plot Velocities 
    plot_aircraft_velocities(results, line_style)
    
    # Plot propeller conditions
    plot_propeller_conditions(results, line_style)
    
    file.close()
        
    return

if __name__ == '__main__': 
    main()    
    plt.show()
