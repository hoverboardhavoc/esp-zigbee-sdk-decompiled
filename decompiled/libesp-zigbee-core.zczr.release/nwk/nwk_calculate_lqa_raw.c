/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_calculate_lqa_raw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_calculate_lqa_raw(uint8_t lqi,int8_t rssi)

{
  undefined3 in_register_00002029;
  undefined3 in_register_0000202d;
  uint uVar1;
  int iVar2;
  
  iVar2 = CONCAT31(in_register_0000202d,rssi);
  uVar1 = (uint)lqi;
  if (CONCAT31(in_register_00002029,lqi) < 7) {
    uVar1 = 7;
  }
  if (iVar2 < -100) {
    iVar2 = -100;
  }
  iVar2 = (int)(char)iVar2;
  if (10 < uVar1) {
    uVar1 = 10;
  }
  if (8 < iVar2) {
    iVar2 = 8;
  }
  return (uint8_t)((int)((uVar1 - 6) * ((iVar2 + 0x65) * 0x1000000 >> 0x18) * 0xff) / 0x1b4);
}

