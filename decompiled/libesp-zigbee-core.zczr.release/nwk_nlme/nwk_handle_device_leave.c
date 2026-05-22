/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_nlme.o -> nwk_handle_device_leave
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
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  ezb_shortaddr_t eStack_1a;
  
  iVar1 = nwk_neighbor_table_get_by_extended(&ind->device_address);
  memset(&uStack_1b,0,9);
  eStack_1a = ind->short_address;
  uStack_1c = 2;
  nwk_mm_purge_tx_queue(0xff,&uStack_1c);
  nwk_fwd_purge_ex(ind->short_address,0,0);
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

