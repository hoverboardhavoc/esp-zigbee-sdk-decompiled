/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_cb_nwk_mgmt_nwk_update_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_cb_nwk_mgmt_nwk_update_notify(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    zdo_packet_notify_result(param_2,0);
    return 0;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x5c4,
                        "zdo_cb_nwk_mgmt_nwk_update_notify","notify && ctx");
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (iVar1 == 0) {
    iVar2 = 0xfe;
  }
  else if (*(int *)(iVar1 + 0x14) == 0) {
    iVar2 = 0xfe;
  }
  else {
    iVar2 = zdo_op_nwk_mgmt_nwk_update_notify(&uStack_48,0);
    if (iVar2 == 0) {
      iVar2 = zdo_cb_nwk_mgmt_nwk_update_notify(&uStack_48,iVar1 + 8);
    }
  }
  return iVar2;
}

