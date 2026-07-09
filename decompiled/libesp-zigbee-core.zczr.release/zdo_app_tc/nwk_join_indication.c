/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_tc.o -> nwk_join_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_join_indication(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined1 uStack_16;
  
  iVar1 = zdo_dev_joined();
  if (iVar1 != 0) {
    memset(&uStack_28,0,0x18);
    iVar1 = aps_secur_is_centralized();
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)nwk_get_extended_address();
    }
    else {
      puVar2 = (undefined4 *)aps_secur_get_tc_address();
    }
    uStack_28 = *puVar2;
    uStack_24 = puVar2[1];
    uStack_20 = *(undefined4 *)(param_1 + 4);
    uStack_1c = *(undefined4 *)(param_1 + 8);
    uStack_18 = *(undefined2 *)(param_1 + 2);
    if (*(byte *)(param_1 + 1) < 6) {
      uVar3 = 1 << (*(byte *)(param_1 + 1) & 0x1f);
      if ((uVar3 & 0x24) == 0) {
        if ((uVar3 & 0x12) == 0) {
          if ((uVar3 & 9) != 0) {
            uStack_16 = 1;
          }
        }
        else {
          uStack_16 = 3;
        }
      }
      else {
        uStack_16 = 0;
      }
    }
    iVar1 = apsme_update_device_request(&uStack_28);
    if (iVar1 != 0) {
      log_write(2,"zdo_app_tc.c",0x10000,iVar1);
    }
  }
  return;
}

