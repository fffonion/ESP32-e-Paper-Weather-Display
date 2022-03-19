#ifndef ESP32_CTRL_H_
#define ESP32_CTRL_H_

#include <Preferences.h>  // WiFi storage
#include "WiFi.h"
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>

#define SleepDuration 30 // Sleep time in minutes, aligned to the nearest minute boundary, so if 30 will always update at 00 or 30 past the hour
#define  WakeupTime    7  // Don't wakeup until after 07:00 to save battery power
#define  SleepTime     23 // Sleep after (23+1) 00:00 to save battery power
#define NightSleepStart 1
#define NightSleepEnd   9
extern long StartTime;

#define LED GPIO_NUM_19
#define ALT_BUTTON GPIO_NUM_39

void ESP32CtrlStart();
void BeginSleep(bool notimer, int CurrentHour, int CurrentMin, int CurrentSec);
void print_wakeup_reason();

extern String PrefSSID, PrefPassword;

bool WiFiSmartConfig();
uint8_t StartWiFi();
void StopWiFi();

void SetupOTA();
void HandleOTA();

typedef struct {
    float voltage;
    float percentage;
} BatteryVoltage;

BatteryVoltage GetBatteryVoltage();
BatteryVoltage GetBatteryVoltage(bool cached);

void SendStatsd();

#endif