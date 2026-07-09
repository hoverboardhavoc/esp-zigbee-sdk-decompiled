/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_intrp.o -> nwk_intrp_data_indication
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
  byte abStack_68 [2];
  undefined2 uStack_66;
  undefined2 uStack_64;
  undefined2 uStack_62;
  undefined1 auStack_60 [10];
  undefined2 uStack_56;
  undefined1 auStack_54 [2];
  undefined1 auStack_52 [8];
  undefined2 uStack_4a;
  undefined2 uStack_48;
  undefined1 auStack_46 [10];
  undefined2 uStack_3c;
  undefined1 auStack_3a [10];
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined1 uStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  
  memset(abStack_68,0,0x20);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = zmsg_get_offset(iVar2);
  iVar4 = aps_frame_validate_nsdu(iVar2);
  if ((iVar4 != 0) && (iVar4 = zmsg_read_bytes(iVar2,iVar3,1,abStack_68), (abStack_68[0] & 3) == 3))
  {
    uVar1 = iVar3 + iVar4 & 0xffff;
    if ((abStack_68[0] & 0xc) == 0xc) {
      auStack_54[0] = 1;
      iVar3 = zmsg_read_bytes(iVar2,uVar1,2,auStack_52);
      uVar1 = uVar1 + iVar3 & 0xffff;
    }
    else {
      memcpy(auStack_54,param_1 + 7,10);
    }
    iVar3 = zmsg_read_bytes(iVar2,uVar1,2,&uStack_66);
    uVar1 = uVar1 + iVar3 & 0xffff;
    iVar3 = zmsg_read_bytes(iVar2,uVar1,2,&uStack_64);
    memcpy(auStack_60,param_1 + 1,10);
    uStack_62 = *param_1;
    uStack_56 = param_1[6];
    uStack_4a = param_1[0xe];
    zmsg_remove_header(iVar2,uVar1 + iVar3 & 0xffff);
    uStack_48 = uStack_62;
    memcpy(auStack_46,auStack_60,10);
    uStack_3c = uStack_56;
    memcpy(auStack_3a,auStack_54,10);
    uStack_2c = 0;
    uStack_30 = uStack_64;
    uStack_2e = uStack_66;
    uStack_24 = uStack_4a;
    iStack_28 = iVar2;
    aps_intrp_data_indication(&uStack_48);
    return;
  }
  if (iVar2 != 0) {
    zmsg_free(iVar2);
  }
  return;
}

