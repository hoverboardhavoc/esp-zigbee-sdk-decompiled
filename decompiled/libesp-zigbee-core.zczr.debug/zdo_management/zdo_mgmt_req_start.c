/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_req_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_req_start(short *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 1;
  sVar1 = *param_1;
  if (sVar1 == 0x36) {
    iVar3 = zdo_dev_joined();
    if (iVar3 == 0) {
      uVar2 = 0xd;
    }
    else {
      uVar2 = nwk_permit_joining((char)param_1[4]);
    }
  }
  else {
    if (sVar1 == 0x38) {
      uVar2 = 0;
    }
    else if (sVar1 == 0x34) {
      uVar2 = nwk_leave_request(param_1 + 4);
    }
    else {
      uVar2 = 6;
    }
    if (uVar2 == 0) {
      return;
    }
  }
  iVar3 = core_globals_get();
  list_remove_node(iVar3 + 0xce0,param_1 + 2);
  zdo_mgmt_req_finish(param_1,uVar2 & 0xff);
  return;
}

