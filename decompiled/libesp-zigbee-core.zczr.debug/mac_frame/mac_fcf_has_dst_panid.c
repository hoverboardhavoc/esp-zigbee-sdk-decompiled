/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_fcf_has_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool mac_fcf_has_dst_panid(uint16_t fcf)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  
  if ((fcf & 0x3000) != 0x2000) {
    return (fcf & 0xc00) != 0;
  }
  uVar1 = CONCAT22(in_register_0000202a,fcf) & 0xffffcc40;
  if (uVar1 == 0x8040) {
    return false;
  }
  if (0x8040 < uVar1) {
    if (uVar1 == 0xc040) {
      return false;
    }
    if (uVar1 != 0xcc40) {
      if (uVar1 != 0xc000) {
        return true;
      }
      return false;
    }
    return false;
  }
  if (uVar1 == 0xc40) {
    return false;
  }
  if (0xc40 < uVar1) {
    if (uVar1 != 0x8000) {
      return true;
    }
    return false;
  }
  if (uVar1 == 0) {
    return false;
  }
  if (uVar1 != 0x840) {
    return true;
  }
  return false;
}

