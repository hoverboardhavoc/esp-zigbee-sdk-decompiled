/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_psa_import_aes_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_psa_import_aes_key
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_26 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_28 = 0x2400;
  uStack_2c = param_3;
  uStack_1c = param_2;
  psa_extend_key_usage_flags(&uStack_2c);
  uStack_20 = uStack_2c;
  uStack_24 = 0;
  uStack_14 = 0;
  psa_import_key(&uStack_28,param_1,0x10,param_4);
  return;
}

