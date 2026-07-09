/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> bdb_comm_target_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_target_handle_comm_done(uint param_1,undefined4 param_2)

{
  if (param_1 == 3) {
    touchlink_target_process_rejoin_done(param_2);
  }
  else if (param_1 < 4) {
    if (param_1 == 1) {
      touchlink_target_process_formation_done();
    }
    else if (param_1 == 2) {
      touchlink_target_process_discovery_done();
    }
  }
  else if (param_1 == 7) {
    touchlink_target_process_device_start_done();
  }
  else if (param_1 == 8) {
    touchlink_target_process_device_annce_done();
  }
  return;
}

