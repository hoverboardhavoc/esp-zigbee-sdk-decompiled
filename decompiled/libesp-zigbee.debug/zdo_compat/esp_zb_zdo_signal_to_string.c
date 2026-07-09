/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_compat.o -> esp_zb_zdo_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * esp_zb_zdo_signal_to_string(uint param_1)

{
  char *pcVar1;
  
  if (param_1 < 0x205) {
    pcVar1 = (char *)ezb_app_signal_to_string();
  }
  else if (param_1 == 0x20c) {
    pcVar1 = "ZDO Config Ready";
  }
  else {
    if (param_1 < 0x20d) {
      if (param_1 == 0x209) {
        return "BDB Touchlink Network";
      }
      if (param_1 < 0x20a) {
        if (param_1 == 0x207) {
          return "BDB Network Joined Router";
        }
        if (param_1 == 0x208) {
          return "BDB Touchlink Target";
        }
        if (param_1 == 0x206) {
          return "BDB Network Started";
        }
      }
      else {
        if (param_1 == 0x20a) {
          return "ZGP Commissioning";
        }
        if (param_1 == 0x20b) {
          return "Can Sleep";
        }
      }
    }
    else {
      if (param_1 == 0x20f) {
        return "BDB Formation Cancelled";
      }
      if (param_1 < 0x210) {
        if (param_1 == 0x20d) {
          return "BDB TC Rejoin Done";
        }
        if (param_1 == 0x20e) {
          return "BDB Steering Cancelled";
        }
      }
      else {
        if (param_1 == 0x210) {
          return "ZGP Mode Change";
        }
        if (param_1 == 0x211) {
          return "ZGP Approve Commissioning";
        }
      }
    }
    pcVar1 = (char *)ezb_app_signal_to_string(0x205);
  }
  return pcVar1;
}

