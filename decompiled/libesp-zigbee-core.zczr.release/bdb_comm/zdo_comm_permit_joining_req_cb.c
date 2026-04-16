/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> zdo_comm_permit_joining_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_comm_permit_joining_req_cb
               (ezb_zdo_nwk_mgmt_permit_joining_req_result_t *result,void *user_ctx)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uStack_1c;
  zdo_nwk_mgmt_permit_joining_req_t req;
  
  iVar2 = nwk_is_device_zczr();
  if (iVar2 != 0) {
    uStack_1c = 0;
    req.dst_nwk_addr = 0;
    req.field.permit_duration = '\0';
    req.field.tc_significance = '\0';
    req.cb = (ezb_zdo_nwk_mgmt_permit_joining_req_callback_t)0x0;
    uVar1 = nwk_get_short_address();
    uStack_1c = CONCAT13(1,CONCAT12((char)user_ctx,uVar1));
    zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
  }
  return;
}

