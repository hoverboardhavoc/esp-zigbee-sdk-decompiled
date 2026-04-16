/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_handle_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_data_confirm(zmsg_t *msg,ezb_err_t error)

{
  undefined4 uVar1;
  uint uVar2;
  ushort uStack_1e;
  zmsg_t *pzStack_1c;
  uint16_t fcf;
  nwk_nlde_data_cnf_t cnf;
  
  zmsg_read_bytes(0,2,&uStack_1e);
  if ((uStack_1e & 3) == 0) {
    cnf.nsdu = (zmsg_t *)0x0;
    cnf._4_4_ = error & 0xff;
    pzStack_1c = msg;
    zmsg_read_bytes(msg,4,2,&cnf);
    zmsg_read_bytes(msg,2,(undefined1 *)((int)&cnf.nsdu + 2));
    uVar1 = zmsg_get_offset(msg);
    zmsg_remove_header(msg,uVar1);
    nwk_nlde_data_confirm(&stack0xffffffe4);
    return;
  }
  if ((uStack_1e & 3) == 1) {
    pzStack_1c = (zmsg_t *)((uint)pzStack_1c & 0xffffff00);
    uVar1 = zmsg_get_offset(msg);
    zmsg_read_bytes(msg,uVar1,1,&stack0xffffffe4);
    uVar2 = (uint)pzStack_1c & 0xff;
    if (uVar2 == 0xb) {
      nwk_ed_handle_tmo_req_sent(msg,error);
      return;
    }
    if (uVar2 < 0xc) {
      if (uVar2 == 6) {
        nwk_handle_rejoin_req_sent(msg,error);
        return;
      }
      if (uVar2 == 7) {
        nwk_handle_rejoin_rsp_sent(msg,error);
        return;
      }
      if (uVar2 == 4) {
        nwk_handle_leave_sent(msg,error);
        return;
      }
    }
    else {
      if (uVar2 == 0xe) {
        nwk_handle_network_comm_req_sent(msg,error);
        return;
      }
      if (uVar2 == 0xf) {
        nwk_handle_network_comm_rsp_sent(msg,error);
        return;
      }
    }
  }
  zmsg_free(msg);
  return;
}

