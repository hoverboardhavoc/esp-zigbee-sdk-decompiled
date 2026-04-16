/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_rejoin_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_rejoin_req(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ushort uVar1;
  _Bool _Var2;
  mac_status_t mVar3;
  short sVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined3 extraout_var_00;
  int iVar6;
  undefined2 uStack_2e;
  ezb_shortaddr_t eStack_2c;
  mac_cap_info_t mac_cap;
  nwk_join_method_t join_method;
  ezb_shortaddr_t alloc_shortaddr;
  ezb_extaddr_t device_address;
  
  _Var2 = nwk_is_router_started();
  if ((CONCAT31(extraout_var,_Var2) == 0) || (rx_info->mac_src_addr != rx_info->nwk_src_addr)) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    sVar4 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,sVar4 + 1,1,&uStack_2e);
    uVar1 = msg->flags;
    uStack_2e = CONCAT11(((uVar1 & 2) != 0) + '\x01',(mac_cap_info_t)uStack_2e);
    eStack_2c = rx_info->nwk_src_addr;
    iVar5 = nwk_frame_get_src_extaddr(msg,&alloc_shortaddr);
    if (iVar5 == 0) {
      mVar3 = nwk_accept_child(rx_info->iface_id,(ezb_extaddr_t *)&alloc_shortaddr,
                               (mac_cap_info_t)uStack_2e,uStack_2e._1_1_,&eStack_2c);
      if (CONCAT31(extraout_var_00,mVar3) == 0xe2) {
        return;
      }
      zmsg_free(msg);
      iVar5 = zmsg_alloc((-(uint)((uVar1 & 2) == 0) & 0xfffffff2) + 0x2f);
      if (iVar5 == 0) {
        __assert_func(0,0,0);
      }
      zmsg_set_offset(0);
      nwk_frame_write_hdr(iVar5,rx_info->nwk_dst_addr,rx_info->nwk_src_addr,1,(uVar1 & 2) >> 1,0);
      nwk_frame_add_dst_extaddr(iVar5,&alloc_shortaddr);
      iVar6 = core_globals_get();
      mac_cap = *(mac_cap_info_t *)(iVar6 + 0x9d9);
      *(mac_cap_info_t *)(iVar6 + 0x9d9) = mac_cap + '\x01';
      zmsg_write_bytes(iVar5,7,1,&mac_cap);
      _mac_cap = CONCAT11(join_method,7);
      zmsg_append_bytes(iVar5,1,&mac_cap);
      _mac_cap = eStack_2c;
      zmsg_append_bytes(iVar5,2,&mac_cap);
      _mac_cap = CONCAT11(join_method,mVar3);
      zmsg_append_bytes(iVar5,1,&mac_cap);
      zmsg_add_footer(iVar5,(int)&uStack_2e + 1,1);
      nwk_fwd_mac_data_req(iVar5,rx_info->iface_id,rx_info->nwk_src_addr,uStack_2e >> 3 & 1 ^ 1);
      return;
    }
  }
  zmsg_free(msg);
  return;
}

