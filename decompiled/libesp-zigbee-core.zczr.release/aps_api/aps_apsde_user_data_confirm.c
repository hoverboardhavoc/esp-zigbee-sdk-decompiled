/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_api.o -> aps_apsde_user_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_apsde_user_data_confirm(void *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_38 [10];
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined2 uStack_26;
  int iStack_24;
  
  if (param_1 != (void *)0x0) goto _L0;
  while( true ) {
    param_1 = (void *)__assert_func(0,0,0,0);
_L0:
    iVar5 = *(int *)((int)param_1 + 0x14);
    if (s_apsde_data_confirm_handler == (code *)0x0) goto _L0;
    iVar2 = zmsg_get_length(iVar5);
    iVar3 = mm_alloc_notrap(1,iVar2);
    if ((iVar3 == 0) && (iVar2 != 0)) break;
    iVar4 = zmsg_read_bytes(iVar5,0,iVar2,iVar3);
    if (iVar4 == iVar2) {
_L0:
      pcVar1 = s_apsde_data_confirm_handler;
      memcpy(auStack_38,param_1,10);
      uStack_2e = *(undefined2 *)((int)param_1 + 10);
      uStack_28 = *(undefined1 *)((int)param_1 + 0x10);
      uStack_26 = (undefined2)iVar2;
      uStack_2c = *(undefined4 *)((int)param_1 + 0xc);
      iStack_24 = iVar3;
      (*pcVar1)(auStack_38);
      if (iVar3 != 0) {
        mm_free(iVar3);
      }
_L0:
      if (iVar5 != 0) {
        zmsg_free(iVar5);
      }
      return;
    }
  }
  log_write(2,"aps_api.c","NO MEM for ASDU in APSDE-DATA.confirm");
  iVar2 = 0;
  goto _L0;
}

