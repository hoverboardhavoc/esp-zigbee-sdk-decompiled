/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_handle_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_handle_rrep(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ezb_shortaddr_t eVar1;
  _Bool _Var2;
  char cVar3;
  short sVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined4 uVar6;
  nwk_neighbor_t *pnVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint8_t uStack_39;
  undefined1 uStack_38;
  uint8_t uStack_37;
  ushort uStack_36;
  nwk_rrep_cmd_t rrep;
  
  _Var2 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var2) == 0) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    iVar5 = nwk_secur_get_seclevel();
    if ((ushort)(iVar5 != 0) == (msg->flags >> 1 & 1)) {
      memset(&uStack_38,0,0x17);
      zmsg_move_offset(msg,1);
      uVar6 = zmsg_get_offset(msg);
      zmsg_read_bytes(msg,uVar6,0x17,&uStack_38);
      eVar1 = rx_info->mac_src_addr;
      pnVar7 = nwk_mesh_update_neighbor(rx_info);
      uVar11 = (uint)uStack_36;
      iVar5 = nwk_route_disc_table_find(uVar11,uStack_37);
      if ((((pnVar7 != (nwk_neighbor_t *)0x0) && (iVar5 != 0)) && (*(int *)(iVar5 + 4) != 0)) &&
         (((*(ushort *)(*(int *)(iVar5 + 4) + 0xe) & 7) != 3 &&
          ((byte)rrep.orig_addr < *(byte *)(iVar5 + 0xc))))) {
        *(byte *)(iVar5 + 0xc) = (byte)rrep.orig_addr;
        nwk_route_table_update_route(eVar1);
        uVar8 = nwk_get_short_address();
        if ((uVar11 != uVar8) &&
           ((iVar9 = nwk_neighbor_table_get_by_short(*(undefined2 *)(iVar5 + 2)), iVar9 != 0 &&
            (iVar10 = nwk_neighbor_get_outgoing_cost(), iVar10 != 0)))) {
          cVar3 = nwk_neighbor_get_link_cost(iVar9);
          rrep.orig_addr._0_1_ = cVar3 + (byte)rrep.orig_addr;
          sVar4 = zmsg_get_offset(msg);
          uStack_39 = (byte)rrep.orig_addr;
          zmsg_write_bytes(msg,sVar4 + 6,1,&uStack_39);
          nwk_mesh_send_rrep(msg,uStack_37,(byte)rrep.orig_addr,uStack_36,rrep._0_2_,
                             *(ezb_shortaddr_t *)(iVar5 + 2));
          nwk_route_table_add_rev_route(uVar11,*(undefined2 *)(iVar5 + 2),0);
          return;
        }
      }
    }
  }
  zmsg_free(msg);
  return;
}

