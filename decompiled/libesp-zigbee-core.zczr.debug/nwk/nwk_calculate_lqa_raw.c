/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_calculate_lqa_raw
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
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = CONCAT31(in_register_0000202d,rssi);
  uVar3 = CONCAT31(in_register_00002029,lqi);
  if (uVar3 < 7) {
    uVar3 = 7;
  }
  if (10 < (uVar3 & 0xff)) {
    uVar3 = 10;
  }
  if (iVar2 < -100) {
    iVar2 = -100;
  }
  cVar1 = (char)iVar2;
  if ('\b' < cVar1) {
    cVar1 = '\b';
  }
  iVar2 = ((uVar3 & 0xff) - 6) * (cVar1 + 0x65) * 0xff;
  return (char)((ulonglong)((longlong)iVar2 * 0x964fda6d) >> 0x28) - (char)(iVar2 >> 0x1f);
}

