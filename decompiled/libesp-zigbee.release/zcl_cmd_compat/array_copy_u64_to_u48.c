/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> array_copy_u64_to_u48
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void array_copy_u64_to_u48(esp_zb_uint48_t *dst,uint64_t *src,size_t num)

{
  undefined2 uVar1;
  size_t sVar2;
  size_t sVar3;
  undefined4 uVar4;
  esp_zb_uint48_t *peVar5;
  
  sVar2 = 0;
  do {
    uVar4 = (undefined4)src[sVar2];
    uVar1 = *(undefined2 *)((int)(src + sVar2) + 4);
    sVar3 = sVar2 + 1;
    peVar5 = dst + sVar2;
    *(char *)&peVar5->low = (char)uVar4;
    *(char *)((int)&peVar5->low + 1) = (char)((uint)uVar4 >> 8);
    *(char *)&peVar5->high = (char)uVar1;
    *(char *)((int)&peVar5->low + 2) = (char)((uint)uVar4 >> 0x10);
    *(char *)((int)&peVar5->low + 3) = (char)((uint)uVar4 >> 0x18);
    *(char *)((int)&peVar5->high + 1) = (char)((ushort)uVar1 >> 8);
    sVar2 = sVar3;
  } while (num != sVar3);
  return;
}

