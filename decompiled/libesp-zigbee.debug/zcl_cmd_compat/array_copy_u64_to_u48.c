/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> array_copy_u64_to_u48
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void array_copy_u64_to_u48(esp_zb_uint48_t *dst,uint64_t *src,size_t num)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  esp_zb_uint48_t *peVar4;
  
  for (uVar2 = 0; uVar2 < num; uVar2 = uVar2 + 1) {
    uVar3 = (undefined4)src[uVar2];
    uVar1 = *(undefined2 *)((int)(src + uVar2) + 4);
    peVar4 = dst + uVar2;
    *(char *)&peVar4->low = (char)uVar3;
    *(char *)((int)&peVar4->low + 1) = (char)((uint)uVar3 >> 8);
    *(char *)((int)&peVar4->low + 2) = (char)((uint)uVar3 >> 0x10);
    *(char *)((int)&peVar4->low + 3) = (char)((uint)uVar3 >> 0x18);
    *(char *)&peVar4->high = (char)uVar1;
    *(char *)((int)&peVar4->high + 1) = (char)((ushort)uVar1 >> 8);
  }
  return;
}

