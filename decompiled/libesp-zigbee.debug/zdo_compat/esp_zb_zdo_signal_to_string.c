/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zdo_compat.o -> esp_zb_zdo_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

char * esp_zb_zdo_signal_to_string(esp_zb_app_signal_type_t signal)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  char *pcVar2;
  
  uVar1 = CONCAT22(in_register_0000202a,signal);
  if (uVar1 < 0x205) {
    pcVar2 = (char *)ezb_app_signal_to_string();
  }
  else if (uVar1 == 0x20c) {
    pcVar2 = "ZDO Config Ready";
  }
  else {
    if (uVar1 < 0x20d) {
      if (uVar1 == 0x209) {
        return "BDB Touchlink Network";
      }
      if (uVar1 < 0x20a) {
        if (uVar1 == 0x207) {
          return "BDB Network Joined Router";
        }
        if (uVar1 == 0x208) {
          return "BDB Touchlink Target";
        }
        if (uVar1 == 0x206) {
          return "BDB Network Started";
        }
      }
      else {
        if (uVar1 == 0x20a) {
          return "ZGP Commissioning";
        }
        if (uVar1 == 0x20b) {
          return "Can Sleep";
        }
      }
    }
    else {
      if (uVar1 == 0x20f) {
        return "BDB Formation Cancelled";
      }
      if (uVar1 < 0x210) {
        if (uVar1 == 0x20d) {
          return "BDB TC Rejoin Done";
        }
        if (uVar1 == 0x20e) {
          return "BDB Steering Cancelled";
        }
      }
      else {
        if (uVar1 == 0x210) {
          return "ZGP Mode Change";
        }
        if (uVar1 == 0x211) {
          return "ZGP Approve Commissioning";
        }
      }
    }
    pcVar2 = (char *)ezb_app_signal_to_string(0x205);
  }
  return pcVar2;
}

