#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "simscape_final_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 18
#endif
#ifndef SS_INT64
#define SS_INT64 19
#endif
#else
#include "builtin_typeid_types.h"
#include "simscape_final.h"
#include "simscape_final_capi.h"
#include "simscape_final_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 2 , TARGET_STRING (
"simscape_final/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 0 , TARGET_STRING (
"simscape_final/MATLAB Function/is_active_c5_simscape_final" ) ,
TARGET_STRING ( "is_active_c5_simscape_final" ) , 0 , 1 , 0 , 0 , 0 } , { 2 ,
0 , TARGET_STRING ( "simscape_final/25 kHz PWM Boost/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"simscape_final/Current Measurement1/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"simscape_final/PV Panel1/PVVICurves 2D Lookup Table" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"simscape_final/PV Panel1/Transfer Fcn" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 6 , 0 , TARGET_STRING (
"simscape_final/System Measurements1/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"simscape_final/System Measurements1/Product1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"simscape_final/Voltage Measurement1/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"simscape_final/25 kHz PWM Boost/Repeating Sequence/Output" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 1 , TARGET_STRING (
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/MPPT Controller IncCond Method Buck Converter"
) , TARGET_STRING ( "duty" ) , 0 , 0 , 0 , 0 , 2 } , { 11 , 0 , TARGET_STRING
(
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/MPPT Controller IncCond Method Buck Converter/is_active_c1_simscape_final"
) , TARGET_STRING ( "is_active_c1_simscape_final" ) , 0 , 1 , 0 , 0 , 3 } , {
12 , 0 , TARGET_STRING (
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/MPPT Controller IncCond Method Buck Converter/is_c1_simscape_final"
) , TARGET_STRING ( "is_c1_simscape_final" ) , 0 , 3 , 0 , 0 , 3 } , { 13 , 0
, TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/1 MHz samples" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 14 , 0 , TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 15 , 0 , TARGET_STRING (
"simscape_final/PV Panel1/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING ( ""
) , 1 , 0 , 1 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING ( ""
) , 1 , 0 , 3 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/25 kHz PWM Buck/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
"simscape_final/Mosfet/Ideal Switch/Model/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/25 kHz PWM Buck/Repeating Sequence/Output"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 23 , TARGET_STRING (
"simscape_final/Transfer Fcn1" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 24
, TARGET_STRING ( "simscape_final/Transfer Fcn1" ) , TARGET_STRING ( "C" ) ,
0 , 0 , 0 } , { 25 , TARGET_STRING (
"simscape_final/25 kHz PWM Boost/Repeating Sequence" ) , TARGET_STRING (
"rep_seq_y" ) , 0 , 4 , 0 } , { 26 , TARGET_STRING (
"simscape_final/Current Measurement1/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING (
"simscape_final/PV Panel1/PVVICurves 2D Lookup Table" ) , TARGET_STRING (
"maxIndex" ) , 3 , 1 , 0 } , { 28 , TARGET_STRING (
"simscape_final/PV Panel1/Transfer Fcn" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0
} , { 29 , TARGET_STRING ( "simscape_final/PV Panel1/Transfer Fcn" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 30 , TARGET_STRING (
"simscape_final/Voltage Measurement1/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"simscape_final/25 kHz PWM Boost/Repeating Sequence/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"simscape_final/25 kHz PWM Boost/Repeating Sequence/Look-Up Table1" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 4 , 0 } , { 33 ,
TARGET_STRING ( "simscape_final/D2/Model/eee" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 34 , TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/1 MHz samples" ) ,
TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/1 MHz samples" ) ,
TARGET_STRING ( "Period" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/1 MHz samples" ) ,
TARGET_STRING ( "PulseWidth" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/1 MHz samples" ) ,
TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"simscape_final/Irradiance1/Constant 1000/FromWs" ) , TARGET_STRING ( "Time0"
) , 0 , 1 , 0 } , { 41 , TARGET_STRING (
"simscape_final/Irradiance1/Constant 1000/FromWs" ) , TARGET_STRING ( "Data0"
) , 0 , 1 , 0 } , { 42 , TARGET_STRING (
"simscape_final/PV Panel1/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel2/State-Space" ) , TARGET_STRING (
"DS_param" ) , 0 , 5 , 0 } , { 44 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING (
"AS_param" ) , 0 , 6 , 0 } , { 45 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING (
"BS_param" ) , 0 , 7 , 0 } , { 46 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING (
"CS_param" ) , 0 , 8 , 0 } , { 47 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING (
"DS_param" ) , 0 , 9 , 0 } , { 48 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/State-Space" ) , TARGET_STRING (
"X0_param" ) , 0 , 10 , 0 } , { 49 , TARGET_STRING (
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/25 kHz PWM Buck/Repeating Sequence"
) , TARGET_STRING ( "rep_seq_y" ) , 0 , 4 , 0 } , { 50 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel2/Sources/SwitchCurrents" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 51 , TARGET_STRING (
"simscape_final/powergui/EquivalentModel3/Sources/SwitchCurrents" ) ,
TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 52 , TARGET_STRING (
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/25 kHz PWM Buck/Repeating Sequence/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/25 kHz PWM Buck/Repeating Sequence/Look-Up Table1"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 4 , 0 } , { 0 , ( NULL
) , ( NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1
} ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [
] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 54 , TARGET_STRING (
"ArrayCurrent" ) , 0 , 11 , 0 } , { 55 , TARGET_STRING ( "ArrayVoltage" ) , 0
, 12 , 0 } , { 56 , TARGET_STRING ( "Irradiance" ) , 0 , 13 , 0 } , { 0 , (
NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . eegmnycxav , & rtDW . jme2moc1et
, & rtB . mwopycrmyl , & rtB . hqowogsuxf , & rtB . komxp1m4wp , & rtB .
cnkqn5cq34 , & rtB . d5gcx4z2ek , & rtB . muug30hfrt , & rtB . oh1bjpifcg , &
rtB . lo4k4qjncy , & rtB . fxy4mvun3n , & rtDW . beqq1oqdr3 , & rtDW .
bkas1funiq , & rtB . h0uehzgjjn , & rtB . k0pihcl1dy , & rtB . lxbjkrt1na , &
rtB . abuqvgw4ua [ 0 ] , & rtB . m4cchbruom [ 0 ] , & rtB . o20komhacz [ 0 ]
, & rtB . la52j4vcgf [ 0 ] , & rtB . avft534bzw , & rtB . o1kbtlj4kh , & rtB
. gpis0zvuxp , & rtP . TransferFcn1_A , & rtP . TransferFcn1_C , & rtP .
RepeatingSequence_rep_seq_y [ 0 ] , & rtP .
donotdeletethisgain_Gain_fvxcttqcfp , & rtP .
PVVICurves2DLookupTable_maxIndex [ 0 ] , & rtP . TransferFcn_A , & rtP .
TransferFcn_C , & rtP . donotdeletethisgain_Gain_lgq0rbvoze , & rtP .
Constant_Value , & rtP . LookUpTable1_bp01Data [ 0 ] , & rtP . eee_Value , &
rtP . uMHzsamples_Amp , & rtP . uMHzsamples_Period , & rtP . uMHzsamples_Duty
, & rtP . uMHzsamples_PhaseDelay , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . FromWs_Time0 [ 0 ] , & rtP . FromWs_Data0 [ 0 ]
, & rtP . donotdeletethisgain_Gain , & rtP . StateSpace_DS_param [ 0 ] , &
rtP . StateSpace_AS_param [ 0 ] , & rtP . StateSpace_BS_param [ 0 ] , & rtP .
StateSpace_CS_param [ 0 ] , & rtP . StateSpace_DS_param_cz3yopvi0n [ 0 ] , &
rtP . StateSpace_X0_param [ 0 ] , & rtP .
RepeatingSequence_rep_seq_y_jww4cxb3xy [ 0 ] , & rtP . SwitchCurrents_Value [
0 ] , & rtP . SwitchCurrents_Value_aynlaxlp3g [ 0 ] , & rtP .
Constant_Value_ctutefl32y , & rtP . LookUpTable1_bp01Data_cnvefmrvbz [ 0 ] ,
& rtP . ArrayCurrent [ 0 ] , & rtP . ArrayVoltage [ 0 ] , & rtP . Irradiance
[ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } , { "unsigned char" , "boolean_T" , 0 , 0 , sizeof (
boolean_T ) , ( uint8_T ) SS_BOOLEAN , 0 , 0 , 0 } , { "unsigned int" ,
"uint32_T" , 0 , 0 , sizeof ( uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0
} } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 18 , 2 , 0 } , { rtwCAPI_VECTOR , 20 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 22 , 2 , 0 } , { rtwCAPI_VECTOR , 24 , 2 , 0 } , {
rtwCAPI_VECTOR , 26 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 2 , 1 , 6 , 1 , 3 , 1 , 1 , 2 , 2 , 2 , 4 , 4 , 4 , 5 , 6 , 4 , 6 ,
5 , 4 , 1 , 183 , 17 , 1 , 183 , 1 , 17 } ; static const real_T
rtcapiStoredFloats [ ] = { 1.0E-7 , 0.0 , 1.0 , - 2.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0
} , { ( NULL ) , ( NULL ) , - 1 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 2 ] , (
int8_T ) 1 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 3 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 3 , ( uint8_T ) 0
} } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals ,
23 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 31 ,
rtModelParameters , 3 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2638811857U , 2278787672U , 549373888U , 185719008U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * simscape_final_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void simscape_final_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void simscape_final_host_InitializeDataMapInfo (
simscape_final_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
