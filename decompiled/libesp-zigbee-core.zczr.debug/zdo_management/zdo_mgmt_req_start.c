/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_req_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_req_start(zdo_mgmt_req_t *req)

{
  uint16_t uVar1;
  int iVar2;
  int iVar3;
  
  req->field_0x20 = req->field_0x20 | 1;
  uVar1 = req->cluster_id;
  if (uVar1 == 0x36) {
    iVar2 = zdo_dev_joined();
    if (iVar2 == 0) {
      iVar2 = 0xd;
    }
    else {
      iVar2 = nwk_permit_joining((req->param).permit_joining);
    }
  }
  else {
    if (uVar1 == 0x38) {
      iVar2 = 0;
    }
    else if (uVar1 == 0x34) {
      iVar2 = nwk_leave_request(&req->param);
    }
    else {
      iVar2 = 6;
    }
    if (iVar2 == 0) {
      return;
    }
  }
  iVar3 = core_globals_get();
  list_remove_node(iVar3 + 0xd44,&req->node);
  zdo_mgmt_req_finish(req,(uint8_t)iVar2);
  return;
}

