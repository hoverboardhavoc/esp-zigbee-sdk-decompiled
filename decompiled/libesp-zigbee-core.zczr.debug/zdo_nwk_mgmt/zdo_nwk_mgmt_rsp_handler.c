/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_rsp_handler(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x80;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 6);
    if (uVar1 == 0x8034) {
      uVar2 = zdo_nwk_mgmt_leave_rsp_handler();
    }
    else if (uVar1 < 0x8035) {
      if (uVar1 == 0x8032) {
        uVar2 = zdo_nwk_mgmt_rtg_rsp_handler();
      }
      else if (uVar1 == 0x8033) {
        uVar2 = zdo_nwk_mgmt_bind_rsp_handler();
      }
      else if (uVar1 == 0x8031) {
        uVar2 = zdo_nwk_mgmt_lqi_rsp_handler();
      }
      else {
        uVar2 = 0x84;
      }
    }
    else if (uVar1 == 0x8036) {
      uVar2 = zdo_nwk_mgmt_permit_joining_rsp_handler();
    }
    else if (uVar1 == 0x8038) {
      uVar2 = zdo_nwk_mgmt_nwk_update_notify_handler();
    }
    else {
      uVar2 = 0x84;
    }
  }
  return uVar2;
}

