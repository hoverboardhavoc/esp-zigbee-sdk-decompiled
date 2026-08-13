/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_cb_nwk_mgmt_permit_joining_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_cb_nwk_mgmt_permit_joining_rsp(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_24 [12];
  
  if ((param_1 != 0) && (param_2 != 0)) {
    zdo_packet_notify_result(param_2,0);
    return 0;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x431,
                        "zdo_cb_nwk_mgmt_permit_joining_rsp","rsp && ctx");
  auStack_24[0] = 0;
  if (iVar1 == 0) {
    uVar3 = 0xfe;
  }
  else if (*(int *)(iVar1 + 0x14) == 0) {
    uVar3 = 0xfe;
  }
  else {
    iVar2 = zdo_op_nwk_mgmt_permit_joining_rsp(auStack_24,0);
    if (iVar2 == 0) {
      uVar3 = zdo_cb_nwk_mgmt_permit_joining_rsp(auStack_24,iVar1 + 8);
    }
    else {
      uVar3 = 0xfe;
    }
  }
  return uVar3;
}

