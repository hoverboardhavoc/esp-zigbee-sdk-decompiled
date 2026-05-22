/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_nlme_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_nlme_scan(nwk_scan_req_t *req)

{
  int iVar1;
  ezb_err_t eVar2;
  uint32_t uVar3;
  anon_union_4_2_0921b8ba_for_ezb_nwk_scan_req_s_3 aVar4;
  void *pvVar5;
  int local_20;
  mac_scan_req_t scan_req;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xac0) == '\0') {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac0) = 1;
    iVar1 = core_globals_get();
    uVar3 = req->scan_channels;
    aVar4 = req->field_3;
    pvVar5 = req->user_ctx;
    *(undefined4 *)(iVar1 + 0xac8) = *(undefined4 *)req;
    *(uint32_t *)(iVar1 + 0xacc) = uVar3;
    *(anon_union_4_2_0921b8ba_for_ezb_nwk_scan_req_s_3 *)(iVar1 + 0xad0) = aVar4;
    *(void **)(iVar1 + 0xad4) = pvVar5;
    local_20 = (uint)req->scan_duration << 8;
    scan_req._0_4_ = req->scan_channels;
    if (req->scan_type == '\0') {
      scan_req.scan_channels.u32 = (uint32_t)nwk_nlme_ed_scan_callback;
      scan_req.cb_u = (anon_union_4_2_0921b8ba_for_cb_u)req->user_ctx;
    }
    else {
      if (req->scan_type != '\x01') {
        return 2;
      }
      local_20 = CONCAT31((uint3)req->scan_duration,1);
      scan_req.scan_channels.u32 = (uint32_t)nwk_nlme_active_scan_callback;
      scan_req.cb_u = (anon_union_4_2_0921b8ba_for_cb_u)req->user_ctx;
    }
    eVar2 = nwk_mm_scan_request(0,&local_20);
  }
  else {
    eVar2 = 3;
  }
  return eVar2;
}

