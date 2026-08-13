/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_md_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_md_start(int param_1)

{
  int iVar1;
  
  iVar1 = crypto_hash_init();
  if (iVar1 == 0) {
    (**(code **)(param_1 + 4))(param_1 + 0x10,*(code **)(param_1 + 4));
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0x120,
                        "crypto_md_start","(crypto_hash_init(ctx, hash_id)) == 0");
  (**(code **)(iVar1 + 8))(iVar1 + 0x10,*(code **)(iVar1 + 8));
  return;
}

