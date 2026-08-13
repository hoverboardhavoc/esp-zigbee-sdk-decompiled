/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_mbedtls.o -> ezb_plat_crypto_ecdh_set_generator
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_crypto_ecdh_set_generator(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    if (*(ushort *)(param_1 + 1) < 0x80) {
      return 0xffffffff;
    }
    if (*(int *)*param_1 == 9) {
      iVar1 = mbedtls_ecp_point_read_binary((int *)*param_1 + 7,param_2,param_3);
      if (iVar1 == 0) {
        return 0;
      }
      return 0xffffffff;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/crypto_platform_mbedtls.c",
                  0x15d,"ezb_plat_crypto_ecdh_set_generator","grp->id == MBEDTLS_ECP_DP_CURVE25519")
    ;
  }
  return 2;
}

