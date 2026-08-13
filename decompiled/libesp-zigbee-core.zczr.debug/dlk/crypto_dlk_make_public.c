/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> dlk.o -> crypto_dlk_make_public
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_dlk_make_public(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = crypto_ecdh_generate_keypair(param_1 + 8);
  if (iVar1 == 0) {
    crypto_ecdh_export_public(param_1 + 8,param_2);
  }
  return;
}

