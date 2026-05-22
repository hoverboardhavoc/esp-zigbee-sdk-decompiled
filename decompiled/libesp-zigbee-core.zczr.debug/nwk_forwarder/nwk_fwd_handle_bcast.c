/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_bcast
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_fwd_handle_bcast(nwk_rx_info_t *rx_info,zmsg_t *msg)

{
  ushort uVar1;
  _Bool _Var2;
  uint uVar3;
  undefined3 extraout_var;
  
  core_globals_get();
  uVar3 = nwk_is_device_in_bcast_group(rx_info->nwk_dst_addr);
  if (uVar3 != 0) {
    _Var2 = nwk_btt_add_if_absent(rx_info,msg);
    uVar3 = CONCAT31(extraout_var,_Var2);
    if (uVar3 != 0) {
      uVar1 = rx_info->nwk_src_addr;
      uVar3 = nwk_get_short_address();
      uVar3 = (uint)(uVar1 != uVar3);
    }
  }
  return SUB41(uVar3,0);
}

