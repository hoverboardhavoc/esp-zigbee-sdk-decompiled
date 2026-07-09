/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_tc.o -> nwk_join_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_join_indication(int param_1)

{
  ushort uVar1;
  undefined1 auVar2 [4];
  undefined1 auVar3 [4];
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  
  iVar4 = zdo_dev_joined();
  if (iVar4 != 0) {
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    auStack_18 = (undefined1  [4])0x0;
    uStack_14 = 0;
    iVar4 = aps_secur_is_centralized();
    if (iVar4 == 0) {
      puVar5 = (undefined4 *)nwk_get_extended_address();
      uStack_28 = *puVar5;
      uStack_24 = puVar5[1];
    }
    else {
      puVar5 = (undefined4 *)aps_secur_get_tc_address();
      uStack_28 = *puVar5;
      uStack_24 = puVar5[1];
    }
    auVar2 = auStack_18;
    uStack_20 = *(undefined4 *)(param_1 + 4);
    uStack_1c = *(undefined4 *)(param_1 + 8);
    uVar1 = *(ushort *)(param_1 + 2);
    auStack_18._0_2_ = uVar1;
    auVar3 = auStack_18;
    if (*(byte *)(param_1 + 1) < 6) {
      uVar6 = 1 << (*(byte *)(param_1 + 1) & 0x1f);
      auStack_18[3] = auVar2[3];
      if ((uVar6 & 0x24) == 0) {
        if ((uVar6 & 0x12) == 0) {
          if ((uVar6 & 9) != 0) {
            auStack_18[2] = 1;
            auVar3 = auStack_18;
          }
        }
        else {
          auStack_18[2] = 3;
          auVar3 = auStack_18;
        }
      }
      else {
        auStack_18[2] = 0;
        auVar3 = auStack_18;
      }
    }
    auStack_18 = auVar3;
    iVar4 = apsme_update_device_request(&uStack_28);
    if (iVar4 != 0) {
      log_write(2,"zdo_app_tc.c","UpdateDevice failed(0x%x)",iVar4);
    }
  }
  return;
}

