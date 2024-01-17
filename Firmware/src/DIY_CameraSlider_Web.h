
#ifndef DIY_CAMERASLIDER_WEB_H
#define DIY_CAMERASLIDER_WEB_H

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "config_cameraslider.h"

// Helper function that allows us to replace template variable in .html file
// with a value from our running code.
// ie. Any instance of %RAIL_LENGTH% will be replaced with the actual
// value of `SliderConfig.Config.rail_length` in our firmware
String template_const_processor(const String &var);

void setupWebServer(void);

// Helper function to move camera slider into requested position
// arguments
//      - move_type -> enum indicating relative or absolute positioning
//      - request   -> HTTP request pointer
void WebAPI_MoveToPosition(CameraSliderMovement_t move_type, AsyncWebServerRequest *request);

// Helper function to retrieve integer value from HTTP request
// arguments
//      - request   -> HTTP request pointer
//      - argName   -> name of the http argument
//      - pInt      -> pointer to where we want value to be stored
// returns
//      - true      -> value has been found in HTTP request and stored in pInt
//      - false     -> HTTP request does NOT contain valid value. pInt was not modified
bool WebAPI_GetIntValueFromRequest(AsyncWebServerRequest *pRequest, const char *argName, int32_t *pInt);

// Helper function to update SliderConfig from a HTTP request
// arguments
//      - parameter -> enum indicating which parameter we want changed
//      - request   -> HTTP request pointer
// returns
//      - true      -> value has been succesfully updated
//      - false     -> failed to update value
bool WebAPI_UpdateMotorConfig(CameraSliderConfig_t parameter, AsyncWebServerRequest *pRequest);

#endif // DIY_CAMERASLIDER_WEB_H
