/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_network_comm_req
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
  code *pcVar2;
  _Bool _Var3;
  mac_status_t mVar4;
  short sVar5;
  short sVar6;
  undefined3 extraout_var;
  int iVar7;
  undefined3 extraout_var_00;
  undefined4 uVar8;
  int iVar9;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  int extraout_a1;
  ezb_extaddr_t *device_extaddr;
  _Bool is_secured;
  uint uVar10;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 aStack_8c;
  ezb_shortaddr_t eStack_84;
  mac_status_t mStack_82;
  undefined1 uStack_81;
  int iStack_7c;
  int iStack_78;
  code *pcStack_74;
  ezb_shortaddr_t eStack_70;
  ezb_shortaddr_t eStack_6e;
  ezb_extaddr_t eStack_6c;
  nwk_join_method_t nStack_62;
  byte abStack_61 [9];
  uint uStack_58;
  int iStack_54;
  uint uStack_50;
  nwk_rx_info_t *pnStack_4c;
  int iStack_48;
  code *pcStack_44;
  ezb_shortaddr_t eStack_38;
  ezb_shortaddr_t eStack_36;
  undefined1 auStack_34 [2];
  ezb_shortaddr_t alloc_shortaddr;
  ezb_extaddr_t device_address;
  byte abStack_28 [2];
  mac_cap_info_t mac_cap;
  uint8_t comm_type;
  undefined2 uStack_24;
  
  _Var3 = nwk_is_router_started();
  if ((CONCAT31(extraout_var,_Var3) != 0) && (rx_info->mac_src_addr == rx_info->nwk_src_addr)) {
    sVar5 = zmsg_get_offset(msg);
    sVar6 = zmsg_read_bytes(msg,sVar5 + 1,1,(undefined1 *)((int)&device_address.field_0 + 7));
    zmsg_read_bytes(msg,sVar5 + 1 + sVar6,1,(undefined1 *)((int)&device_address.field_0 + 6));
    uVar1 = msg->flags;
    uVar10 = (uint)((uVar1 & 2) != 0);
    _abStack_28 = 0x5040603;
    uStack_24 = 0x606;
    join_method = abStack_28[(uint)((uVar1 & 2) != 0) + (uint)device_address.field_0.u8[7] * 2];
    if (join_method < 6) {
      eStack_36 = rx_info->nwk_src_addr;
      iVar7 = nwk_frame_get_src_extaddr(msg,auStack_34);
      if (iVar7 == 0) {
        mVar4 = nwk_accept_child(rx_info->iface_id,(ezb_extaddr_t *)auStack_34,
                                 device_address.field_0.u8[6],join_method,&eStack_36);
        if (CONCAT31(extraout_var_00,mVar4) == 0xe2) {
          return;
        }
        zmsg_free(msg);
        if ((uVar1 & 2) == 0) {
          uVar8 = 0x21;
        }
        else {
          uVar8 = 0x2f;
        }
        iVar7 = zmsg_alloc(uVar8);
        if (iVar7 != 0) {
          zmsg_set_offset(0);
          uVar8 = nwk_get_short_address();
          nwk_frame_write_hdr(iVar7,uVar8,rx_info->nwk_src_addr,1,uVar10,0);
          nwk_frame_add_dst_extaddr(iVar7,auStack_34);
          iVar9 = core_globals_get();
          eStack_38._0_1_ = *(char *)(iVar9 + 0x9d9);
          *(char *)(iVar9 + 0x9d9) = (char)eStack_38 + '\x01';
          zmsg_write_bytes(iVar7,7,1,&eStack_38);
          eStack_38 = CONCAT11(eStack_38._1_1_,0xf);
          zmsg_append_bytes(iVar7,1,&eStack_38);
          eStack_38 = eStack_36;
          zmsg_append_bytes(iVar7,2,&eStack_38);
          eStack_38 = CONCAT11(eStack_38._1_1_,mVar4);
          zmsg_append_bytes(iVar7,1,&eStack_38);
          nwk_fwd_mac_data_req
                    (iVar7,rx_info->iface_id,rx_info->nwk_src_addr,
                     device_address.field_0.u8[6] >> 3 & 1 ^ 1);
          return;
        }
        pcVar2 = nwk_handle_rejoin_req;
        iVar9 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",299,
                              "nwk_handle_network_comm_req",
                              "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((is_secured) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                             );
        uStack_58 = uVar10;
        iStack_54 = CONCAT31(extraout_var_00,mVar4);
        uStack_50 = uVar1 & 2;
        pnStack_4c = rx_info;
        iStack_48 = iVar7;
        pcStack_44 = pcVar2;
        _Var3 = nwk_is_router_started();
        if ((CONCAT31(extraout_var_01,_Var3) != 0) &&
           (*(short *)(extraout_a1 + 2) == *(short *)(extraout_a1 + 6))) {
          sVar5 = zmsg_get_offset(iVar9);
          zmsg_read_bytes(iVar9,sVar5 + 1,1,abStack_61);
          uVar1 = *(ushort *)(iVar9 + 0x16);
          if ((uVar1 & 2) == 0) {
            nStack_62 = '\x01';
          }
          else {
            nStack_62 = '\x02';
          }
          eStack_6e = *(ezb_shortaddr_t *)(extraout_a1 + 6);
          iVar7 = nwk_frame_get_src_extaddr(iVar9,&eStack_6c);
          if (iVar7 == 0) {
            mVar4 = nwk_accept_child(*(uint8_t *)(extraout_a1 + 8),&eStack_6c,abStack_61[0],
                                     nStack_62,&eStack_6e);
            if (CONCAT31(extraout_var_02,mVar4) == 0xe2) {
              return;
            }
            zmsg_free(iVar9);
            if ((uVar1 & 2) == 0) {
              uVar8 = 0x21;
            }
            else {
              uVar8 = 0x2f;
            }
            iVar7 = zmsg_alloc(uVar8);
            if (iVar7 != 0) {
              zmsg_set_offset(0);
              nwk_frame_write_hdr(iVar7,*(undefined2 *)(extraout_a1 + 4),
                                  *(undefined2 *)(extraout_a1 + 6),1,(uVar1 & 2) != 0,0);
              nwk_frame_add_dst_extaddr(iVar7,&eStack_6c);
              iVar9 = core_globals_get();
              eStack_70._0_1_ = *(char *)(iVar9 + 0x9d9);
              *(char *)(iVar9 + 0x9d9) = (char)eStack_70 + '\x01';
              zmsg_write_bytes(iVar7,7,1,&eStack_70);
              eStack_70 = CONCAT11(eStack_70._1_1_,7);
              zmsg_append_bytes(iVar7,1,&eStack_70);
              eStack_70 = eStack_6e;
              zmsg_append_bytes(iVar7,2,&eStack_70);
              eStack_70 = CONCAT11(eStack_70._1_1_,mVar4);
              zmsg_append_bytes(iVar7,1,&eStack_70);
              zmsg_add_footer(iVar7,&nStack_62,1);
              nwk_fwd_mac_data_req
                        (iVar7,*(undefined1 *)(extraout_a1 + 8),*(undefined2 *)(extraout_a1 + 6),
                         abStack_61[0] >> 3 & 1 ^ 1);
              return;
            }
            pcVar2 = nwk_handle_asso_indication;
            uVar8 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",
                                  0x15b,"nwk_handle_rejoin_req",
                                  "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((is_secured) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                                 );
            iStack_7c = extraout_a1;
            iStack_78 = iVar7;
            pcStack_74 = pcVar2;
            _Var3 = nwk_is_router_started();
            if (CONCAT31(extraout_var_03,_Var3) != 0) {
              _eStack_84 = 0xfffe;
              aStack_8c.u64._0_4_ = *(undefined4 *)&device_extaddr->field_0;
              aStack_8c.u64._4_4_ = *(undefined4 *)((int)&device_extaddr->field_0 + 4);
              mVar4 = nwk_accept_child((uint8_t)uVar8,device_extaddr,device_extaddr[1].field_0.u8[0]
                                       ,'\0',&eStack_84);
              _eStack_84 = CONCAT12(mVar4,eStack_84);
              if ((CONCAT31(extraout_var_04,mVar4) != 0xe2) &&
                 (iVar7 = nwk_mm_asso_response(uVar8,&aStack_8c), iVar7 != 0)) {
                nwk_accept_child_done(iVar7,(ezb_extaddr_t *)&aStack_8c,'\0');
              }
            }
            return;
          }
        }
        if (iVar9 != 0) {
          zmsg_free(iVar9);
        }
        return;
      }
    }
  }
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

