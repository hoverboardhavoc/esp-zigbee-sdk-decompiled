/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> crypto_platform_mbedtls.o -> ecc_rng
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ecc_rng(undefined4 param_1,uint param_2)

{
  if (0xffff < param_2) {
    param_2 = 0;
    param_1 = __assert_func(0,0,0,0);
  }
  ezb_plat_crypto_random_get(param_1,param_2 & 0xffff);
  return;
}

