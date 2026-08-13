/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> secur_ic_get_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_ic_get_key(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 auStack_30 [8];
  undefined1 uStack_28;
  undefined1 auStack_27 [21];
  char cStack_12;
  
  if (param_1 == 0) {
    uVar1 = 2;
  }
  else if (param_2 == 0) {
    uVar1 = 2;
  }
  else {
    secur_ic_get_stored_ic(auStack_30);
    if (cStack_12 == '\0') {
      uVar1 = ic_size(uStack_28);
      crypto_aes_mmo_hash(auStack_27,uVar1,param_2);
      uVar1 = 0;
    }
    else {
      uVar1 = 5;
    }
  }
  return uVar1;
}

