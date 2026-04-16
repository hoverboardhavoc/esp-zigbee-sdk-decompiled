/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_formation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_comm_formation(void)

{
  int iVar1;
  ezb_err_t eVar2;
  uint32_t uStack_18;
  nwk_network_formation_req_t req;
  
  uStack_18 = 0;
  req.scan_channels.u32 = 0;
  iVar1 = core_globals_get();
  uStack_18 = *(uint *)(iVar1 + 8);
  req.scan_channels.u32._0_1_ = 3;
  iVar1 = aps_secur_is_centralized();
  if (iVar1 == 0) {
    req.scan_channels.u32 = req.scan_channels.u32 | 0x2000000;
  }
  else {
    req.scan_channels.u32 = req.scan_channels.u32 & 0xfdffffff;
    iVar1 = nwk_is_device_zc();
    if (iVar1 != 0) {
      nwk_get_extended_address();
      aps_secur_set_tc_address();
    }
  }
  zdo_comm_get_scan_duration((uint8_t *)&req);
  zdo_comm_get_channel_mask(&uStack_18);
  iVar1 = core_globals_get();
  uStack_18 = uStack_18 & 0xf8000000 | uStack_18 & 0x7ffffff & *(uint *)(iVar1 + 8) & 0x7ffffff;
  eVar2 = nwk_network_formation_request(&uStack_18);
  return eVar2;
}

