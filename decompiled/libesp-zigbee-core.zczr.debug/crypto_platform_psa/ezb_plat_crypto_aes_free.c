/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_aes_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_crypto_aes_free(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 2;
  }
  else if (*(ushort *)(param_1 + 1) < 4) {
    uVar1 = 0xffffffff;
  }
  else {
    param_1 = (undefined4 *)*param_1;
    psa_destroy_key(*param_1);
    uVar1 = psa_to_ezb_error();
    *param_1 = 0;
  }
  return uVar1;
}

