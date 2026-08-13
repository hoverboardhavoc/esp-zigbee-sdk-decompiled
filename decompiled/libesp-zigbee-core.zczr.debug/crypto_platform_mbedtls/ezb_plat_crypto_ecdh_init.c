/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_mbedtls.o -> ezb_plat_crypto_ecdh_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_plat_crypto_ecdh_init(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar3 = 2;
  }
  else if (*(ushort *)(param_1 + 1) < 0x80) {
    iVar3 = -1;
  }
  else {
    uVar1 = *param_1;
    if (param_2 == 1) {
      uVar2 = 9;
    }
    else {
      if (param_2 != 2) {
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

