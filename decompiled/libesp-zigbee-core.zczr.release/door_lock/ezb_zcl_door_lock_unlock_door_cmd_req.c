/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> ezb_zcl_door_lock_unlock_door_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_door_lock_unlock_door_cmd_req(void *param_1)

{
  undefined1 auStack_30 [40];
  
  memcpy(auStack_30,param_1,0x18);
  ezb_zcl_door_lock_control_door_cmd_req_internal(auStack_30,*(undefined1 *)((int)param_1 + 0x18),1)
  ;
  return;
}

