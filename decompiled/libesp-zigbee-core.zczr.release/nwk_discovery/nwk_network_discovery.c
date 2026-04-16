/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_network_discovery
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
  undefined1 local_30;
  uint8_t uStack_2f;
  undefined1 auStack_2e [2];
  mac_scan_req_t scan_req;
  
  iVar1 = core_globals_get();
  eVar2 = 3;
  if ((*(char *)(iVar1 + 0xac0) == '\0') &&
     (eVar2 = 2, CONCAT31(in_register_0000202d,duration) != 0)) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xac0) = 1;
    iVar1 = core_globals_get();
    *(_Bool *)(iVar1 + 0xac8) = permit_join_only;
    iVar1 = core_globals_get();
    *(_Bool *)(iVar1 + 0xac9) = ed_cap_only;
    memset(auStack_2e,0,0xe);
    local_30 = 1;
    scan_req.scan_channels.u32 = (uint32_t)nwk_active_scan_callback;
    uStack_2f = duration;
    scan_req._0_4_ = channels;
    nwk_mm_scan_request(0,&local_30);
    eVar2 = 0;
  }
  return eVar2;
}

