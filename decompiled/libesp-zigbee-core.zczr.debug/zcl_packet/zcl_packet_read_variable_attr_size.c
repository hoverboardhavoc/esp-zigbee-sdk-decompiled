/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_read_variable_attr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_read_variable_attr_size(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x22) {
    return 4;
  }
  if (param_1 < 0x23) {
    if (param_1 == 0x1a) {
      return 4;
    }
    if (param_1 < 0x1b) {
      if (param_1 == 0xd) {
        return 8;
      }
      if (param_1 < 0xe) {
        if (param_1 == 10) {
          return 4;
        }
        if (param_1 == 0xc) {
          return 8;
        }
      }
      else if (param_1 == 0xe) {
        return 8;
      }
    }
    else {
      if (param_1 == 0x1d) {
        return 8;
      }
      if (param_1 == 0x1e) {
        return 8;
      }
      if (param_1 == 0x1c) {
        return 8;
      }
    }
  }
  else {
    if (param_1 == 0x2a) {
      return 4;
    }
    if (param_1 < 0x2b) {
      if (param_1 == 0x25) {
        return 8;
      }
      if (param_1 == 0x26) {
        return 8;
      }
      if (param_1 == 0x24) {
        return 8;
      }
    }
    else {
      if (param_1 == 0x2d) {
        return 8;
      }
      if (param_1 == 0x2e) {
        return 8;
      }
      if (param_1 == 0x2c) {
        return 8;
      }
    }
  }
  uVar1 = zcl_packet_read_variable_attr_actual_size();
  return uVar1;
}

