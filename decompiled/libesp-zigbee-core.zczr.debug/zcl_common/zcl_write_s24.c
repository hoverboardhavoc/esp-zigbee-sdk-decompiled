/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_write_s24
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_write_s24(uint8_t *buf,ezb_zcl_int24_t val)

{
  uint8_t uStack_4;
  uint8_t uStack_3;
  byte bStack_2;
  
  uStack_4 = (uint8_t)val;
  *buf = uStack_4;
  uStack_3 = (uint8_t)((uint)val >> 8);
  buf[1] = uStack_3;
  bStack_2 = (byte)((uint)val >> 0x10);
  buf[2] = bStack_2;
  buf[2] = bStack_2 | (byte)((uint)val >> 0x18) & 0x80;
  return;
}

