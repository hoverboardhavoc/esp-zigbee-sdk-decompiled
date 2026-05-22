/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ezb_plat_crypto_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = psa_crypto_init();
  if (iVar1 == 0) {
    return;
  }
  puVar2 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/crypto_platform_psa.c",
                         0x4a,"ezb_plat_crypto_init","psa_crypto_init() == ((psa_status_t)0)");
  if (puVar2 != (undefined4 *)0x0) {
    if (3 < *(ushort *)(puVar2 + 1)) {
      *(undefined4 *)*puVar2 = 0;
      return;
    }
    return;
  }
  return;
}

