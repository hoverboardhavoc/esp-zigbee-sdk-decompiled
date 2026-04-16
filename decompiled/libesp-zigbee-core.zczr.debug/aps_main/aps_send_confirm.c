/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_send_confirm(zmsg_t *msg,ezb_err_t error)

{
  undefined4 uVar1;
  undefined1 auStack_44 [4];
  aps_apsde_data_cnf_t cnf;
  aps_apsde_data_req_t req;
  
  zmsg_get_footer(&cnf.asdu,0x1c);
  zmsg_remove_footer(msg,0x1c);
  if ((msg->flags & 0x20) == 0) {
    uVar1 = zmsg_get_offset(msg);
    zmsg_remove_header(msg,uVar1);
    cnf.cluster_id._0_1_ = (undefined1)error;
    cnf._16_4_ = msg;
    if ((req.radius & 0x20) == 0) {
      aps_apsde_data_confirm((aps_apsde_data_cnf_t *)auStack_44);
    }
    else {
      aps_apsde_user_data_confirm((aps_apsde_data_cnf_t *)auStack_44);
    }
  }
  else {
    aps_bind_trans_confirm(msg,error);
  }
  return;
}

