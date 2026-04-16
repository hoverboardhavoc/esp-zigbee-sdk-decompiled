/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> array_copy_u24_to_u32
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void array_copy_u24_to_u32(uint32_t *dst,esp_zb_uint24_t *src,size_t num)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < num; uVar1 = uVar1 + 1) {
    dst[uVar1] = (uint)(uint3)src[uVar1];
  }
  return;
}

