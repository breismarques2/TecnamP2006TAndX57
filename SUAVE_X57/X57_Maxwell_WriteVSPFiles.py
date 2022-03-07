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
     
from SUAVE.Methods.Propulsion.electric_motor_sizing import size_from_kv
from SUAVE.Methods.Power.Battery.Sizing import initialize_from_energy_and_power, initialize_from_mass

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
    
    #np.savetxt("Surrogate_Inputs_Alt.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alt, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_Alt_Normalized.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alt_normalized, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_Alpha.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alpha, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_Alpha_Normalized.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_alpha_normalized, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_Mach.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_mach, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_RPM.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_rpm, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_RPM_Normalized.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_rpm_normalized, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_Cp.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_cp, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Inputs_Ct.csv", configs.base.fuselages.fuselage.OpenVSP_values.surrogate_ct, delimiter =", ", fmt = '%.18f')
    
    #np.savetxt("Surrogate_Results_CL_HS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl_hs, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Results_CDi_HS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi_hs, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Results_CL_VS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl_vs, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Results_CDi_VS.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi_vs, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Results_CL_Main_Wing.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl_main_wing, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Results_CDi_Main_Wing.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi_main_wing, delimiter =", ", fmt = '%.18f')    
    #np.savetxt("Surrogate_Results_CL.csv", configs.base.fuselages.fuselage.OpenVSP_values.cl, delimiter =", ", fmt = '%.18f')
    #np.savetxt("Surrogate_Results_CDi.csv", configs.base.fuselages.fuselage.OpenVSP_values.cdi, delimiter =", ", fmt = '%.18f')

    # print weight breakdown
    print_weight_breakdown(configs.base,filename = 'X57_weight_breakdown.dat')
    

    # print engine data into file
    #print_engine_data(configs.base,filename = 'P2006T_engine_data.dat')

    # print parasite drag data into file
    # define reference condition for parasite drag
    ref_condition = Data()
    ref_condition.mach_number =  0.21
    ref_condition.reynolds_number = 7.26e6   
    print_parasite_drag(ref_condition,configs.cruise,analyses,'X57_parasite_drag.dat')

    # print compressibility drag data into file
    #print_compress_drag(configs.cruise,analyses,filename = 'P2006T_compress_drag.dat')

    # print mission breakdown
    print_mission_breakdown(results,filename='X57_mission_breakdown.dat')

    
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
    mission  = mission_setup(configs_analyses, configs)
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
    weights = SUAVE.Analyses.Weights.Weights_General_Aviation_No_Fuel()
    weights.vehicle = vehicle
    analyses.append(weights)

    # ------------------------------------------------------------------
    #  Aerodynamics Analysis
    aerodynamics = SUAVE.Analyses.Aerodynamics.Open_VSP_Analysis_X57_Maxwell()
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
    vehicle.tag = 'X57_Maxwell'    


    # ------------------------------------------------------------------
    #   Vehicle-level Properties
    # ------------------------------------------------------------------    

    # mass properties
    vehicle.mass_properties.max_takeoff   = 1156.66 * Units.kilogram
    vehicle.mass_properties.takeoff       = 1156.66 * Units.kilogram
    vehicle.mass_properties.operating_empty           = 1156.66 * Units.kilogram  
    vehicle.mass_properties.max_zero_fuel             = 1156.66 * Units.kilogram
    vehicle.mass_properties.zero_fuel_center_of_gravity = np.array([[3.356*Units.meter,0.0,0.346*Units.meter]]) #IMPORTANT
    #vehicle.mass_properties.fuel             = 151 * Units.kilogram
    vehicle.mass_properties.cargo                     = 0.  * Units.kilogram   
    
    # design
    vehicle.design_dynamic_pressure = 1976.0 * Units.pascal
    vehicle.design_mach_number = 0.21
    
    # envelope properties
    vehicle.envelope.ultimate_load = 5.7
    vehicle.envelope.limit_load    = 3.8

    # basic parameters
    vehicle.reference_area         = 6.194 * Units['meters**2']  
    vehicle.passengers             = 4
    vehicle.systems.control        = "fully powered" 
    vehicle.systems.accessories    = "medium range"  #For Weight Analysis
    
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

    wing.sweeps.quarter_chord    = 1.226 * Units.deg
    wing.sweeps.leading_edge     = 1.9 * Units.deg
    wing.thickness_to_chord      = 0.14967
    wing.areas.reference         = 6.194 * Units['meters**2']  
    wing.spans.projected         = 9.639 * Units.meter  


    wing.taper                   = 0.7
    wing.chords.root             = 0.756 * Units.meter  
    wing.chords.tip              = wing.chords.root * wing.taper
    wing.chords.mean_aerodynamic = (wing.chords.root*(2.0/3.0)*((1.0+wing.taper+wing.taper**2.0)/(1.0+wing.taper)))

    wing.aspect_ratio            = wing.spans.projected**2. / wing.areas.reference
    
    wing.span_efficiency         = 0.95

    wing.twists.root             = 2.0 * Units.degrees
    wing.twists.tip              = 0.0 * Units.degrees

    wing.origin                  = [[2.85* Units.meter,0,1.077* Units.meter]]
    wing.aerodynamic_center      = [0.189, 0., 1.077]

    wing.vertical                = False
    wing.symmetric               = True
    wing.high_lift               = True

    wing.dynamic_pressure_ratio  = 1.0
    
    
    segment = SUAVE.Components.Wings.Segment()
    
    segment.tag                   = 'root'
    segment.percent_span_location = 0.0
    segment.twist                 = wing.twists.root
    segment.root_chord_percent    = 1.
    segment.dihedral_outboard     = 0. * Units.degrees
    segment.sweeps.quarter_chord  = wing.sweeps.quarter_chord
    segment.thickness_to_chord    = wing.thickness_to_chord
    
    
    #segment airfoil
    
    airfoil = SUAVE.Components.Wings.Airfoils.Airfoil()
    airfoil.coordinate_file       = '/Users/Bruno/Documents/Delft/Courses/2016-2017/Thesis/Code/Airfoils/NASAX57.dat'
    
    segment.append_airfoil(airfoil)
    
    
    wing.Segments.append(segment)
    
    
    segment = SUAVE.Components.Wings.Segment()
    
    segment.tag                   = 'tip'
    segment.percent_span_location = 1.0
    segment.twist                 = wing.twists.tip
    segment.root_chord_percent    = 0.7
    segment.dihedral_outboard     = 0. * Units.degrees
    segment.sweeps.quarter_chord  = wing.sweeps.quarter_chord
    segment.thickness_to_chord    = wing.thickness_to_chord
    
    #segment airfoil
    
    airfoil = SUAVE.Components.Wings.Airfoils.Airfoil()
    airfoil.coordinate_file       = '/Users/Bruno/Documents/Delft/Courses/2016-2017/Thesis/Code/Airfoils/NASAX57.dat'
    
    segment.append_airfoil(airfoil)
    
    wing.Segments.append(segment)
    

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
    batteryprop = SUAVE.Components.Energy.Networks.Lift_Cruise()
    batteryprop.tag = 'propulsor'
    
    # setup
    batteryprop.nacelle_diameter_lift     = 0.162 * Units.meters
    batteryprop.nacelle_diameter_forward  = 0.350 * Units.meters
    batteryprop.engine_length_lift        = 0.735 * Units.meters
    batteryprop.engine_length_forward     = 1.423 * Units.meters
    batteryprop.number_of_engines_lift    = 12
    batteryprop.number_of_engines_forward = 2
    batteryprop.thrust_angle_lift         = 0.0 * Units.degrees
    batteryprop.thrust_angle_forward      = 0.0 * Units.degrees
    batteryprop.rated_speed       = 2400.0 * Units['rpm']  #5800.0
    batteryprop.rated_power       = 79600.0 * Units.watts #For Weight Analysis  #149139.9744
    
    #compute engine areas
    batteryprop.areas.wetted      = batteryprop.number_of_engines_forward*1.1*np.pi*batteryprop.nacelle_diameter_forward*batteryprop.engine_length_forward + batteryprop.number_of_engines_lift*1.1*np.pi*batteryprop.nacelle_diameter_lift*batteryprop.engine_length_lift
    
    
    # Component 1.1 - Cruise ESC 
    esc = SUAVE.Components.Energy.Distributors.Electronic_Speed_Controller()
    esc.efficiency = 0.95 # Gundlach for brushless motors
    batteryprop.esc_forward        = esc
    
    # Component 1.2 - High Lift ESC 
    esc = SUAVE.Components.Energy.Distributors.Electronic_Speed_Controller()
    esc.efficiency = 0.95 # Gundlach for brushless motors
    batteryprop.esc_lift        = esc
    
    # Component 2 - Payload
    payload = SUAVE.Components.Energy.Peripherals.Payload()
    payload.power_draw           = 10. * Units.watts 
    payload.mass_properties.mass = 1.0 * Units.kg
    batteryprop.payload                  = payload
    
    # Component 3 - Avionics
    avionics = SUAVE.Components.Energy.Peripherals.Avionics()
    avionics.power_draw = 20. * Units.watts
    batteryprop.avionics        = avionics 

    # Component 4 - Battery
    bat = SUAVE.Components.Energy.Storages.Batteries.Constant_Mass.Lithium_Ion()
    bat.mass_properties.mass = 390.09 * Units.kg  
    bat.specific_energy      = 180. * Units.Wh/Units.kg
    bat.resistance           = 0.006
    bat.max_voltage          = 500.
    
    initialize_from_mass(bat,bat.mass_properties.mass)
    batteryprop.battery              = bat 
    batteryprop.voltage              = bat.max_voltage   
    
    # Component 5.1 - Cruise Propeller
    prop = SUAVE.Components.Energy.Converters.Propeller() 

    prop.number_blades       = 3.0
    #prop.propulsive_efficiency = 0.95
    prop.freestream_velocity = 60.3504*Units['m/s']    
    prop.angular_velocity    = 1300.  * Units.rpm  
    prop.tip_radius          = 1.524/2.0 * Units.meter
    prop.hub_radius          = 0.214/2.0 * Units.meter
    prop.design_Cl           = 0.8
    prop.design_altitude     = 3657.6 * Units.meter
    prop.design_thrust       = None  
    prop.origin              = [[3.507 * Units.meter , 4.819 * Units.meter, 2.226 * Units.meter]]                 
    prop.symmetry            = True
    prop.design_power        = 60000.0 * Units.watts  #59600
    #prop.airfoil_geometry    = None
    prop                     = propeller_design(prop)    
    batteryprop.propeller            = prop    
    
    # Component 5.2 - High Lift Propeller
    rot = SUAVE.Components.Energy.Converters.Propeller() 

    rot.number_blades       = 5.0
    #rot.propulsive_efficiency = 0.95
    rot.freestream_velocity = 60.3504*Units['m/s']    
    rot.angular_velocity    = 3600.  * Units.rpm  
    rot.tip_radius          = 0.579/2.0 * Units.meter
    rot.hub_radius          = 0.155/2.0 * Units.meter
    rot.design_Cl           = 0.6
    rot.design_altitude     = 3657.6 * Units.meter
    rot.design_thrust       = None  
    rot.origin              = [[3.45 * Units.meter , 0.888 * Units.meter, 2.095 * Units.meter]]                 
    rot.symmetry            = True
    rot.design_power        = 10500.0 * Units.watts  #59600
    rot                     = propeller_design(rot)  
    batteryprop.rotor            = rot
    
    # Component 6.1 - Cruise Motor
    motor_for                          = SUAVE.Components.Energy.Converters.Motor()
    etam                               = 0.95
    v                                  = bat.max_voltage *3/4
    omeg                               = prop.angular_velocity  
    io                                 = 4.0 
    start_kv                           = 1
    end_kv                             = 25
    # do optimization to find kv or just do a linspace then remove all negative values, take smallest one use 0.05 change
    # essentially you are sizing the motor for a particular rpm which is sized for a design tip mach 
    # this reduces the bookkeeping errors     
    possible_kv_vals                   = np.linspace(start_kv,end_kv,(end_kv-start_kv)*20 +1 , endpoint = True) * Units.rpm
    res_kv_vals                        = ((v-omeg/possible_kv_vals)*(1.-etam*v*possible_kv_vals/omeg))/io  
    positive_res_vals                  = np.extract(res_kv_vals > 0 ,res_kv_vals) 
    kv_idx                             = np.where(res_kv_vals == min(positive_res_vals))[0][0]   
    kv                                 = possible_kv_vals[kv_idx]  
    res                                = min(positive_res_vals) 

    motor_for.mass_properties.mass         = 10. * Units.kg
    motor_for.origin                       = prop.origin  
    motor_for.propeller_radius             = prop.tip_radius   
    motor_for.speed_constant               = 0.35 
    motor_for.resistance                   = res
    motor_for.no_load_current              = io 
    motor_for.gear_ratio                   = 1. 
    motor_for.gearbox_efficiency           = 1. # Gear box efficiency     
    batteryprop.motor_forward                          = motor_for
    
    # Component 6.2 - High Lift Motor
    motor_lif                              = SUAVE.Components.Energy.Converters.Motor()
    etam                               = 0.95
    v                                  = bat.max_voltage *3/4
    omeg                               = rot.angular_velocity
    io                                 = 4.0 
    start_kv                           = 1
    end_kv                             = 25
    # do optimization to find kv or just do a linspace then remove all negative values, take smallest one use 0.05 change
    # essentially you are sizing the motor for a particular rpm which is sized for a design tip mach 
    # this reduces the bookkeeping errors     
    possible_kv_vals                   = np.linspace(start_kv,end_kv,(end_kv-start_kv)*20 +1 , endpoint = True) * Units.rpm
    res_kv_vals                        = ((v-omeg/possible_kv_vals)*(1.-etam*v*possible_kv_vals/omeg))/io
    positive_res_vals                  = np.extract(res_kv_vals > 0 ,res_kv_vals) 
    kv_idx                             = np.where(res_kv_vals == min(positive_res_vals))[0][0]   
    kv                                 = possible_kv_vals[kv_idx]  
    res                                = min(positive_res_vals) 

    motor_lif.mass_properties.mass         = 10. * Units.kg
    motor_lif.origin                       = rot.origin  
    motor_lif.propeller_radius             = rot.tip_radius   
    motor_lif.speed_constant               = 0.35 
    motor_lif.resistance                   = res
    motor_lif.no_load_current              = io 
    motor_lif.gear_ratio                   = 1. 
    motor_lif.gearbox_efficiency           = 1. # Gear box efficiency     
    batteryprop.motor_lift                          = motor_lif
     
    
    
    
    # add the energy network to the vehicle
    vehicle.append_component(batteryprop)
    
    
    # ------------------------------------------------------------------
    #   Vehicle Definition Complete
    # ------------------------------------------------------------------
    
    print('SETUP DONE')
    


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
    #config.wings['main_wing'].control_surfaces.flap.deflection = 0.0 * Units.deg
    configs.append(config)

    # ------------------------------------------------------------------
    #   Takeoff Configuration
    # ------------------------------------------------------------------
    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'takeoff'
    #config.wings['main_wing'].control_surfaces.flap.deflection = 0. * Units.deg
    #config.max_lift_coefficient_factor    = 1.

    configs.append(config)
    
    # ------------------------------------------------------------------
    #   Cutback Configuration
    # ------------------------------------------------------------------
    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'cutback'
    #config.wings['main_wing'].control_surfaces.flap.deflection = 0. * Units.deg
    config.max_lift_coefficient_factor    = 1. #0.95

    configs.append(config)    

    # ------------------------------------------------------------------
    #   Landing Configuration
    # ------------------------------------------------------------------

    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'landing'

    #config.wings['main_wing'].control_surfaces.flap.deflection = 0. * Units.deg  
    #config.max_lift_coefficient_factor    = 1. #0.95

    configs.append(config)

    # ------------------------------------------------------------------
    #   Short Field Takeoff Configuration
    # ------------------------------------------------------------------ 

    config = SUAVE.Components.Configs.Config(base_config)
    config.tag = 'short_field_takeoff'
    
    #config.wings['main_wing'].control_surfaces.flap.deflection = 30. * Units.deg
    config.max_lift_coefficient_factor    = 1. #0.95
  
    configs.append(config)

    return configs

