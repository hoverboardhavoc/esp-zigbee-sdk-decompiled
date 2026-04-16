/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_write_s40
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_write_s40(uint8_t *buf,ezb_zcl_int40_t val)

{
  undefined4 in_a1;
  undefined4 in_a2;
  uint8_t uStack_8;
  uint8_t uStack_7;
  uint8_t uStack_6;
  uint8_t uStack_5;
  byte bStack_4;
  byte bStack_1;
  
  uStack_8 = (uint8_t)in_a1;
  uStack_7 = (uint8_t)((uint)in_a1 >> 8);
  uStack_6 = (uint8_t)((uint)in_a1 >> 0x10);
  uStack_5 = (uint8_t)((uint)in_a1 >> 0x18);
  bStack_4 = (byte)in_a2;
  *buf = uStack_8;
  buf[1] = uStack_7;
  buf[2] = uStack_6;
  buf[3] = uStack_5;
  buf[4] = bStack_4;
  bStack_1 = (byte)((uint)in_a2 >> 0x18);
  buf[4] = bStack_4 | bStack_1 & 0x80;
  return;
}

