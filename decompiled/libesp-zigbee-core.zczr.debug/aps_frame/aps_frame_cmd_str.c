/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_cmd_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

char * aps_frame_cmd_str(aps_cmd_id_t cmd_id)

{
  undefined3 in_register_00002029;
  
  if (CONCAT31(in_register_00002029,cmd_id) < 0x13) {
    return aps_frame_cmd_str::cmd_string[CONCAT31(in_register_00002029,cmd_id)];
  }
  return "Unknown";
}

