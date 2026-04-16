/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_mgmt_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_task(void *arg)

{
  uint16_t uVar1;
  int *piVar2;
  zdo_mgmt_req_t *req;
  int iVar3;
  int iVar4;
  
  iVar3 = core_globals_get();
  piVar2 = *(int **)(iVar3 + 0xd44);
  while( true ) {
    req = (zdo_mgmt_req_t *)(piVar2 + -1);
    if (req == (zdo_mgmt_req_t *)0xfffffffc) {
      return;
    }
    if ((piVar2[7] & 1U) == 0) break;
    piVar2 = (int *)*piVar2;
  }
  *(byte *)(piVar2 + 7) = *(byte *)(piVar2 + 7) | 1;
  uVar1 = req->cluster_id;
  if (uVar1 == 0x36) {
    iVar4 = zdo_dev_joined();
    iVar3 = 0xd;
    if (iVar4 != 0) {
      iVar3 = nwk_permit_joining(*(undefined1 *)(piVar2 + 1));
    }
  }
  else {
    if (uVar1 == 0x38) goto _L0;
    if (uVar1 == 0x34) {
      iVar3 = nwk_leave_request(piVar2 + 1);
      if (iVar3 == 0) goto _L0;
    }
    else {
      iVar3 = 6;
    }
  }
  iVar4 = core_globals_get();
  list_remove_node(iVar4 + 0xd44,piVar2);
  zdo_mgmt_req_finish(req,(uint8_t)iVar3);
_L0:
  iVar3 = core_globals_get();
  tasklet_post(iVar3 + 0xd48);
  return;
}

