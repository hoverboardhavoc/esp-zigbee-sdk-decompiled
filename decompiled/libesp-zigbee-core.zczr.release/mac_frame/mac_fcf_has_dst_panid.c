/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_fcf_has_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool mac_fcf_has_dst_panid(uint param_1)

{
  bool bVar1;
  uint uVar2;
  
  if ((param_1 & 0x3000) == 0x2000) {
    uVar2 = param_1 & 0xffffcc40;
    bVar1 = false;
    if (uVar2 != 0x8040) {
      if (0x8040 < uVar2) {
        return (param_1 & 0xffffcc00) != 0xc000 && uVar2 != 0xcc40;
      }
      if (uVar2 != 0xc40) {
        if (uVar2 < 0xc41) {
          return uVar2 != 0x840 && uVar2 != 0;
        }
        return uVar2 != 0x8000;
      }
    }
  }
  else {
    bVar1 = (param_1 & 0xc00) != 0;
  }
  return bVar1;
}

