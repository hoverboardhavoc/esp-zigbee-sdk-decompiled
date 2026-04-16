/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_get_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_get_key
               (aps_device_key_pair_t *key_pair,uint8_t *key,secur_scf_key_id_t key_id)

{
  undefined1 uStack_12;
  undefined1 auStack_11 [13];
  
  if (key_id == SECUR_SCF_KT_KEY) {
    uStack_12 = 0;
    crypto_hmac_aes_mmo(key_pair->link_key,0x10,&uStack_12,1);
  }
  else if (key_id == SECUR_SCF_KL_KEY) {
    auStack_11[0] = 2;
    crypto_hmac_aes_mmo(key_pair->link_key,0x10,auStack_11,1);
  }
  else if (key_id == SECUR_SCF_DATA_KEY) {
    memcpy(key,key_pair->link_key,0x10);
  }
  else {
    memset(key,0,0x10);
  }
  return;
}

