/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_handle_received_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_received_cmd(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  byte bStack_15;
  byte local_11;
  
  local_11 = 0;
  uVar2 = zmsg_get_offset();
  zmsg_read_bytes(param_1,uVar2,1,&local_11);
  if (local_11 == 7) {
    nwk_handle_rejoin_rsp(param_1,param_2);
    param_1 = 0;
    goto _L0;
  }
  if (local_11 < 8) {
    if (local_11 == 4) {
      nwk_handle_leave(param_1,param_2);
      param_1 = 0;
      goto _L0;
    }
    if (local_11 < 5) {
      if (local_11 == 2) {
        nwk_mesh_handle_rrep(param_1,param_2);
        param_1 = 0;
        goto _L0;
      }
      if (local_11 == 3) {
        nwk_handle_network_status(param_1,param_2);
        param_1 = 0;
        goto _L0;
      }
      if (local_11 == 1) {
        nwk_mesh_handle_rreq(param_1,param_2);
        param_1 = 0;
        goto _L0;
      }
    }
    else {
      if (local_11 == 5) {
        nwk_mesh_handle_rrec(param_1,param_2);
        param_1 = 0;
        goto _L0;
      }
      if (local_11 == 6) {
        nwk_handle_rejoin_req(param_1,param_2);
        param_1 = 0;
        goto _L0;
      }
    }
    goto _L0;
  }
  if (local_11 == 0xc) {
    nwk_ed_handle_ed_tmo_rsp(param_1,param_2);
    param_1 = 0;
    goto _L0;
  }
  if (local_11 < 0xd) {
    if (10 < local_11) {
      if (local_11 == 0xb) {
        nwk_ed_mngr_handle_ed_tmo_req(param_1,param_2);
        param_1 = 0;
        goto _L0;
      }
      goto _L0;
    }
    if (local_11 < 9) {
      if (local_11 == 8) {
        nwk_link_mngr_handle_link_status(param_1,param_2);
        goto _L0;
      }
      goto _L0;
    }
_L0:
    uVar2 = nwk_frame_cmd_str(local_11);
    log_write(2,"nwk.c","Receive unsupported command: %s",uVar2);
  }
  else {
    if (local_11 == 0xe) {
      nwk_handle_network_comm_req(param_1,param_2);
      param_1 = 0;
      goto _L0;
    }
    if (local_11 == 0xf) {
      nwk_handle_network_comm_rsp(param_1,param_2);
      param_1 = 0;
      goto _L0;
    }
    if (local_11 == 0xd) goto _L0;
_L0:
    log_write(1,"nwk.c","Receive invalid command: %d");
  }
  uVar1 = *(ushort *)(param_2 + 4);
  uVar3 = nwk_get_short_address();
  if (uVar1 == uVar3) {
    uStack_18 = 0x13;
    uStack_17 = (undefined1)*(undefined2 *)(param_2 + 6);
    uStack_16 = (undefined1)((ushort)*(undefined2 *)(param_2 + 6) >> 8);
    bStack_15 = local_11;
    nwk_send_status(&uStack_18);
  }
_L0:
  if (param_1 != 0) {
    zmsg_free(param_1);
  }
  return;
}

