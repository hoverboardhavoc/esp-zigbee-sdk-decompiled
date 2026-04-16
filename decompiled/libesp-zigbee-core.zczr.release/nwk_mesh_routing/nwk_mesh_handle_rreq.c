/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_handle_rreq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_handle_rreq(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ezb_shortaddr_t sender_addr;
  ezb_shortaddr_t src_addr;
  ushort dst_addr;
  _Bool _Var1;
  uint8_t path_cost;
  char cVar2;
  short sVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 uVar5;
  nwk_neighbor_t *pnVar6;
  uint uVar7;
  ezb_err_t eVar8;
  uint uVar9;
  byte bStack_32;
  uint8_t uStack_31;
  uint8_t radius;
  uint uStack_30;
  nwk_rreq_cmd_t rreq;
  
  _Var1 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
    goto _L0;
  }
  iVar4 = nwk_secur_get_seclevel();
  if ((ushort)(iVar4 != 0) != (msg->flags >> 1 & 1)) goto _L0;
  uStack_30 = 0;
  rreq.cmd_opt = '\0';
  rreq.rreq_id = '\0';
  rreq.dst_addr = 0;
  rreq._4_4_ = 0;
  rreq.dst_ieee_addr.field_0.u8[3] = '\0';
  zmsg_move_offset(msg,1);
  uVar5 = zmsg_get_offset(msg);
  zmsg_read_bytes(msg,uVar5,0xd,&stack0xffffffd0);
  sender_addr = rx_info->mac_src_addr;
  pnVar6 = nwk_mesh_update_neighbor(rx_info);
  if (pnVar6 == (nwk_neighbor_t *)0x0) goto _L0;
  dst_addr = _radius;
  uVar9 = (uint)_radius;
  if (0xfff7 < uVar9 != (((int)(uStack_30 & 0xff) >> 3 & 3U) != 0)) goto _L0;
  src_addr = rx_info->nwk_src_addr;
  path_cost = nwk_neighbor_get_link_cost();
  rreq.cmd_opt = (uint8_t)rreq._0_4_ + path_cost;
  iVar4 = core_globals_get();
  if ((*(char *)(iVar4 + 0x9f7) != '\0') && (uVar7 = nwk_get_short_address(), uVar9 == uVar7)) {
    nwk_concentrator_discovery();
  }
  eVar8 = nwk_mesh_route_discovery_update
                    (uStack_30._1_1_,(byte)((int)(uStack_30 & 0xff) >> 3) & 3,rreq.cmd_opt,src_addr,
                     sender_addr,dst_addr);
  if (eVar8 != 0) goto _L0;
  nwk_route_table_add_rev_route(src_addr,sender_addr,(int)(uStack_30 & 0xff) >> 3 & 3);
  iVar4 = nwk_neighbor_table_get_by_short(uVar9);
  if ((iVar4 != 0) && ((*(uint *)(iVar4 + 0xc) & 0x3c0) != 0x40)) {
    iVar4 = 0;
  }
  if (((int)(uStack_30 & 0xff) >> 3 & 3U) != 0) {
_L0:
    zmsg_read_bytes(msg,6,1,&bStack_32);
    if (1 < bStack_32) {
      uStack_31 = bStack_32 - 1;
      zmsg_write_bytes(msg,6,&uStack_31);
      sVar3 = zmsg_get_offset(msg);
      uStack_31 = rreq.cmd_opt;
      zmsg_write_bytes(msg,sVar3 + 4,1,&uStack_31);
      nwk_fwd_send_msg(msg);
      return;
    }
_L0:
    zmsg_free(msg);
    return;
  }
  uVar7 = nwk_get_short_address();
  if (uVar9 == uVar7) {
    if (iVar4 == 0) goto _L0;
  }
  else if (iVar4 == 0) goto _L0;
  cVar2 = nwk_neighbor_get_link_cost(iVar4);
  path_cost = cVar2 + path_cost;
_L0:
  nwk_mesh_send_rrep(msg,uStack_30._1_1_,path_cost,src_addr,dst_addr,sender_addr);
  return;
}

