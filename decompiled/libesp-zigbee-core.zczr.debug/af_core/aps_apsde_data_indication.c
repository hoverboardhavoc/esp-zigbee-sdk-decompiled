/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> aps_apsde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_apsde_data_indication(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*(short *)(param_1 + 4) == 0) {
    af_data_indication_deliver_handler(param_1);
  }
  else {
    uVar2 = aps_group_table_find();
    iVar1 = 0xff;
    while (iVar1 = aps_group_next_endpoint(uVar2,iVar1 + 1U & 0xff), iVar1 != 0xff) {
      uVar3 = random_add_jitter(0,10);
      af_data_indication_deliver_ep(param_1,iVar1,uVar3);
    }
  }
  return;
}

