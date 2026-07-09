/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_apsde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_apsde_data_request(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort local_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  code *pcStack_18;
  int iStack_14;
  
  iVar2 = 2;
  if (param_1 == (int *)0x0) {
    return 2;
  }
  iVar5 = *param_1;
  if (iVar5 == 0) {
    return 2;
  }
  uVar4 = (uint)*(byte *)(param_1 + 1);
  if (uVar4 == 2) {
    uVar1 = *(ushort *)((int)param_1 + 6);
_L0:
    local_26 = uVar1;
    iVar2 = apsde_data_request_continue(param_1,local_26);
    iVar3 = iVar2;
  }
  else if (uVar4 < 3) {
    if (uVar4 != 0) {
      uVar1 = *(ushort *)(param_1 + 2);
      if ((uVar1 < 0xfff8) || (uVar1 == 0xfffe)) goto _L0;
      goto _L0;
    }
    uVar4 = *(ushort *)(iVar5 + 0x16) & 0x20;
    if ((*(ushort *)(iVar5 + 0x16) & 0x20) != 0) {
      iVar2 = __assert_func(0,0,0,0);
      goto _L0;
    }
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    pcStack_18 = (code *)0x0;
    nwk_get_extended_address();
    iVar2 = 0x3a8;
    uStack_24 = aps_bind_table_find_src(*(undefined1 *)((int)param_1 + 0xe),(short)param_1[4]);
    if (((uStack_24 == 0) || (iVar2 = zmsg_add_footer(*param_1,param_1,0x1c), iVar2 != 0)) ||
       (iVar2 = aps_bind_trans_schedule_next_nmsg(uStack_24,uStack_20,*param_1,&pcStack_18),
       iVar2 != 0)) goto _L0;
    iVar2 = zmsg_add_footer(*param_1,&uStack_24,0x10);
    iVar3 = iVar2;
  }
  else {
_L0:
    if (uVar4 != 3) goto _L0;
    iVar2 = nwk_address_short_by_extended((void *)((int)param_1 + 6),&local_26);
    uVar1 = local_26;
    if (iVar2 == 0) goto _L0;
    zmsg_add_footer(iVar5,param_1,0x1c);
    uStack_24 = CONCAT22(uStack_24._2_2_,0xffff);
    uStack_1c = uStack_1c & 0xffff;
    memcpy((void *)((int)&uStack_24 + 2),(void *)((int)param_1 + 6),8);
    pcStack_18 = apsde_handle_nwk_addr_req_result;
    iStack_14 = iVar5;
    iVar3 = zdo_nwk_addr_req(&uStack_24);
    iVar2 = 0x3a9;
  }
  if (iVar3 == 0) {
    return 0;
  }
_L0:
  zmsg_free(iVar5);
  return iVar2;
}

