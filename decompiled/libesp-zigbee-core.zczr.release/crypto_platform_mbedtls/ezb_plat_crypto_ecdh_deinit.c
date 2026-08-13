/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> crypto_platform_mbedtls.o -> ezb_plat_crypto_ecdh_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_crypto_ecdh_deinit(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return 2;
  }
  if (0x7f < *(ushort *)(param_1 + 1)) {
    mbedtls_ecp_keypair_free(*param_1);
    return 0;
  }
  return 0xffffffff;
}

