/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_remove_stored_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_remove_stored_key_pair(aps_device_key_pair_t *key_pair)

{
  undefined1 auStack_44 [4];
  ds_aps_key_pair_iterator_t itor;
  
  itor.data.supported_kn_methods = '\0';
  itor.data.supported_kn_secrets = '\0';
  itor.data.flags._0_1_ = '\0';
  while( true ) {
    ds_aps_key_pair_itor_read((ds_aps_key_pair_iterator_t *)auStack_44);
    if ((char)itor.data.flags != '\0') {
      return;
    }
    if (((undefined1  [4])*(int *)&(key_pair->device_address).field_0 == auStack_44) &&
       (*(int *)((int)&(key_pair->device_address).field_0 + 4) ==
        itor.data.device_address.field_0.u64._0_4_)) break;
    itor.data._44_2_ = itor.data._44_2_ + 1;
  }
  ds_internal_remove_entry(9,auStack_44);
  return;
}

