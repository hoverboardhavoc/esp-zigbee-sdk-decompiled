/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_network_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_network_discovery
                    (channel_page_t channels,uint8_t duration,_Bool permit_join_only,
                    _Bool ed_cap_only)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined3 in_register_0000202d;
  undefined4 local_30;
  mac_scan_req_t scan_req;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xac0) == '\0') {
    if (CONCAT31(in_register_0000202d,duration) == 0) {
      eVar2 = 2;
    }
    else {
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xac0) = 1;
      iVar1 = core_globals_get();
      *(_Bool *)(iVar1 + 0xac8) = permit_join_only;
      iVar1 = core_globals_get();
      *(_Bool *)(iVar1 + 0xac9) = ed_cap_only;
      scan_req.cb_u.active_scan_cb = (active_scan_callback)0x0;
      local_30 = (uint)CONCAT11(duration,1);
      scan_req.scan_channels.u32 = (uint32_t)nwk_active_scan_callback;
      scan_req._0_4_ = channels;
      eVar2 = nwk_mm_scan_request(0,&local_30);
    }
  }
  else {
    eVar2 = 3;
  }
  return eVar2;
}

