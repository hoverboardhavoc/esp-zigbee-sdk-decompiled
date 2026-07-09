/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_psa_import_aes_key.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_psa_import_aes_key_constprop_0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uStack_28;
  undefined1 auStack_26 [6];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  memset(auStack_26,0,0x16);
  uStack_28 = 0x2400;
  uStack_20 = param_3;
  uStack_1c = param_2;
  psa_import_key(&uStack_28,param_1,0x10,param_4);
  return;
}

