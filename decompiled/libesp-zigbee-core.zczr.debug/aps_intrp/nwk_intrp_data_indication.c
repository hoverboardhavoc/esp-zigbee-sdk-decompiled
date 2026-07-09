/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> nwk_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_intrp_data_indication(undefined2 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar2 = zmsg_get_offset(iVar4);
  iVar3 = aps_frame_validate_nsdu(iVar4);
  if (iVar3 == 0) {
    if (iVar4 != 0) {
      zmsg_free(iVar4);
    }
  }
  else {
    iVar3 = zmsg_read_bytes(iVar4,iVar2,1,&local_30);
    uVar1 = iVar2 + iVar3 & 0xffff;
    if ((local_30 & 3) == 3) {
      if ((local_30 & 0xc) == 0xc) {
        uStack_1c = CONCAT31(uStack_1c._1_3_,1);
        iVar2 = zmsg_read_bytes(iVar4,uVar1,2,(int)&uStack_1c + 2);
        uVar1 = iVar2 + uVar1 & 0xffff;
      }
      else {
        uStack_1c = *(undefined4 *)(param_1 + 7);
        uStack_18 = *(undefined4 *)(param_1 + 9);
        uStack_14 = CONCAT22(uStack_14._2_2_,param_1[0xb]);
      }
      iVar2 = zmsg_read_bytes(iVar4,uVar1,2,(int)&local_30 + 2);
      uVar1 = uVar1 + iVar2 & 0xffff;
      iVar2 = zmsg_read_bytes(iVar4,uVar1,2,&uStack_2c);
      uStack_28 = *(undefined4 *)(param_1 + 1);
      uStack_24 = *(undefined4 *)(param_1 + 3);
      uStack_2c = CONCAT22(*param_1,(undefined2)uStack_2c);
      uStack_20 = *(undefined4 *)(param_1 + 5);
      uStack_14 = CONCAT13(*(undefined1 *)((int)param_1 + 0x1d),
                           CONCAT12(*(undefined1 *)(param_1 + 0xe),(undefined2)uStack_14));
      zmsg_remove_header(iVar4,uVar1 + iVar2 & 0xffff);
      aps_handle_intrp_data_ind(&local_30,iVar4);
    }
    else if (iVar4 != 0) {
      zmsg_free(iVar4);
    }
  }
  return;
}

