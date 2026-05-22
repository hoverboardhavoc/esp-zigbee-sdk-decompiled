/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_verified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_set_verified(aps_device_key_pair_t *key_pair)

{
  aps_device_key_pair_t *unaff_s0;
  ushort in_a5;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  int iStack_18;
  undefined2 uStack_14;
  anon_union_2_2_657f631f_for_aps_device_key_pair_s_8 aStack_12;
  
  if ((key_pair == (aps_device_key_pair_t *)0x0) ||
     (in_a5 = (key_pair->field_8).flags, unaff_s0 = key_pair, (in_a5 & 6) != 2)) {
    key_pair = (aps_device_key_pair_t *)__assert_func(0,0,0,0);
  }
  (key_pair->field_8).flags = in_a5 & 0xfff9 | 4;
  key_pair->incoming_frame_cntr = 0;
  key_pair->timeout = 0xffff;
  time_ticker_register_receiver(3);
  memset(&uStack_40,0,0x30);
  aps_secur_remove_stored_key_pair(unaff_s0);
  uStack_40 = *(undefined4 *)&(unaff_s0->device_address).field_0;
  uStack_3c = *(undefined4 *)((int)&(unaff_s0->device_address).field_0 + 4);
  memcpy(auStack_38,unaff_s0->link_key,0x10);
  memcpy(auStack_28,unaff_s0->passphrase,0x10);
  uStack_14._0_1_ = unaff_s0->supported_kn_methods;
  uStack_14._1_1_ = unaff_s0->supported_kn_secrets;
  iStack_18 = unaff_s0->outgoing_frame_cntr + 0x400;
  aStack_12 = unaff_s0->field_8;
  ds_internal_add_entry(9,&uStack_40,0x30);
  return;
}

