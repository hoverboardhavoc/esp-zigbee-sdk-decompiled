/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_mngr_handle_poll_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_mngr_handle_poll_indication(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = nwk_is_router_started();
  if (iVar1 != 0) {
    if (*param_2 == '\x02') {
      iVar1 = nwk_neighbor_table_get_by_short(*(undefined2 *)(param_2 + 2));
    }
    else {
      iVar1 = nwk_neighbor_table_get_by_extended(param_2 + 2);
    }
    if (iVar1 == 0) {
      if (*param_2 == '\x02') {
        nwk_send_direct_leave(param_1,*(undefined2 *)(param_2 + 2));
      }
    }
    else {
      if ((*(uint *)(iVar1 + 0xc) & 0x3c0) == 0x200) {
        nwk_child_address_change_request(iVar1);
      }
      if ((*(uint *)(iVar1 + 0xc) & 0x3c0) == 0x40) {
        nwk_neighbor_zed_keepalive(iVar1);
      }
    }
  }
  return;
}

