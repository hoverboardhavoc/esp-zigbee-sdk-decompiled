/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_handle_rrep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_handle_rrep(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ezb_shortaddr_t eVar1;
  ushort originator;
  undefined2 responder;
  nwk_route_disc_t *route_disc;
  _Bool _Var2;
  char cVar3;
  short sVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined4 uVar6;
  nwk_neighbor_t *pnVar7;
  uint uVar8;
  ezb_shortaddr_t src_addr;
  uint uVar9;
  undefined1 uStack_39;
  undefined4 uStack_38;
  nwk_rrep_cmd_t rrep;
  
  _Var2 = nwk_is_router_started();
  if ((CONCAT31(extraout_var,_Var2) != 0) &&
     (iVar5 = nwk_secur_get_seclevel(), ((msg->flags & 2) != 0) == (iVar5 != 0))) {
    uStack_38 = 0;
    rrep.cmd_opt = '\0';
    rrep.rreq_id = '\0';
    rrep.orig_addr = 0;
    rrep._4_4_ = 0;
    rrep.orig_ieee_addr.field_0.u64._1_4_ = 0;
    rrep._12_4_ = 0;
    rrep.resp_ieee_addr.field_0.u64._1_2_ = 0;
    rrep.resp_ieee_addr.field_0.u8[3] = '\0';
    zmsg_move_offset(msg,1);
    uVar6 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,uVar6,0x17,&uStack_38);
    eVar1 = rx_info->mac_src_addr;
    pnVar7 = nwk_mesh_update_neighbor(rx_info);
    originator = uStack_38._2_2_;
    uVar9 = (uint)uStack_38._2_2_;
    responder = rrep._0_2_;
    iVar5 = nwk_route_disc_table_find(uVar9,uStack_38 >> 8 & 0xff);
    if (((pnVar7 != (nwk_neighbor_t *)0x0) &&
        (((iVar5 != 0 && (*(int *)(iVar5 + 4) != 0)) &&
         ((*(ushort *)(*(int *)(iVar5 + 4) + 0xe) & 7) != 3)))) &&
       ((byte)rrep.orig_addr < *(byte *)(iVar5 + 0xc))) {
      *(byte *)(iVar5 + 0xc) = (byte)rrep.orig_addr;
      nwk_route_table_update_route(eVar1);
      uVar8 = nwk_get_short_address();
      if (uVar9 == uVar8) {
        zmsg_free(msg);
        return;
      }
      pnVar7 = nwk_mesh_find_router_nbr(*(ezb_shortaddr_t *)(iVar5 + 2));
      if (pnVar7 != (nwk_neighbor_t *)0x0) {
        cVar3 = nwk_neighbor_get_link_cost();
        rrep.orig_addr._0_1_ = SUB41(rrep._0_4_,2) + cVar3;
        sVar4 = zmsg_get_offset(msg);
        uStack_39 = (byte)rrep.orig_addr;
        zmsg_write_bytes(msg,sVar4 + 6,1,&uStack_39);
        nwk_mesh_send_rrep(msg,uStack_38._1_1_,(byte)rrep.orig_addr,originator,responder,
                           *(ezb_shortaddr_t *)(iVar5 + 2));
        nwk_route_table_add_rev_route(uVar9,*(undefined2 *)(iVar5 + 2),0);
        return;
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

