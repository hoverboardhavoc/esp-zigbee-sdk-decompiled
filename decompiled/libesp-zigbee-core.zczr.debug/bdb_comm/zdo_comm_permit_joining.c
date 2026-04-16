/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> zdo_comm_permit_joining
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_comm_permit_joining(uint8_t permit_duration)

{
  undefined3 in_register_00002029;
  int iVar1;
  ezb_err_t eVar2;
  undefined2 uStack_1c;
  uint8_t uStack_1a;
  undefined1 uStack_19;
  zdo_nwk_mgmt_permit_joining_req_t req;
  
  iVar1 = zdo_dev_joined();
  if (iVar1 == 0) {
    eVar2 = 3;
  }
  else {
    uStack_1c = 0xfffc;
    uStack_19 = 1;
    req._0_4_ = zdo_comm_permit_joining_req_cb;
    uStack_1a = permit_duration;
    req.cb = (ezb_zdo_nwk_mgmt_permit_joining_req_callback_t)
             CONCAT31(in_register_00002029,permit_duration);
    eVar2 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
  }
  return eVar2;
}

