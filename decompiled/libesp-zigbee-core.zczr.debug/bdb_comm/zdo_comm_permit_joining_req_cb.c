/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> zdo_comm_permit_joining_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_permit_joining_req_cb(undefined1 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = nwk_is_device_zczr();
  if (iVar2 != 0) {
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    uVar1 = nwk_get_short_address();
    uStack_1c = CONCAT13(1,CONCAT12(param_1,uVar1));
    zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
  }
  return;
}

