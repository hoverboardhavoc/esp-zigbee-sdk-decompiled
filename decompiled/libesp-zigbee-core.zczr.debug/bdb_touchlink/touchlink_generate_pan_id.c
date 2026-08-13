/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> touchlink_generate_pan_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_generate_pan_id(uint param_1)

{
  int iVar1;
  
  while (iVar1 = check_pan_id_valid(param_1), iVar1 == 0) {
    param_1 = random_noncrypto_get_u32();
    param_1 = param_1 % 0xffff;
  }
  return param_1;
}

