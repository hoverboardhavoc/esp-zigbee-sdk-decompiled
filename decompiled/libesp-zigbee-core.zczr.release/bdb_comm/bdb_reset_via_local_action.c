/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_reset_via_local_action
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_reset_via_local_action(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uStack_24;
  zdo_nwk_mgmt_leave_req_t req;
  
  uStack_24 = 0;
  req._0_4_ = 0;
  req.field.device_addr.field_0.u64._2_4_ = 0;
  req.field._6_4_ = 0;
  req.cb = (ezb_zdo_nwk_mgmt_leave_req_callback_t)0x0;
  uVar1 = nwk_get_short_address();
  uStack_24 = CONCAT22(uStack_24._2_2_,uVar1);
  uVar2 = zdo_nwk_mgmt_leave_req(&uStack_24);
  log_write(3,"bdb_comm.c","Reset via local action: 0x%04x",uVar2);
  return;
}

