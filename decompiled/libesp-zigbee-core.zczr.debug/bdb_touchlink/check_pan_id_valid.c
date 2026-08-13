/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> check_pan_id_valid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 check_pan_id_valid(uint param_1)

{
  int iVar1;
  ushort auStack_12 [3];
  
  if ((param_1 - 1 & 0xffff) < 0xfffe) {
    auStack_12[0] = 0;
    iVar1 = 0;
    do {
      iVar1 = nwk_disc_table_next(iVar1);
      if (iVar1 == 0) {
        return 1;
      }
      nwk_address_get_panid(*(undefined1 *)(iVar1 + 8),auStack_12);
    } while (auStack_12[0] != param_1);
  }
  return 0;
}

