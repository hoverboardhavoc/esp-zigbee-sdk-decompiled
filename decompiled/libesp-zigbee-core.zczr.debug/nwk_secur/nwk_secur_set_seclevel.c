/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_set_seclevel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_secur_set_seclevel(uint param_1)

{
  int iVar1;
  void *__src;
  uint uVar2;
  undefined4 extraout_a1;
  byte abStack_31 [13];
  
  if (param_1 < 8) {
    iVar1 = core_globals_get();
    *(byte *)(iVar1 + 0xa23) = *(byte *)(iVar1 + 0xa23) & 0xf1 | (byte)((param_1 & 7) << 1);
    return;
  }
  __src = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_secur.c",0x7b,
                                "nwk_secur_set_seclevel","seclevel < SECUR_SECLEVEL_MAX_NR");
  iVar1 = core_globals_get();
  uVar2 = nwk_secur_find_slot_by_seq(iVar1 + 0x9fc,extraout_a1);
  if (1 < uVar2) {
    abStack_31[0] = (byte)((uint)*(undefined4 *)(iVar1 + 0xa20) >> 0x1d) & 3;
    uVar2 = bitmap_find_first_zero_bit(abStack_31,2);
    uVar2 = uVar2 & 0xff;
    if (1 < uVar2) {
      uVar2 = *(byte *)(iVar1 + 0xa23) & 1 ^ 1;
    }
  }
  *(byte *)(iVar1 + 0xa23) =
       (byte)((*(uint *)(iVar1 + 0xa20) >> 0x1d & 3 | 1 << (uVar2 & 0x1f) & 3U) << 5) |
       *(byte *)(iVar1 + 0xa23) & 0x9f;
  if (__src == (void *)0x0) {
    random_crypto_fill_buffer(iVar1 + uVar2 * 0x11 + 0xa00,0x10);
  }
  else {
    memcpy((void *)(iVar1 + uVar2 * 0x11 + 0xa00),__src,0x10);
  }
  *(char *)(iVar1 + uVar2 * 0x11 + 0xa10) = (char)extraout_a1;
  return;
}

