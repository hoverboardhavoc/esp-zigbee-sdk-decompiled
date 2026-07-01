/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_unverified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_set_unverified(aps_device_key_pair_t *key_pair,uint8_t *unverified_key)

{
  ushort uVar1;
  uint16_t uVar2;
  bool bVar3;
  int iVar4;
  aps_device_key_pair_t *key_pair_00;
  uint uVar5;
  
  if (key_pair != (aps_device_key_pair_t *)0x0) {
    memcpy(key_pair->link_key,unverified_key,0x10);
    uVar1 = (key_pair->field_8).flags;
    (key_pair->field_8).flags = uVar1 & 0xfffe;
    (key_pair->field_8).flags = uVar1 & 0xfff8 | 2;
    key_pair->incoming_frame_cntr = 0;
    key_pair->outgoing_frame_cntr = 0;
    iVar4 = core_globals_get();
    aps_secur_key_pair_set_timeout(key_pair,(ushort)*(byte *)(iVar4 + 0x9b4));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0x15d,
                "aps_secur_key_pair_set_unverified","key_pair != ((void *)0)");
  iVar4 = core_globals_get();
  uVar5 = 0;
  bVar3 = true;
  while( true ) {
    uVar5 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar4 + 0x9a4),*(undefined2 *)(iVar4 + 0x9a8),uVar5);
    if (*(ushort *)(iVar4 + 0x9a8) <= uVar5) break;
    key_pair_00 = (aps_device_key_pair_t *)(*(int *)(iVar4 + 0x9a0) + uVar5 * 0x38);
    uVar2 = key_pair_00->timeout;
    if (uVar2 != 0xffff) {
      if (uVar2 != 0) {
        key_pair_00->timeout = uVar2 - 1;
      }
      if (key_pair_00->timeout == 0) {
        aps_secur_delete_key_pair(key_pair_00);
      }
      else {
        bVar3 = false;
      }
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  if (bVar3) {
    time_ticker_unregister_receiver(3);
  }
  return;
}