def simple_sizing(configs):

    base = configs.base
    base.pull_base()

    # zero fuel weight
    #base.mass_properties.max_zero_fuel = 0.9 * base.mass_properties.max_takeoff 

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
    #landing = configs.landing

    # make sure base data is current
    #landing.pull_base()

    # landing weight
    #landing.mass_properties.landing = 0.85 * base.mass_properties.takeoff

    # diff the new data
    #landing.store_diff()

    return

# ----------------------------------------------------------------------
#   Define the Mission
# ----------------------------------------------------------------------

def mission_setup(analyses, vehicle):

    # ------------------------------------------------------------------
    #   Initialize the Mission
    # ------------------------------------------------------------------
    
    #mission = SUAVE.Analyses.Mission.Vary_Cruise.Given_Battery_Energy()
    mission = SUAVE.Analyses.Mission.Sequential_Segments()
    mission.tag = 'the_mission'
    mission.planet      = SUAVE.Attributes.Planets.Earth()
    
    # the cruise tag to vary cruise distance
    ##mission.cruise_tag = 'cruise'
    #print (analyses.base.weights.vehicle.mass_properties.operating_empty)
    ##mission.target_battery_energy = 100

    #airport
    airport = SUAVE.Attributes.Airports.Airport()
    airport.altitude   =  0.0  * Units.meter
    airport.delta_isa  =  0.0
    airport.atmosphere = SUAVE.Attributes.Atmospheres.Earth.US_Standard_1976()

    mission.airport = airport    

    # unpack Segments module
    Segments = SUAVE.Analyses.Mission.Segments
    
    # all motors segment
    #base_segment = Segments.Segment()   
    #ones_row     = base_segment.state.ones_row
    
    #base_segment.state.unknowns.battery_voltage_under_load   = vehicle.base.propulsors.propulsor.battery.max_voltage * ones_row(1)
    #base_segment.state.unknowns.propeller_power_coefficient  = vehicle.base.propulsors.propulsor.propeller.power_coefficient[0]  * ones_row(1)
    
    #base_segment.process.iterate.unknowns.network            = vehicle.base.propulsors.propulsor.unpack_unknowns
    #base_segment.process.iterate.residuals.network           = vehicle.base.propulsors.propulsor.residuals    
    #base_segment.process.iterate.initials.initialize_battery = SUAVE.Methods.Missions.Segments.Common.Energy.initialize_battery
    #base_segment.process.iterate.conditions.planet_position  = SUAVE.Methods.skip
    #base_segment.state.residuals.network                     = 0. * ones_row(2)  

    base_segment = Segments.Segment()
    ones_row = base_segment.state.ones_row
    base_segment.process.iterate.initials.initialize_battery = SUAVE.Methods.Missions.Segments.Common.Energy.initialize_battery
    base_segment.process.iterate.conditions.planet_position  = SUAVE.Methods.skip
    base_segment.process.iterate.unknowns.network            = vehicle.base.propulsors.propulsor.unpack_unknowns_transition
    base_segment.process.iterate.residuals.network           = vehicle.base.propulsors.propulsor.residuals_transition    
    #base_segment.process.iterate.initials.initialize_battery = SUAVE.Methods.Missions.Segments.Common.Energy.initialize_battery
    base_segment.state.unknowns.propeller_power_coefficient  = vehicle.base.propulsors.propulsor.propeller.power_coefficient[0]  * ones_row(1)
    base_segment.state.unknowns.propeller_power_coefficient_lift  = vehicle.base.propulsors.propulsor.rotor.power_coefficient[0]  * ones_row(1)
    base_segment.state.unknowns.throttle_lift  =  0.9  * ones_row(1)
    #base_segment.state.unknowns.throttle  =  0.9  * ones_row(1)
    base_segment.state.unknowns.battery_voltage_under_load   = vehicle.base.propulsors.propulsor.battery.max_voltage * ones_row(1)
    base_segment.state.residuals.network                     = 0. * ones_row(4)
    
    # base segment
    #base_segment = Segments.Segment()
    base_segment.state.numerics.number_control_points = 8
    base_segment.process.iterate.conditions.stability      = SUAVE.Methods.skip
    base_segment.process.finalize.post_process.stability   = SUAVE.Methods.skip
    
    # ------------------------------------------------------------------
    #   First Climb Segment: Constant Speed, Constant Rate
    # ------------------------------------------------------------------
    
    segment = Segments.Climb.Linear_Mach_Constant_Rate(base_segment)
    segment.tag = "climb"

    segment.analyses.extend( analyses.base )
    
    segment.battery_energy = vehicle.base.propulsors.propulsor.battery.max_energy * 1.
    #segment.state.unknowns.throttle_lift = 0.9 * ones_row(1)
    #segment.state.unknowns.throttle = 0.7 * ones_row(1)
    segment.altitude_start = 0.0   * Units.meter
    segment.altitude_end   = 2438.4   * Units.meter
    segment.climb_rate     = 1.0 * Units['m/s']
    segment.mach_start     = 0.13    #0.05
    segment.mach_end       = 0.197    #0.1
    #segment.state.unknowns.throttle          = 0.15 * ones_row(1)

    # add to misison
    mission.append_segment(segment)
    



    # ------------------------------------------------------------------    
    #   Cruise Segment: Constant Speed, Constant Altitude
    # ------------------------------------------------------------------  
    
    #base_segment = Segments.Segment()
    #ones_row = base_segment.state.ones_row
    #base_segment.process.iterate.initials.initialize_battery = SUAVE.Methods.Missions.Segments.Common.Energy.initialize_battery
    #base_segment.process.iterate.conditions.planet_position  = SUAVE.Methods.skip
    #base_segment.process.iterate.unknowns.network            = vehicle.base.propulsors.propulsor.unpack_unknowns
    #base_segment.process.iterate.residuals.network           = vehicle.base.propulsors.propulsor.residuals    
    #base_segment.process.iterate.initials.initialize_battery = SUAVE.Methods.Missions.Segments.Common.Energy.initialize_battery
    #base_segment.state.unknowns.propeller_power_coefficient  = 0.005 * ones_row(1)
    #base_segment.state.unknowns.battery_voltage_under_load   = vehicle.base.propulsors.propulsor.battery.max_voltage * ones_row(1)
    #base_segment.state.residuals.network                     = 0. * ones_row(2)
    
    ##segment = Segments.Cruise.Constant_Mach_Constant_Altitude(base_segment)
    ##segment.tag = "cruise" 

    ##segment.analyses.extend( analyses.cruise )
    
    #segment.battery_energy = vehicle.base.propulsors.propulsor.battery.max_energy * 1.
    ##segment.mach  =  0.196  #0.196        #0.087       #0.099
    #segment.state.unknowns.throttle_lift = 0.826 * ones_row(1)
    #segment.state.unknowns.throttle = 0.7 * ones_row(1)
    #segment.altitude = 2438.4   * Units.meter
    ##segment.distance   = 200.0 * Units.nautical_miles

    # add to mission
    ##mission.append_segment(segment)


    # ------------------------------------------------------------------
    #   Second Descent Segment: Constant Speed, Constant Rate
    # ------------------------------------------------------------------
    
    #segment = Segments.Descent.Linear_Mach_Constant_Rate(base_segment)
    #segment.tag = "descent"

    #segment.analyses.extend( analyses.base )
    #analyses.landing.aerodynamics.settings.spoiler_drag_increment = 0.00
    
    #segment.state.unknowns.throttle = 0.8 * ones_row(1)
    #segment.altitude_end = 0.0   * Units.meter
    #segment.descent_rate = 2.0 * Units['m/s']
    #segment.mach_start     = 0.073      #0.081     #0.091
    #segment.mach_end       = 0.05      #0.05

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
    plot_lift_cruise_network(results, line_style)
    
    plot_electronic_conditions(results, line_style)
    
    #plot_eMotor_Prop_efficiencies(results, line_style)
    
    file.close()
        
    return

if __name__ == '__main__': 
    main()    
    plt.show()
