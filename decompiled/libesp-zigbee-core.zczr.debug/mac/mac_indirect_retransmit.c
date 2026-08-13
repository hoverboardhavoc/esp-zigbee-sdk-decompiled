/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_indirect_retransmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_indirect_retransmit(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  
  for (puVar2 = *(undefined4 **)(param_1 + 0x60);
      ((undefined4 *)(param_1 + 0x60) != puVar2 && ((int)(puVar2[6] - param_2[6]) < 0));
      puVar2 = (undefined4 *)*puVar2) {
  }
  piVar1 = (int *)puVar2[1];
  puVar2[1] = param_2;
  *param_2 = puVar2;
  param_2[1] = piVar1;
  *piVar1 = (int)param_2;
  *(short *)(param_1 + 0x68) = *(short *)(param_1 + 0x68) + 1;
  if (param_2 == *(undefined4 **)(param_1 + 0x60)) {
    micro_timer_fire_at(param_1 + 0x6c,param_2[6]);
  }
  return;
}

