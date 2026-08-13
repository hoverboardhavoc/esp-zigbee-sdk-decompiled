/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_mbedtls.o -> ezb_plat_crypto_ecdh_compute_shared
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_plat_crypto_ecdh_compute_shared
              (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [24];
  
  if (param_1 == (int *)0x0) {
    iVar1 = 2;
  }
  else if (*(ushort *)(param_1 + 1) < 0x80) {
    iVar1 = -1;
  }
  else {
    iVar1 = *param_1;
    mbedtls_ecp_point_init(auStack_38);
    mbedtls_ecp_point_init(auStack_50);
    iVar2 = mbedtls_ecp_point_read_binary(iVar1,auStack_50,param_2,param_3);
    if (iVar2 == 0) {
      iVar2 = mbedtls_ecp_mul(iVar1,auStack_38,iVar1 + 0x60,auStack_50,ecc_rng,0);
      if (iVar2 == 0) {
        iVar1 = mbedtls_ecp_get_type(iVar1);
        if (iVar1 == 2) {
          iVar1 = mbedtls_mpi_write_binary_le(auStack_38,param_4,param_5);
          if (iVar1 != 0) {
            iVar1 = -1;
          }
        }
        else {
          iVar1 = mbedtls_mpi_write_binary(auStack_38,param_4,param_5);
          if (iVar1 != 0) {
            iVar1 = -1;
          }
        }
      }
      else {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  mbedtls_ecp_point_free(auStack_38);
  mbedtls_ecp_point_free(auStack_50);
  return iVar1;
}

