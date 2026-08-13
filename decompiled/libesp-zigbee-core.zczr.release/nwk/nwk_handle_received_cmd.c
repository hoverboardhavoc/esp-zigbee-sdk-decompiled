/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_handle_received_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_received_cmd(int param_1,int param_2)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte local_15 [3];
  undefined1 uStack_12;
  byte bStack_11;
  
  local_15[0] = 0;
  uVar3 = zmsg_get_offset();
  zmsg_read_bytes(param_1,uVar3,1,local_15);
  uVar4 = (uint)local_15[0];
  if (uVar4 == 7) {
    nwk_handle_rejoin_rsp(param_1,param_2);
    return;
  }
  if (uVar4 < 8) {
    if (uVar4 == 4) {
      nwk_handle_leave(param_1,param_2);
      return;
    }
    if (4 < uVar4) {
      if (uVar4 == 5) {
        nwk_mesh_handle_rrec(param_1,param_2);
        return;
      }
      nwk_handle_rejoin_req(param_1,param_2);
      return;
    }
    if (uVar4 == 2) {
      nwk_mesh_handle_rrep(param_1,param_2);
      return;
    }
    if (uVar4 == 3) {
      nwk_handle_network_status(param_1,param_2);
      return;
    }
    if (uVar4 == 1) {
      nwk_mesh_handle_rreq(param_1,param_2);
      return;
    }
_L0:
    iVar1 = -0x5f0;
    uVar3 = 1;
  }
  else {
    if (uVar4 == 0xc) {
      nwk_ed_handle_ed_tmo_rsp(param_1,param_2);
      return;
    }
    if (uVar4 < 0xd) {
      if (uVar4 == 0xb) {
        nwk_ed_mngr_handle_ed_tmo_req(param_1,param_2);
        return;
      }
      if (uVar4 == 8) {
        nwk_link_mngr_handle_link_status(param_1,param_2);
        goto _L0;
      }
    }
    else {
      if (uVar4 == 0xe) {
        nwk_handle_network_comm_req(param_1,param_2);
        return;
      }
      if (uVar4 == 0xf) {
        nwk_handle_network_comm_rsp(param_1,param_2);
        return;
      }
      if (uVar4 != 0xd) goto _L0;
    }
    uVar4 = nwk_frame_cmd_str(uVar4);
    iVar1 = -0x618;
    uVar3 = 2;
  }
  log_write(uVar3,"nwk.c",iVar1 + 0x11000,uVar4);
  uVar2 = *(ushort *)(param_2 + 4);
  uVar4 = nwk_get_short_address();
  if (uVar2 == uVar4) {
    local_15[1] = 0x13;
    local_15[2] = (byte)*(undefined2 *)(param_2 + 6);
    uStack_12 = (undefined1)((ushort)*(undefined2 *)(param_2 + 6) >> 8);
    bStack_11 = local_15[0];
    nwk_send_status(local_15 + 1);
  }
_L0:
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

