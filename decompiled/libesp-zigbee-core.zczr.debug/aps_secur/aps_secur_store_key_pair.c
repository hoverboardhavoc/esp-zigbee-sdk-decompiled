/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_store_key_pair
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
  
  local_40 = 0;
  ds_key_pair.device_address.field_0.u64._0_4_ = 0;
  ds_key_pair.device_address.field_0.u64._4_4_ = 0;
  ds_key_pair.link_key[0] = '\0';
  ds_key_pair.link_key[1] = '\0';
  ds_key_pair.link_key[2] = '\0';
  ds_key_pair.link_key[3] = '\0';
  ds_key_pair.link_key[4] = '\0';
  ds_key_pair.link_key[5] = '\0';
  ds_key_pair.link_key[6] = '\0';
  ds_key_pair.link_key[7] = '\0';
  ds_key_pair.link_key[8] = '\0';
  ds_key_pair.link_key[9] = '\0';
  ds_key_pair.link_key[10] = '\0';
  ds_key_pair.link_key[0xb] = '\0';
  ds_key_pair.link_key[0xc] = '\0';
  ds_key_pair.link_key[0xd] = '\0';
  ds_key_pair.link_key[0xe] = '\0';
  ds_key_pair.link_key[0xf] = '\0';
  ds_key_pair.passphrase[0] = '\0';
  ds_key_pair.passphrase[1] = '\0';
  ds_key_pair.passphrase[2] = '\0';
  ds_key_pair.passphrase[3] = '\0';
  ds_key_pair.passphrase[4] = '\0';
  ds_key_pair.passphrase[5] = '\0';
  ds_key_pair.passphrase[6] = '\0';
  ds_key_pair.passphrase[7] = '\0';
  ds_key_pair.passphrase[8] = '\0';
  ds_key_pair.passphrase[9] = '\0';
  ds_key_pair.passphrase[10] = '\0';
  ds_key_pair.passphrase[0xb] = '\0';
  ds_key_pair.passphrase[0xc] = '\0';
  ds_key_pair.passphrase[0xd] = '\0';
  ds_key_pair.passphrase[0xe] = '\0';
  ds_key_pair.passphrase[0xf] = '\0';
  ds_key_pair.outgoing_frame_cntr = 0;
  aps_secur_remove_stored_key_pair(key_pair);
  local_40 = *(undefined4 *)&(key_pair->device_address).field_0;
  ds_key_pair.device_address.field_0.u64._0_4_ =
       *(undefined4 *)((int)&(key_pair->device_address).field_0 + 4);
  memcpy((void *)((int)&ds_key_pair.device_address.field_0 + 4),key_pair->link_key,0x10);
  memcpy(ds_key_pair.link_key + 0xc,key_pair->passphrase,0x10);
  ds_key_pair.passphrase._12_4_ = key_pair->outgoing_frame_cntr + 0x400;
  ds_key_pair.outgoing_frame_cntr._0_1_ = key_pair->supported_kn_methods;
  ds_key_pair.outgoing_frame_cntr._1_1_ = key_pair->supported_kn_secrets;
  ds_key_pair.outgoing_frame_cntr._2_2_ = key_pair->field_8;
  eVar1 = ds_internal_add_entry(9,&local_40,0x30);
  return eVar1;
}

