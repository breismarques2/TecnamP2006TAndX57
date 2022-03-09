#ifndef  SDAICONFIG_CONTROL_DESIGN_UNITY_ENTITIES_CC
#define  SDAICONFIG_CONTROL_DESIGN_UNITY_ENTITIES_CC

// This file was generated by exp2cxx,
// git commit id: 0.8, build timestamp 03 Nov 2020 03:17.
// You probably don't want to edit it since your modifications
// will be lost if exp2cxx is used to regenerate it.


/** this file is for unity builds, which allow faster compilation
 * with fewer translation units. not compatible with all compilers!
 */

#include "schema.h"
#include "SdaiCONFIG_CONTROL_DESIGN_unity_entities.h"
#include "entity/SdaiDocument_usage_constraint.cc"
#include "entity/SdaiRepresentation.cc"
#include "entity/SdaiShape_representation.cc"
#include "entity/SdaiFaceted_brep_shape_representation.cc"
#include "entity/SdaiFounded_item.cc"
#include "entity/SdaiComposite_curve_segment.cc"
#include "entity/SdaiReparametrised_composite_curve_segment.cc"
#include "entity/SdaiRepresentation_item.cc"
#include "entity/SdaiGeometric_representation_item.cc"
#include "entity/SdaiPlacement.cc"
#include "entity/SdaiAxis1_placement.cc"
#include "entity/SdaiCurve.cc"
#include "entity/SdaiBounded_curve.cc"
#include "entity/SdaiB_spline_curve.cc"
#include "entity/SdaiBezier_curve.cc"
#include "entity/SdaiRepresentation_relationship.cc"
#include "entity/SdaiShape_representation_relationship.cc"
#include "entity/SdaiDate_and_time.cc"
#include "entity/SdaiProduct_definition_formation.cc"
#include "entity/SdaiProduct_definition_formation_with_specified_source.cc"
#include "entity/SdaiSurface.cc"
#include "entity/SdaiSurface_replica.cc"
#include "entity/SdaiDocument.cc"
#include "entity/SdaiDocument_with_class.cc"
#include "entity/SdaiAssembly_component_usage_substitute.cc"
#include "entity/SdaiItem_defined_transformation.cc"
#include "entity/SdaiSolid_model.cc"
#include "entity/SdaiManifold_solid_brep.cc"
#include "entity/SdaiFaceted_brep.cc"
#include "entity/SdaiNamed_unit.cc"
#include "entity/SdaiMass_unit.cc"
#include "entity/SdaiSolid_angle_unit.cc"
#include "entity/SdaiBounded_surface.cc"
#include "entity/SdaiRectangular_composite_surface.cc"
#include "entity/SdaiPerson_and_organization_role.cc"
#include "entity/SdaiElementary_surface.cc"
#include "entity/SdaiToroidal_surface.cc"
#include "entity/SdaiAction_status.cc"
#include "entity/SdaiApproval_role.cc"
#include "entity/SdaiOrganization_relationship.cc"
#include "entity/SdaiComposite_curve.cc"
#include "entity/SdaiB_spline_curve_with_knots.cc"
#include "entity/SdaiRepresentation_context.cc"
#include "entity/SdaiGlobal_unit_assigned_context.cc"
#include "entity/SdaiAddress.cc"
#include "entity/SdaiOrganizational_address.cc"
#include "entity/SdaiPersonal_address.cc"
#include "entity/SdaiShape_aspect_relationship.cc"
#include "entity/SdaiAdvanced_brep_shape_representation.cc"
#include "entity/SdaiTopological_representation_item.cc"
#include "entity/SdaiFace.cc"
#include "entity/SdaiFace_surface.cc"
#include "entity/SdaiProperty_definition_representation.cc"
#include "entity/SdaiSecurity_classification_level.cc"
#include "entity/SdaiB_spline_surface.cc"
#include "entity/SdaiB_spline_surface_with_knots.cc"
#include "entity/SdaiComposite_curve_on_surface.cc"
#include "entity/SdaiBoundary_curve.cc"
#include "entity/SdaiOuter_boundary_curve.cc"
#include "entity/SdaiParametric_representation_context.cc"
#include "entity/SdaiSurface_patch.cc"
#include "entity/SdaiAction_request_status.cc"
#include "entity/SdaiMeasure_with_unit.cc"
#include "entity/SdaiArea_measure_with_unit.cc"
#include "entity/SdaiPerson.cc"
#include "entity/SdaiQuasi_uniform_surface.cc"
#include "entity/SdaiEdge.cc"
#include "entity/SdaiOriented_edge.cc"
#include "entity/SdaiFunctionally_defined_transformation.cc"
#include "entity/SdaiCartesian_transformation_operator.cc"
#include "entity/SdaiCartesian_transformation_operator_3d.cc"
#include "entity/SdaiAction_request_assignment.cc"
#include "entity/SdaiChange_request.cc"
#include "entity/SdaiPoint.cc"
#include "entity/SdaiDegenerate_pcurve.cc"
#include "entity/SdaiDate_and_time_assignment.cc"
#include "entity/SdaiCc_design_date_and_time_assignment.cc"
#include "entity/SdaiApproval_relationship.cc"
#include "entity/SdaiGeometric_set.cc"
#include "entity/SdaiUniform_surface.cc"
#include "entity/SdaiCertification.cc"
#include "entity/SdaiEdge_based_wireframe_model.cc"
#include "entity/SdaiSurface_curve.cc"
#include "entity/SdaiBounded_surface_curve.cc"
#include "entity/SdaiConic.cc"
#include "entity/SdaiHyperbola.cc"
#include "entity/SdaiProperty_definition.cc"
#include "entity/SdaiDegenerate_toroidal_surface.cc"
#include "entity/SdaiProduct_definition.cc"
#include "entity/SdaiProduct_definition_with_associated_documents.cc"
#include "entity/SdaiPath.cc"
#include "entity/SdaiAction_assignment.cc"
#include "entity/SdaiStart_work.cc"
#include "entity/SdaiApproval.cc"
#include "entity/SdaiLoop.cc"
#include "entity/SdaiPoly_loop.cc"
#include "entity/SdaiPoint_on_surface.cc"
#include "entity/SdaiProduct_concept.cc"
#include "entity/SdaiRational_b_spline_curve.cc"
#include "entity/SdaiStart_request.cc"
#include "entity/SdaiEdge_based_wireframe_shape_representation.cc"
#include "entity/SdaiPolyline.cc"
#include "entity/SdaiSpherical_surface.cc"
#include "entity/SdaiContract_assignment.cc"
#include "entity/SdaiCc_design_contract.cc"
#include "entity/SdaiConfiguration_item.cc"
#include "entity/SdaiDate.cc"
#include "entity/SdaiWeek_of_year_and_day_date.cc"
#include "entity/SdaiEffectivity.cc"
#include "entity/SdaiLot_effectivity.cc"
#include "entity/SdaiApplication_context_element.cc"
#include "entity/SdaiShape_definition_representation.cc"
#include "entity/SdaiConnected_face_set.cc"
#include "entity/SdaiClosed_shell.cc"
#include "entity/SdaiApplication_protocol_definition.cc"
#include "entity/SdaiProduct_category.cc"
#include "entity/SdaiProduct_related_product_category.cc"
#include "entity/SdaiAction_method.cc"
#include "entity/SdaiProduct_definition_shape.cc"
#include "entity/SdaiSeam_curve.cc"
#include "entity/SdaiConfiguration_design.cc"
#include "entity/SdaiContext_dependent_unit.cc"
#include "entity/SdaiAction.cc"
#include "entity/SdaiExecuted_action.cc"
#include "entity/SdaiProduct_definition_relationship.cc"
#include "entity/SdaiProduct_definition_usage.cc"
#include "entity/SdaiAssembly_component_usage.cc"
#include "entity/SdaiSpecified_higher_usage_occurrence.cc"
#include "entity/SdaiMapped_item.cc"
#include "entity/SdaiApproval_assignment.cc"
#include "entity/SdaiCc_design_approval.cc"
#include "entity/SdaiProduct_definition_context.cc"
#include "entity/SdaiDesign_context.cc"
#include "entity/SdaiSwept_surface.cc"
#include "entity/SdaiSurface_of_revolution.cc"
#include "entity/SdaiVector.cc"
#include "entity/SdaiSolid_angle_measure_with_unit.cc"
#include "entity/SdaiPerson_and_organization_assignment.cc"
#include "entity/SdaiTrimmed_curve.cc"
#include "entity/SdaiVertex.cc"
#include "entity/SdaiQuantified_assembly_component_usage.cc"
#include "entity/SdaiProduct_category_relationship.cc"
#include "entity/SdaiOrganization.cc"
#include "entity/SdaiCartesian_point.cc"
#include "entity/SdaiEllipse.cc"
#include "entity/SdaiGlobal_uncertainty_assigned_context.cc"
#include "entity/SdaiEvaluated_degenerate_pcurve.cc"
#include "entity/SdaiGeometrically_bounded_wireframe_shape_representation.cc"
#include "entity/SdaiPlane_angle_unit.cc"
#include "entity/SdaiShell_based_wireframe_model.cc"
#include "entity/SdaiApplication_context.cc"
#include "entity/SdaiOpen_shell.cc"
#include "entity/SdaiAxis2_placement_3d.cc"
#include "entity/SdaiSecurity_classification_assignment.cc"
#include "entity/SdaiCc_design_security_classification.cc"
#include "entity/SdaiCurve_replica.cc"
#include "entity/SdaiVertex_loop.cc"
#include "entity/SdaiCalendar_date.cc"
#include "entity/SdaiEdge_loop.cc"
#include "entity/SdaiOriented_closed_shell.cc"
#include "entity/SdaiDesign_make_from_relationship.cc"
#include "entity/SdaiShell_based_surface_model.cc"
#include "entity/SdaiFace_bound.cc"
#include "entity/SdaiRepresentation_relationship_with_transformation.cc"
#include "entity/SdaiOriented_face.cc"
#include "entity/SdaiContract_type.cc"
#include "entity/SdaiPcurve.cc"
#include "entity/SdaiBounded_pcurve.cc"
#include "entity/SdaiCertification_assignment.cc"
#include "entity/SdaiCc_design_certification.cc"
#include "entity/SdaiPlane.cc"
#include "entity/SdaiChange.cc"
#include "entity/SdaiCircle.cc"
#include "entity/SdaiLine.cc"
#include "entity/SdaiContract.cc"
#include "entity/SdaiProduct_definition_effectivity.cc"
#include "entity/SdaiConfiguration_effectivity.cc"
#include "entity/SdaiProduct.cc"
#include "entity/SdaiDocument_relationship.cc"
#include "entity/SdaiVersioned_action_request.cc"
#include "entity/SdaiFace_outer_bound.cc"
#include "entity/SdaiOrganizational_project.cc"
#include "entity/SdaiOrdinal_date.cc"
#include "entity/SdaiRectangular_trimmed_surface.cc"
#include "entity/SdaiCc_design_person_and_organization_assignment.cc"
#include "entity/SdaiDefinitional_representation.cc"
#include "entity/SdaiApproval_person_organization.cc"
#include "entity/SdaiCurve_bounded_surface.cc"
#include "entity/SdaiParabola.cc"
#include "entity/SdaiQuasi_uniform_curve.cc"
#include "entity/SdaiUncertainty_measure_with_unit.cc"
#include "entity/SdaiUniform_curve.cc"
#include "entity/SdaiGeometric_curve_set.cc"
#include "entity/SdaiLength_unit.cc"
#include "entity/SdaiLength_measure_with_unit.cc"
#include "entity/SdaiProduct_concept_context.cc"
#include "entity/SdaiRational_b_spline_surface.cc"
#include "entity/SdaiLocal_time.cc"
#include "entity/SdaiNext_assembly_usage_occurrence.cc"
#include "entity/SdaiConversion_based_unit.cc"
#include "entity/SdaiVertex_point.cc"
#include "entity/SdaiDimensional_exponents.cc"
#include "entity/SdaiProduct_context.cc"
#include "entity/SdaiOffset_surface.cc"
#include "entity/SdaiContext_dependent_shape_representation.cc"
#include "entity/SdaiGeometric_representation_context.cc"
#include "entity/SdaiMass_measure_with_unit.cc"
#include "entity/SdaiSi_unit.cc"
#include "entity/SdaiDocument_reference.cc"
#include "entity/SdaiVertex_shell.cc"
#include "entity/SdaiPromissory_usage_occurrence.cc"
#include "entity/SdaiPlane_angle_measure_with_unit.cc"
#include "entity/SdaiShape_aspect.cc"
#include "entity/SdaiVolume_measure_with_unit.cc"
#include "entity/SdaiAction_request_solution.cc"
#include "entity/SdaiAxis2_placement_2d.cc"
#include "entity/SdaiDirected_action.cc"
#include "entity/SdaiManifold_surface_shape_representation.cc"
#include "entity/SdaiGeometrically_bounded_surface_shape_representation.cc"
#include "entity/SdaiPoint_replica.cc"
#include "entity/SdaiCc_design_specification_reference.cc"
#include "entity/SdaiCoordinated_universal_time_offset.cc"
#include "entity/SdaiDirection.cc"
#include "entity/SdaiApproval_status.cc"
#include "entity/SdaiOriented_path.cc"
#include "entity/SdaiRepresentation_map.cc"
#include "entity/SdaiDated_effectivity.cc"
#include "entity/SdaiVolume_unit.cc"
#include "entity/SdaiBezier_surface.cc"
#include "entity/SdaiCylindrical_surface.cc"
#include "entity/SdaiPerson_and_organization.cc"
#include "entity/SdaiBrep_with_voids.cc"
#include "entity/SdaiConnected_edge_set.cc"
#include "entity/SdaiAlternate_product_relationship.cc"
#include "entity/SdaiSurface_of_linear_extrusion.cc"
#include "entity/SdaiSecurity_classification.cc"
#include "entity/SdaiCertification_type.cc"
#include "entity/SdaiApproval_date_time.cc"
#include "entity/SdaiPoint_on_curve.cc"
#include "entity/SdaiIntersection_curve.cc"
#include "entity/SdaiAction_directive.cc"
#include "entity/SdaiOffset_curve_3d.cc"
#include "entity/SdaiArea_unit.cc"
#include "entity/SdaiOriented_open_shell.cc"
#include "entity/SdaiShell_based_wireframe_shape_representation.cc"
#include "entity/SdaiAdvanced_face.cc"
#include "entity/SdaiDate_time_role.cc"
#include "entity/SdaiDocument_type.cc"
#include "entity/SdaiSupplied_part_relationship.cc"
#include "entity/SdaiConical_surface.cc"
#include "entity/SdaiEdge_curve.cc"
#include "entity/SdaiSerial_numbered_effectivity.cc"
#include "entity/SdaiWire_shell.cc"
#include "entity/SdaiMechanical_context.cc"
#endif