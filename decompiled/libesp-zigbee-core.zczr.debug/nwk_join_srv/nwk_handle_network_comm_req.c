/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_network_comm_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_comm_req(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  code *pcVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int extraout_a1;
  undefined4 *extraout_a1_00;
  uint uVar10;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  int iStack_7c;
  int iStack_78;
  code *pcStack_74;
  undefined2 uStack_70;
  undefined2 uStack_6e;
  undefined1 auStack_6c [10];
  undefined1 uStack_62;
  byte abStack_61 [9];
  uint uStack_58;
  int iStack_54;
  uint uStack_50;
  int iStack_4c;
  int iStack_48;
  code *pcStack_44;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined1 auStack_34 [10];
  byte bStack_2a;
  byte bStack_29;
  byte abStack_28 [16];
  
  iVar6 = nwk_is_router_started();
  if ((iVar6 != 0) && (*(short *)(param_2 + 2) == *(short *)(param_2 + 6))) {
    sVar4 = zmsg_get_offset(param_1);
    sVar5 = zmsg_read_bytes(param_1,sVar4 + 1,1,&bStack_29);
    zmsg_read_bytes(param_1,sVar4 + 1 + sVar5,1,&bStack_2a);
    uVar2 = *(ushort *)(param_1 + 0x16);
    uVar10 = (uint)((uVar2 & 2) != 0);
    abStack_28[0] = 3;
    abStack_28[1] = 6;
    abStack_28[2] = 4;
    abStack_28[3] = 5;
    abStack_28[4] = 6;
    abStack_28[5] = 6;
    bVar1 = abStack_28[(uint)((uVar2 & 2) != 0) + (uint)bStack_29 * 2];
    if (bVar1 < 6) {
      uStack_36 = *(undefined2 *)(param_2 + 6);
      iVar6 = nwk_frame_get_src_extaddr(param_1,auStack_34);
      if (iVar6 == 0) {
        iVar6 = nwk_accept_child(*(undefined1 *)(param_2 + 8),auStack_34,bStack_2a,bVar1,&uStack_36)
        ;
        if (iVar6 == 0xe2) {
          return;
        }
        zmsg_free(param_1);
        if ((uVar2 & 2) == 0) {
          uVar7 = 0x21;
        }
        else {
          uVar7 = 0x2f;
        }
        iVar8 = zmsg_alloc(uVar7);
        if (iVar8 != 0) {
          zmsg_set_offset(0);
          uVar7 = nwk_get_short_address();
          nwk_frame_write_hdr(iVar8,uVar7,*(undefined2 *)(param_2 + 6),1,uVar10,0);
          nwk_frame_add_dst_extaddr(iVar8,auStack_34);
          iVar9 = core_globals_get();
          uStack_38._0_1_ = *(char *)(iVar9 + 0x9d9);
          *(char *)(iVar9 + 0x9d9) = (char)uStack_38 + '\x01';
          zmsg_write_bytes(iVar8,7,1,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,0xf);
          zmsg_append_bytes(iVar8,1,&uStack_38);
          uStack_38 = uStack_36;
          zmsg_append_bytes(iVar8,2,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,(char)iVar6);
          zmsg_append_bytes(iVar8,1,&uStack_38);
          nwk_fwd_mac_data_req
                    (iVar8,*(undefined1 *)(param_2 + 8),*(undefined2 *)(param_2 + 6),
                     bStack_2a >> 3 & 1 ^ 1);
          return;
        }
        pcVar3 = nwk_handle_rejoin_req;
        iVar9 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",299,
                              "nwk_handle_network_comm_req",
                              "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((is_secured) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                             );
        uStack_58 = uVar10;
        iStack_54 = iVar6;
        uStack_50 = uVar2 & 2;
        iStack_4c = param_2;
        iStack_48 = iVar8;
        pcStack_44 = pcVar3;
        iVar6 = nwk_is_router_started();
        if ((iVar6 != 0) && (*(short *)(extraout_a1 + 2) == *(short *)(extraout_a1 + 6))) {
          sVar4 = zmsg_get_offset(iVar9);
          zmsg_read_bytes(iVar9,sVar4 + 1,1,abStack_61);
          uVar2 = *(ushort *)(iVar9 + 0x16);
          if ((uVar2 & 2) == 0) {
            uStack_62 = 1;
          }
          else {
            uStack_62 = 2;
          }
          uStack_6e = *(undefined2 *)(extraout_a1 + 6);
          iVar6 = nwk_frame_get_src_extaddr(iVar9,auStack_6c);
          if (iVar6 == 0) {
            iVar6 = nwk_accept_child(*(undefined1 *)(extraout_a1 + 8),auStack_6c,abStack_61[0],
                                     uStack_62,&uStack_6e);
            if (iVar6 == 0xe2) {
              return;
            }
            zmsg_free(iVar9);
            if ((uVar2 & 2) == 0) {
              uVar7 = 0x21;
            }
            else {
              uVar7 = 0x2f;
            }
            iVar8 = zmsg_alloc(uVar7);
            if (iVar8 != 0) {
              zmsg_set_offset(0);
              nwk_frame_write_hdr(iVar8,*(undefined2 *)(extraout_a1 + 4),
                                  *(undefined2 *)(extraout_a1 + 6),1,(uVar2 & 2) != 0,0);
              nwk_frame_add_dst_extaddr(iVar8,auStack_6c);
              iVar9 = core_globals_get();
              uStack_70._0_1_ = *(char *)(iVar9 + 0x9d9);
              *(char *)(iVar9 + 0x9d9) = (char)uStack_70 + '\x01';
              zmsg_write_bytes(iVar8,7,1,&uStack_70);
              uStack_70 = CONCAT11(uStack_70._1_1_,7);
              zmsg_append_bytes(iVar8,1,&uStack_70);
              uStack_70 = uStack_6e;
              zmsg_append_bytes(iVar8,2,&uStack_70);
              uStack_70 = CONCAT11(uStack_70._1_1_,(char)iVar6);
              zmsg_append_bytes(iVar8,1,&uStack_70);
              zmsg_add_footer(iVar8,&uStack_62,1);
              nwk_fwd_mac_data_req
                        (iVar8,*(undefined1 *)(extraout_a1 + 8),*(undefined2 *)(extraout_a1 + 6),
                         abStack_61[0] >> 3 & 1 ^ 1);
              return;
            }
            pcVar3 = nwk_handle_asso_indication;
            uVar7 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",
                                  0x15b,"nwk_handle_rejoin_req",
                                  "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((is_secured) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                                 );
            iStack_7c = extraout_a1;
            iStack_78 = iVar8;
            pcStack_74 = pcVar3;
            iVar6 = nwk_is_router_started();
            if (iVar6 != 0) {
              uStack_84 = 0xfffe;
              uStack_8c = *extraout_a1_00;
              uStack_88 = extraout_a1_00[1];
              iVar6 = nwk_accept_child(uVar7,extraout_a1_00,*(undefined1 *)(extraout_a1_00 + 2),0,
                                       &uStack_84);
              uStack_84._0_3_ = CONCAT12((char)iVar6,(undefined2)uStack_84);
              if ((iVar6 != 0xe2) && (iVar6 = nwk_mm_asso_response(uVar7,&uStack_8c), iVar6 != 0)) {
                nwk_accept_child_done(&uStack_8c,0);
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
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

