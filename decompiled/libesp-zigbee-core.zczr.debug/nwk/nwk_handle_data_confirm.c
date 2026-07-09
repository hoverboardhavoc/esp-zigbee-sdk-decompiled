/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_handle_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

void nwk_handle_data_confirm(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint local_20;
  undefined4 uStack_1c;
  undefined1 auStack_1a [2];
  uint uStack_18;
  ushort auStack_12 [3];
  
  zmsg_read_bytes(0,2,auStack_12);
  if ((auStack_12[0] & 3) == 0) {
    uStack_1c = 0;
    uStack_18 = param_2 & 0xff;
    local_20 = param_1;
    zmsg_read_bytes(param_1,4,2,&stack0xffffffe4);
    zmsg_read_bytes(param_1,2,auStack_1a);
    uVar1 = zmsg_get_offset(param_1);
    zmsg_remove_header(param_1,uVar1);
    nwk_nlde_data_confirm(&local_20);
  }
  else if ((auStack_12[0] & 3) == 1) {
    local_20 = local_20 & 0xffffff00;
    uVar1 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,uVar1,1,&local_20);
    uVar2 = local_20 & 0xff;
    if (uVar2 == 0xb) {
      nwk_ed_handle_tmo_req_sent(param_1,param_2);
    }
    else {
      if (uVar2 < 0xc) {
        if (uVar2 == 6) {
          nwk_handle_rejoin_req_sent(param_1,param_2);
          return;
        }
        if (uVar2 == 7) {
          nwk_handle_rejoin_rsp_sent(param_1,param_2);
          return;
        }
        if (uVar2 == 4) {
          nwk_handle_leave_sent(param_1,param_2);
          return;
        }
      }
      else {
        if (uVar2 == 0xe) {
          nwk_handle_network_comm_req_sent(param_1,param_2);
          return;
        }
        if (uVar2 == 0xf) {
          nwk_handle_network_comm_rsp_sent(param_1,param_2);
          return;
        }
      }
      zmsg_free(param_1);
    }
  }
  else {
    zmsg_free(param_1);
  }
  return;
}

