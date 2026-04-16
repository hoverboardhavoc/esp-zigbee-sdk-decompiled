/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_network_steering_on_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_network_steering_on_network(void)

{
  int iVar1;
  undefined1 auStack_24 [4];
  ezb_zdo_nwk_mgmt_permit_joining_req_result_t result;
  zdo_nwk_mgmt_permit_joining_req_t req;
  
  result.rsp = (ezb_zdp_nwk_mgmt_permit_joining_rsp_field_t *)0x1b4fffc;
  iVar1 = zdo_nwk_mgmt_permit_joining_req(&result.rsp);
  if (iVar1 != 0) {
    result.error = 0;
    auStack_24 = (undefined1  [4])0xffffffff;
    bdb_comm_permit_joining_req_cb
              ((ezb_zdo_nwk_mgmt_permit_joining_req_result_t *)auStack_24,(void *)0x0);
  }
  return;
}

