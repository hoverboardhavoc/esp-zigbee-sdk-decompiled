/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_do_ed_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_do_ed_scan(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  
  iVar4 = mac_update_scan_channel();
  if (iVar4 == 0) {
    uVar2 = *(uint *)(param_1 + 0x34) >> 0x1b;
    uVar1 = *(undefined1 *)(param_1 + 0x32);
    uVar3 = mac_scan_duration_to_msec(*(undefined1 *)(param_1 + 0x33));
    if ((*(uint *)(param_1 + 0x28) >> 0x11 & 1) == 0) {
      mac_pal_receive(uVar2,uVar1);
    }
    iVar4 = mac_pal_energy_detect(uVar2,uVar1,uVar3);
    if (iVar4 == 0) {
      return;
    }
  }
  mac_finish_op(param_1);
  mac_set_state(param_1,0);
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
    (**(code **)(param_1 + 0x38))(0,*(undefined4 *)(param_1 + 0x3c));
  }
  mac_perform_next_op(param_1);
  return;
}

