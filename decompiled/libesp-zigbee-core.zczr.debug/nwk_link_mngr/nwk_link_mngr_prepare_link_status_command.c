/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_prepare_link_status_command
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2
nwk_link_mngr_prepare_link_status_command(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined1 uVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short *psVar8;
  undefined2 uVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  undefined2 *puVar13;
  ushort uStack_40;
  short asStack_3e [5];
  undefined2 local_34;
  short local_32;
  
  zmsg_set_offset(0);
  uVar4 = nwk_get_short_address();
  nwk_frame_write_hdr(param_1,uVar4,0xfffc,1,1,0);
  iVar5 = core_globals_get();
  local_34._0_1_ = *(char *)(iVar5 + 0x9d9);
  *(char *)(iVar5 + 0x9d9) = (char)local_34 + '\x01';
  zmsg_write_bytes(param_1,7,1,&local_34);
  local_34._0_1_ = 8;
  zmsg_append_bytes(param_1,1,&local_34);
  local_34 = (ushort)local_34._1_1_ << 8;
  zmsg_append_bytes(param_1,1,&local_34);
  if (param_3 == 0) {
    bVar12 = 0x20;
  }
  else {
    bVar12 = 0;
  }
  uVar10 = param_4 + 1 & 0xff;
  iVar5 = -(uVar10 * 4 + 0xf & 0x7f0);
  iVar1 = 0;
  uVar11 = 0;
_L0:
  iVar1 = nwk_router_table_next(iVar1);
  uVar7 = uVar11;
  if (iVar1 == 0) {
    while (1 < uVar7) {
      local_34 = *(short *)((int)&uStack_40 + iVar5);
      local_32 = *(short *)((int)asStack_3e + iVar5);
      psVar8 = (short *)((int)&uStack_40 + (uVar7 - 1) * 4 + iVar5);
      *(short *)((int)&uStack_40 + iVar5) = *psVar8;
      *(short *)((int)asStack_3e + iVar5) = psVar8[1];
      *psVar8 = local_34;
      psVar8[1] = local_32;
      uVar7 = uVar7 - 1 & 0xff;
      nwk_ls_heap_shift_down((int)&uStack_40 + iVar5,uVar7,0);
    }
    if (param_4 < uVar11) {
      uVar11 = uVar11 - 1 & 0xff;
      uVar9 = *(undefined2 *)((int)&uStack_40 + uVar11 * 4 + iVar5);
    }
    else {
      bVar12 = bVar12 | 0x40;
      uVar9 = 0;
    }
    for (uVar10 = 0; uVar10 < uVar11; uVar10 = uVar10 + 1 & 0xff) {
      psVar8 = (short *)((int)&uStack_40 + uVar10 * 4 + iVar5);
      local_34 = *psVar8;
      local_32 = CONCAT11(local_32._1_1_,(char)psVar8[1]);
      zmsg_append_bytes(param_1,3,&local_34);
    }
    sVar3 = zmsg_get_offset(param_1);
    local_34 = CONCAT11(local_34._1_1_,bVar12 | (byte)uVar11 & 0x1f);
    zmsg_write_bytes(param_1,sVar3 + 1,1,&local_34);
    return uVar9;
  }
  uVar7 = *(uint *)(iVar1 + 0xc) & 3;
  if ((uVar7 == 0) || (uVar7 == 1)) goto _L0;
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_link_mngr.c",0xac,
                "nwk_link_mngr_prepare_link_status_command",
                "nwk_device_type_is_zczr(nbr->device_type)");
  goto _L0;
_L0:
  if ((*(uint *)(iVar1 + 0xc) >> 0xd & 0x1f) == param_2) {
_L0:
    iVar6 = nwk_neighbor_get_incoming_cost(iVar1);
    if ((iVar6 != 0) &&
       (((uVar7 = *(uint *)(iVar1 + 0xc) & 0x3c0, uVar7 == 0x80 || (uVar7 == 0x240)) &&
        (uVar7 = nwk_neighbor_get_shortaddr(iVar1), param_3 <= uVar7)))) {
      if (uVar11 < uVar10) {
        puVar13 = (undefined2 *)((int)&uStack_40 + uVar11 * 4 + iVar5);
        *puVar13 = (short)uVar7;
        uVar2 = nwk_neighbor_get_link_status(iVar1);
        *(undefined1 *)(puVar13 + 1) = uVar2;
        nwk_ls_heap_shift_up((int)&uStack_40 + iVar5,uVar11);
        uVar11 = uVar11 + 1 & 0xff;
      }
      else if (uVar7 < *(ushort *)((int)&uStack_40 + iVar5)) {
        *(short *)((int)&uStack_40 + iVar5) = (short)uVar7;
        uVar2 = nwk_neighbor_get_link_status(iVar1);
        *(undefined1 *)((int)asStack_3e + iVar5) = uVar2;
        nwk_ls_heap_shift_down((int)&uStack_40 + iVar5,uVar11,0);
      }
    }
  }
  goto _L0;
}

