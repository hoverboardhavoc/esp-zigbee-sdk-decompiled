/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_handle_device_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_device_leave(nwk_leave_ind_t *ind)

{
  int iVar1;
  int iVar2;
  
  iVar1 = nwk_neighbor_table_get_by_extended(&ind->device_address);
  nwk_fwd_purge(ind->short_address);
  iVar2 = nwk_is_device_zed();
  if (iVar2 == 0) {
    nwk_route_table_remove_by_dst(ind->short_address);
    nwk_route_table_remove_by_next_hop(ind->short_address);
    nwk_route_record_table_remove_by_dst(ind->short_address);
    nwk_route_record_table_remove_by_next_hop(ind->short_address);
    if (iVar1 != 0) {
      nwk_neighbor_table_delete(iVar1);
    }
  }
  else if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0xc) & 0x3c0) == 0)) && ((ind->field_0xa & 2) != 0))
  {
    nwk_do_leave('\x02',false,(_Bool)((byte)(*(ushort *)&ind->field_0xa >> 1) & 1));
  }
  return;
}

