/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_mgmt_ed_scan_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_ed_scan_handler(int param_1,int param_2)

{
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x4fd,
                  "zdo_mgmt_ed_scan_handler",&_L0);
  }
  else {
    zmsg_get_footer(*(undefined4 *)(param_2 + 0x14),&uStack_38,0x28);
    zmsg_remove_footer(*(undefined4 *)(param_2 + 0x14),0x28);
    if (param_1 != 0) {
      uStack_34 = uStack_34 | 1 << (*(byte *)(param_1 + 1) & 0x1f);
      uStack_30 = 0;
      if ((uStack_2c & 0xff) < 0x1b) {
        *(undefined1 *)((int)&uStack_2c + (uStack_2c & 0xff) + 1) = *(undefined1 *)(param_1 + 2);
        uStack_2c = CONCAT31(uStack_2c._1_3_,(char)uStack_2c + '\x01');
      }
      zmsg_add_footer(*(undefined4 *)(param_2 + 0x14),&uStack_38,0x28);
      return;
    }
  }
  uStack_38 = uStack_38 & 0xffffff00;
  zdo_op_nwk_mgmt_nwk_update_notify(*(undefined4 *)(param_2 + 0x14),&uStack_38,1);
  zdo_packet_send(param_2);
  mm_free(param_2);
  return;
}

