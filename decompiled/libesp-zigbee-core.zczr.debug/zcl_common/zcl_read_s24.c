/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_common.o -> zcl_read_s24
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_int24_t zcl_read_s24(uint8_t *buf)

{
  uint uVar1;
  ezb_zcl_uint24_t ret;
  uint uStack_4;
  
  uStack_4 = (uint)*(uint3 *)buf;
  if ((char)buf[2] < '\0') {
    uVar1 = 0xff000000;
  }
  else {
    uVar1 = 0;
  }
  return uVar1 | uStack_4;
}

