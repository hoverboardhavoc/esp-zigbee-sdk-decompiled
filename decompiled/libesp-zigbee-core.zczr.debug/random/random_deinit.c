/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void random_deinit(void)

{
  if (s_init_count == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/random.c",0x3f,"random_deinit",
                  "s_init_count > 0");
  }
  else {
    s_init_count = s_init_count - 1;
    if (s_init_count != 0) {
      return;
    }
  }
  ezb_plat_crypto_random_deinit();
  return;
}

