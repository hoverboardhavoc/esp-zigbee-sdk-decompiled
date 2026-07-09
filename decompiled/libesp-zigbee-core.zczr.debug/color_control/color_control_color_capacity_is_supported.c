/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_color_capacity_is_supported
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort color_control_color_capacity_is_supported(uint param_1)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = color_control_srv_get_attr_desc(0x400a);
  if (iVar2 == 0) {
    return 0;
  }
  uVar1 = **(ushort **)(iVar2 + 8);
  if (param_1 < 0x44) {
    if (0x3f < param_1) {
      return uVar1 >> 1 & 1;
    }
    if (param_1 < 10) {
      if (6 < param_1) {
        return uVar1 >> 3 & 1;
      }
      if (param_1 < 7) {
        return uVar1 & 1;
      }
      return 0;
    }
    if (param_1 != 10) {
      return 0;
    }
  }
  else {
    if (param_1 == 0x47) {
      return 1;
    }
    if (param_1 < 0x48) {
      if (param_1 == 0x44) {
        return uVar1 >> 2 & 1;
      }
      return 0;
    }
    if (1 < (param_1 - 0x4b & 0xff)) {
      return 0;
    }
  }
  return uVar1 >> 4 & 1;
}

