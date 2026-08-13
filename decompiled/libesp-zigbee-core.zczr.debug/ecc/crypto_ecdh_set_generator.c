/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ecc.o -> crypto_ecdh_set_generator
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_ecdh_set_generator(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 1) {
    ezb_plat_crypto_ecdh_set_generator(param_1 + 1,0x20);
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/ecc.c",0x2f,
                        "crypto_ecdh_set_generator",0x1012c);
  ezb_plat_crypto_ecdh_generate_public(iVar1 + 4);
  return;
}

