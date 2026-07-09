/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_mgmt_ed_scan_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_ed_scan_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined1 auStack_38 [4];
  uint uStack_34;
  undefined4 uStack_30;
  byte bStack_2c;
  undefined1 auStack_2b [31];
  
  memset(auStack_38,0,0x28);
  if (param_2 == 0) {
    __assert_func(0,0,0,0);
  }
  zmsg_get_footer(*(undefined4 *)(param_2 + 0x14),auStack_38,0x28);
  zmsg_remove_footer(*(undefined4 *)(param_2 + 0x14),0x28);
  if (param_1 == 0) {
    auStack_38[0] = 0;
    zdo_op_nwk_mgmt_nwk_update_notify(*(undefined4 *)(param_2 + 0x14),auStack_38,1);
    zdo_packet_send(param_2);
    mm_free(param_2);
  }
  else {
    uStack_30 = 0;
    uStack_34 = uStack_34 | 1 << (*(byte *)(param_1 + 1) & 0x1f);
    uVar1 = (uint)bStack_2c;
    if (uVar1 < 0x1b) {
      bStack_2c = bStack_2c + 1;
      auStack_2b[uVar1] = *(undefined1 *)(param_1 + 2);
    }
    zmsg_add_footer(auStack_38,0x28);
  }
  return;
}

