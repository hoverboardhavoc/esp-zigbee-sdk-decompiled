/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_active_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_active_scan(mac_device *dev,channel_page_t scan_channels,uint16_t scan_duration,
                         active_scan_callback cb,void *user_ctx)

{
  _Bool _Var1;
  undefined3 extraout_var;
  uint uVar2;
  uint uVar3;
  ezb_err_t eVar4;
  
  if ((*(uint *)&(dev->ctx).field_0x70 & 1) != 0) {
    _Var1 = mac_can_scan(dev);
    eVar4 = 9;
    if (CONCAT31(extraout_var,_Var1) != 0) {
      (dev->ctx).scan_channel = 0xff;
      uVar2 = (dev->pib).supported_channel_page.u32;
      (dev->ctx).scan_channels.u32 =
           (dev->ctx).scan_channels.u32 & 0x7ffffff | (scan_channels.u32 >> 0x1b) << 0x1b;
      (dev->ctx).field_7.active_scan_result_handler = cb;
      (dev->ctx).scan_user_ctx = user_ctx;
      (dev->ctx).scan_duration = (uint8_t)scan_duration;
      uVar3 = 0;
      if (uVar2 >> 0x1b == scan_channels.u32 >> 0x1b) {
        uVar3 = uVar2 & 0x7ffffff & scan_channels.u32 & 0x7ffffff;
      }
      (dev->ctx).scan_channels.u32 = (dev->ctx).scan_channels.u32 & 0xf8000000 | uVar3;
      mac_start_op(dev,MAC_OPERATION_ACTIVE_SCAN);
      eVar4 = 0;
    }
    return eVar4;
  }
  return 3;
}

