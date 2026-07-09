/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_crypto_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = psa_crypto_init();
  if (iVar1 == 0) {
    return 0;
  }
  puVar2 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/crypto_platform_psa.c",
                         0x4a,"ezb_plat_crypto_init","psa_crypto_init() == ((psa_status_t)0)");
  if (puVar2 != (undefined4 *)0x0) {
    if (3 < *(ushort *)(puVar2 + 1)) {
      *(undefined4 *)*puVar2 = 0;
      return 0;
    }
    return 0xffffffff;
  }
  return 2;
}

