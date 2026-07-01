/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_send_data_confirm(zmsg_t *msg,ezb_err_t error)

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

