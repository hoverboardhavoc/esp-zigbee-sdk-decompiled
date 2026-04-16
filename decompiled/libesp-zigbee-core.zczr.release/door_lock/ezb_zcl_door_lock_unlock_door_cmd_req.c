/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> ezb_zcl_door_lock_unlock_door_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_door_lock_unlock_door_cmd_req(ezb_zcl_door_lock_unlock_door_cmd_t *cmd_req)

{
  ezb_zcl_cluster_cmd_ctrl_t *unaff_s1;
  ezb_err_t eVar1;
  undefined1 auStack_30 [40];
  
  memcpy(auStack_30,cmd_req,0x18);
  eVar1 = ezb_zcl_door_lock_control_door_cmd_req_internal
                    (unaff_s1,cmd_req->aps_secur_enabled,'\x01');
  return eVar1;
}

