/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_network_comm_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_network_comm_req(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  byte join_method;
  ushort uVar1;
  _Bool _Var2;
  mac_status_t mVar3;
  short sVar4;
  short sVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined3 extraout_var_00;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte bStack_36;
  byte bStack_35;
  ezb_shortaddr_t eStack_34;
  uint8_t comm_type;
  mac_cap_info_t mac_cap;
  ezb_shortaddr_t alloc_shortaddr;
  undefined2 uStack_2c;
  undefined1 auStack_28 [4];
  ezb_extaddr_t device_address;
  
  _Var2 = nwk_is_router_started();
  if ((CONCAT31(extraout_var,_Var2) == 0) || (rx_info->mac_src_addr != rx_info->nwk_src_addr)) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
  }
  else {
    sVar4 = zmsg_get_offset(msg);
    sVar5 = zmsg_read_bytes(msg,sVar4 + 1,1,&bStack_36);
    zmsg_read_bytes(msg,sVar4 + 1 + sVar5,1,&bStack_35);
    _alloc_shortaddr = 0x5040603;
    uStack_2c = 0x606;
    uVar1 = msg->flags;
    uVar9 = (uVar1 & 2) >> 1;
    join_method = *(byte *)((int)&alloc_shortaddr + uVar9 + (uint)bStack_36 * 2);
    if (join_method < 6) {
      eStack_34 = rx_info->nwk_src_addr;
      iVar6 = nwk_frame_get_src_extaddr(msg,auStack_28);
      if (iVar6 == 0) {
        mVar3 = nwk_accept_child(rx_info->iface_id,(ezb_extaddr_t *)auStack_28,bStack_35,join_method
                                 ,&eStack_34);
        if (CONCAT31(extraout_var_00,mVar3) == 0xe2) {
          return;
        }
        zmsg_free(msg);
        iVar6 = zmsg_alloc((-(uint)((uVar1 & 2) == 0) & 0xfffffff2) + 0x2f);
        if (iVar6 == 0) {
          __assert_func(0,0,0);
        }
        zmsg_set_offset(0);
        uVar7 = nwk_get_short_address();
        nwk_frame_write_hdr(iVar6,uVar7,rx_info->nwk_src_addr,1,uVar9,0);
        nwk_frame_add_dst_extaddr(iVar6,auStack_28);
        iVar8 = core_globals_get();
        comm_type = *(uint8_t *)(iVar8 + 0x9d9);
        *(uint8_t *)(iVar8 + 0x9d9) = comm_type + '\x01';
        zmsg_write_bytes(iVar6,7,1,&comm_type);
        _comm_type = CONCAT11(mac_cap,0xf);
        zmsg_append_bytes(iVar6,1,&comm_type);
        _comm_type = eStack_34;
        zmsg_append_bytes(iVar6,2,&comm_type);
        _comm_type = CONCAT11(mac_cap,mVar3);
        zmsg_append_bytes(iVar6,1,&comm_type);
        nwk_fwd_mac_data_req(iVar6,rx_info->iface_id,rx_info->nwk_src_addr,bStack_35 >> 3 & 1 ^ 1);
        return;
      }
    }
  }
  zmsg_free(msg);
  return;
}

