#ifndef MAIN_H
#define MAIN_H

#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <ESPmDNS.h>
#include <FlexyStepper.h>
#include "config_cameraslider.h"
#include "config_wifi.h"
#include "include/PersistSettings.h"

extern AsyncWebServer server;
extern int WiFi_status;

struct SliderConfigStruct
{
    static const unsigned int Version = 1;

    uint16_t rail_length = RAIL_LENGTH_MM;
    uint16_t min_slider_step = MIN_STEP_SLIDER;

    int homing_direction = -1;
    int slider_direction = 1;
    int rotate_direction = 1;

    uint16_t slide_steps_per_mm = SLIDE_STEPS_PER_MM;
    uint16_t pan_steps_per_degree = PAN_STEPS_PER_DEGREE;

    uint16_t homing_speed_slide = DEFAULT_HOMING_SPEED_SLIDE;
    uint16_t homing_speed_pan = DEFAULT_HOMING_SPEED_PAN;

    float default_slider_speed = DEFAULT_SLIDE_TO_POS_SPEED;
    float default_slider_accel = DEFAULT_SLIDE_TO_POS_ACCEL;
    float default_rotate_speed = DEFAULT_ROTATE_TO_POS_SPEED;
    float default_rotate_accel = DEFAULT_ROTATE_TO_POS_ACCEL;
};

extern PersistSettings<SliderConfigStruct> SliderConfig;

void setup();
void loop();

#endif // MAIN_H
