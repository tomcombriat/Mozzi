#ifndef SAW_MAX_481_AT_16384_2048INT8_H_
#define SAW_MAX_481_AT_16384_2048INT8_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"


#define SAW_MAX_481_AT_16384_2048_NUM_CELLS 2048
#define SAW_MAX_481_AT_16384_2048_SAMPLERATE 2048

CONSTTABLE_STORAGE(int8_t) SAW_MAX_481_AT_16384_2048_DATA [] = 
{
0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -5, -5, -5, 
-5, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, 
-6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -8, -8, -8, -8, -8, -8, 
-8, -9, -9, -9, -9, -9, -9, -10, -10, -10, -10, -11, -11, -11, -11, -11, -12, -12, -12, -12, -12, -13, -13, -13, -13, -14, -14, -14, -14, -14, -15, -15, 
-15, -15, -15, -16, -16, -16, -16, -16, -17, -17, -17, -17, -17, -17, -17, -18, -18, -18, -18, -18, -18, -18, -18, -18, -18, -19, -19, -19, -19, -19, -19, -19, 
-19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, 
-19, -19, -19, -19, -19, -19, -20, -20, -20, -20, -20, -20, -20, -20, -20, -20, -21, -21, -21, -21, -21, -21, -21, -22, -22, -22, -22, -22, -23, -23, -23, -23, 
-23, -24, -24, -24, -24, -25, -25, -25, -25, -25, -26, -26, -26, -26, -27, -27, -27, -27, -27, -28, -28, -28, -28, -29, -29, -29, -29, -29, -29, -30, -30, -30, 
-30, -30, -30, -31, -31, -31, -31, -31, -31, -31, -31, -31, -31, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, 
-32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -33, -33, 
-33, -33, -33, -33, -33, -33, -34, -34, -34, -34, -34, -34, -34, -35, -35, -35, -35, -35, -36, -36, -36, -36, -37, -37, -37, -37, -37, -38, -38, -38, -38, -39, 
-39, -39, -39, -40, -40, -40, -40, -41, -41, -41, -41, -41, -42, -42, -42, -42, -42, -43, -43, -43, -43, -43, -43, -44, -44, -44, -44, -44, -44, -44, -44, -45, 
-45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, 
-45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -45, -46, -46, -46, -46, -46, -46, -46, -47, -47, -47, 
-47, -47, -47, -48, -48, -48, -48, -48, -49, -49, -49, -49, -50, -50, -50, -50, -51, -51, -51, -51, -52, -52, -52, -52, -53, -53, -53, -53, -54, -54, -54, -54, 
-55, -55, -55, -55, -56, -56, -56, -56, -56, -56, -57, -57, -57, -57, -57, -57, -57, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, 
-58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -57, -57, -57, -57, -57, -57, -57, -57, -57, -57, -57, 
-57, -57, -57, -57, -57, -58, -58, -58, -58, -58, -58, -58, -58, -58, -58, -59, -59, -59, -59, -59, -59, -60, -60, -60, -60, -60, -61, -61, -61, -61, -62, -62, 
-62, -62, -63, -63, -63, -64, -64, -64, -64, -65, -65, -65, -66, -66, -66, -66, -67, -67, -67, -68, -68, -68, -68, -69, -69, -69, -69, -69, -70, -70, -70, -70, 
-70, -71, -71, -71, -71, -71, -71, -71, -71, -71, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -72, -71, -71, -71, -71, -71, -71, -71, 
-71, -71, -71, -71, -71, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, -70, 
-70, -70, -70, -71, -71, -71, -71, -71, -71, -72, -72, -72, -72, -73, -73, -73, -73, -74, -74, -74, -75, -75, -75, -75, -76, -76, -76, -77, -77, -78, -78, -78, 
-79, -79, -79, -80, -80, -80, -81, -81, -81, -82, -82, -82, -82, -83, -83, -83, -83, -84, -84, -84, -84, -85, -85, -85, -85, -85, -85, -85, -85, -86, -86, -86, 
-86, -86, -86, -86, -86, -86, -86, -86, -86, -86, -85, -85, -85, -85, -85, -85, -85, -85, -84, -84, -84, -84, -84, -84, -83, -83, -83, -83, -83, -83, -82, -82, 
-82, -82, -82, -82, -82, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -81, -82, -82, -82, -82, -82, -82, -83, -83, -83, 
-84, -84, -84, -85, -85, -85, -86, -86, -86, -87, -87, -88, -88, -89, -89, -89, -90, -90, -91, -91, -92, -92, -93, -93, -94, -94, -95, -95, -95, -96, -96, -97, 
-97, -97, -98, -98, -99, -99, -99, -99, -100, -100, -100, -100, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -101, -100, -100, 
-100, -100, -99, -99, -99, -99, -98, -98, -98, -97, -97, -96, -96, -96, -95, -95, -94, -94, -94, -93, -93, -93, -92, -92, -92, -91, -91, -91, -90, -90, -90, -90, 
-89, -89, -89, -89, -89, -89, -89, -89, -89, -89, -89, -89, -89, -89, -90, -90, -90, -91, -91, -91, -92, -92, -93, -93, -94, -95, -95, -96, -97, -97, -98, -99, 
-100, -100, -101, -102, -103, -104, -105, -106, -107, -108, -109, -110, -111, -112, -112, -113, -114, -115, -116, -117, -118, -119, -120, -120, -121, -122, -123, -123, -124, -124, -125, -125, 
-126, -126, -126, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -125, -125, -124, -123, -122, -122, -121, -119, -118, -117, -116, -114, -113, -111, -109, -107, -106, -104, -102, 
-99, -97, -95, -92, -90, -87, -85, -82, -79, -76, -73, -70, -67, -64, -61, -57, -54, -51, -47, -44, -40, -37, -33, -29, -26, -22, -18, -15, -11, -7, -3, 0, 
3, 7, 11, 15, 18, 22, 26, 29, 33, 37, 40, 44, 47, 51, 54, 57, 61, 64, 67, 70, 73, 76, 79, 82, 85, 87, 90, 92, 95, 97, 99, 102, 
104, 106, 107, 109, 111, 113, 114, 116, 117, 118, 119, 121, 122, 122, 123, 124, 125, 125, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 126, 126, 126, 125, 
125, 124, 124, 123, 123, 122, 121, 120, 120, 119, 118, 117, 116, 115, 114, 113, 112, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 100, 99, 
98, 97, 97, 96, 95, 95, 94, 93, 93, 92, 92, 91, 91, 91, 90, 90, 90, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 89, 90, 
90, 90, 90, 91, 91, 91, 92, 92, 92, 93, 93, 93, 94, 94, 94, 95, 95, 96, 96, 96, 97, 97, 98, 98, 98, 99, 99, 99, 99, 100, 100, 100, 
100, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 100, 100, 100, 100, 99, 99, 99, 99, 98, 98, 97, 97, 97, 
96, 96, 95, 95, 95, 94, 94, 93, 93, 92, 92, 91, 91, 90, 90, 89, 89, 89, 88, 88, 87, 87, 86, 86, 86, 85, 85, 85, 84, 84, 84, 83, 
83, 83, 82, 82, 82, 82, 82, 82, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 82, 82, 82, 82, 82, 82, 
82, 83, 83, 83, 83, 83, 83, 84, 84, 84, 84, 84, 84, 85, 85, 85, 85, 85, 85, 85, 85, 86, 86, 86, 86, 86, 86, 86, 86, 86, 86, 86, 
86, 86, 85, 85, 85, 85, 85, 85, 85, 85, 84, 84, 84, 84, 83, 83, 83, 83, 82, 82, 82, 82, 81, 81, 81, 80, 80, 80, 79, 79, 79, 78, 
78, 78, 77, 77, 76, 76, 76, 75, 75, 75, 75, 74, 74, 74, 73, 73, 73, 73, 72, 72, 72, 72, 71, 71, 71, 71, 71, 71, 70, 70, 70, 70, 
70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 71, 71, 71, 71, 71, 71, 
71, 71, 71, 71, 71, 71, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 71, 71, 71, 71, 71, 71, 71, 71, 71, 70, 70, 
70, 70, 70, 69, 69, 69, 69, 69, 68, 68, 68, 68, 67, 67, 67, 66, 66, 66, 66, 65, 65, 65, 64, 64, 64, 64, 63, 63, 63, 62, 62, 62, 
62, 61, 61, 61, 61, 60, 60, 60, 60, 60, 59, 59, 59, 59, 59, 59, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 57, 57, 57, 57, 57, 57, 
57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 
58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 57, 57, 57, 57, 57, 57, 57, 56, 56, 56, 56, 56, 56, 55, 55, 55, 55, 54, 
54, 54, 54, 53, 53, 53, 53, 52, 52, 52, 52, 51, 51, 51, 51, 50, 50, 50, 50, 49, 49, 49, 49, 48, 48, 48, 48, 48, 47, 47, 47, 47, 
47, 47, 46, 46, 46, 46, 46, 46, 46, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 
45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 
44, 44, 44, 44, 44, 44, 44, 44, 43, 43, 43, 43, 43, 43, 42, 42, 42, 42, 42, 41, 41, 41, 41, 41, 40, 40, 40, 40, 39, 39, 39, 39, 
38, 38, 38, 38, 37, 37, 37, 37, 37, 36, 36, 36, 36, 35, 35, 35, 35, 35, 34, 34, 34, 34, 34, 34, 34, 33, 33, 33, 33, 33, 33, 33, 
33, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 
32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 
30, 30, 29, 29, 29, 29, 29, 29, 28, 28, 28, 28, 27, 27, 27, 27, 27, 26, 26, 26, 26, 25, 25, 25, 25, 25, 24, 24, 24, 24, 23, 23, 
23, 23, 23, 22, 22, 22, 22, 22, 21, 21, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 19, 19, 19, 19, 19, 19, 19, 
19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 
19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 17, 17, 16, 16, 16, 16, 16, 15, 15, 15, 15, 
15, 14, 14, 14, 14, 14, 13, 13, 13, 13, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 8, 8, 
8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 
6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 
5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 
 };

#endif