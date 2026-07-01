/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_setup_ic_key_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_setup_ic_key_continue(aps_device_key_pair_t *key_pair)

{
  ushort uVar1;
  
  memcpy(key_pair->passphrase,key_pair->link_key,0x10);
  uVar1 = (key_pair->field_8).flags;
  (key_pair->field_8).flags = uVar1 & 0xfff9;
  (key_pair->field_8).flags = uVar1 & 0xfff8;
  (key_pair->field_8).flags = uVar1 & 0xff38 | 0x40;
  key_pair->timeout = 0xffff;
  key_pair->incoming_frame_cntr = 0;
  key_pair->outgoing_frame_cntr = 0;
  return;
}

