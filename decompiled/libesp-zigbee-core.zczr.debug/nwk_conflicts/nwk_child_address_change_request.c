/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_child_address_change_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_child_address_change_request(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  ushort uStack_24;
  undefined1 auStack_21 [9];
  
  iVar2 = zmsg_alloc(0x2f);
  if (iVar2 == 0) {
    nwk_child_address_change_confirm(param_1,0xfffe,1);
  }
  else {
    uVar1 = nwk_assign_shortaddr();
    zmsg_set_offset(iVar2,0);
    uVar3 = nwk_get_short_address();
    uVar4 = nwk_neighbor_get_shortaddr(param_1);
    nwk_frame_write_hdr(iVar2,uVar3,uVar4,1,1,0);
    iVar5 = core_globals_get();
    uStack_24._0_1_ = *(char *)(iVar5 + 0x9d9);
    *(char *)(iVar5 + 0x9d9) = (char)uStack_24 + '\x01';
    zmsg_write_bytes(iVar2,7,1,&uStack_24);
    uStack_24 = CONCAT11(uStack_24._1_1_,7);
    zmsg_append_bytes(iVar2,1,&uStack_24);
    uStack_24 = uVar1;
    zmsg_append_bytes(iVar2,2,&uStack_24);
    uStack_24 = uStack_24 & 0xff00;
    zmsg_append_bytes(iVar2,1,&uStack_24);
    auStack_21[0] = 7;
    zmsg_add_footer(iVar2,auStack_21,1);
    uVar6 = *(uint *)(param_1 + 0xc);
    uVar3 = nwk_neighbor_get_shortaddr(param_1);
    nwk_fwd_mac_data_req(iVar2,uVar6 >> 0xd & 0x1f,uVar3,*(uint *)(param_1 + 0xc) >> 10 & 1 ^ 1);
  }
  return;
}

