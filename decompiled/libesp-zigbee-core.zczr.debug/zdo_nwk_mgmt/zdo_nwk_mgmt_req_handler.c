/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_nwk_mgmt_req_handler(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    return 0x80;
  }
  iVar2 = zdo_packet_response_init(&uStack_28,param_1,*(ushort *)(param_1 + 6) | 0x8000);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar1 = *(ushort *)(param_1 + 6);
  if (uVar1 == 0x34) {
    iVar2 = zdo_nwk_mgmt_leave_req_handler(param_1,&uStack_28);
  }
  else if (uVar1 < 0x35) {
    if (uVar1 == 0x32) {
      iVar2 = zdo_nwk_mgmt_rtg_req_handler(param_1,&uStack_28);
    }
    else if (uVar1 == 0x33) {
      iVar2 = zdo_nwk_mgmt_bind_req_handler(param_1,&uStack_28);
    }
    else {
      if (uVar1 != 0x31) {
        iVar2 = 0x84;
        goto _L0;
      }
      iVar2 = zdo_nwk_mgmt_lqi_req_handler(param_1,&uStack_28);
    }
  }
  else if (uVar1 == 0x36) {
    iVar2 = zdo_nwk_mgmt_permit_joining_req_handler(param_1,&uStack_28);
  }
  else {
    if (uVar1 != 0x38) {
      iVar2 = 0x84;
      goto _L0;
    }
    iVar2 = zdo_nwk_mgmt_nwk_update_req_handler(param_1,&uStack_28);
  }
  if (iVar2 == 0) {
    iVar2 = zdo_packet_send(&uStack_28);
    return iVar2;
  }
_L0:
  zdo_packet_free(&uStack_28);
  return iVar2;
}

