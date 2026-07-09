/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_ic.o -> secur_ic_get_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_ic_get_key(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [8];
  undefined1 uStack_28;
  undefined1 auStack_27 [21];
  char cStack_12;
  
  if (param_1 != 0) {
    uVar2 = 2;
    if (param_2 != 0) {
      secur_ic_get_stored_ic(auStack_30);
      uVar2 = 5;
      if (cStack_12 == '\0') {
        cVar1 = ic_crc_offset(uStack_28);
        uVar2 = crypto_aes_mmo_hash(auStack_27,cVar1 + '\x02',param_2);
      }
    }
    return uVar2;
  }
  return 2;
}

