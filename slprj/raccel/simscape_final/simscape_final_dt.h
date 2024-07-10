#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_0iYiPGaMRaHpDwb4NfgRzD" , 17 , 952 } , { "uint64_T" , 18 , 8 } , {
"int64_T" , 19 , 8 } , { "uint_T" , 20 , 32 } , { "char_T" , 21 , 8 } , {
"uchar_T" , 22 , 8 } , { "time_T" , 23 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( struct_0iYiPGaMRaHpDwb4NfgRzD ) , sizeof ( uint64_T )
, sizeof ( int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof (
uchar_T ) , sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] =
{ "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "physical_connection" , "int64_T" ,
"uint64_T" , "struct_0iYiPGaMRaHpDwb4NfgRzD" , "uint64_T" , "int64_T" ,
"uint_T" , "char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition
rtBTransitions [ ] = { { ( char_T * ) ( & rtB . abuqvgw4ua [ 0 ] ) , 0 , 0 ,
27 } , { ( char_T * ) ( & rtB . ow25jkzfhv ) , 2 , 0 , 1 } , { ( char_T * ) (
& rtB . mwopycrmyl ) , 8 , 0 , 2 } , { ( char_T * ) ( & rtDW . dnnn0nu0zb [ 0
] ) , 0 , 0 , 36 } , { ( char_T * ) ( & rtDW . cy1425fqxu ) , 15 , 0 , 1 } ,
{ ( char_T * ) ( & rtDW . npdjbxplf3 . AS ) , 11 , 0 , 14 } , { ( char_T * )
( & rtDW . bisrotwkmc ) , 6 , 0 , 4 } , { ( char_T * ) ( & rtDW . g50qfbcmcf
) , 7 , 0 , 630 } , { ( char_T * ) ( & rtDW . alk0fbzgi4 [ 0 ] ) , 10 , 0 ,
23 } , { ( char_T * ) ( & rtDW . ous2glk3vz ) , 2 , 0 , 1 } , { ( char_T * )
( & rtDW . jme2moc1et ) , 3 , 0 , 3 } , { ( char_T * ) ( & rtDW . afcgtasyrg
) , 8 , 0 , 13 } } ; static DataTypeTransitionTable rtBTransTable = { 12U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . ArrayCurrent [ 0 ] ) , 0 , 0 , 3442 } , { ( char_T * ) (
& rtP . PVVICurves2DLookupTable_maxIndex [ 0 ] ) , 7 , 0 , 2 } } ; static
DataTypeTransitionTable rtPTransTable = { 2U , rtPTransitions } ;
