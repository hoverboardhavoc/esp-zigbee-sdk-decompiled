/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_verified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_set_verified(aps_device_key_pair_t *key_pair)

{
  uint16_t uVar1;
  bool bVar2;
  int iVar3;
  aps_device_key_pair_t *key_pair_00;
  uint uVar4;
  
  if ((key_pair != (aps_device_key_pair_t *)0x0) && (((key_pair->field_8).flags & 6) == 2)) {
    (key_pair->field_8).flags = (key_pair->field_8).flags & 0xfff9 | 4;
    key_pair->incoming_frame_cntr = 0;
    aps_secur_key_pair_set_timeout(key_pair,0xffff);
    aps_secur_store_key_pair(key_pair);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0x14e,
                "aps_secur_key_pair_set_verified",
                "key_pair != ((void *)0) && key_pair->key_attr == APS_KEY_ATTR_UNVERIFIED");
  iVar3 = core_globals_get();
  uVar4 = 0;
  bVar2 = true;
  while( true ) {
    uVar4 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar3 + 0x9a4),*(undefined2 *)(iVar3 + 0x9a8),uVar4);
    if (*(ushort *)(iVar3 + 0x9a8) <= uVar4) break;
    key_pair_00 = (aps_device_key_pair_t *)(*(int *)(iVar3 + 0x9a0) + uVar4 * 0x38);
    uVar1 = key_pair_00->timeout;
    if (uVar1 != 0xffff) {
      if (uVar1 != 0) {
        key_pair_00->timeout = uVar1 - 1;
      }
      if (key_pair_00->timeout == 0) {
        aps_secur_delete_key_pair(key_pair_00);
      }
      else {
        bVar2 = false;
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
  }
  if (bVar2) {
    time_ticker_unregister_receiver(3);
  }
  return;
}

