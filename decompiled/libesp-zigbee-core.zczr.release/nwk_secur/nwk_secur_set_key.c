/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_secur.o -> nwk_secur_set_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_secur_set_key(void *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bStack_21;
  
  iVar1 = core_globals_get();
  iVar4 = iVar1 + 0x9fc;
  uVar2 = nwk_secur_find_slot_by_seq(iVar4,param_2);
  if (1 < uVar2) {
    bStack_21 = (byte)((uint)*(undefined4 *)(iVar1 + 0xa20) >> 0x1d) & 3;
    uVar2 = bitmap_find_first_zero_bit(&bStack_21,2);
    uVar2 = uVar2 & 0xff;
    if (1 < uVar2) {
      uVar2 = *(byte *)(iVar1 + 0xa23) & 1 ^ 1;
    }
  }
  *(byte *)(iVar1 + 0xa23) =
       (byte)(((1 << (uVar2 & 0x1f) | *(uint *)(iVar1 + 0xa20) >> 0x1d) & 3) << 5) |
       *(byte *)(iVar1 + 0xa23) & 0x9f;
  iVar3 = (-uVar2 & 0x11) + 4;
  if (param_1 == (void *)0x0) {
    random_crypto_fill_buffer(iVar4 + iVar3,0x10);
  }
  else {
    memcpy((void *)(iVar4 + iVar3),param_1,0x10);
  }
  *(char *)(iVar1 + uVar2 * 0x11 + 0xa10) = (char)param_2;
  return;
}

