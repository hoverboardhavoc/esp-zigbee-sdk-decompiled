/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_fcf_has_dst_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool mac_fcf_has_dst_panid(uint16_t fcf)

{
  bool bVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  
  if ((fcf & 0x3000) == 0x2000) {
    uVar2 = CONCAT22(in_register_0000202a,fcf) & 0xffffcc40;
    bVar1 = false;
    if (uVar2 != 0x8040) {
      if (0x8040 < uVar2) {
        return (CONCAT22(in_register_0000202a,fcf) & 0xffffcc00) != 0xc000 && uVar2 != 0xcc40;
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
    bVar1 = (fcf & 0xc00) != 0;
  }
  return bVar1;
}

