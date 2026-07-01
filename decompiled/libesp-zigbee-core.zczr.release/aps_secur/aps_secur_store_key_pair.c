/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_store_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_secur_store_key_pair(aps_device_key_pair_t *key_pair)

{
  ezb_err_t eVar1;
  undefined4 local_40;
  dataset_aps_key_pair_t ds_key_pair;
  
  memset(&local_40,0,0x30);
  aps_secur_remove_stored_key_pair(key_pair);
  local_40 = *(undefined4 *)&(key_pair->device_address).field_0;
  ds_key_pair.device_address.field_0.u64._0_4_ =
       *(undefined4 *)((int)&(key_pair->device_address).field_0 + 4);
  secur_key_copy(ds_key_pair.device_address.field_0.u8 + 4,key_pair->link_key);
  secur_key_copy(ds_key_pair.link_key + 0xc,key_pair->passphrase);
  ds_key_pair.outgoing_frame_cntr._0_1_ = key_pair->supported_kn_methods;
  ds_key_pair.outgoing_frame_cntr._1_1_ = key_pair->supported_kn_secrets;
  ds_key_pair.passphrase._12_4_ = key_pair->outgoing_frame_cntr + 0x400;
  ds_key_pair.outgoing_frame_cntr._2_2_ = key_pair->field_8;
  eVar1 = ds_internal_add_entry(9,&local_40,0x30);
  return eVar1;
}

