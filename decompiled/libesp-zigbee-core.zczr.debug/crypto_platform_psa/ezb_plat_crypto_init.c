/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
                         0x4b,"ezb_plat_crypto_init","psa_crypto_init() == ((psa_status_t)0)");
  if (puVar2 != (undefined4 *)0x0) {
    if (3 < *(ushort *)(puVar2 + 1)) {
      *(undefined4 *)*puVar2 = 0;
      return 0;
    }
    return 0xffffffff;
  }
  return 2;
}

