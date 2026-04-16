/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_handle_received_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: cmd */
/* WARNING: Unknown calling convention */

void nwk_handle_received_cmd(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  int iVar1;
  ushort uVar2;
  ezb_shortaddr_t eVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  uint uVar5;
  byte local_15 [3];
  undefined1 uStack_12;
  uint8_t cmd_id;
  nwk_network_status_cmd_t cmd;
  
  local_15[0] = 0;
  uVar4 = zmsg_get_offset();
  zmsg_read_bytes(msg,uVar4,1,local_15);
  uVar5 = (uint)local_15[0];
  if (uVar5 == 7) {
    nwk_handle_rejoin_rsp(msg,rx_info);
    return;
  }
  if (uVar5 < 8) {
    if (uVar5 == 4) {
      nwk_handle_leave(msg,rx_info);
      return;
    }
    if (4 < uVar5) {
      if (uVar5 == 5) {
        nwk_mesh_handle_rrec(msg,rx_info);
        return;
      }
      nwk_handle_rejoin_req(msg,rx_info);
      return;
    }
    if (uVar5 == 2) {
      nwk_mesh_handle_rrep(msg,rx_info);
      return;
    }
    if (uVar5 == 3) {
      nwk_handle_network_status(msg,rx_info);
      return;
    }
    if (uVar5 == 1) {
      nwk_mesh_handle_rreq(msg,rx_info);
      return;
    }
_L0:
    iVar1 = -0x4c4;
    uVar4 = 1;
  }
  else {
    if (uVar5 == 0xc) {
      nwk_ed_handle_ed_tmo_rsp(msg,rx_info);
      return;
    }
    if (uVar5 < 0xd) {
      if (uVar5 == 0xb) {
        nwk_ed_mngr_handle_ed_tmo_req(msg,rx_info);
        return;
      }
      if (uVar5 == 8) {
        nwk_link_mngr_handle_link_status(msg,rx_info);
        goto _L0;
      }
    }
    else {
      if (uVar5 == 0xe) {
        nwk_handle_network_comm_req(msg,rx_info);
        return;
      }
      if (uVar5 == 0xf) {
        nwk_handle_network_comm_rsp(msg,rx_info);
        return;
      }
      if (uVar5 != 0xd) goto _L0;
    }
    uVar5 = nwk_frame_cmd_str(uVar5);
    iVar1 = -0x4ec;
    uVar4 = 2;
  }
  log_write(uVar4,"nwk.c",iVar1 + 0x11000,uVar5);
  uVar2 = rx_info->nwk_dst_addr;
  eVar3 = nwk_get_short_address();
  if ((uint)uVar2 == CONCAT22(extraout_var,eVar3)) {
    local_15[1] = 0x13;
    local_15[2] = (byte)rx_info->nwk_src_addr;
    uStack_12 = (undefined1)(rx_info->nwk_src_addr >> 8);
    cmd_id = local_15[0];
    nwk_send_status(local_15 + 1);
  }
_L0:
  if (msg != (zmsg_t *)0x0) {
    zmsg_free(msg);
  }
  return;
}

