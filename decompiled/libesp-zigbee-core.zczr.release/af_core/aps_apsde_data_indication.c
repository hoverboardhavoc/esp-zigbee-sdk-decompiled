/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> aps_apsde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_apsde_data_indication(int param_1)

{
  short sVar1;
  int unaff_s0;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  iVar2 = 0xff;
  if (*(short *)(param_1 + 4) != 0) {
    uVar3 = aps_group_table_find(*(short *)(param_1 + 4));
    while (iVar2 = aps_group_next_endpoint(uVar3,iVar2 + 1U & 0xff), iVar2 != 0xff) {
      uVar4 = random_add_jitter(0,10);
      af_data_indication_deliver_ep(param_1,iVar2,uVar4);
    }
    return;
  }
  if (*(char *)(param_1 + 7) != -1) {
    if ((param_1 == 0) || (unaff_s0 = param_1, *(char *)(param_1 + 7) == -1)) {
      param_1 = __assert_func(0,0,0,0);
    }
    sVar1 = *(short *)(param_1 + 10);
    if ((sVar1 == 0x104) || (sVar1 == -0x3fa2)) {
      zcl_indication_handler(unaff_s0);
    }
    else if (sVar1 == 0) {
      zdo_indication_handler();
    }
    zmsg_free(*(undefined4 *)(unaff_s0 + 0x10));
    return;
  }
  uVar3 = 0;
  pcVar5 = (char *)0x0;
  while (pcVar5 = (char *)af_device_get_next_endpoint_desc(pcVar5), pcVar5 != (char *)0x0) {
    if ((*pcVar5 != -1) && (*(short *)(pcVar5 + 2) == *(short *)(param_1 + 10))) {
      af_data_indication_deliver_ep(param_1,uVar3);
      uVar3 = random_add_jitter(uVar3,10);
    }
  }
  zmsg_free(*(undefined4 *)(param_1 + 0x10));
  return;
}

