/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> nwk_nlde_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_nlde_data_confirm(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  byte abStack_11 [5];
  
  zmsg_read_bytes(*param_1,0,1,abStack_11);
  if (((abStack_11[0] & 3) == 2) ||
     (uVar1 = aps_process_transmit_done_security(*param_1), uVar1 == 0)) {
    uVar1 = 0;
    if (*(byte *)(param_1 + 2) != 0) {
      uVar1 = *(byte *)(param_1 + 2) | 0x200;
    }
  }
  else {
    uVar2 = aps_frame_type_str(abStack_11[0] & 3);
    log_write(1,"aps_main.c","APS %s frame (dst:0x%04x err:0x%02x) tx done security failed 0x%x",
              uVar2,*(undefined2 *)((int)param_1 + 6),*(undefined1 *)(param_1 + 2),uVar1);
  }
  if ((abStack_11[0] & 0x40) == 0) {
    aps_send_frame_confirm(uVar1);
  }
  else {
    zmsg_free(*param_1);
  }
  return;
}

