/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_get_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_get_key(int param_1,void *param_2,int param_3)

{
  undefined1 auStack_11 [13];
  
  if (param_3 == 0x10) {
    auStack_11[0] = 0;
  }
  else {
    if (param_3 != 0x18) {
      if (param_3 != 0) {
        memset(param_2,0,0x10);
        return;
      }
      memcpy(param_2,(void *)(param_1 + 0x12),0x10);
      return;
    }
    auStack_11[0] = 2;
  }
  crypto_hmac_aes_mmo(param_1 + 0x12,0x10,auStack_11,1);
  return;
}

