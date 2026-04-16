/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_bcast
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool nwk_fwd_handle_bcast(nwk_rx_info_t *rx_info,zmsg_t *msg)

{
  _Bool _Var1;
  uint uVar2;
  
  core_globals_get();
  uVar2 = nwk_is_device_in_bcast_group(rx_info->nwk_dst_addr);
  if (uVar2 != 0) {
    _Var1 = nwk_btt_add_if_absent(rx_info->nwk_src_addr,msg);
    uVar2 = (uint)_Var1;
  }
  return SUB41(uVar2,0);
}

