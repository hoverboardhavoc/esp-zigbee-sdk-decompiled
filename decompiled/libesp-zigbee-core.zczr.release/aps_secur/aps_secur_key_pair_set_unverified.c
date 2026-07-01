/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_unverified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_set_unverified(aps_device_key_pair_t *key_pair,uint8_t *unverified_key)

{
  byte bVar1;
  int iVar2;
  uint8_t *extraout_a1;
  
  if (key_pair == (aps_device_key_pair_t *)0x0) {
    key_pair = (aps_device_key_pair_t *)__assert_func(0,0,0);
    unverified_key = extraout_a1;
  }
  secur_key_copy(key_pair->link_key,unverified_key);
  key_pair->incoming_frame_cntr = 0;
  key_pair->outgoing_frame_cntr = 0;
  *(byte *)&key_pair->field_8 = *(byte *)&key_pair->field_8 & 0xf8 | 2;
  iVar2 = core_globals_get();
  bVar1 = *(byte *)(iVar2 + 0x9b4);
  key_pair->timeout = (ushort)bVar1;
  if (bVar1 == 0) {
    return;
  }
  time_ticker_register_receiver(3);
  return;
}

