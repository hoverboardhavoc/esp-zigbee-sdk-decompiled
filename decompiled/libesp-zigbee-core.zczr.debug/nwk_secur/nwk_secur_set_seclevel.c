/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_secur.o -> nwk_secur_set_seclevel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_secur_set_seclevel(uint8_t seclevel)

{
  uint8_t uVar1;
  undefined3 in_register_00002029;
  int iVar2;
  void *__src;
  undefined3 extraout_var;
  uint uVar3;
  uint8_t key_seq;
  byte abStack_31 [13];
  
  if (CONCAT31(in_register_00002029,seclevel) < 8) {
    iVar2 = core_globals_get();
    *(byte *)(iVar2 + 0xa23) = *(byte *)(iVar2 + 0xa23) & 0xf1 | (byte)((seclevel & 7) << 1);
    return;
  }
  __src = (void *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_secur.c",0x7b,
                                "nwk_secur_set_seclevel","seclevel < SECUR_SECLEVEL_MAX_NR");
  iVar2 = core_globals_get();
  uVar1 = nwk_secur_find_slot_by_seq((nwk_secur_context_t *)(iVar2 + 0x9fc),key_seq);
  uVar3 = CONCAT31(extraout_var,uVar1);
  if (1 < uVar3) {
    abStack_31[0] = (byte)((uint)*(undefined4 *)(iVar2 + 0xa20) >> 0x1d) & 3;
    uVar3 = bitmap_find_first_zero_bit(abStack_31,2);
    uVar3 = uVar3 & 0xff;
    if (1 < uVar3) {
      uVar3 = *(byte *)(iVar2 + 0xa23) & 1 ^ 1;
    }
  }
  *(byte *)(iVar2 + 0xa23) =
       (byte)((*(uint *)(iVar2 + 0xa20) >> 0x1d & 3 | 1 << (uVar3 & 0x1f) & 3U) << 5) |
       *(byte *)(iVar2 + 0xa23) & 0x9f;
  if (__src == (void *)0x0) {
    random_crypto_fill_buffer(iVar2 + uVar3 * 0x11 + 0xa00,0x10);
  }
  else {
    memcpy((void *)(iVar2 + uVar3 * 0x11 + 0xa00),__src,0x10);
  }
  *(uint8_t *)(iVar2 + uVar3 * 0x11 + 0xa10) = key_seq;
  return;
}

