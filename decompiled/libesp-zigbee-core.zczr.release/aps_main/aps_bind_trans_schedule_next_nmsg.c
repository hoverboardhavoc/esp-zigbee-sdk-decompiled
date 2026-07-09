/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_bind_trans_schedule_next_nmsg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_bind_trans_schedule_next_nmsg
               (undefined4 param_1,undefined2 *param_2,undefined4 param_3,char *param_4)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 local_50;
  int iStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined4 uStack_44;
  undefined2 uStack_40;
  undefined1 uStack_3d;
  
  local_50 = param_3;
  memset(&iStack_4c,0,0x1c);
  zmsg_get_footer(param_3,&iStack_4c,0x1c);
  cVar2 = '\0';
  while (((param_2 = (undefined2 *)aps_bind_table_next_dst_by_src(param_1,param_2),
          param_2 != (undefined2 *)0x0 && (iVar3 = zmsg_clone(param_3), iVar3 != 0)) &&
         (iVar4 = zmsg_add_footer(&local_50,4), iVar4 == 0))) {
    uVar1 = *param_2;
    *(ushort *)(iVar3 + 0x16) = *(ushort *)(iVar3 + 0x16) | 0x20;
    if ((*(byte *)((int)param_2 + 5) & 1) == 0) {
      _uStack_48 = CONCAT31(stack0xffffffb9,3);
      iVar4 = nwk_address_extended_by_ref(&uStack_46);
      if (iVar4 != 0) {
        __assert_func(0,0,0,0);
      }
      uStack_3d = *(undefined1 *)(param_2 + 1);
    }
    else {
      uStack_40 = 0;
      _uStack_48 = CONCAT22(uVar1,1);
      uStack_44 = 0xffff;
      uStack_3d = 0;
    }
    iStack_4c = iVar3;
    iVar3 = aps_apsde_data_request(&iStack_4c);
    if (iVar3 == 0) {
      cVar2 = cVar2 + '\x01';
    }
  }
  if (cVar2 != '\0') {
    *param_4 = cVar2;
  }
  return cVar2 == '\0';
}

