/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_handle_rejoin_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_rejoin_req(int param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined1 auStack_28 [20];
  
  iVar3 = nwk_is_router_started();
  if ((iVar3 == 0) || (*(short *)(param_2 + 2) != *(short *)(param_2 + 6))) {
    if (param_1 == 0) {
      return;
    }
  }
  else {
    sVar2 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,sVar2 + 1,1,&uStack_2e);
    uVar1 = *(ushort *)(param_1 + 0x16);
    uStack_2e = CONCAT11(((uVar1 & 2) != 0) + '\x01',(undefined1)uStack_2e);
    uStack_2c = *(undefined2 *)(param_2 + 6);
    iVar3 = nwk_frame_get_src_extaddr(param_1,auStack_28);
    if (iVar3 == 0) {
      iVar3 = nwk_accept_child(*(undefined1 *)(param_2 + 8),auStack_28,(undefined1)uStack_2e,
                               uStack_2e._1_1_,&uStack_2c);
      if (iVar3 == 0xe2) {
        return;
      }
      zmsg_free(param_1);
      iVar4 = zmsg_alloc((-(uint)((uVar1 & 2) == 0) & 0xfffffff2) + 0x2f);
      if (iVar4 == 0) {
        __assert_func(0,0,0);
      }
      zmsg_set_offset(0);
      nwk_frame_write_hdr(iVar4,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 6),1,
                          (uVar1 & 2) >> 1,0);
      nwk_frame_add_dst_extaddr(iVar4,auStack_28);
      iVar5 = core_globals_get();
      uStack_2a._0_1_ = *(char *)(iVar5 + 0x9d9);
      *(char *)(iVar5 + 0x9d9) = (char)uStack_2a + '\x01';
      zmsg_write_bytes(iVar4,7,1,&uStack_2a);
      uStack_2a = CONCAT11(uStack_2a._1_1_,7);
      zmsg_append_bytes(iVar4,1,&uStack_2a);
      uStack_2a = uStack_2c;
      zmsg_append_bytes(iVar4,2,&uStack_2a);
      uStack_2a = CONCAT11(uStack_2a._1_1_,(char)iVar3);
      zmsg_append_bytes(iVar4,1,&uStack_2a);
      zmsg_add_footer(iVar4,(int)&uStack_2e + 1,1);
      nwk_fwd_mac_data_req
                (iVar4,*(undefined1 *)(param_2 + 8),*(undefined2 *)(param_2 + 6),
                 uStack_2e >> 3 & 1 ^ 1);
      return;
    }
  }
  zmsg_free(param_1);
  return;
}

