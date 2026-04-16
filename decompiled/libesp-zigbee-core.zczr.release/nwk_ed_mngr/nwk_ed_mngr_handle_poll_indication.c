/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_mngr_handle_poll_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_mngr_handle_poll_indication(uint8_t iface_id,mac_poll_ind_t *ind)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  int iVar2;
  
  _Var1 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var1) != 0) {
    if ((ind->device_address).addr_mode == '\x02') {
      iVar2 = nwk_neighbor_table_get_by_short((ind->device_address).u.short_addr);
    }
    else {
      iVar2 = nwk_neighbor_table_get_by_extended(&(ind->device_address).u);
    }
    if (iVar2 == 0) {
      if ((ind->device_address).addr_mode == '\x02') {
        nwk_send_direct_leave
                  (CONCAT31(in_register_00002029,iface_id),(ind->device_address).u.short_addr);
        return;
      }
    }
    else {
      if ((*(uint *)(iVar2 + 0xc) & 0x3c0) == 0x200) {
        nwk_child_address_change_request();
      }
      if ((*(uint *)(iVar2 + 0xc) & 0x3c0) == 0x40) {
        nwk_neighbor_zed_keepalive();
        return;
      }
    }
  }
  return;
}

