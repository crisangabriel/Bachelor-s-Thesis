#include "simscape_final.h"
#include "rtwtypes.h"
#include <string.h>
#include "mwmathutil.h"
#include <float.h>
#include "simscape_final_private.h"
#include "rt_logging_mmi.h"
#include "simscape_final_capi.h"
#include "zero_crossing_types.h"
#include "simscape_final_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "9.9 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes
( SimStruct * S , const char * inportFileName , int * matFileFormat ) {
return rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define dkp5okdpd4 ((uint8_T)0U)
#define gvvs4ef133 (3U)
#define i1ltibpkac (5U)
#define igvywyqxhz (2U)
#define jghipa04qx (4U)
#define k0kqspzzug (1U)
#define lgnpfxrcb0 (-1)
#define nks1fjs4s3 (0)
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; static real_T i203t0ykso ( void ) ;
real_T look2_binlxpw ( real_T u0 , real_T u1 , const real_T bp0 [ ] , const
real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex [ ] ,
uint32_T stride ) { real_T fractions [ 2 ] ; real_T frac ; real_T yL_0d0 ;
real_T yL_0d1 ; uint32_T bpIndices [ 2 ] ; uint32_T bpIdx ; uint32_T iLeft ;
uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex [ 0U ]
] ) { bpIdx = maxIndex [ 0U ] >> 1U ; iLeft = 0U ; iRght = maxIndex [ 0U ] ;
while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; }
else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 -
bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft =
maxIndex [ 0U ] - 1U ; frac = ( u0 - bp0 [ maxIndex [ 0U ] - 1U ] ) / ( bp0 [
maxIndex [ 0U ] ] - bp0 [ maxIndex [ 0U ] - 1U ] ) ; } fractions [ 0U ] =
frac ; bpIndices [ 0U ] = iLeft ; if ( u1 <= bp1 [ 0U ] ) { iLeft = 0U ; frac
= ( u1 - bp1 [ 0U ] ) / ( bp1 [ 1U ] - bp1 [ 0U ] ) ; } else if ( u1 < bp1 [
maxIndex [ 1U ] ] ) { bpIdx = maxIndex [ 1U ] >> 1U ; iLeft = 0U ; iRght =
maxIndex [ 1U ] ; while ( iRght - iLeft > 1U ) { if ( u1 < bp1 [ bpIdx ] ) {
iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ;
} frac = ( u1 - bp1 [ iLeft ] ) / ( bp1 [ iLeft + 1U ] - bp1 [ iLeft ] ) ; }
else { iLeft = maxIndex [ 1U ] - 1U ; frac = ( u1 - bp1 [ maxIndex [ 1U ] -
1U ] ) / ( bp1 [ maxIndex [ 1U ] ] - bp1 [ maxIndex [ 1U ] - 1U ] ) ; } bpIdx
= iLeft * stride + bpIndices [ 0U ] ; yL_0d0 = table [ bpIdx ] ; yL_0d0 += (
table [ bpIdx + 1U ] - yL_0d0 ) * fractions [ 0U ] ; bpIdx += stride ; yL_0d1
= table [ bpIdx ] ; return ( ( ( table [ bpIdx + 1U ] - yL_0d1 ) * fractions
[ 0U ] + yL_0d1 ) - yL_0d0 ) * frac + yL_0d0 ; } real_T look1_binlxpw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex
) { real_T frac ; real_T yL_0d0 ; uint32_T bpIdx ; uint32_T iLeft ; uint32_T
iRght ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / (
bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx =
maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U )
{ if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; }
bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [
iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = ( u0
- bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; }
yL_0d0 = table [ iLeft ] ; return ( table [ iLeft + 1U ] - yL_0d0 ) * frac +
yL_0d0 ; } static real_T i203t0ykso ( void ) { real_T r ; int32_T hi ;
int32_T kk ; uint32_T u [ 2 ] ; uint32_T mti ; uint32_T y ; if ( rtDW .
g50qfbcmcf == 4U ) { hi = ( int32_T ) ( rtDW . bkwsxkusxs / 127773U ) ; mti =
( rtDW . bkwsxkusxs - ( uint32_T ) hi * 127773U ) * 16807U ; y = 2836U * (
uint32_T ) hi ; if ( mti < y ) { mti = ~ ( y - mti ) & 2147483647U ; } else {
mti -= y ; } r = ( real_T ) mti * 4.6566128752457969E-10 ; rtDW . bkwsxkusxs
= mti ; } else if ( rtDW . g50qfbcmcf == 5U ) { mti = 69069U * rtDW .
bfivdkhzmt [ 0 ] + 1234567U ; y = rtDW . bfivdkhzmt [ 1 ] << 13 ^ rtDW .
bfivdkhzmt [ 1 ] ; y ^= y >> 17 ; y ^= y << 5 ; rtDW . bfivdkhzmt [ 0 ] = mti
; rtDW . bfivdkhzmt [ 1 ] = y ; r = ( real_T ) ( mti + y ) *
2.328306436538696E-10 ; } else { do { for ( hi = 0 ; hi < 2 ; hi ++ ) { mti =
rtDW . n23urvprlg [ 624 ] + 1U ; if ( rtDW . n23urvprlg [ 624 ] + 1U >= 625U
) { for ( kk = 0 ; kk < 227 ; kk ++ ) { mti = ( rtDW . n23urvprlg [ kk + 1 ]
& 2147483647U ) | ( rtDW . n23urvprlg [ kk ] & 2147483648U ) ; if ( ( mti &
1U ) == 0U ) { mti >>= 1U ; } else { mti = mti >> 1U ^ 2567483615U ; } rtDW .
n23urvprlg [ kk ] = rtDW . n23urvprlg [ kk + 397 ] ^ mti ; } for ( kk = 0 ;
kk < 396 ; kk ++ ) { mti = ( rtDW . n23urvprlg [ kk + 227 ] & 2147483648U ) |
( rtDW . n23urvprlg [ kk + 228 ] & 2147483647U ) ; if ( ( mti & 1U ) == 0U )
{ mti >>= 1U ; } else { mti = mti >> 1U ^ 2567483615U ; } rtDW . n23urvprlg [
kk + 227 ] = rtDW . n23urvprlg [ kk ] ^ mti ; } mti = ( rtDW . n23urvprlg [
623 ] & 2147483648U ) | ( rtDW . n23urvprlg [ 0 ] & 2147483647U ) ; if ( (
mti & 1U ) == 0U ) { mti >>= 1U ; } else { mti = mti >> 1U ^ 2567483615U ; }
rtDW . n23urvprlg [ 623 ] = rtDW . n23urvprlg [ 396 ] ^ mti ; mti = 1U ; } y
= rtDW . n23urvprlg [ ( int32_T ) mti - 1 ] ; rtDW . n23urvprlg [ 624 ] = mti
; y ^= y >> 11U ; y ^= y << 7U & 2636928640U ; y ^= y << 15U & 4022730752U ;
u [ hi ] = y >> 18U ^ y ; } r = ( ( real_T ) ( u [ 0 ] >> 5U ) * 6.7108864E+7
+ ( real_T ) ( u [ 1 ] >> 6U ) ) * 1.1102230246251565E-16 ; } while ( r ==
0.0 ) ; } return r ; } void MdlInitialize ( void ) { static const uint32_T
tmp [ 625 ] = { 5489U , 1301868182U , 2938499221U , 2950281878U , 1875628136U
, 751856242U , 944701696U , 2243192071U , 694061057U , 219885934U ,
2066767472U , 3182869408U , 485472502U , 2336857883U , 1071588843U ,
3418470598U , 951210697U , 3693558366U , 2923482051U , 1793174584U ,
2982310801U , 1586906132U , 1951078751U , 1808158765U , 1733897588U ,
431328322U , 4202539044U , 530658942U , 1714810322U , 3025256284U ,
3342585396U , 1937033938U , 2640572511U , 1654299090U , 3692403553U ,
4233871309U , 3497650794U , 862629010U , 2943236032U , 2426458545U ,
1603307207U , 1133453895U , 3099196360U , 2208657629U , 2747653927U ,
931059398U , 761573964U , 3157853227U , 785880413U , 730313442U , 124945756U
, 2937117055U , 3295982469U , 1724353043U , 3021675344U , 3884886417U ,
4010150098U , 4056961966U , 699635835U , 2681338818U , 1339167484U ,
720757518U , 2800161476U , 2376097373U , 1532957371U , 3902664099U ,
1238982754U , 3725394514U , 3449176889U , 3570962471U , 4287636090U ,
4087307012U , 3603343627U , 202242161U , 2995682783U , 1620962684U ,
3704723357U , 371613603U , 2814834333U , 2111005706U , 624778151U ,
2094172212U , 4284947003U , 1211977835U , 991917094U , 1570449747U ,
2962370480U , 1259410321U , 170182696U , 146300961U , 2836829791U ,
619452428U , 2723670296U , 1881399711U , 1161269684U , 1675188680U ,
4132175277U , 780088327U , 3409462821U , 1036518241U , 1834958505U ,
3048448173U , 161811569U , 618488316U , 44795092U , 3918322701U , 1924681712U
, 3239478144U , 383254043U , 4042306580U , 2146983041U , 3992780527U ,
3518029708U , 3545545436U , 3901231469U , 1896136409U , 2028528556U ,
2339662006U , 501326714U , 2060962201U , 2502746480U , 561575027U ,
581893337U , 3393774360U , 1778912547U , 3626131687U , 2175155826U ,
319853231U , 986875531U , 819755096U , 2915734330U , 2688355739U ,
3482074849U , 2736559U , 2296975761U , 1029741190U , 2876812646U , 690154749U
, 579200347U , 4027461746U , 1285330465U , 2701024045U , 4117700889U ,
759495121U , 3332270341U , 2313004527U , 2277067795U , 4131855432U ,
2722057515U , 1264804546U , 3848622725U , 2211267957U , 4100593547U ,
959123777U , 2130745407U , 3194437393U , 486673947U , 1377371204U , 17472727U
, 352317554U , 3955548058U , 159652094U , 1232063192U , 3835177280U ,
49423123U , 3083993636U , 733092U , 2120519771U , 2573409834U , 1112952433U ,
3239502554U , 761045320U , 1087580692U , 2540165110U , 641058802U ,
1792435497U , 2261799288U , 1579184083U , 627146892U , 2165744623U ,
2200142389U , 2167590760U , 2381418376U , 1793358889U , 3081659520U ,
1663384067U , 2009658756U , 2689600308U , 739136266U , 2304581039U ,
3529067263U , 591360555U , 525209271U , 3131882996U , 294230224U ,
2076220115U , 3113580446U , 1245621585U , 1386885462U , 3203270426U ,
123512128U , 12350217U , 354956375U , 4282398238U , 3356876605U , 3888857667U
, 157639694U , 2616064085U , 1563068963U , 2762125883U , 4045394511U ,
4180452559U , 3294769488U , 1684529556U , 1002945951U , 3181438866U ,
22506664U , 691783457U , 2685221343U , 171579916U , 3878728600U , 2475806724U
, 2030324028U , 3331164912U , 1708711359U , 1970023127U , 2859691344U ,
2588476477U , 2748146879U , 136111222U , 2967685492U , 909517429U ,
2835297809U , 3206906216U , 3186870716U , 341264097U , 2542035121U ,
3353277068U , 548223577U , 3170936588U , 1678403446U , 297435620U ,
2337555430U , 466603495U , 1132321815U , 1208589219U , 696392160U ,
894244439U , 2562678859U , 470224582U , 3306867480U , 201364898U ,
2075966438U , 1767227936U , 2929737987U , 3674877796U , 2654196643U ,
3692734598U , 3528895099U , 2796780123U , 3048728353U , 842329300U ,
191554730U , 2922459673U , 3489020079U , 3979110629U , 1022523848U ,
2202932467U , 3583655201U , 3565113719U , 587085778U , 4176046313U ,
3013713762U , 950944241U , 396426791U , 3784844662U , 3477431613U ,
3594592395U , 2782043838U , 3392093507U , 3106564952U , 2829419931U ,
1358665591U , 2206918825U , 3170783123U , 31522386U , 2988194168U ,
1782249537U , 1105080928U , 843500134U , 1225290080U , 1521001832U ,
3605886097U , 2802786495U , 2728923319U , 3996284304U , 903417639U ,
1171249804U , 1020374987U , 2824535874U , 423621996U , 1988534473U ,
2493544470U , 1008604435U , 1756003503U , 1488867287U , 1386808992U ,
732088248U , 1780630732U , 2482101014U , 976561178U , 1543448953U ,
2602866064U , 2021139923U , 1952599828U , 2360242564U , 2117959962U ,
2753061860U , 2388623612U , 4138193781U , 2962920654U , 2284970429U ,
766920861U , 3457264692U , 2879611383U , 815055854U , 2332929068U ,
1254853997U , 3740375268U , 3799380844U , 4091048725U , 2006331129U ,
1982546212U , 686850534U , 1907447564U , 2682801776U , 2780821066U ,
998290361U , 1342433871U , 4195430425U , 607905174U , 3902331779U ,
2454067926U , 1708133115U , 1170874362U , 2008609376U , 3260320415U ,
2211196135U , 433538229U , 2728786374U , 2189520818U , 262554063U ,
1182318347U , 3710237267U , 1221022450U , 715966018U , 2417068910U ,
2591870721U , 2870691989U , 3418190842U , 4238214053U , 1540704231U ,
1575580968U , 2095917976U , 4078310857U , 2313532447U , 2110690783U ,
4056346629U , 4061784526U , 1123218514U , 551538993U , 597148360U ,
4120175196U , 3581618160U , 3181170517U , 422862282U , 3227524138U ,
1713114790U , 662317149U , 1230418732U , 928171837U , 1324564878U ,
1928816105U , 1786535431U , 2878099422U , 3290185549U , 539474248U ,
1657512683U , 552370646U , 1671741683U , 3655312128U , 1552739510U ,
2605208763U , 1441755014U , 181878989U , 3124053868U , 1447103986U ,
3183906156U , 1728556020U , 3502241336U , 3055466967U , 1013272474U ,
818402132U , 1715099063U , 2900113506U , 397254517U , 4194863039U ,
1009068739U , 232864647U , 2540223708U , 2608288560U , 2415367765U ,
478404847U , 3455100648U , 3182600021U , 2115988978U , 434269567U ,
4117179324U , 3461774077U , 887256537U , 3545801025U , 286388911U ,
3451742129U , 1981164769U , 786667016U , 3310123729U , 3097811076U ,
2224235657U , 2959658883U , 3370969234U , 2514770915U , 3345656436U ,
2677010851U , 2206236470U , 271648054U , 2342188545U , 4292848611U ,
3646533909U , 3754009956U , 3803931226U , 4160647125U , 1477814055U ,
4043852216U , 1876372354U , 3133294443U , 3871104810U , 3177020907U ,
2074304428U , 3479393793U , 759562891U , 164128153U , 1839069216U ,
2114162633U , 3989947309U , 3611054956U , 1333547922U , 835429831U ,
494987340U , 171987910U , 1252001001U , 370809172U , 3508925425U ,
2535703112U , 1276855041U , 1922855120U , 835673414U , 3030664304U ,
613287117U , 171219893U , 3423096126U , 3376881639U , 2287770315U ,
1658692645U , 1262815245U , 3957234326U , 1168096164U , 2968737525U ,
2655813712U , 2132313144U , 3976047964U , 326516571U , 353088456U ,
3679188938U , 3205649712U , 2654036126U , 1249024881U , 880166166U ,
691800469U , 2229503665U , 1673458056U , 4032208375U , 1851778863U ,
2563757330U , 376742205U , 1794655231U , 340247333U , 1505873033U ,
396524441U , 879666767U , 3335579166U , 3260764261U , 3335999539U ,
506221798U , 4214658741U , 975887814U , 2080536343U , 3360539560U ,
571586418U , 138896374U , 4234352651U , 2737620262U , 3928362291U ,
1516365296U , 38056726U , 3599462320U , 3585007266U , 3850961033U ,
471667319U , 1536883193U , 2310166751U , 1861637689U , 2530999841U ,
4139843801U , 2710569485U , 827578615U , 2012334720U , 2907369459U ,
3029312804U , 2820112398U , 1965028045U , 35518606U , 2478379033U ,
643747771U , 1924139484U , 4123405127U , 3811735531U , 3429660832U ,
3285177704U , 1948416081U , 1311525291U , 1183517742U , 1739192232U ,
3979815115U , 2567840007U , 4116821529U , 213304419U , 4125718577U ,
1473064925U , 2442436592U , 1893310111U , 4195361916U , 3747569474U ,
828465101U , 2991227658U , 750582866U , 1205170309U , 1409813056U ,
678418130U , 1171531016U , 3821236156U , 354504587U , 4202874632U ,
3882511497U , 1893248677U , 1903078632U , 26340130U , 2069166240U ,
3657122492U , 3725758099U , 831344905U , 811453383U , 3447711422U ,
2434543565U , 4166886888U , 3358210805U , 4142984013U , 2988152326U ,
3527824853U , 982082992U , 2809155763U , 190157081U , 3340214818U ,
2365432395U , 2548636180U , 2894533366U , 3474657421U , 2372634704U ,
2845748389U , 43024175U , 2774226648U , 1987702864U , 3186502468U ,
453610222U , 4204736567U , 1392892630U , 2471323686U , 2470534280U ,
3541393095U , 4269885866U , 3909911300U , 759132955U , 1482612480U ,
667715263U , 1795580598U , 2337923983U , 3390586366U , 581426223U ,
1515718634U , 476374295U , 705213300U , 363062054U , 2084697697U ,
2407503428U , 2292957699U , 2426213835U , 2199989172U , 1987356470U ,
4026755612U , 2147252133U , 270400031U , 1367820199U , 2369854699U ,
2844269403U , 79981964U , 624U } ; { int32_T i , j ; real_T * Ds = ( real_T *
) rtDW . npdjbxplf3 . DS ; for ( i = 0 ; i < 2 ; i ++ ) { for ( j = 0 ; j < 2
; j ++ ) Ds [ i * 2 + j ] = ( rtP . StateSpace_DS_param [ i + j * 2 ] ) ; } {
int_T * switch_status = ( int_T * ) rtDW . npdjbxplf3 . SWITCH_STATUS ; int_T
* gState = ( int_T * ) rtDW . npdjbxplf3 . G_STATE ; real_T * yswitch = (
real_T * ) rtDW . npdjbxplf3 . Y_SWITCH ; int_T * switchTypes = ( int_T * )
rtDW . npdjbxplf3 . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * ) rtDW .
npdjbxplf3 . IDX_OUT_SW ; int_T * switch_status_init = ( int_T * ) rtDW .
npdjbxplf3 . SWITCH_STATUS_INIT ; switch_status [ 0 ] = 0 ;
switch_status_init [ 0 ] = 0 ; gState [ 0 ] = ( int_T ) 0.0 ; yswitch [ 0 ] =
1 / 0.1 ; switchTypes [ 0 ] = ( int_T ) 1.0 ; idxOutSw [ 0 ] = ( ( int_T )
0.0 ) - 1 ; switch_status [ 1 ] = 0 ; switch_status_init [ 1 ] = 0 ; gState [
1 ] = ( int_T ) 0.0 ; yswitch [ 1 ] = 1 / 0.01 ; switchTypes [ 1 ] = ( int_T
) 3.0 ; idxOutSw [ 1 ] = ( ( int_T ) 0.0 ) - 1 ; } } rtX . egd4eqagru = 0.0 ;
{ int32_T i , j ; real_T * As = ( real_T * ) rtDW . d0znnfktb4 . AS ; real_T
* Bs = ( real_T * ) rtDW . d0znnfktb4 . BS ; real_T * Cs = ( real_T * ) rtDW
. d0znnfktb4 . CS ; real_T * Ds = ( real_T * ) rtDW . d0znnfktb4 . DS ;
real_T * X0 = ( real_T * ) & rtDW . dnnn0nu0zb [ 0 ] ; for ( i = 0 ; i < 4 ;
i ++ ) { X0 [ i ] = ( rtP . StateSpace_X0_param [ i ] ) ; } for ( i = 0 ; i <
4 ; i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) As [ i * 4 + j ] = ( rtP .
StateSpace_AS_param [ i + j * 4 ] ) ; for ( j = 0 ; j < 5 ; j ++ ) Bs [ i * 5
+ j ] = ( rtP . StateSpace_BS_param [ i + j * 4 ] ) ; } for ( i = 0 ; i < 6 ;
i ++ ) { for ( j = 0 ; j < 4 ; j ++ ) Cs [ i * 4 + j ] = ( rtP .
StateSpace_CS_param [ i + j * 6 ] ) ; } for ( i = 0 ; i < 6 ; i ++ ) { for (
j = 0 ; j < 5 ; j ++ ) Ds [ i * 5 + j ] = ( rtP .
StateSpace_DS_param_cz3yopvi0n [ i + j * 6 ] ) ; } { int_T * switch_status =
( int_T * ) rtDW . d0znnfktb4 . SWITCH_STATUS ; int_T * gState = ( int_T * )
rtDW . d0znnfktb4 . G_STATE ; real_T * yswitch = ( real_T * ) rtDW .
d0znnfktb4 . Y_SWITCH ; int_T * switchTypes = ( int_T * ) rtDW . d0znnfktb4 .
SWITCH_TYPES ; int_T * idxOutSw = ( int_T * ) rtDW . d0znnfktb4 . IDX_OUT_SW
; int_T * switch_status_init = ( int_T * ) rtDW . d0znnfktb4 .
SWITCH_STATUS_INIT ; switch_status [ 0 ] = 0 ; switch_status_init [ 0 ] = 0 ;
gState [ 0 ] = ( int_T ) 0.0 ; yswitch [ 0 ] = 1 / 0.001 ; switchTypes [ 0 ]
= ( int_T ) 1.0 ; idxOutSw [ 0 ] = ( ( int_T ) 0.0 ) - 1 ; switch_status [ 1
] = 0 ; switch_status_init [ 1 ] = 0 ; gState [ 1 ] = ( int_T ) 0.0 ; yswitch
[ 1 ] = 1 / 0.001 ; switchTypes [ 1 ] = ( int_T ) 3.0 ; idxOutSw [ 1 ] = ( (
int_T ) 0.0 ) - 1 ; switch_status [ 2 ] = 0 ; switch_status_init [ 2 ] = 0 ;
gState [ 2 ] = ( int_T ) 0.0 ; yswitch [ 2 ] = 1 / 0.001 ; switchTypes [ 2 ]
= ( int_T ) 3.0 ; idxOutSw [ 2 ] = ( ( int_T ) 0.0 ) - 1 ; } } rtX .
acjhwfjuvh = 0.0 ; memcpy ( & rtDW . n23urvprlg [ 0 ] , & tmp [ 0 ] , 625U *
sizeof ( uint32_T ) ) ; rtDW . h01almjvh0 = lgnpfxrcb0 ; rtDW . jme2moc1et =
0U ; rtDW . g50qfbcmcf = 7U ; rtDW . j0d32edslo = true ; rtDW . bkwsxkusxs =
1144108930U ; rtDW . kldd00soyg = true ; rtDW . bfivdkhzmt [ 0 ] = 362436069U
; rtDW . bfivdkhzmt [ 1 ] = 521288629U ; rtDW . ewri5fxxq1 = true ; rtDW .
kbqlsft4jh = true ; rtDW . lvrt4bac12 = 0.0 ; rtDW . mmrindr4fr = true ; rtDW
. fjp44ee5ax = 0.9 ; rtDW . nbbupkxuro = true ; rtDW . dutnzjrzkf = 0.9 ;
rtDW . iuyncjvcn5 = true ; rtDW . pwk2utciwp = true ; rtDW . ni51rbhl2o =
true ; rtDW . nb12wxexy1 [ 0 ] = 0.0 ; rtDW . cosdp1wu4w [ 0 ] = 0.0 ; rtDW .
no4vepxkrz [ 0 ] = 0.0 ; rtDW . nb12wxexy1 [ 1 ] = 0.0 ; rtDW . cosdp1wu4w [
1 ] = 0.0 ; rtDW . no4vepxkrz [ 1 ] = 0.0 ; rtDW . nb12wxexy1 [ 2 ] = 0.0 ;
rtDW . cosdp1wu4w [ 2 ] = 0.0 ; rtDW . no4vepxkrz [ 2 ] = 0.0 ; rtDW .
nb12wxexy1 [ 3 ] = 0.0 ; rtDW . cosdp1wu4w [ 3 ] = 0.0 ; rtDW . no4vepxkrz [
3 ] = 0.0 ; rtDW . p4rnq0dwuk = true ; rtDW . fr1e1xckpl = 0.0 ; rtDW .
bxgmk1eaw0 = true ; rtDW . kxrkzyjlww = true ; rtDW . ef10paht5m [ 0 ] = 0.0
; rtDW . ef10paht5m [ 1 ] = 0.1 ; rtDW . ef10paht5m [ 2 ] = 0.5 ; rtDW .
ef10paht5m [ 3 ] = 0.5 ; rtDW . b020pa3iys = lgnpfxrcb0 ; rtDW . kvqfradwlq =
0U ; rtDW . beqq1oqdr3 = 0U ; rtDW . bkas1funiq = dkp5okdpd4 ; rtDW .
j01dz0mnne = 0.0 ; rtDW . jsymurmz45 = 0.0 ; rtDW . eppwlrjdji = 0.0 ; rtDW .
j0laytj34w = 0.0 ; rtDW . f5vqif0wgf = 0.0 ; rtDW . dqvjx3jolm = 0.0 ; rtDW .
bxebon4qnu = 0.0 ; rtDW . ia3rykgwil = 0.0 ; rtDW . kwtpxxi2kh = 0.0 ; rtDW .
eetww0o3hn = 0.0 ; rtDW . h2hkmnje1k = 0.008 ; rtB . fxy4mvun3n = 0.7 ; }
void MdlEnable ( void ) { rtDW . bisrotwkmc = 1 ; _ssSetSampleHit ( rtS , 3 ,
1 ) ; _ssSetTaskTime ( rtS , 3 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime (
rtS , 0 , ssGetT ( rtS ) ) ; ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [
] = { 2 , 2 , 2 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 , 1 ,
1 } ; static int_T rt_ScopeSignalDimensions [ ] = { 2 , 2 , 2 } ; static void
* rt_ScopeCurrSigDims [ ] = { ( NULL ) , ( NULL ) , ( NULL ) } ; static int_T
rt_ScopeCurrSigDimsSize [ ] = { 4 , 4 , 4 } ; static const char_T *
rt_ScopeSignalLabels [ ] = { "" , "" , "" } ; static char_T
rt_ScopeSignalTitles [ ] = "Voltage [V]Current [A]Power [W]" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 11 , 11 , 9 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 , 0 , 0 } ; static int_T
rt_ScopeSignalPlotStyles [ ] = { 1 , 1 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId
dTypes [ 3 ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static char_T
rt_ScopeBlockName [ ] = "simscape_final/System Measurements1/DC Measurements"
; static int_T rt_ScopeFrameData [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) } ; rt_ScopeSignalInfo . numSignals = 3 ;
rt_ScopeSignalInfo . numCols = rt_ScopeSignalWidths ; rt_ScopeSignalInfo .
numDims = rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . dkrsl0kl2e . LoggedData [ 0 ] = rt_CreateStructLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "ScopeData" , 1 , 0 , 5 , 0.0 , &
rt_ScopeSignalInfo , rt_ScopeBlockName ) ; if ( rtDW . dkrsl0kl2e .
LoggedData [ 0 ] == ( NULL ) ) return ; } { rtDW . npdjbxplf3 . DS = ( real_T
* ) calloc ( 2 * 2 , sizeof ( real_T ) ) ; rtDW . npdjbxplf3 . DX_COL = (
real_T * ) calloc ( 2 , sizeof ( real_T ) ) ; rtDW . npdjbxplf3 . TMP2 = (
real_T * ) calloc ( 2 , sizeof ( real_T ) ) ; rtDW . npdjbxplf3 .
SWITCH_STATUS = ( int_T * ) calloc ( 2 , sizeof ( int_T ) ) ; rtDW .
npdjbxplf3 . SW_CHG = ( int_T * ) calloc ( 2 , sizeof ( int_T ) ) ; rtDW .
npdjbxplf3 . G_STATE = ( int_T * ) calloc ( 2 , sizeof ( int_T ) ) ; rtDW .
npdjbxplf3 . Y_SWITCH = ( real_T * ) calloc ( 2 , sizeof ( real_T ) ) ; rtDW
. npdjbxplf3 . SWITCH_TYPES = ( int_T * ) calloc ( 2 , sizeof ( int_T ) ) ;
rtDW . npdjbxplf3 . IDX_OUT_SW = ( int_T * ) calloc ( 2 , sizeof ( int_T ) )
; rtDW . npdjbxplf3 . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 2 , sizeof (
int_T ) ) ; rtDW . npdjbxplf3 . USWLAST = ( real_T * ) calloc ( 2 , sizeof (
real_T ) ) ; } { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * )
calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 2 ; fromwksInfo -> time
= ( double * ) rtP . FromWs_Time0 ; rtDW . c5zfcz3wqy . TimePtr = fromwksInfo
-> time ; rtDW . c5zfcz3wqy . DataPtr = fromwksInfo -> data ; rtDW .
c5zfcz3wqy . RSimInfoPtr = fromwksInfo ; } rtDW . i4bhulkutv . PrevIndex = 0
; } { rtDW . d0znnfktb4 . AS = ( real_T * ) calloc ( 4 * 4 , sizeof ( real_T
) ) ; rtDW . d0znnfktb4 . BS = ( real_T * ) calloc ( 4 * 5 , sizeof ( real_T
) ) ; rtDW . d0znnfktb4 . CS = ( real_T * ) calloc ( 6 * 4 , sizeof ( real_T
) ) ; rtDW . d0znnfktb4 . DS = ( real_T * ) calloc ( 6 * 5 , sizeof ( real_T
) ) ; rtDW . d0znnfktb4 . DX_COL = ( real_T * ) calloc ( 6 , sizeof ( real_T
) ) ; rtDW . d0znnfktb4 . TMP2 = ( real_T * ) calloc ( 5 , sizeof ( real_T )
) ; rtDW . d0znnfktb4 . BD_COL = ( real_T * ) calloc ( 4 , sizeof ( real_T )
) ; rtDW . d0znnfktb4 . TMP1 = ( real_T * ) calloc ( 4 , sizeof ( real_T ) )
; rtDW . d0znnfktb4 . XTMP = ( real_T * ) calloc ( 4 , sizeof ( real_T ) ) ;
rtDW . d0znnfktb4 . SWITCH_STATUS = ( int_T * ) calloc ( 3 , sizeof ( int_T )
) ; rtDW . d0znnfktb4 . SW_CHG = ( int_T * ) calloc ( 3 , sizeof ( int_T ) )
; rtDW . d0znnfktb4 . G_STATE = ( int_T * ) calloc ( 3 , sizeof ( int_T ) ) ;
rtDW . d0znnfktb4 . Y_SWITCH = ( real_T * ) calloc ( 3 , sizeof ( real_T ) )
; rtDW . d0znnfktb4 . SWITCH_TYPES = ( int_T * ) calloc ( 3 , sizeof ( int_T
) ) ; rtDW . d0znnfktb4 . IDX_OUT_SW = ( int_T * ) calloc ( 3 , sizeof (
int_T ) ) ; rtDW . d0znnfktb4 . SWITCH_STATUS_INIT = ( int_T * ) calloc ( 3 ,
sizeof ( int_T ) ) ; rtDW . d0znnfktb4 . USWLAST = ( real_T * ) calloc ( 3 ,
sizeof ( real_T ) ) ; } MdlInitialize ( ) ; MdlEnable ( ) ; } void MdlOutputs
( int_T tid ) { real_T n5cnwijlmj ; real_T r2 ; real_T ratio ; int32_T b_k ;
int32_T k ; int_T iy ; uint32_T numCycles ; boolean_T exitg1 ; boolean_T
guard1 ; boolean_T guard2 ; boolean_T guard3 ; boolean_T guard4 ; ZCEventType
zcEvent ; srClearBC ( rtDW . ous2glk3vz ) ; if ( ssIsSampleHit ( rtS , 2 , 0
) ) { { real_T accum ; int_T * switch_status = ( int_T * ) rtDW . npdjbxplf3
. SWITCH_STATUS ; int_T * switch_status_init = ( int_T * ) rtDW . npdjbxplf3
. SWITCH_STATUS_INIT ; int_T * SwitchChange = ( int_T * ) rtDW . npdjbxplf3 .
SW_CHG ; int_T * gState = ( int_T * ) rtDW . npdjbxplf3 . G_STATE ; real_T *
yswitch = ( real_T * ) rtDW . npdjbxplf3 . Y_SWITCH ; int_T * switchTypes = (
int_T * ) rtDW . npdjbxplf3 . SWITCH_TYPES ; int_T * idxOutSw = ( int_T * )
rtDW . npdjbxplf3 . IDX_OUT_SW ; real_T * DxCol = ( real_T * ) rtDW .
npdjbxplf3 . DX_COL ; real_T * tmp2 = ( real_T * ) rtDW . npdjbxplf3 . TMP2 ;
real_T * uswlast = ( real_T * ) rtDW . npdjbxplf3 . USWLAST ; int_T newState
; int_T swChanged = 0 ; int loopsToDo = 20 ; real_T temp ; memcpy (
switch_status_init , switch_status , 2 * sizeof ( int_T ) ) ; memcpy (
uswlast , & rtB . abuqvgw4ua [ 0 ] , 2 * sizeof ( real_T ) ) ; do { if (
loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0 ; i1 < 2 ; i1 ++
) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init [ i1 ] -
switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ] =
switch_status_init [ i1 ] ; } } } else { real_T * Ds = ( real_T * ) rtDW .
npdjbxplf3 . DS ; accum = 0.0 ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value [ 1 ] ; rtB . abuqvgw4ua [ 0 ] = accum ; accum = 0.0 ;
accum += * ( Ds ++ ) * rtP . SwitchCurrents_Value [ 0 ] ; accum += * ( Ds ++
) * rtP . SwitchCurrents_Value [ 1 ] ; rtB . abuqvgw4ua [ 1 ] = accum ;
swChanged = 0 ; newState = gState [ 0 ] > 0 ? 1 : 0 ; swChanged = ( (
SwitchChange [ 0 ] = newState - switch_status [ 0 ] ) != 0 ) ? 1 : swChanged
; switch_status [ 0 ] = newState ; newState = rtB . abuqvgw4ua [ 1 ] > 0.0 ?
1 : ( ( rtB . abuqvgw4ua [ 1 ] < 0.0 ) ? 0 : switch_status [ 1 ] ) ;
swChanged = ( ( SwitchChange [ 1 ] = newState - switch_status [ 1 ] ) != 0 )
? 1 : swChanged ; switch_status [ 1 ] = newState ; } if ( swChanged ) {
real_T * Ds = ( real_T * ) rtDW . npdjbxplf3 . DS ; real_T a1 ; { int_T i1 ;
for ( i1 = 0 ; i1 < 2 ; i1 ++ ) { if ( SwitchChange [ i1 ] != 0 ) { a1 =
yswitch [ i1 ] * SwitchChange [ i1 ] ; temp = 1 / ( 1 - Ds [ i1 * 3 ] * a1 )
; DxCol [ 0 ] = Ds [ 0 + i1 ] * temp * a1 ; DxCol [ 1 ] = Ds [ 2 + i1 ] *
temp * a1 ; DxCol [ i1 ] = temp ; memcpy ( tmp2 , & Ds [ i1 * 2 ] , 2 *
sizeof ( real_T ) ) ; memset ( & Ds [ i1 * 2 ] , '\0' , 2 * sizeof ( real_T )
) ; a1 = DxCol [ 0 ] ; Ds [ 0 + 0 ] += a1 * tmp2 [ 0 ] ; Ds [ 0 + 1 ] += a1 *
tmp2 [ 1 ] ; a1 = DxCol [ 1 ] ; Ds [ 2 + 0 ] += a1 * tmp2 [ 0 ] ; Ds [ 2 + 1
] += a1 * tmp2 [ 1 ] ; } } } } } while ( swChanged > 0 && -- loopsToDo > 0 )
; if ( loopsToDo == 0 ) { real_T * Ds = ( real_T * ) rtDW . npdjbxplf3 . DS ;
accum = 0.0 ; accum += * ( Ds ++ ) * rtP . SwitchCurrents_Value [ 0 ] ; accum
+= * ( Ds ++ ) * rtP . SwitchCurrents_Value [ 1 ] ; rtB . abuqvgw4ua [ 0 ] =
accum ; accum = 0.0 ; accum += * ( Ds ++ ) * rtP . SwitchCurrents_Value [ 0 ]
; accum += * ( Ds ++ ) * rtP . SwitchCurrents_Value [ 1 ] ; rtB . abuqvgw4ua
[ 1 ] = accum ; } rtB . m4cchbruom [ 0 ] = ( real_T ) switch_status [ 0 ] ;
rtB . m4cchbruom [ 1 ] = ( real_T ) switch_status [ 1 ] ; } } rtB .
cnkqn5cq34 = rtP . TransferFcn_C * rtX . egd4eqagru ; { real_T * pDataValues
= ( real_T * ) rtDW . c5zfcz3wqy . DataPtr ; real_T * pTimeValues = ( real_T
* ) rtDW . c5zfcz3wqy . TimePtr ; int_T currTimeIndex = rtDW . i4bhulkutv .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint
; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . c5zfcz3wqy . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . i4bhulkutv . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { n5cnwijlmj =
pDataValues [ currTimeIndex ] ; } else { n5cnwijlmj = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; n5cnwijlmj = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } rtB . komxp1m4wp = look2_binlxpw ( rtB .
cnkqn5cq34 , n5cnwijlmj , rtP . ArrayVoltage , rtP . Irradiance , rtP .
ArrayCurrent , rtP . PVVICurves2DLookupTable_maxIndex , 183U ) ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { { real_T accum ; int_T * switch_status = (
int_T * ) rtDW . d0znnfktb4 . SWITCH_STATUS ; int_T * switch_status_init = (
int_T * ) rtDW . d0znnfktb4 . SWITCH_STATUS_INIT ; int_T * SwitchChange = (
int_T * ) rtDW . d0znnfktb4 . SW_CHG ; int_T * gState = ( int_T * ) rtDW .
d0znnfktb4 . G_STATE ; real_T * yswitch = ( real_T * ) rtDW . d0znnfktb4 .
Y_SWITCH ; int_T * switchTypes = ( int_T * ) rtDW . d0znnfktb4 . SWITCH_TYPES
; int_T * idxOutSw = ( int_T * ) rtDW . d0znnfktb4 . IDX_OUT_SW ; real_T *
DxCol = ( real_T * ) rtDW . d0znnfktb4 . DX_COL ; real_T * tmp2 = ( real_T *
) rtDW . d0znnfktb4 . TMP2 ; real_T * BDcol = ( real_T * ) rtDW . d0znnfktb4
. BD_COL ; real_T * tmp1 = ( real_T * ) rtDW . d0znnfktb4 . TMP1 ; real_T *
uswlast = ( real_T * ) rtDW . d0znnfktb4 . USWLAST ; int_T newState ; int_T
swChanged = 0 ; int loopsToDo = 20 ; real_T temp ; memcpy (
switch_status_init , switch_status , 3 * sizeof ( int_T ) ) ; memcpy (
uswlast , & rtB . o20komhacz [ 0 ] , 3 * sizeof ( real_T ) ) ; do { if (
loopsToDo == 1 ) { swChanged = 0 ; { int_T i1 ; for ( i1 = 0 ; i1 < 3 ; i1 ++
) { swChanged = ( ( SwitchChange [ i1 ] = switch_status_init [ i1 ] -
switch_status [ i1 ] ) != 0 ) ? 1 : swChanged ; switch_status [ i1 ] =
switch_status_init [ i1 ] ; } } } else { real_T * Cs = ( real_T * ) rtDW .
d0znnfktb4 . CS ; real_T * Ds = ( real_T * ) rtDW . d0znnfktb4 . DS ; { int_T
i1 ; real_T * y0 = & rtB . o20komhacz [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ )
{ accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . dnnn0nu0zb [ 0 ] ; accum += * (
Cs ++ ) * rtDW . dnnn0nu0zb [ 1 ] ; accum += * ( Cs ++ ) * rtDW . dnnn0nu0zb
[ 2 ] ; accum += * ( Cs ++ ) * rtDW . dnnn0nu0zb [ 3 ] ; accum += * ( Ds ++ )
* rtP . SwitchCurrents_Value_aynlaxlp3g [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 1 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 2 ] ; accum += * ( Ds ++ ) * rtB .
komxp1m4wp ; accum += * ( Ds ++ ) * rtP . eee_Value ; y0 [ i1 ] = accum ; } }
swChanged = 0 ; newState = gState [ 0 ] > 0 ? 1 : 0 ; swChanged = ( (
SwitchChange [ 0 ] = newState - switch_status [ 0 ] ) != 0 ) ? 1 : swChanged
; switch_status [ 0 ] = newState ; newState = rtB . o20komhacz [ 1 ] > 0.0 ?
1 : ( ( rtB . o20komhacz [ 1 ] < 0.0 ) ? 0 : switch_status [ 1 ] ) ;
swChanged = ( ( SwitchChange [ 1 ] = newState - switch_status [ 1 ] ) != 0 )
? 1 : swChanged ; switch_status [ 1 ] = newState ; newState = rtB .
o20komhacz [ 2 ] > 0.0 ? 1 : ( ( rtB . o20komhacz [ 2 ] < 0.0 ) ? 0 :
switch_status [ 2 ] ) ; swChanged = ( ( SwitchChange [ 2 ] = newState -
switch_status [ 2 ] ) != 0 ) ? 1 : swChanged ; switch_status [ 2 ] = newState
; } if ( swChanged ) { real_T * As = ( real_T * ) rtDW . d0znnfktb4 . AS ;
real_T * Cs = ( real_T * ) rtDW . d0znnfktb4 . CS ; real_T * Bs = ( real_T *
) rtDW . d0znnfktb4 . BS ; real_T * Ds = ( real_T * ) rtDW . d0znnfktb4 . DS
; real_T a1 ; { int_T i1 ; for ( i1 = 0 ; i1 < 3 ; i1 ++ ) { if (
SwitchChange [ i1 ] != 0 ) { a1 = 1000.0 * SwitchChange [ i1 ] ; temp = 1 / (
1 - Ds [ i1 * 6 ] * a1 ) ; { int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) {
DxCol [ i2 ] = Ds [ i2 * 5 + i1 ] * temp * a1 ; } } DxCol [ i1 ] = temp ;
BDcol [ 0 ] = Bs [ 0 + i1 ] * a1 ; BDcol [ 1 ] = Bs [ 5 + i1 ] * a1 ; BDcol [
2 ] = Bs [ 10 + i1 ] * a1 ; BDcol [ 3 ] = Bs [ 15 + i1 ] * a1 ; memcpy ( tmp1
, & Cs [ i1 * 4 ] , 4 * sizeof ( real_T ) ) ; memset ( & Cs [ i1 * 4 ] , '\0'
, 4 * sizeof ( real_T ) ) ; memcpy ( tmp2 , & Ds [ i1 * 5 ] , 5 * sizeof (
real_T ) ) ; memset ( & Ds [ i1 * 5 ] , '\0' , 5 * sizeof ( real_T ) ) ; {
int_T i2 ; for ( i2 = 0 ; i2 < 6 ; i2 ++ ) { a1 = DxCol [ i2 ] ; Cs [ i2 * 4
+ 0 ] += a1 * tmp1 [ 0 ] ; Cs [ i2 * 4 + 1 ] += a1 * tmp1 [ 1 ] ; Cs [ i2 * 4
+ 2 ] += a1 * tmp1 [ 2 ] ; Cs [ i2 * 4 + 3 ] += a1 * tmp1 [ 3 ] ; { int_T i3
; for ( i3 = 0 ; i3 < 5 ; i3 ++ ) { Ds [ i2 * 5 + i3 ] += a1 * tmp2 [ i3 ] ;
} } } } a1 = BDcol [ 0 ] ; As [ 0 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 0 +
1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 0 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [
0 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 5 ; i2
++ ) { Bs [ 0 + i2 ] += a1 * Ds [ i1 * 5 + i2 ] ; } } a1 = BDcol [ 1 ] ; As [
4 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 4 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ;
As [ 4 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 4 + 3 ] += a1 * Cs [ i1 * 4 + 3
] ; { int_T i2 ; for ( i2 = 0 ; i2 < 5 ; i2 ++ ) { Bs [ 5 + i2 ] += a1 * Ds [
i1 * 5 + i2 ] ; } } a1 = BDcol [ 2 ] ; As [ 8 + 0 ] += a1 * Cs [ i1 * 4 + 0 ]
; As [ 8 + 1 ] += a1 * Cs [ i1 * 4 + 1 ] ; As [ 8 + 2 ] += a1 * Cs [ i1 * 4 +
2 ] ; As [ 8 + 3 ] += a1 * Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2
< 5 ; i2 ++ ) { Bs [ 10 + i2 ] += a1 * Ds [ i1 * 5 + i2 ] ; } } a1 = BDcol [
3 ] ; As [ 12 + 0 ] += a1 * Cs [ i1 * 4 + 0 ] ; As [ 12 + 1 ] += a1 * Cs [ i1
* 4 + 1 ] ; As [ 12 + 2 ] += a1 * Cs [ i1 * 4 + 2 ] ; As [ 12 + 3 ] += a1 *
Cs [ i1 * 4 + 3 ] ; { int_T i2 ; for ( i2 = 0 ; i2 < 5 ; i2 ++ ) { Bs [ 15 +
i2 ] += a1 * Ds [ i1 * 5 + i2 ] ; } } } } } } } while ( swChanged > 0 && --
loopsToDo > 0 ) ; if ( loopsToDo == 0 ) { real_T * Cs = ( real_T * ) rtDW .
d0znnfktb4 . CS ; real_T * Ds = ( real_T * ) rtDW . d0znnfktb4 . DS ; { int_T
i1 ; real_T * y0 = & rtB . o20komhacz [ 0 ] ; for ( i1 = 0 ; i1 < 6 ; i1 ++ )
{ accum = 0.0 ; accum += * ( Cs ++ ) * rtDW . dnnn0nu0zb [ 0 ] ; accum += * (
Cs ++ ) * rtDW . dnnn0nu0zb [ 1 ] ; accum += * ( Cs ++ ) * rtDW . dnnn0nu0zb
[ 2 ] ; accum += * ( Cs ++ ) * rtDW . dnnn0nu0zb [ 3 ] ; accum += * ( Ds ++ )
* rtP . SwitchCurrents_Value_aynlaxlp3g [ 0 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 1 ] ; accum += * ( Ds ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 2 ] ; accum += * ( Ds ++ ) * rtB .
komxp1m4wp ; accum += * ( Ds ++ ) * rtP . eee_Value ; y0 [ i1 ] = accum ; } }
} rtB . la52j4vcgf [ 0 ] = ( real_T ) switch_status [ 0 ] ; rtB . la52j4vcgf
[ 1 ] = ( real_T ) switch_status [ 1 ] ; rtB . la52j4vcgf [ 2 ] = ( real_T )
switch_status [ 2 ] ; } rtB . lxbjkrt1na = rtP . donotdeletethisgain_Gain *
rtB . o20komhacz [ 3 ] ; rtDW . h01almjvh0 = lgnpfxrcb0 ; if ( ( rtDW .
lvrt4bac12 >= 1.0 ) && ( rtDW . lvrt4bac12 < 300.0 ) ) { rtB . eegmnycxav =
rtDW . fjp44ee5ax ; rtDW . lvrt4bac12 ++ ; } else { rtDW . lvrt4bac12 = 0.0 ;
if ( ( rtDW . fr1e1xckpl >= 1.0 ) && ( rtDW . fr1e1xckpl <= 4.0 ) && ( rtB .
lxbjkrt1na * rtB . komxp1m4wp > rtDW . nb12wxexy1 [ ( int32_T ) rtDW .
fr1e1xckpl - 1 ] ) ) { rtDW . nb12wxexy1 [ ( int32_T ) rtDW . fr1e1xckpl - 1
] = rtB . lxbjkrt1na * rtB . komxp1m4wp ; rtDW . no4vepxkrz [ ( int32_T )
rtDW . fr1e1xckpl - 1 ] = rtDW . fjp44ee5ax ; } rtDW . fr1e1xckpl ++ ; if (
rtDW . fr1e1xckpl == 6.0 ) { rtDW . fr1e1xckpl = 1.0 ; } if ( rtDW .
fr1e1xckpl == 1.0 ) { rtB . eegmnycxav = rtDW . ef10paht5m [ 0 ] ; rtDW .
fjp44ee5ax = rtDW . ef10paht5m [ 0 ] ; rtDW . lvrt4bac12 = 1.0 ; } else if (
rtDW . fr1e1xckpl == 2.0 ) { rtB . eegmnycxav = rtDW . ef10paht5m [ 1 ] ;
rtDW . fjp44ee5ax = rtDW . ef10paht5m [ 1 ] ; rtDW . lvrt4bac12 = 1.0 ; }
else if ( rtDW . fr1e1xckpl == 3.0 ) { rtB . eegmnycxav = rtDW . ef10paht5m [
2 ] ; rtDW . fjp44ee5ax = rtDW . ef10paht5m [ 2 ] ; rtDW . lvrt4bac12 = 1.0 ;
} else if ( rtDW . fr1e1xckpl == 4.0 ) { rtB . eegmnycxav = rtDW . ef10paht5m
[ 3 ] ; rtDW . fjp44ee5ax = rtDW . ef10paht5m [ 3 ] ; rtDW . lvrt4bac12 = 1.0
; } else if ( rtDW . fr1e1xckpl == 5.0 ) { if ( ! muDoubleScalarIsNaN ( rtDW
. nb12wxexy1 [ 0 ] ) ) { iy = 1 ; } else { iy = 0 ; k = 2 ; exitg1 = false ;
while ( ( ! exitg1 ) && ( k < 5 ) ) { if ( ! muDoubleScalarIsNaN ( rtDW .
nb12wxexy1 [ k - 1 ] ) ) { iy = k ; exitg1 = true ; } else { k ++ ; } } } if
( iy == 0 ) { k = 1 ; } else { r2 = rtDW . nb12wxexy1 [ iy - 1 ] ; k = iy ;
for ( b_k = iy + 1 ; b_k < 5 ; b_k ++ ) { ratio = rtDW . nb12wxexy1 [ b_k - 1
] ; if ( r2 < ratio ) { r2 = ratio ; k = b_k ; } } } rtDW . dutnzjrzkf = rtDW
. no4vepxkrz [ k - 1 ] ; rtB . eegmnycxav = rtDW . dutnzjrzkf ; rtDW .
fjp44ee5ax = rtDW . dutnzjrzkf ; rtDW . lvrt4bac12 = 1.0 ; r2 = i203t0ykso (
) ; rtDW . cosdp1wu4w [ 0 ] = 2.0 * r2 * rtDW . no4vepxkrz [ 0 ] - rtDW .
ef10paht5m [ 0 ] ; r2 = i203t0ykso ( ) ; rtDW . cosdp1wu4w [ 1 ] = 2.0 * r2 *
rtDW . no4vepxkrz [ 1 ] - rtDW . ef10paht5m [ 1 ] ; r2 = i203t0ykso ( ) ;
rtDW . cosdp1wu4w [ 2 ] = 2.0 * r2 * rtDW . no4vepxkrz [ 2 ] - rtDW .
ef10paht5m [ 2 ] ; r2 = i203t0ykso ( ) ; rtDW . cosdp1wu4w [ 3 ] = 2.0 * r2 *
rtDW . no4vepxkrz [ 3 ] - rtDW . ef10paht5m [ 3 ] ; r2 = i203t0ykso ( ) ; r2
= rtDW . dutnzjrzkf - ( 0.2 * r2 - 0.1 ) * rtDW . cosdp1wu4w [ 0 ] ; if ( r2
> 1.0 ) { rtDW . ef10paht5m [ 0 ] = 1.0 ; } else if ( r2 < 0.1 ) { rtDW .
ef10paht5m [ 0 ] = 0.1 ; } else { rtDW . ef10paht5m [ 0 ] = r2 ; } r2 =
i203t0ykso ( ) ; r2 = rtDW . dutnzjrzkf - ( 0.2 * r2 - 0.1 ) * rtDW .
cosdp1wu4w [ 1 ] ; if ( r2 > 1.0 ) { rtDW . ef10paht5m [ 1 ] = 1.0 ; } else
if ( r2 < 0.1 ) { rtDW . ef10paht5m [ 1 ] = 0.1 ; } else { rtDW . ef10paht5m
[ 1 ] = r2 ; } r2 = i203t0ykso ( ) ; r2 = rtDW . dutnzjrzkf - ( 0.2 * r2 -
0.1 ) * rtDW . cosdp1wu4w [ 2 ] ; if ( r2 > 1.0 ) { rtDW . ef10paht5m [ 2 ] =
1.0 ; } else if ( r2 < 0.1 ) { rtDW . ef10paht5m [ 2 ] = 0.1 ; } else { rtDW
. ef10paht5m [ 2 ] = r2 ; } r2 = i203t0ykso ( ) ; r2 = rtDW . dutnzjrzkf - (
0.2 * r2 - 0.1 ) * rtDW . cosdp1wu4w [ 3 ] ; if ( r2 > 1.0 ) { rtDW .
ef10paht5m [ 3 ] = 1.0 ; } else if ( r2 < 0.1 ) { rtDW . ef10paht5m [ 3 ] =
0.1 ; } else { rtDW . ef10paht5m [ 3 ] = r2 ; } } else { rtB . eegmnycxav =
0.1 ; } } } rtB . lo4k4qjncy = look1_binlxpw ( muDoubleScalarRem ( ssGetT (
rtS ) , rtP . Constant_Value ) , rtP . LookUpTable1_bp01Data , rtP .
RepeatingSequence_rep_seq_y , 1U ) ; rtB . mwopycrmyl = ( rtB . lo4k4qjncy <=
rtB . eegmnycxav ) ; if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { r2 =
ssGetTaskTime ( rtS , 3 ) ; if ( ssGetTNextWasAdjusted ( rtS , 3 ) ) { rtDW .
aoqbzw24yh = _ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW . bisrotwkmc != 0
) { rtDW . bisrotwkmc = 0 ; if ( r2 >= rtP . uMHzsamples_PhaseDelay ) { ratio
= ( r2 - rtP . uMHzsamples_PhaseDelay ) / rtP . uMHzsamples_Period ;
numCycles = ( uint32_T ) muDoubleScalarFloor ( ratio ) ; if (
muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio ) < DBL_EPSILON *
ratio ) { numCycles ++ ; } rtDW . cy1425fqxu = numCycles ; ratio = ( ( real_T
) numCycles * rtP . uMHzsamples_Period + rtP . uMHzsamples_PhaseDelay ) + rtP
. uMHzsamples_Duty * rtP . uMHzsamples_Period / 100.0 ; if ( r2 < ratio ) {
rtDW . bzwtriiduw = 1 ; rtDW . aoqbzw24yh = ratio ; } else { rtDW .
bzwtriiduw = 0 ; rtDW . aoqbzw24yh = ( real_T ) ( numCycles + 1U ) * rtP .
uMHzsamples_Period + rtP . uMHzsamples_PhaseDelay ; } } else { rtDW .
cy1425fqxu = rtP . uMHzsamples_PhaseDelay != 0.0 ? - 1 : 0 ; rtDW .
bzwtriiduw = 0 ; rtDW . aoqbzw24yh = rtP . uMHzsamples_PhaseDelay ; } } else
if ( rtDW . aoqbzw24yh <= r2 ) { if ( rtDW . bzwtriiduw == 1 ) { rtDW .
bzwtriiduw = 0 ; rtDW . aoqbzw24yh = ( real_T ) ( rtDW . cy1425fqxu + 1L ) *
rtP . uMHzsamples_Period + rtP . uMHzsamples_PhaseDelay ; } else { rtDW .
cy1425fqxu ++ ; rtDW . bzwtriiduw = 1 ; rtDW . aoqbzw24yh = ( rtP .
uMHzsamples_Duty * rtP . uMHzsamples_Period * 0.01 + ( real_T ) rtDW .
cy1425fqxu * rtP . uMHzsamples_Period ) + rtP . uMHzsamples_PhaseDelay ; } }
_ssSetVarNextHitTime ( rtS , 0 , rtDW . aoqbzw24yh ) ; if ( rtDW . bzwtriiduw
== 1 ) { rtB . h0uehzgjjn = rtP . uMHzsamples_Amp ; } else { rtB . h0uehzgjjn
= 0.0 ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING
, & rtPrevZCX . g5au2r45a1 , ( rtB . h0uehzgjjn ) ) ; if ( zcEvent !=
NO_ZCEVENT ) { rtB . ow25jkzfhv = ( int8_T ) zcEvent ; if ( rtDW . kvqfradwlq
< 127U ) { rtDW . kvqfradwlq ++ ; } rtDW . b020pa3iys = nks1fjs4s3 ; if (
rtDW . beqq1oqdr3 == 0U ) { rtDW . beqq1oqdr3 = 1U ; rtDW . bkas1funiq =
k0kqspzzug ; rtDW . kvqfradwlq = 0U ; rtDW . bxebon4qnu = 0.0 ; rtDW .
j0laytj34w = 0.0 ; rtDW . j01dz0mnne = 0.0 ; } else { guard1 = false ; guard2
= false ; guard3 = false ; guard4 = false ; switch ( rtDW . bkas1funiq ) {
case k0kqspzzug : if ( rtDW . kvqfradwlq >= 100 ) { rtDW . f5vqif0wgf = rtDW
. bxebon4qnu / rtDW . j01dz0mnne ; rtDW . jsymurmz45 = rtDW . j0laytj34w /
rtDW . j01dz0mnne ; rtDW . bkas1funiq = i1ltibpkac ; rtDW . eetww0o3hn = rtDW
. f5vqif0wgf - rtDW . dqvjx3jolm ; rtDW . kwtpxxi2kh = rtDW . jsymurmz45 -
rtDW . eppwlrjdji ; rtDW . ia3rykgwil = rtB . fxy4mvun3n ; } else { rtDW .
bxebon4qnu += rtB . lxbjkrt1na ; rtDW . j0laytj34w += rtB . komxp1m4wp ; rtDW
. j01dz0mnne ++ ; } break ; case igvywyqxhz : rtDW . bkas1funiq = jghipa04qx
; rtDW . dqvjx3jolm = rtDW . f5vqif0wgf ; rtDW . eppwlrjdji = rtDW .
jsymurmz45 ; rtB . fxy4mvun3n = rtDW . ia3rykgwil ; break ; case gvvs4ef133 :
rtDW . bkas1funiq = jghipa04qx ; rtDW . dqvjx3jolm = rtDW . f5vqif0wgf ; rtDW
. eppwlrjdji = rtDW . jsymurmz45 ; rtB . fxy4mvun3n = rtDW . ia3rykgwil ;
break ; case jghipa04qx : rtDW . bkas1funiq = k0kqspzzug ; rtDW . kvqfradwlq
= 0U ; rtDW . bxebon4qnu = 0.0 ; rtDW . j0laytj34w = 0.0 ; rtDW . j01dz0mnne
= 0.0 ; break ; default : if ( rtDW . eetww0o3hn != 0.0 ) { if ( rtDW .
kwtpxxi2kh / rtDW . eetww0o3hn > - rtDW . jsymurmz45 / rtDW . f5vqif0wgf ) {
guard1 = true ; } else if ( rtDW . kwtpxxi2kh / rtDW . eetww0o3hn < - rtDW .
jsymurmz45 / rtDW . f5vqif0wgf ) { guard2 = true ; } else if ( rtDW .
kwtpxxi2kh / rtDW . eetww0o3hn == - rtDW . jsymurmz45 / rtDW . f5vqif0wgf ) {
guard3 = true ; } else { guard4 = true ; } } else { guard4 = true ; } break ;
} if ( guard4 ) { if ( rtDW . eetww0o3hn == 0.0 ) { if ( rtDW . kwtpxxi2kh <
0.0 ) { guard2 = true ; } else if ( rtDW . kwtpxxi2kh > 0.0 ) { guard1 = true
; } else if ( rtDW . kwtpxxi2kh == 0.0 ) { guard3 = true ; } } } if ( guard3
) { rtDW . bkas1funiq = jghipa04qx ; rtDW . dqvjx3jolm = rtDW . f5vqif0wgf ;
rtDW . eppwlrjdji = rtDW . jsymurmz45 ; rtB . fxy4mvun3n = rtDW . ia3rykgwil
; } if ( guard2 ) { rtDW . bkas1funiq = gvvs4ef133 ; rtDW . ia3rykgwil +=
rtDW . h2hkmnje1k ; } if ( guard1 ) { rtDW . bkas1funiq = igvywyqxhz ; rtDW .
ia3rykgwil -= rtDW . h2hkmnje1k ; } } rtDW . ous2glk3vz = 4 ; } } if ( rtB .
fxy4mvun3n > rtP . Saturation_UpperSat ) { rtB . k0pihcl1dy = rtP .
Saturation_UpperSat ; } else if ( rtB . fxy4mvun3n < rtP .
Saturation_LowerSat ) { rtB . k0pihcl1dy = rtP . Saturation_LowerSat ; } else
{ rtB . k0pihcl1dy = rtB . fxy4mvun3n ; } } rtB . gpis0zvuxp = look1_binlxpw
( muDoubleScalarRem ( ssGetT ( rtS ) , rtP . Constant_Value_ctutefl32y ) ,
rtP . LookUpTable1_bp01Data_cnvefmrvbz , rtP .
RepeatingSequence_rep_seq_y_jww4cxb3xy , 1U ) ; rtB . avft534bzw = ( rtB .
gpis0zvuxp <= rtB . k0pihcl1dy ) ; rtB . o1kbtlj4kh = rtB . avft534bzw ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . hqowogsuxf = rtP .
donotdeletethisgain_Gain_fvxcttqcfp * rtB . o20komhacz [ 5 ] ; rtB .
oh1bjpifcg = rtP . donotdeletethisgain_Gain_lgq0rbvoze * rtB . o20komhacz [ 4
] ; rtB . muug30hfrt = rtB . hqowogsuxf * rtB . oh1bjpifcg ; } rtB .
d5gcx4z2ek = rtB . komxp1m4wp * rtB . lxbjkrt1na ; if ( ssGetLogOutput ( rtS
) ) { StructLogVar * svar = ( StructLogVar * ) rtDW . dkrsl0kl2e . LoggedData
[ 0 ] ; LogVar * var = svar -> signals . values ; { double locTime =
ssGetTaskTime ( rtS , 0 ) ; rt_UpdateLogVar ( ( LogVar * ) svar -> time , &
locTime , 0 ) ; } { real_T up0 [ 2 ] ; up0 [ 0 ] = rtB . lxbjkrt1na ; up0 [ 1
] = rtB . oh1bjpifcg ; rt_UpdateLogVar ( ( LogVar * ) var , up0 , 0 ) ; var =
var -> next ; } { real_T up1 [ 2 ] ; up1 [ 0 ] = rtB . komxp1m4wp ; up1 [ 1 ]
= rtB . hqowogsuxf ; rt_UpdateLogVar ( ( LogVar * ) var , up1 , 0 ) ; var =
var -> next ; } { real_T up2 [ 2 ] ; up2 [ 0 ] = rtB . d5gcx4z2ek ; up2 [ 1 ]
= rtB . muug30hfrt ; rt_UpdateLogVar ( ( LogVar * ) var , up2 , 0 ) ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { { int_T * gState = ( int_T * ) rtDW .
npdjbxplf3 . G_STATE ; * ( gState ++ ) = ( int_T ) 0.0 ; * ( gState ++ ) = (
int_T ) 0.0 ; } { const real_T * As = ( real_T * ) rtDW . d0znnfktb4 . AS ;
const real_T * Bs = ( real_T * ) rtDW . d0znnfktb4 . BS ; real_T * xtmp = (
real_T * ) rtDW . d0znnfktb4 . XTMP ; real_T accum ; accum = 0.0 ; accum += *
( As ++ ) * rtDW . dnnn0nu0zb [ 0 ] ; accum += * ( As ++ ) * rtDW .
dnnn0nu0zb [ 1 ] ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb [ 2 ] ; accum +=
* ( As ++ ) * rtDW . dnnn0nu0zb [ 3 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 2 ] ; accum += * ( Bs ++ ) * rtB .
komxp1m4wp ; accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 0 ] = accum ;
accum = 0.0 ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb [ 0 ] ; accum += * (
As ++ ) * rtDW . dnnn0nu0zb [ 1 ] ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb
[ 2 ] ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb [ 3 ] ; accum += * ( Bs ++ )
* rtP . SwitchCurrents_Value_aynlaxlp3g [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 2 ] ; accum += * ( Bs ++ ) * rtB .
komxp1m4wp ; accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 1 ] = accum ;
accum = 0.0 ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb [ 0 ] ; accum += * (
As ++ ) * rtDW . dnnn0nu0zb [ 1 ] ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb
[ 2 ] ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb [ 3 ] ; accum += * ( Bs ++ )
* rtP . SwitchCurrents_Value_aynlaxlp3g [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 2 ] ; accum += * ( Bs ++ ) * rtB .
komxp1m4wp ; accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 2 ] = accum ;
accum = 0.0 ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb [ 0 ] ; accum += * (
As ++ ) * rtDW . dnnn0nu0zb [ 1 ] ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb
[ 2 ] ; accum += * ( As ++ ) * rtDW . dnnn0nu0zb [ 3 ] ; accum += * ( Bs ++ )
* rtP . SwitchCurrents_Value_aynlaxlp3g [ 0 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 1 ] ; accum += * ( Bs ++ ) * rtP .
SwitchCurrents_Value_aynlaxlp3g [ 2 ] ; accum += * ( Bs ++ ) * rtB .
komxp1m4wp ; accum += * ( Bs ++ ) * rtP . eee_Value ; xtmp [ 3 ] = accum ;
rtDW . dnnn0nu0zb [ 0 ] = xtmp [ 0 ] ; rtDW . dnnn0nu0zb [ 1 ] = xtmp [ 1 ] ;
rtDW . dnnn0nu0zb [ 2 ] = xtmp [ 2 ] ; rtDW . dnnn0nu0zb [ 3 ] = xtmp [ 3 ] ;
{ int_T * gState = ( int_T * ) rtDW . d0znnfktb4 . G_STATE ; * ( gState ++ )
= ( int_T ) rtB . o1kbtlj4kh ; * ( gState ++ ) = ( int_T ) 0.0 ; * ( gState
++ ) = ( int_T ) 0.0 ; } } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID4
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot ->
egd4eqagru = rtP . TransferFcn_A * rtX . egd4eqagru ; _rtXdot -> egd4eqagru
+= rtB . lxbjkrt1na ; _rtXdot -> acjhwfjuvh = rtP . TransferFcn1_A * rtX .
acjhwfjuvh ; } void MdlProjection ( void ) { } void MdlTerminate ( void ) { {
free ( rtDW . npdjbxplf3 . DS ) ; free ( rtDW . npdjbxplf3 . DX_COL ) ; free
( rtDW . npdjbxplf3 . TMP2 ) ; free ( rtDW . npdjbxplf3 . G_STATE ) ; free (
rtDW . npdjbxplf3 . SWITCH_STATUS ) ; free ( rtDW . npdjbxplf3 . SW_CHG ) ;
free ( rtDW . npdjbxplf3 . SWITCH_STATUS_INIT ) ; } rt_FREE ( rtDW .
c5zfcz3wqy . RSimInfoPtr ) ; { free ( rtDW . d0znnfktb4 . AS ) ; free ( rtDW
. d0znnfktb4 . BS ) ; free ( rtDW . d0znnfktb4 . CS ) ; free ( rtDW .
d0znnfktb4 . DS ) ; free ( rtDW . d0znnfktb4 . DX_COL ) ; free ( rtDW .
d0znnfktb4 . TMP2 ) ; free ( rtDW . d0znnfktb4 . BD_COL ) ; free ( rtDW .
d0znnfktb4 . TMP1 ) ; free ( rtDW . d0znnfktb4 . XTMP ) ; free ( rtDW .
d0znnfktb4 . G_STATE ) ; free ( rtDW . d0znnfktb4 . SWITCH_STATUS ) ; free (
rtDW . d0znnfktb4 . SW_CHG ) ; free ( rtDW . d0znnfktb4 . SWITCH_STATUS_INIT
) ; } } static void mr_simscape_final_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_simscape_final_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void mr_simscape_final_restoreDataFromMxArray (
void * destData , const mxArray * srcArray , mwIndex i , int j , size_t
numBytes ) ; static void mr_simscape_final_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) {
memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_simscape_final_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void
mr_simscape_final_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_simscape_final_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_simscape_final_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_simscape_final_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_simscape_final_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_simscape_final_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_simscape_final_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_simscape_final_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void mr_simscape_final_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_simscape_final_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_simscape_final_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_simscape_final_GetDWork ( ) { static
const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "rtPrevZCX" , } ;
mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_simscape_final_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & (
rtB ) , sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 51 ]
= { "rtDW.dnnn0nu0zb" , "rtDW.aoqbzw24yh" , "rtDW.fr1e1xckpl" ,
"rtDW.fjp44ee5ax" , "rtDW.no4vepxkrz" , "rtDW.nb12wxexy1" , "rtDW.ef10paht5m"
, "rtDW.cosdp1wu4w" , "rtDW.lvrt4bac12" , "rtDW.dutnzjrzkf" ,
"rtDW.j01dz0mnne" , "rtDW.jsymurmz45" , "rtDW.eppwlrjdji" , "rtDW.j0laytj34w"
, "rtDW.f5vqif0wgf" , "rtDW.dqvjx3jolm" , "rtDW.bxebon4qnu" ,
"rtDW.ia3rykgwil" , "rtDW.kwtpxxi2kh" , "rtDW.eetww0o3hn" , "rtDW.h2hkmnje1k"
, "rtDW.cy1425fqxu" , "rtDW.bisrotwkmc" , "rtDW.bzwtriiduw" ,
"rtDW.h01almjvh0" , "rtDW.b020pa3iys" , "rtDW.g50qfbcmcf" , "rtDW.bkwsxkusxs"
, "rtDW.bfivdkhzmt" , "rtDW.n23urvprlg" , "rtDW.bkas1funiq" ,
"rtDW.alk0fbzgi4" , "rtDW.i4bhulkutv" , "rtDW.g1wwsnainz" , "rtDW.ous2glk3vz"
, "rtDW.jme2moc1et" , "rtDW.beqq1oqdr3" , "rtDW.kvqfradwlq" ,
"rtDW.afcgtasyrg" , "rtDW.bxgmk1eaw0" , "rtDW.nbbupkxuro" , "rtDW.p4rnq0dwuk"
, "rtDW.pwk2utciwp" , "rtDW.kxrkzyjlww" , "rtDW.ni51rbhl2o" ,
"rtDW.mmrindr4fr" , "rtDW.iuyncjvcn5" , "rtDW.j0d32edslo" , "rtDW.kldd00soyg"
, "rtDW.ewri5fxxq1" , "rtDW.kbqlsft4jh" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 51 , rtdwDataFieldNames ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) &
( rtDW . dnnn0nu0zb ) , sizeof ( rtDW . dnnn0nu0zb ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) &
( rtDW . aoqbzw24yh ) , sizeof ( rtDW . aoqbzw24yh ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) &
( rtDW . fr1e1xckpl ) , sizeof ( rtDW . fr1e1xckpl ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) &
( rtDW . fjp44ee5ax ) , sizeof ( rtDW . fjp44ee5ax ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) &
( rtDW . no4vepxkrz ) , sizeof ( rtDW . no4vepxkrz ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) &
( rtDW . nb12wxexy1 ) , sizeof ( rtDW . nb12wxexy1 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) &
( rtDW . ef10paht5m ) , sizeof ( rtDW . ef10paht5m ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) &
( rtDW . cosdp1wu4w ) , sizeof ( rtDW . cosdp1wu4w ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) &
( rtDW . lvrt4bac12 ) , sizeof ( rtDW . lvrt4bac12 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) &
( rtDW . dutnzjrzkf ) , sizeof ( rtDW . dutnzjrzkf ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) &
( rtDW . j01dz0mnne ) , sizeof ( rtDW . j01dz0mnne ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) &
( rtDW . jsymurmz45 ) , sizeof ( rtDW . jsymurmz45 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) &
( rtDW . eppwlrjdji ) , sizeof ( rtDW . eppwlrjdji ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) &
( rtDW . j0laytj34w ) , sizeof ( rtDW . j0laytj34w ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) &
( rtDW . f5vqif0wgf ) , sizeof ( rtDW . f5vqif0wgf ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) &
( rtDW . dqvjx3jolm ) , sizeof ( rtDW . dqvjx3jolm ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) &
( rtDW . bxebon4qnu ) , sizeof ( rtDW . bxebon4qnu ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) &
( rtDW . ia3rykgwil ) , sizeof ( rtDW . ia3rykgwil ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) &
( rtDW . kwtpxxi2kh ) , sizeof ( rtDW . kwtpxxi2kh ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) &
( rtDW . eetww0o3hn ) , sizeof ( rtDW . eetww0o3hn ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) &
( rtDW . h2hkmnje1k ) , sizeof ( rtDW . h2hkmnje1k ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) &
( rtDW . cy1425fqxu ) , sizeof ( rtDW . cy1425fqxu ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) &
( rtDW . bisrotwkmc ) , sizeof ( rtDW . bisrotwkmc ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) &
( rtDW . bzwtriiduw ) , sizeof ( rtDW . bzwtriiduw ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) &
( rtDW . h01almjvh0 ) , sizeof ( rtDW . h01almjvh0 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) &
( rtDW . b020pa3iys ) , sizeof ( rtDW . b020pa3iys ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) &
( rtDW . g50qfbcmcf ) , sizeof ( rtDW . g50qfbcmcf ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) &
( rtDW . bkwsxkusxs ) , sizeof ( rtDW . bkwsxkusxs ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) &
( rtDW . bfivdkhzmt ) , sizeof ( rtDW . bfivdkhzmt ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) &
( rtDW . n23urvprlg ) , sizeof ( rtDW . n23urvprlg ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) &
( rtDW . bkas1funiq ) , sizeof ( rtDW . bkas1funiq ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) &
( rtDW . alk0fbzgi4 ) , sizeof ( rtDW . alk0fbzgi4 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) &
( rtDW . i4bhulkutv ) , sizeof ( rtDW . i4bhulkutv ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) &
( rtDW . g1wwsnainz ) , sizeof ( rtDW . g1wwsnainz ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) &
( rtDW . ous2glk3vz ) , sizeof ( rtDW . ous2glk3vz ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) &
( rtDW . jme2moc1et ) , sizeof ( rtDW . jme2moc1et ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void * ) &
( rtDW . beqq1oqdr3 ) , sizeof ( rtDW . beqq1oqdr3 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void * ) &
( rtDW . kvqfradwlq ) , sizeof ( rtDW . kvqfradwlq ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) &
( rtDW . afcgtasyrg ) , sizeof ( rtDW . afcgtasyrg ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) &
( rtDW . bxgmk1eaw0 ) , sizeof ( rtDW . bxgmk1eaw0 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void * ) &
( rtDW . nbbupkxuro ) , sizeof ( rtDW . nbbupkxuro ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void * ) &
( rtDW . p4rnq0dwuk ) , sizeof ( rtDW . p4rnq0dwuk ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void * ) &
( rtDW . pwk2utciwp ) , sizeof ( rtDW . pwk2utciwp ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void * ) &
( rtDW . kxrkzyjlww ) , sizeof ( rtDW . kxrkzyjlww ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void * ) &
( rtDW . ni51rbhl2o ) , sizeof ( rtDW . ni51rbhl2o ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void * ) &
( rtDW . mmrindr4fr ) , sizeof ( rtDW . mmrindr4fr ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void * ) &
( rtDW . iuyncjvcn5 ) , sizeof ( rtDW . iuyncjvcn5 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void * ) &
( rtDW . j0d32edslo ) , sizeof ( rtDW . j0d32edslo ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 48 , ( const void * ) &
( rtDW . kldd00soyg ) , sizeof ( rtDW . kldd00soyg ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const void * ) &
( rtDW . ewri5fxxq1 ) , sizeof ( rtDW . ewri5fxxq1 ) ) ;
mr_simscape_final_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void * ) &
( rtDW . kbqlsft4jh ) , sizeof ( rtDW . kbqlsft4jh ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } mr_simscape_final_cacheDataAsMxArray ( ssDW , 0
, 2 , ( const void * ) & ( rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW
; } void mr_simscape_final_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW
; mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0
, 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_simscape_final_restoreDataFromMxArray ( ( void * ) & (
rtDW . dnnn0nu0zb ) , rtdwData , 0 , 0 , sizeof ( rtDW . dnnn0nu0zb ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . aoqbzw24yh )
, rtdwData , 0 , 1 , sizeof ( rtDW . aoqbzw24yh ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . fr1e1xckpl )
, rtdwData , 0 , 2 , sizeof ( rtDW . fr1e1xckpl ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . fjp44ee5ax )
, rtdwData , 0 , 3 , sizeof ( rtDW . fjp44ee5ax ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . no4vepxkrz )
, rtdwData , 0 , 4 , sizeof ( rtDW . no4vepxkrz ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . nb12wxexy1 )
, rtdwData , 0 , 5 , sizeof ( rtDW . nb12wxexy1 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . ef10paht5m )
, rtdwData , 0 , 6 , sizeof ( rtDW . ef10paht5m ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . cosdp1wu4w )
, rtdwData , 0 , 7 , sizeof ( rtDW . cosdp1wu4w ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . lvrt4bac12 )
, rtdwData , 0 , 8 , sizeof ( rtDW . lvrt4bac12 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . dutnzjrzkf )
, rtdwData , 0 , 9 , sizeof ( rtDW . dutnzjrzkf ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . j01dz0mnne )
, rtdwData , 0 , 10 , sizeof ( rtDW . j01dz0mnne ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . jsymurmz45 )
, rtdwData , 0 , 11 , sizeof ( rtDW . jsymurmz45 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . eppwlrjdji )
, rtdwData , 0 , 12 , sizeof ( rtDW . eppwlrjdji ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . j0laytj34w )
, rtdwData , 0 , 13 , sizeof ( rtDW . j0laytj34w ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . f5vqif0wgf )
, rtdwData , 0 , 14 , sizeof ( rtDW . f5vqif0wgf ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . dqvjx3jolm )
, rtdwData , 0 , 15 , sizeof ( rtDW . dqvjx3jolm ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . bxebon4qnu )
, rtdwData , 0 , 16 , sizeof ( rtDW . bxebon4qnu ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . ia3rykgwil )
, rtdwData , 0 , 17 , sizeof ( rtDW . ia3rykgwil ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . kwtpxxi2kh )
, rtdwData , 0 , 18 , sizeof ( rtDW . kwtpxxi2kh ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . eetww0o3hn )
, rtdwData , 0 , 19 , sizeof ( rtDW . eetww0o3hn ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . h2hkmnje1k )
, rtdwData , 0 , 20 , sizeof ( rtDW . h2hkmnje1k ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . cy1425fqxu )
, rtdwData , 0 , 21 , sizeof ( rtDW . cy1425fqxu ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . bisrotwkmc )
, rtdwData , 0 , 22 , sizeof ( rtDW . bisrotwkmc ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . bzwtriiduw )
, rtdwData , 0 , 23 , sizeof ( rtDW . bzwtriiduw ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . h01almjvh0 )
, rtdwData , 0 , 24 , sizeof ( rtDW . h01almjvh0 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . b020pa3iys )
, rtdwData , 0 , 25 , sizeof ( rtDW . b020pa3iys ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . g50qfbcmcf )
, rtdwData , 0 , 26 , sizeof ( rtDW . g50qfbcmcf ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . bkwsxkusxs )
, rtdwData , 0 , 27 , sizeof ( rtDW . bkwsxkusxs ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . bfivdkhzmt )
, rtdwData , 0 , 28 , sizeof ( rtDW . bfivdkhzmt ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . n23urvprlg )
, rtdwData , 0 , 29 , sizeof ( rtDW . n23urvprlg ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . bkas1funiq )
, rtdwData , 0 , 30 , sizeof ( rtDW . bkas1funiq ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . alk0fbzgi4 )
, rtdwData , 0 , 31 , sizeof ( rtDW . alk0fbzgi4 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . i4bhulkutv )
, rtdwData , 0 , 32 , sizeof ( rtDW . i4bhulkutv ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . g1wwsnainz )
, rtdwData , 0 , 33 , sizeof ( rtDW . g1wwsnainz ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . ous2glk3vz )
, rtdwData , 0 , 34 , sizeof ( rtDW . ous2glk3vz ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . jme2moc1et )
, rtdwData , 0 , 35 , sizeof ( rtDW . jme2moc1et ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . beqq1oqdr3 )
, rtdwData , 0 , 36 , sizeof ( rtDW . beqq1oqdr3 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . kvqfradwlq )
, rtdwData , 0 , 37 , sizeof ( rtDW . kvqfradwlq ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . afcgtasyrg )
, rtdwData , 0 , 38 , sizeof ( rtDW . afcgtasyrg ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . bxgmk1eaw0 )
, rtdwData , 0 , 39 , sizeof ( rtDW . bxgmk1eaw0 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . nbbupkxuro )
, rtdwData , 0 , 40 , sizeof ( rtDW . nbbupkxuro ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . p4rnq0dwuk )
, rtdwData , 0 , 41 , sizeof ( rtDW . p4rnq0dwuk ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . pwk2utciwp )
, rtdwData , 0 , 42 , sizeof ( rtDW . pwk2utciwp ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . kxrkzyjlww )
, rtdwData , 0 , 43 , sizeof ( rtDW . kxrkzyjlww ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . ni51rbhl2o )
, rtdwData , 0 , 44 , sizeof ( rtDW . ni51rbhl2o ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . mmrindr4fr )
, rtdwData , 0 , 45 , sizeof ( rtDW . mmrindr4fr ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . iuyncjvcn5 )
, rtdwData , 0 , 46 , sizeof ( rtDW . iuyncjvcn5 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . j0d32edslo )
, rtdwData , 0 , 47 , sizeof ( rtDW . j0d32edslo ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . kldd00soyg )
, rtdwData , 0 , 48 , sizeof ( rtDW . kldd00soyg ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . ewri5fxxq1 )
, rtdwData , 0 , 49 , sizeof ( rtDW . ewri5fxxq1 ) ) ;
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtDW . kbqlsft4jh )
, rtdwData , 0 , 50 , sizeof ( rtDW . kbqlsft4jh ) ) ; }
mr_simscape_final_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW
, 0 , 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_simscape_final_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 9 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 9 ] = { "S-Function" , "S-Function" , "Scope" , "Scope"
, "Scope" , "Scope" , "Scope" , "S-Function" , "S-Function" , } ; static
const char_T * blockPath [ 9 ] = {
"simscape_final/powergui/EquivalentModel2/State-Space" ,
"simscape_final/powergui/EquivalentModel3/State-Space" ,
"simscape_final/Scope" , "simscape_final/25 kHz PWM Boost/Measurements" ,
"simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/Scope" ,
 "simscape_final/DC-DC MPPT Buck Controls1/IncCond Method/25 kHz PWM Buck/Measurements"
, "simscape_final/System Measurements1/DC Measurements" ,
"simscape_final/powergui/EquivalentModel2/State-Space" ,
"simscape_final/powergui/EquivalentModel3/State-Space" , } ; static const int
reason [ 9 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , 2 , } ; for ( subs [ 0 ] = 0
; subs [ 0 ] < 9 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 2 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
4 ) ; ssSetNumBlocks ( rtS , 86 ) ; ssSetNumBlockIO ( rtS , 21 ) ;
ssSetNumBlockParams ( rtS , 3444 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 1.0E-7 ) ; ssSetSampleTime ( rtS , 3 , - 2.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2638811857U ) ;
ssSetChecksumVal ( rtS , 1 , 2278787672U ) ; ssSetChecksumVal ( rtS , 2 ,
549373888U ) ; ssSetChecksumVal ( rtS , 3 , 185719008U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { real_T * x
= ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void
* ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 24 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
simscape_final_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "simscape_final" ) ;
ssSetPath ( rtS , "simscape_final" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 0.1 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 4 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 } ; static
int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 4 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "simscape_final/PV Panel1/Transfer Fcn" ,
"simscape_final/Transfer Fcn1" ,
"simscape_final/powergui/EquivalentModel3/State-Space" } ; static const
char_T * rt_LoggedStateNames [ ] = { "" , "" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 0 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 3 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 3 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . egd4eqagru ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . acjhwfjuvh ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . dnnn0nu0zb ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "xFinal" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 2 ] ;
static real_T absTol [ 2 ] = { 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 2 ] = { 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 2 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 2 ] ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 1 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
lxbjkrt1na ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 2 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 1.0E-7
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 1 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS
, 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . g5au2r45a1 = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal
( rtS , 0 , 2638811857U ) ; ssSetChecksumVal ( rtS , 1 , 2278787672U ) ;
ssSetChecksumVal ( rtS , 2 , 549373888U ) ; ssSetChecksumVal ( rtS , 3 ,
185719008U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 3 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . ous2glk3vz ; systemRan [ 2 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_simscape_final_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_simscape_final_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_simscape_final_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
