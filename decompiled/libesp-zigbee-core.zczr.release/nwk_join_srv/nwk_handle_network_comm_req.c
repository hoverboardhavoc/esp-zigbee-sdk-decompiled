/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_network_comm_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_network_comm_req(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte bStack_36;
  byte bStack_35;
  undefined2 uStack_34;
  undefined2 uStack_32;
  byte abStack_30 [8];
  undefined1 auStack_28 [16];
  
  iVar5 = nwk_is_router_started();
  if ((iVar5 == 0) || (*(short *)(param_2 + 2) != *(short *)(param_2 + 6))) {
    if (param_1 == 0) {
      return;
    }
  }
  else {
    sVar3 = zmsg_get_offset(param_1);
    sVar4 = zmsg_read_bytes(param_1,sVar3 + 1,1,&bStack_36);
    zmsg_read_bytes(param_1,sVar3 + 1 + sVar4,1,&bStack_35);
    abStack_30[0] = 3;
    abStack_30[1] = 6;
    abStack_30[2] = 4;
    abStack_30[3] = 5;
    abStack_30[4] = 6;
    abStack_30[5] = 6;
    uVar2 = *(ushort *)(param_1 + 0x16);
    uVar9 = (uVar2 & 2) >> 1;
    bVar1 = abStack_30[uVar9 + (uint)bStack_36 * 2];
    if (bVar1 < 6) {
      uStack_34 = *(undefined2 *)(param_2 + 6);
      iVar5 = nwk_frame_get_src_extaddr(param_1,auStack_28);
      if (iVar5 == 0) {
        iVar5 = nwk_accept_child(*(undefined1 *)(param_2 + 8),auStack_28,bStack_35,bVar1,&uStack_34)
        ;
        if (iVar5 == 0xe2) {
          return;
        }
        zmsg_free(param_1);
        iVar6 = zmsg_alloc((-(uint)((uVar2 & 2) == 0) & 0xfffffff2) + 0x2f);
        if (iVar6 == 0) {
          __assert_func(0,0,0);
        }
        zmsg_set_offset(0);
        uVar7 = nwk_get_short_address();
        nwk_frame_write_hdr(iVar6,uVar7,*(undefined2 *)(param_2 + 6),1,uVar9,0);
        nwk_frame_add_dst_extaddr(iVar6,auStack_28);
        iVar8 = core_globals_get();
        uStack_32._0_1_ = *(char *)(iVar8 + 0x9d9);
        *(char *)(iVar8 + 0x9d9) = (char)uStack_32 + '\x01';
        zmsg_write_bytes(iVar6,7,1,&uStack_32);
        uStack_32 = CONCAT11(uStack_32._1_1_,0xf);
        zmsg_append_bytes(iVar6,1,&uStack_32);
        uStack_32 = uStack_34;
        zmsg_append_bytes(iVar6,2,&uStack_32);
        uStack_32 = CONCAT11(uStack_32._1_1_,(char)iVar5);
        zmsg_append_bytes(iVar6,1,&uStack_32);
        nwk_fwd_mac_data_req
                  (iVar6,*(undefined1 *)(param_2 + 8),*(undefined2 *)(param_2 + 6),
                   bStack_35 >> 3 & 1 ^ 1);
        return;
      }
    }
  }
  zmsg_free(param_1);
  return;
}

