/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_finish_association
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_finish_association(int param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  mac_set_state(0);
  if (*(char *)(param_2 + 1) == '\0') {
    uVar2 = *(undefined2 *)(param_1 + 10);
    uVar1 = *param_2;
    mac_set_pan_channel(param_1,*(undefined1 *)(param_1 + 0x42),*(undefined1 *)(param_1 + 0x41));
  }
  else {
    uVar2 = 0xffff;
    uVar1 = uVar2;
  }
  mac_set_panid(param_1,uVar2);
  mac_set_short_address(param_1,uVar1);
  nwk_mm_asso_confirm(*(undefined1 *)(param_1 + 0x2c),param_2);
  return;
}

