/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_ed_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_ed_scan(mac_device *dev,channel_page_t scan_channels,uint16_t scan_duration,
                     ed_scan_callback cb,void *user_ctx)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ezb_err_t eVar2;
  
  _Var1 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar2 = 3;
  }
  else {
    _Var1 = mac_can_scan(dev);
    if (CONCAT31(extraout_var_00,_Var1) == 0) {
      eVar2 = 9;
    }
    else {
      (dev->ctx).field_7.ed_scan_result_handler = cb;
      (dev->ctx).scan_user_ctx = user_ctx;
      mac_scan(dev,MAC_OPERATION_ED_SCAN,scan_channels,scan_duration);
      eVar2 = 0;
    }
  }
  return eVar2;
}

