/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_handle_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_mesh_handle_rrep(int param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uStack_39;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined1 uStack_22;
  
  iVar5 = nwk_is_router_started();
  if ((iVar5 != 0) &&
     (iVar5 = nwk_secur_get_seclevel(), ((*(ushort *)(param_1 + 0x16) & 2) != 0) == (iVar5 != 0))) {
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_22 = 0;
    zmsg_move_offset(param_1,1);
    uVar6 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,uVar6,0x17,&uStack_38);
    uVar1 = *(undefined2 *)(param_2 + 2);
    iVar5 = nwk_mesh_update_neighbor(param_2);
    uVar2 = uStack_38 >> 0x10;
    uVar9 = uStack_34 & 0xffff;
    iVar7 = nwk_route_disc_table_find(uVar2,uStack_38 >> 8 & 0xff);
    if (((iVar5 != 0) &&
        (((iVar7 != 0 && (*(int *)(iVar7 + 4) != 0)) &&
         ((*(ushort *)(*(int *)(iVar7 + 4) + 0xe) & 7) != 3)))) &&
       (uStack_34._2_1_ < *(byte *)(iVar7 + 0xc))) {
      *(byte *)(iVar7 + 0xc) = uStack_34._2_1_;
      nwk_route_table_update_route(uVar1);
      uVar8 = nwk_get_short_address();
      if (uVar2 == uVar8) {
        zmsg_free(param_1);
        return;
      }
      iVar5 = nwk_mesh_find_router_nbr(*(undefined2 *)(iVar7 + 2));
      if (iVar5 != 0) {
        cVar3 = nwk_neighbor_get_link_cost();
        uVar8 = uStack_34 >> 0x10;
        uStack_34._0_3_ = CONCAT12((char)uVar8 + cVar3,(undefined2)uStack_34);
        sVar4 = zmsg_get_offset(param_1);
        uStack_39 = uStack_34._2_1_;
        zmsg_write_bytes(param_1,sVar4 + 6,1,&uStack_39);
        nwk_mesh_send_rrep(param_1,uStack_38 >> 8 & 0xff,uStack_34 >> 0x10 & 0xff,uVar2,uVar9,
                           *(undefined2 *)(iVar7 + 2));
        nwk_route_table_add_rev_route(uVar2,*(undefined2 *)(iVar7 + 2),0);
        return;
      }
    }
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

