/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> ezb_zcl_door_lock_lock_door_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_door_lock_lock_door_cmd_req(undefined4 *param_1)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_30 = *param_1;
  uStack_2c = param_1[1];
  uStack_28 = param_1[2];
  uStack_24 = param_1[3];
  uStack_20 = param_1[4];
  uStack_1c = param_1[5];
  ezb_zcl_door_lock_control_door_cmd_req_internal(&local_30,*(undefined1 *)(param_1 + 6),0);
  return;
}

