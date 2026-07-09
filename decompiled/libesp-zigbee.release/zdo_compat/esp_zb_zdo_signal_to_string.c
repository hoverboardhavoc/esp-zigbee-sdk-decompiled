/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_compat.o -> esp_zb_zdo_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * esp_zb_zdo_signal_to_string(uint param_1)

{
  char *pcVar1;
  
  if (0x204 < param_1) {
    if (param_1 == 0x20c) {
      return "ZDO Config Ready";
    }
    if (param_1 < 0x20d) {
      if (param_1 == 0x209) {
        return "BDB Touchlink Network";
      }
      if (0x209 < param_1) {
        if (param_1 != 0x20a) {
          return "Can Sleep";
        }
        return "ZGP Commissioning";
      }
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
      if (param_1 == 0x20f) {
        return "BDB Formation Cancelled";
      }
      if (param_1 < 0x210) {
        if (param_1 != 0x20d) {
          return "BDB Steering Cancelled";
        }
        return "BDB TC Rejoin Done";
      }
      if (param_1 == 0x210) {
        return "ZGP Mode Change";
      }
      if (param_1 == 0x211) {
        return "ZGP Approve Commissioning";
      }
    }
    param_1 = 0x205;
  }
  pcVar1 = (char *)ezb_app_signal_to_string(param_1);
  return pcVar1;
}

