/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_rejoin_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_rejoin_req(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  ushort uVar1;
  code *pcVar2;
  _Bool _Var3;
  mac_status_t mVar4;
  short sVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined3 extraout_var_00;
  undefined4 uVar7;
  int iVar8;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  ezb_extaddr_t *device_extaddr;
  _Bool is_secured;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 aStack_4c;
  ezb_shortaddr_t eStack_44;
  mac_status_t mStack_42;
  undefined1 uStack_41;
  nwk_rx_info_t *pnStack_3c;
  int iStack_38;
  code *pcStack_34;
  ezb_shortaddr_t local_30;
  ezb_shortaddr_t eStack_2e;
  undefined1 auStack_2c [2];
  ezb_shortaddr_t alloc_shortaddr;
  ezb_extaddr_t device_address;
  nwk_join_method_t join_method;
  mac_cap_info_t mac_cap;
  
  _Var3 = nwk_is_router_started();
  if ((CONCAT31(extraout_var,_Var3) != 0) && (rx_info->mac_src_addr == rx_info->nwk_src_addr)) {
    sVar5 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,sVar5 + 1,1,(undefined1 *)((int)&device_address.field_0 + 7));
    uVar1 = msg->flags;
    if ((uVar1 & 2) == 0) {
      device_address.field_0.u8[6] = '\x01';
    }
    else {
      device_address.field_0.u8[6] = '\x02';
    }
    eStack_2e = rx_info->nwk_src_addr;
    iVar6 = nwk_frame_get_src_extaddr(msg,auStack_2c);
    if (iVar6 == 0) {
      mVar4 = nwk_accept_child(rx_info->iface_id,(ezb_extaddr_t *)auStack_2c,
                               device_address.field_0.u8[7],device_address.field_0.u8[6],&eStack_2e)
      ;
      if (CONCAT31(extraout_var_00,mVar4) == 0xe2) {
        return;
      }
      zmsg_free(msg);
      if ((uVar1 & 2) == 0) {
        uVar7 = 0x21;
      }
      else {
        uVar7 = 0x2f;
      }
      iVar6 = zmsg_alloc(uVar7);
      if (iVar6 != 0) {
        zmsg_set_offset(0);
        nwk_frame_write_hdr(iVar6,rx_info->nwk_dst_addr,rx_info->nwk_src_addr,1,(uVar1 & 2) != 0,0);
        nwk_frame_add_dst_extaddr(iVar6,auStack_2c);
        iVar8 = core_globals_get();
        local_30._0_1_ = *(char *)(iVar8 + 0x9d9);
        *(char *)(iVar8 + 0x9d9) = (char)local_30 + '\x01';
        zmsg_write_bytes(iVar6,7,1,&local_30);
        local_30 = CONCAT11(local_30._1_1_,7);
        zmsg_append_bytes(iVar6,1,&local_30);
        local_30 = eStack_2e;
        zmsg_append_bytes(iVar6,2,&local_30);
        local_30 = CONCAT11(local_30._1_1_,mVar4);
        zmsg_append_bytes(iVar6,1,&local_30);
        zmsg_add_footer(iVar6,(undefined1 *)((int)&device_address.field_0 + 6),1);
        nwk_fwd_mac_data_req
                  (iVar6,rx_info->iface_id,rx_info->nwk_src_addr,
                   device_address.field_0.u8[7] >> 3 & 1 ^ 1);
        return;
      }
      pcVar2 = nwk_handle_asso_indication;
      uVar7 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x15a,
                            "nwk_handle_rejoin_req",
                            "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((is_secured) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                           );
      pnStack_3c = rx_info;
      iStack_38 = iVar6;
      pcStack_34 = pcVar2;
      _Var3 = nwk_is_router_started();
      if (CONCAT31(extraout_var_01,_Var3) != 0) {
        _eStack_44 = 0xfffe;
        aStack_4c.u64._0_4_ = *(undefined4 *)&device_extaddr->field_0;
        aStack_4c.u64._4_4_ = *(undefined4 *)((int)&device_extaddr->field_0 + 4);
        mVar4 = nwk_accept_child((uint8_t)uVar7,device_extaddr,device_extaddr[1].field_0.u8[0],'\0',
                                 &eStack_44);
        _eStack_44 = CONCAT12(mVar4,eStack_44);
        if ((CONCAT31(extraout_var_02,mVar4) != 0xe2) &&
           (iVar6 = nwk_mm_asso_response(uVar7,&aStack_4c), iVar6 != 0)) {
          nwk_accept_child_done(iVar6,(ezb_extaddr_t *)&aStack_4c,'\0');
        }
      }
      return;
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

