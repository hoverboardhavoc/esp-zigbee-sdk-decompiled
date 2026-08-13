/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_handle_rejoin_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_rejoin_req(int param_1,int param_2)

{
  ushort uVar1;
  code *pcVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *extraout_a1;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_3c;
  int iStack_38;
  code *pcStack_34;
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined1 auStack_2c [10];
  undefined1 uStack_22;
  byte abStack_21 [9];
  
  iVar4 = nwk_is_router_started();
  if ((iVar4 != 0) && (*(short *)(param_2 + 2) == *(short *)(param_2 + 6))) {
    sVar3 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,sVar3 + 1,1,abStack_21);
    uVar1 = *(ushort *)(param_1 + 0x16);
    if ((uVar1 & 2) == 0) {
      uStack_22 = 1;
    }
    else {
      uStack_22 = 2;
    }
    uStack_2e = *(undefined2 *)(param_2 + 6);
    iVar4 = nwk_frame_get_src_extaddr(param_1,auStack_2c);
    if (iVar4 == 0) {
      iVar4 = nwk_accept_child(*(undefined1 *)(param_2 + 8),auStack_2c,abStack_21[0],uStack_22,
                               &uStack_2e);
      if (iVar4 == 0xe2) {
        return;
      }
      zmsg_free(param_1);
      if ((uVar1 & 2) == 0) {
        uVar5 = 0x21;
      }
      else {
        uVar5 = 0x2f;
      }
      iVar6 = zmsg_alloc(uVar5);
      if (iVar6 != 0) {
        zmsg_set_offset(0);
        nwk_frame_write_hdr(iVar6,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 6),1,
                            (uVar1 & 2) != 0,0);
        nwk_frame_add_dst_extaddr(iVar6,auStack_2c);
        iVar7 = core_globals_get();
        local_30._0_1_ = *(char *)(iVar7 + 0x9d9);
        *(char *)(iVar7 + 0x9d9) = (char)local_30 + '\x01';
        zmsg_write_bytes(iVar6,7,1,&local_30);
        local_30 = CONCAT11(local_30._1_1_,7);
        zmsg_append_bytes(iVar6,1,&local_30);
        local_30 = uStack_2e;
        zmsg_append_bytes(iVar6,2,&local_30);
        local_30 = CONCAT11(local_30._1_1_,(char)iVar4);
        zmsg_append_bytes(iVar6,1,&local_30);
        zmsg_add_footer(iVar6,&uStack_22,1);
        nwk_fwd_mac_data_req
                  (iVar6,*(undefined1 *)(param_2 + 8),*(undefined2 *)(param_2 + 6),
                   abStack_21[0] >> 3 & 1 ^ 1);
        return;
      }
      pcVar2 = nwk_handle_asso_indication;
      uVar5 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x161,
                            "nwk_handle_rejoin_req",
                            "(msg = zmsg_alloc(((0x0b - sizeof(uint16_t)) + ((0) ? (__builtin_offsetof (nwk_hdr_t, src_ieee_addr)) : (sizeof(nwk_hdr_t))) + ((is_secured) ? sizeof(secur_aux_hdr_t) : 0)))) != ((void *)0)"
                           );
      iStack_3c = param_2;
      iStack_38 = iVar6;
      pcStack_34 = pcVar2;
      iVar4 = nwk_is_router_started();
      if (iVar4 != 0) {
        uStack_44 = 0xfffe;
        uStack_4c = *extraout_a1;
        uStack_48 = extraout_a1[1];
        iVar4 = nwk_accept_child(uVar5,extraout_a1,*(undefined1 *)(extraout_a1 + 2),0,&uStack_44);
        uStack_44._0_3_ = CONCAT12((char)iVar4,(undefined2)uStack_44);
        if ((iVar4 != 0xe2) && (iVar4 = nwk_mm_asso_response(uVar5,&uStack_4c), iVar4 != 0)) {
          nwk_accept_child_done(&uStack_4c,0);
        }
      }
      return;
    }
  }
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

