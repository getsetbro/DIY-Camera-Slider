#include <stdint.h>
#include "config_cameraslider.h"

#ifndef DIY_CAMERASLIDER_MOTORCONTROL_H
#define DIY_CAMERASLIDER_MOTORCONTROL_H

void CameraSlider_tick(void);
void setupMotors();
void CameraSlider_MoveToPositionRelative(float xPos, float xSpeed, float xAccel, float rAngle, float rSpeed, float rAccel);
void CameraSlider_MoveToPositionAbsolute(float xPos, float xSpeed, float xAccel, float rSteps, float rSpeed, float rAccel);
void CameraSlider_MoveToStart(float xSpeed, float xAccel, float rSpeed, float rAccel);
void CameraSlider_MoveToEnd(float xSpeed, float xAccel, float rSpeed, float rAccel);
void CameraSlider_HomeSlidingRail(void);
bool CameraSlider_getMotorState();
bool CameraSlider_SetState(sliderState_t newState);
void CameraSlider_EnableMotors(bool enable);
bool CameraSlider_FormatJSON_CameraSliderStatus(char *buff, int size);
bool CameraSlider_FormatJSON_CameraConfig(char *buff, int size);
bool CameraSlider_getHomingState(void);
bool CameraSlider_StartMotion(void);
bool CameraSlider_SetDuration(uint32_t durationSec);
bool CameraSlider_SetStartPosition(float slideStartPos, float rotStartPos);
bool CameraSlider_SetEndPosition(float slideEndPos, float rotEndPos);
bool CameraSlider_StoreAsStartPosition(void);
bool CameraSlider_StoreAsEndPosition(void);
bool CameraSlider_StoreAsRotationHome(void);
float getSliderPos();
float getRotationPos(bool calculateDegrees);
void CameraSlider_UpdateRailLength(uint32_t rail_length);

#endif // DIY_CAMERASLIDER_MOTORCONTROL_H
