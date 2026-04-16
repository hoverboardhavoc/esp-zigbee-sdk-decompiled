/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_lqa_to_rssi
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

int8_t nwk_lqa_to_rssi(uint8_t lqa)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  iVar1 = CONCAT31(in_register_00002029,lqa);
  if (iVar1 == 0) {
    iVar1 = __assert_func(0,0,0);
  }
  return (int8_t)((uint)(((iVar1 * 0x6d) / 0xff + -0x65) * 0x1000000) >> 0x18);
}

