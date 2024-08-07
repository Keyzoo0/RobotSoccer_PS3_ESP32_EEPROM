#include <PS4Controller.h>
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_err.h"


//motor1 
#define M1A  23
#define M1B  22
//motor2 
#define M2A  18
#define M2B  19
#define EN 21


#define PWM_M1A 1 
#define PWM_M1B 2 
#define PWM_M2A 3 
#define PWM_M2B 4 

#define M1 1
#define M2 2


#define res 10
#define freq 20000


#define lambda 4
#define d2r(x) x*(PI/180)

#define LengthAlpha 0.1 // Ubah Disini untuk panjang dari sumbu roda ke tengah roda

int16_t x;
int16_t y;
int16_t th;

float atanVal;
int xL, yL;
int xR, yR;

int SpeedM = 255 ,
    SpeedM2 = 255 ;
int inv_yR ;

int m1, m2, m3 , m4;
