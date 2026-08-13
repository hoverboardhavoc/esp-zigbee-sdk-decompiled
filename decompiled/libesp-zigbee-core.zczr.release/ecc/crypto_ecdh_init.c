/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> ecc.o -> crypto_ecdh_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_ecdh_init(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  param_1[1] = param_1 + 4;
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 2) = 0x80;
  iVar1 = ezb_plat_crypto_ecdh_init(param_1 + 1);
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

