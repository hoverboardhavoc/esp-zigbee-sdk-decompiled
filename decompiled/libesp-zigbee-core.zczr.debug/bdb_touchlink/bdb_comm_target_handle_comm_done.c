/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> bdb_comm_target_handle_comm_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_target_handle_comm_done(zdo_comm_operation_t op,ezb_err_t error)

{
  undefined3 in_register_00002029;
  uint uVar1;
  
  uVar1 = CONCAT31(in_register_00002029,op);
  if (uVar1 == 3) {
    touchlink_target_process_rejoin_done(error);
  }
  else if (uVar1 < 4) {
    if (uVar1 == 1) {
      touchlink_target_process_formation_done(error);
    }
    else if (uVar1 == 2) {
      touchlink_target_process_discovery_done(error);
    }
  }
  else if (uVar1 == 7) {
    touchlink_target_process_device_start_done(error);
  }
  else if (uVar1 == 8) {
    touchlink_target_process_device_annce_done(error);
  }
  return;
}

