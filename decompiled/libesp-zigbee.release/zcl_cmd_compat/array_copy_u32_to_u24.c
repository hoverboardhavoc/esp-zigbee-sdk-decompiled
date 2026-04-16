/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> array_copy_u32_to_u24
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void array_copy_u32_to_u24(esp_zb_uint24_t *dst,uint32_t *src,size_t num)

{
  size_t sVar1;
  uint32_t *puVar2;
  uint uVar3;
  
  sVar1 = 0;
  do {
    puVar2 = src + sVar1;
    sVar1 = sVar1 + 1;
    uVar3 = *puVar2 & 0xffffff;
    *(char *)&dst->low = (char)uVar3;
    *(char *)((int)&dst->low + 1) = (char)(uVar3 >> 8);
    dst->high = (uint8_t)(uVar3 >> 0x10);
    dst = dst + 1;
  } while (num != sVar1);
  return;
}

