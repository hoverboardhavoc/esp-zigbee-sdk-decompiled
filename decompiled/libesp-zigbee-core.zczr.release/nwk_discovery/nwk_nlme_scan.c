/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_nlme_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: scan_req */
/* WARNING: Unknown calling convention */

ezb_err_t nwk_nlme_scan(nwk_scan_req_t *req)

{
  ushort uVar1;
  int iVar2;
  ezb_err_t eVar3;
  code *pcVar4;
  uint local_20;
  mac_scan_req_t scan_req;
  
  iVar2 = core_globals_get();
  eVar3 = 3;
  if (*(char *)(iVar2 + 0xac0) == '\0') {
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xac0) = 1;
    iVar2 = core_globals_get();
    memcpy((void *)(iVar2 + 0xac8),req,0x10);
    local_20 = (uint)req->scan_duration << 8;
    scan_req._0_4_ = req->scan_channels;
    uVar1._0_1_ = req->scan_type;
    uVar1._1_1_ = req->scan_duration;
    if (req->scan_type == '\0') {
      pcVar4 = nwk_nlme_ed_scan_callback;
    }
    else {
      if (req->scan_type != '\x01') {
        return 2;
      }
      local_20 = (uint)uVar1;
      pcVar4 = nwk_nlme_active_scan_callback;
    }
    scan_req.cb_u = (anon_union_4_2_0921b8ba_for_cb_u)req->user_ctx;
    scan_req.scan_channels = (channel_page_t)pcVar4;
    eVar3 = nwk_mm_scan_request(0,&local_20);
  }
  return eVar3;
}

