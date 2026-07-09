/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_handle_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mesh_handle_rrep(int param_1,int param_2)

{
  undefined2 uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char cStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  ushort uStack_36;
  undefined2 uStack_34;
  byte bStack_32;
  
  iVar4 = nwk_is_router_started();
  if (iVar4 == 0) {
    if (param_1 == 0) {
      return;
    }
  }
  else {
    iVar4 = nwk_secur_get_seclevel();
    if ((ushort)(iVar4 != 0) == (*(ushort *)(param_1 + 0x16) >> 1 & 1)) {
      memset(&uStack_38,0,0x17);
      zmsg_move_offset(param_1,1);
      uVar5 = zmsg_get_offset(param_1);
      zmsg_read_bytes(param_1,uVar5,0x17,&uStack_38);
      uVar1 = *(undefined2 *)(param_2 + 2);
      iVar4 = nwk_mesh_update_neighbor(param_2);
      uVar9 = (uint)uStack_36;
      iVar6 = nwk_route_disc_table_find(uVar9,uStack_37);
      if ((((iVar4 != 0) && (iVar6 != 0)) && (*(int *)(iVar6 + 4) != 0)) &&
         (((*(ushort *)(*(int *)(iVar6 + 4) + 0xe) & 7) != 3 && (bStack_32 < *(byte *)(iVar6 + 0xc))
          ))) {
        *(byte *)(iVar6 + 0xc) = bStack_32;
        nwk_route_table_update_route(uVar1);
        uVar7 = nwk_get_short_address();
        if ((uVar9 != uVar7) &&
           ((iVar4 = nwk_neighbor_table_get_by_short(*(undefined2 *)(iVar6 + 2)), iVar4 != 0 &&
            (iVar8 = nwk_neighbor_get_outgoing_cost(), iVar8 != 0)))) {
          cVar2 = nwk_neighbor_get_link_cost(iVar4);
          bStack_32 = cVar2 + bStack_32;
          sVar3 = zmsg_get_offset(param_1);
          cStack_39 = bStack_32;
          zmsg_write_bytes(param_1,sVar3 + 6,1,&cStack_39);
          nwk_mesh_send_rrep(param_1,uStack_37,bStack_32,uVar9,uStack_34,*(undefined2 *)(iVar6 + 2))
          ;
          nwk_route_table_add_rev_route(uVar9,*(undefined2 *)(iVar6 + 2),0);
          return;
        }
      }
    }
  }
  zmsg_free(param_1);
  return;
}

