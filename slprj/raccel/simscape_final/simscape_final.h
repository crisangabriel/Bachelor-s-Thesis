#ifndef RTW_HEADER_simscape_final_h_
#define RTW_HEADER_simscape_final_h_
#ifndef simscape_final_COMMON_INCLUDES_
#define simscape_final_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "simscape_final_types.h"
#include "mwmathutil.h"
#include <stddef.h>
#include "rt_zcfcn.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#define MODEL_NAME simscape_final
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (21) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (2)   
#elif NCSTATES != 2
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T abuqvgw4ua [ 2 ] ; real_T m4cchbruom [ 2 ] ; real_T
cnkqn5cq34 ; real_T komxp1m4wp ; real_T o20komhacz [ 6 ] ; real_T la52j4vcgf
[ 3 ] ; real_T lxbjkrt1na ; real_T lo4k4qjncy ; real_T h0uehzgjjn ; real_T
k0pihcl1dy ; real_T gpis0zvuxp ; real_T o1kbtlj4kh ; real_T hqowogsuxf ;
real_T oh1bjpifcg ; real_T d5gcx4z2ek ; real_T muug30hfrt ; real_T eegmnycxav
; real_T fxy4mvun3n ; int8_T ow25jkzfhv ; boolean_T mwopycrmyl ; boolean_T
avft534bzw ; } B ; typedef struct { real_T dnnn0nu0zb [ 4 ] ; real_T
aoqbzw24yh ; real_T fr1e1xckpl ; real_T fjp44ee5ax ; real_T no4vepxkrz [ 4 ]
; real_T nb12wxexy1 [ 4 ] ; real_T ef10paht5m [ 4 ] ; real_T cosdp1wu4w [ 4 ]
; real_T lvrt4bac12 ; real_T dutnzjrzkf ; real_T j01dz0mnne ; real_T
jsymurmz45 ; real_T eppwlrjdji ; real_T j0laytj34w ; real_T f5vqif0wgf ;
real_T dqvjx3jolm ; real_T bxebon4qnu ; real_T ia3rykgwil ; real_T kwtpxxi2kh
; real_T eetww0o3hn ; real_T h2hkmnje1k ; int64_T cy1425fqxu ; struct { void
* AS ; void * BS ; void * CS ; void * DS ; void * DX_COL ; void * BD_COL ;
void * TMP1 ; void * TMP2 ; void * XTMP ; void * SWITCH_STATUS ; void *
SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ; void * USWLAST ; void *
XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ; void * IDX_SW_CHG ; void
* Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW ; void *
SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } npdjbxplf3 ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } c5zfcz3wqy ; struct { void
* AS ; void * BS ; void * CS ; void * DS ; void * DX_COL ; void * BD_COL ;
void * TMP1 ; void * TMP2 ; void * XTMP ; void * SWITCH_STATUS ; void *
SWITCH_STATUS_INIT ; void * SW_CHG ; void * G_STATE ; void * USWLAST ; void *
XKM12 ; void * XKP12 ; void * XLAST ; void * ULAST ; void * IDX_SW_CHG ; void
* Y_SWITCH ; void * SWITCH_TYPES ; void * IDX_OUT_SW ; void *
SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; } d0znnfktb4 ; struct { void *
LoggedData ; } oztoqsargi ; struct { void * LoggedData [ 3 ] ; } p3sfttpmzm ;
struct { void * LoggedData ; } lmmjbpotji ; struct { void * LoggedData [ 3 ]
; } hkktxe1lpb ; struct { void * LoggedData [ 3 ] ; } dkrsl0kl2e ; int32_T
bisrotwkmc ; int32_T bzwtriiduw ; int32_T h01almjvh0 ; int32_T b020pa3iys ;
uint32_T g50qfbcmcf ; uint32_T bkwsxkusxs ; uint32_T bfivdkhzmt [ 2 ] ;
uint32_T n23urvprlg [ 625 ] ; uint32_T bkas1funiq ; int_T alk0fbzgi4 [ 11 ] ;
struct { int_T PrevIndex ; } i4bhulkutv ; int_T g1wwsnainz [ 11 ] ; int8_T
ous2glk3vz ; uint8_T jme2moc1et ; uint8_T beqq1oqdr3 ; uint8_T kvqfradwlq ;
boolean_T afcgtasyrg ; boolean_T bxgmk1eaw0 ; boolean_T nbbupkxuro ;
boolean_T p4rnq0dwuk ; boolean_T pwk2utciwp ; boolean_T kxrkzyjlww ;
boolean_T ni51rbhl2o ; boolean_T mmrindr4fr ; boolean_T iuyncjvcn5 ;
boolean_T j0d32edslo ; boolean_T kldd00soyg ; boolean_T ewri5fxxq1 ;
boolean_T kbqlsft4jh ; } DW ; typedef struct { real_T egd4eqagru ; real_T
acjhwfjuvh ; } X ; typedef struct { real_T egd4eqagru ; real_T acjhwfjuvh ; }
XDot ; typedef struct { boolean_T egd4eqagru ; boolean_T acjhwfjuvh ; } XDis
; typedef struct { real_T egd4eqagru ; real_T acjhwfjuvh ; } CStateAbsTol ;
typedef struct { real_T egd4eqagru ; real_T acjhwfjuvh ; } CXPtMin ; typedef
struct { real_T egd4eqagru ; real_T acjhwfjuvh ; } CXPtMax ; typedef struct {
ZCSigState g5au2r45a1 ; } PrevZCX ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T ArrayCurrent [ 3111 ] ; real_T
ArrayVoltage [ 183 ] ; real_T Irradiance [ 17 ] ; real_T
RepeatingSequence_rep_seq_y [ 2 ] ; real_T
RepeatingSequence_rep_seq_y_jww4cxb3xy [ 2 ] ; real_T StateSpace_DS_param [ 4
] ; real_T TransferFcn_A ; real_T TransferFcn_C ; real_T FromWs_Time0 [ 2 ] ;
real_T FromWs_Data0 [ 2 ] ; real_T StateSpace_AS_param [ 16 ] ; real_T
StateSpace_BS_param [ 20 ] ; real_T StateSpace_CS_param [ 24 ] ; real_T
StateSpace_DS_param_cz3yopvi0n [ 30 ] ; real_T StateSpace_X0_param [ 4 ] ;
real_T donotdeletethisgain_Gain ; real_T LookUpTable1_bp01Data [ 2 ] ; real_T
uMHzsamples_Amp ; real_T uMHzsamples_Period ; real_T uMHzsamples_Duty ;
real_T uMHzsamples_PhaseDelay ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T LookUpTable1_bp01Data_cnvefmrvbz [ 2 ] ; real_T
donotdeletethisgain_Gain_fvxcttqcfp ; real_T
donotdeletethisgain_Gain_lgq0rbvoze ; real_T TransferFcn1_A ; real_T
TransferFcn1_C ; real_T SwitchCurrents_Value [ 2 ] ; real_T
SwitchCurrents_Value_aynlaxlp3g [ 3 ] ; real_T Constant_Value ; real_T
Constant_Value_ctutefl32y ; real_T eee_Value ; uint32_T
PVVICurves2DLookupTable_maxIndex [ 2 ] ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_simscape_final_GetDWork ( ) ; extern void mr_simscape_final_SetDWork (
const mxArray * ssDW ) ; extern mxArray *
mr_simscape_final_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * simscape_final_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
