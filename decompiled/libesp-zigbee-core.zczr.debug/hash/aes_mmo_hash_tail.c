/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> aes_mmo_hash_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aes_mmo_hash_tail(void *param_1,uint param_2,undefined4 param_3)

{
  uint __n;
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  __n = param_2 & 0xf;
  if (param_2 < 0x20000000) {
    local_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    if (__n == 0) goto _L0;
  }
  else {
    param_1 = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0x72,
                                    "aes_mmo_hash_tail",
                                    "orig_len <= ((1U << (2U * (16) - 3U)) - 1U)");
  }
  memcpy(&local_30,param_1,__n);
_L0:
  *(undefined1 *)((int)&local_30 + __n) = 0x80;
  if (param_2 < 0x2000) {
    iVar1 = 2;
  }
  else {
    iVar1 = 6;
  }
  if (0x10 < __n + iVar1 + 1) {
    aes_mmo_hash_core(&local_30,param_3);
    local_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
  }
  if (iVar1 == 2) {
    uStack_24 = CONCAT22((ushort)(byte)((param_2 << 0x13) >> 0x18) |
                         (ushort)(((param_2 << 0x13) >> 0x10) << 8),(undefined2)uStack_24);
  }
  else {
    write_be32(param_2 << 3,(int)&uStack_28 + 2);
  }
  aes_mmo_hash_core(&local_30,param_3);
  return;
}

