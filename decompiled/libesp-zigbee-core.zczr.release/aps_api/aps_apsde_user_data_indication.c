/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> aps_apsde_user_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_apsde_user_data_indication(undefined2 *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_48 [2];
  short sStack_46;
  short sStack_44;
  undefined1 uStack_3e;
  undefined2 uStack_3c;
  ushort uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  int iStack_24;
  
  if (param_1 != (undefined2 *)0x0) goto _L0;
  while( true ) {
    param_1 = (undefined2 *)__assert_func(0,0,0,0);
_L0:
    if (s_apsde_data_ind_handler == (code *)0x0) goto _L0;
    iVar5 = *(int *)(param_1 + 8);
    iVar2 = zmsg_get_length(iVar5);
    iVar3 = mm_alloc_notrap(1,iVar2);
    if ((iVar3 == 0) && (iVar2 != 0)) break;
    iVar4 = zmsg_read_bytes(iVar5,0,iVar2,iVar3);
    if (iVar4 == iVar2) {
_L0:
      pcVar1 = s_apsde_data_ind_handler;
      memset(auStack_48,0,0x28);
      if (param_1[2] == 0) {
        auStack_48[0] = 2;
        sStack_46 = param_1[1];
      }
      else {
        auStack_48[0] = 1;
        sStack_46 = param_1[2];
        sStack_44 = param_1[1];
      }
      uStack_3e = 2;
      uStack_3c = *param_1;
      uStack_28 = (undefined2)iVar2;
      uStack_34 = param_1[3] << 8 | (ushort)param_1[3] >> 8;
      uStack_32 = param_1[4];
      uStack_30 = param_1[5];
      uStack_2b = *(undefined1 *)(param_1 + 6);
      uStack_2a = *(undefined1 *)((int)param_1 + 0xd);
      iStack_24 = iVar3;
      iVar2 = (*pcVar1)(auStack_48);
      if (iVar3 != 0) {
        mm_free(iVar3);
      }
      if (iVar2 == 0) {
_L0:
        iVar2 = 0;
      }
      else if (iVar5 != 0) {
        zmsg_free(iVar5);
      }
      return iVar2;
    }
  }
  log_write(2,"aps_api.c",0x10000);
  iVar2 = 0;
  goto _L0;
}

