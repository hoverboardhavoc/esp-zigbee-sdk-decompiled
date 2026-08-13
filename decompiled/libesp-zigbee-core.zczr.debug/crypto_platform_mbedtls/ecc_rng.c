/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_mbedtls.o -> ecc_rng
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ecc_rng(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int extraout_a1;
  
  if (param_2 < 0x10000) {
    iVar3 = ezb_plat_crypto_random_get(param_1,param_2 & 0xffff);
    return iVar3;
  }
  puVar4 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/crypto_platform_mbedtls.c"
                         ,0x123,"ecc_rng",0x10000);
  if (puVar4 == (undefined4 *)0x0) {
    iVar3 = 2;
  }
  else if (*(ushort *)(puVar4 + 1) < 0x80) {
    iVar3 = -1;
  }
  else {
    uVar1 = *puVar4;
    if (extraout_a1 == 1) {
      uVar2 = 9;
    }
    else {
      if (extraout_a1 != 2) {
        return 6;
      }
      uVar2 = 3;
    }
    mbedtls_ecp_keypair_init(uVar1);
    iVar3 = mbedtls_ecp_group_load(uVar1,uVar2);
    if (iVar3 != 0) {
      iVar3 = -1;
    }
  }
  return iVar3;
}

