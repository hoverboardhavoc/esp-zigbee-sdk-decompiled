/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> crypto_platform_mbedtls.o -> ezb_plat_crypto_ecdh_compute_shared
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
  undefined1 auStack_38 [28];
  
  iVar1 = 2;
  if (param_1 != (int *)0x0) {
    if (0x7f < *(ushort *)(param_1 + 1)) {
      iVar2 = *param_1;
      mbedtls_ecp_point_init(auStack_50);
      mbedtls_ecp_point_init(auStack_38);
      iVar1 = mbedtls_ecp_point_read_binary(iVar2,auStack_38,param_2,param_3);
      if ((iVar1 == 0) &&
         (iVar1 = mbedtls_ecp_mul(iVar2,auStack_50,iVar2 + 0x60,auStack_38,0x10000,0), iVar1 == 0))
      {
        iVar1 = mbedtls_ecp_get_type(iVar2);
        if (iVar1 == 2) {
          iVar1 = mbedtls_mpi_write_binary_le(auStack_50);
        }
        else {
          iVar1 = mbedtls_mpi_write_binary(auStack_50,param_4,param_5);
        }
        iVar1 = -(uint)(iVar1 != 0);
        goto _L0;
      }
    }
    iVar1 = -1;
  }
_L0:
  mbedtls_ecp_point_free(auStack_50);
  mbedtls_ecp_point_free(auStack_38);
  return iVar1;
}

