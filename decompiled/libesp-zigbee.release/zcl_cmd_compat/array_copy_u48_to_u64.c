/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> array_copy_u48_to_u64
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void array_copy_u48_to_u64(uint64_t *dst,esp_zb_uint48_t *src,size_t num)

{
  uint32_t uVar1;
  size_t sVar2;
  size_t sVar3;
  
  sVar2 = 0;
  do {
    sVar3 = sVar2 + 1;
    uVar1 = src[sVar2].low;
    *(uint *)((int)(dst + sVar2) + 4) = (uint)src[sVar2].high;
    *(uint32_t *)(dst + sVar2) = uVar1;
    sVar2 = sVar3;
  } while (num != sVar3);
  return;
}

